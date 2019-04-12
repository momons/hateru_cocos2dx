//
//  PlayerUnitEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/16.
//
//

#include "PlayerUnitEntity.h"

#include "Const/LogConst.h"
#include "Const/GameConst.h"
#include "Service/GameDataService.h"
#include "Entity/Game/Item/GameItemStatusEntity.h"

#pragma mark - ステータス

/**
 *  ステータス増減
 *
 *  @param maxStatusType    最大ステータスタイプ
 *  @param changeStatusType 変更ステータスタイプ
 *  @param value            変化値
 *
 *  @return 実際の増減値
 */
int PlayerUnitEntity::fluctuateStatus(int maxStatusType, int changeStatusType, int value) {
	
	int statusBackup = statuses[changeStatusType];
	statuses[changeStatusType] += value;
	if (statuses[changeStatusType] < 0) {
		statuses[changeStatusType] = 0;
	} else if (maxStatusType >= 0 && statuses[changeStatusType] > statuses[maxStatusType]) {
		statuses[changeStatusType] = statuses[maxStatusType];
	}
	
	return statuses[changeStatusType] - statusBackup;
}

#pragma mark - アイテム

/**
 *  持ちアイテムがフルか？
 *
 *  @return true: フル、false: まだまだ
 */
bool PlayerUnitEntity::isFullItem() {
	return items.size() >= GameConst::maxUnitItem;
}

/**
 *  アイテム追加
 *
 *  @param id       追加アイテムID
 *  @param useCount 使用回数
 *  @param itemId   アイテムID
 *
 *  @return true: フル、false: まだまだ
 */
bool PlayerUnitEntity::addItem(const int id, const int useCount, const string itemId) {
	
	// フルチェック
	if (isFullItem()) {
		return true;
	}
	
	auto itemEntity = PlayerItemEntity::createEntity(id, useCount, itemId);
	items.push_back(itemEntity);
	
	return false;
}

/**
 *  アイテム削除
 *
 *  @param id 削除アイテムID
 *
 *  @return true: あった、false: なかった
 */
bool PlayerUnitEntity::removeItem(const int id) {
	
	// 検索
	auto it = find_if(begin(items), end(items),
						 [id] (PlayerItemEntity itemEntity) {
							 return itemEntity.id == id;
						 });
	if (it == end(items)) {
		return false;
	}
	
	// 装備位置を調整
	updateEquipmentsIndex((int)(it - items.begin()));
	
	// 削除
	items.erase(it);
	
	return true;
}

/**
 *  アイテムをソート
 */
void PlayerUnitEntity::sortItem() {

	// 退避
	auto itemsBackup = items;
	
	items.clear();
	
	// 地図
	for (auto it = itemsBackup.begin();it != itemsBackup.end();it++) {
		auto itemEntity = GameDataService::sharedInstance()->items[it->id];
		if (itemEntity.type == ItemType::Map){
			// アイテム追加
			items.push_back(*it);
			// 初期化
			it->id = 0;
		}
	}
	
	// 装備品
	for (int i = ENUM_INT(EquipmentType::Weapon);i <= ENUM_INT(EquipmentType::Accessory);i++) {
		auto index = equipments[i];
		if (index < 0) {
			continue;
		}
		items.push_back(itemsBackup[index]);
		// 位置を再設定
		equipments[i] = (int)items.size() - 1;
		// 初期化
		itemsBackup[index].id = 0;
	}
	
	// 武器、鎧、盾、兜、装飾品、回復、種の順
	for (int type = ENUM_INT(ItemType::Weapon);type <= ENUM_INT(ItemType::Seed);type++) {
		for (auto it = itemsBackup.begin();it != itemsBackup.end();it++) {
			if (it->id == 0) {
				continue;
			}
			auto itemEntity = GameDataService::sharedInstance()->items[it->id];
			if (itemEntity.type == (ItemType)type) {
				// アイテム追加
				items.push_back(*it);
				// 初期化
				it->id = 0;
			}
		}
	}
	
}

/**
 *  装備位置を調整する
 *
 *  @param removeIndex 削除位置
 */
void PlayerUnitEntity::updateEquipmentsIndex(const int removeIndex) {

	auto isRemoveEquipment = false;
	
	for (int i = ENUM_INT(EquipmentType::Weapon);i <= ENUM_INT(EquipmentType::Accessory);i++) {
		if (equipments[i] < 0) {
			continue;
		}
		if (equipments[i] == removeIndex) {
			// 装備を捨てた
			equipments[i] = -1;
			// フラグON
			isRemoveEquipment = true;
		} else if (equipments[i] > removeIndex) {
			// 装備品より後のものを削除した
			equipments[i]--;
		}
	}
	
	// TODO:ステータスを再調整
	if (isRemoveEquipment) {
		updateEquippedStatus();
	}
}

/**
 *  装備後ステータスの更新
 */
void PlayerUnitEntity::updateEquippedStatus() {

	// HPから機敏さまで
	for (int i = 0;i < 6;i++) {
		statuses[ENUM_INT(UnitStatusType::HPEq) + i] = statuses[ENUM_INT(UnitStatusType::MaxHP) + 1];
	}
	// 名声から道徳心
	for (int i = 0;i < 2;i++) {
		statuses[ENUM_INT(UnitStatusType::FameEq) + i] = statuses[ENUM_INT(UnitStatusType::Fame) + 1];
	}
	// 炎属性から毒属性を初期化
	for (int i = 0;i < 4;i++) {
		statuses[ENUM_INT(UnitStatusType::FireEq) + i] = 0;
	}
	// 命中率、必殺率
	auto jobEntity = GameDataService::sharedInstance()->jobs[statuses[ENUM_INT(UnitStatusType::Job)]];
	statuses[ENUM_INT(UnitStatusType::HitRate)] = jobEntity.hitRate;
	statuses[ENUM_INT(UnitStatusType::CriticalRate)] = jobEntity.criticalRate;

	// ステータス振り分け
	for (int i = ENUM_INT(EquipmentType::Weapon);i <= ENUM_INT(EquipmentType::Accessory);i++) {
		if (equipments[i] < 0) {
			continue;
		}
		// アイテム情報取得
		auto itemEntity = GameDataService::sharedInstance()->items[items[equipments[i]].id];
		for (auto it = itemEntity.changeStatus.begin();it != itemEntity.changeStatus.end();it++) {
			if (it->status == ItemStatusType::Nothing) {
				continue;
			}
			if (it->status >= ItemStatusType::HP && it->status <= ItemStatusType::Poison) {
				// HPから毒属性
				statuses[ENUM_INT(UnitStatusType::HPEq) + (ENUM_INT(it->status) - ENUM_INT(ItemStatusType::HP))] += it->value;
			} else if (it->status >= ItemStatusType::Fame && it->status <= ItemStatusType::CriticalRate) {
				// 名声から必殺率
				statuses[ENUM_INT(UnitStatusType::FameEq) + (ENUM_INT(it->status) - ENUM_INT(ItemStatusType::Fame))] += it->value;
			}
			
		}
	}
}

#pragma mark - スキル

/**
 *  持ちスキルがフルか？
 *
 *  @return true: フル、false: まだまだ
 */
bool PlayerUnitEntity::isFullSkill() {
	return skills.size() >= GameConst::maxUnitSkill;
}

/**
 *  スキル追加
 *
 *  @param id       追加スキルID
 *
 *  @return true: フル、false: まだまだ
 */
bool PlayerUnitEntity::addSkill(const int id) {
	
	// フルチェック
	if (isFullSkill()) {
		return true;
	}
	
	skills.push_back(id);
	
	return false;
}

/**
 *  スキルをソート
 */
void PlayerUnitEntity::sortSkill() {
	
	auto skillsBackup = skills;
	
	auto maxId = GameDataService::sharedInstance()->skills.size();
	
	skills.clear();
	for (auto it = skillsBackup.begin();it != skillsBackup.end();it++) {
		for (int id = 1;id <= maxId;id++) {
			if (*it == id) {
				skills.push_back(*it);
			}
		}
	}
}

/**
 *  テレポートスキルを所持しているか？
 *
 *  @return true: 所持している、false: していない
 */
bool PlayerUnitEntity::hasSkillTeleport() {
	// 検索
	auto it = find_if(begin(skills), end(skills),
						 [] (int skillId) {
							 auto skillEntity = GameDataService::sharedInstance()->skills[skillId];
							 return skillEntity.skillType == SkillType::Teleport;
						 });
	if (it == end(skills)) {
		return false;
	}
	return true;
}

#pragma mark - バトル

/**
 *  バトルステータスに変換
 *
 *  @return バトルステータス
 */
vector<int> PlayerUnitEntity::battleStatuses() {
	
	vector<int> battleStatuses;
	for (int i = 0;i <= ENUM_INT(BattleStatusType::Max);i++) {
		if (i <= ENUM_INT(BattleStatusType::MaxSpeed)) {
			battleStatuses.push_back(statuses[ENUM_INT(UnitStatusType::HPEq) + i]);
		} else if (i <= ENUM_INT(BattleStatusType::MP)) {
			battleStatuses.push_back(statuses[ENUM_INT(UnitStatusType::HP) + (i - ENUM_INT(BattleStatusType::HP))]);
		} else if (i <= ENUM_INT(BattleStatusType::Poison)) {
			battleStatuses.push_back(statuses[ENUM_INT(UnitStatusType::AttackEq) + (i - ENUM_INT(BattleStatusType::Attack))]);
		} else if (i < ENUM_INT(BattleStatusType::Condition)) {
			battleStatuses.push_back(statuses[ENUM_INT(UnitStatusType::HitRate) + (i - ENUM_INT(BattleStatusType::HitRate))]);
		} else {
			battleStatuses.push_back(0);
		}
	}
	if (battleStatuses[ENUM_INT(BattleStatusType::HP)] <= 0) {
		battleStatuses[ENUM_INT(BattleStatusType::MaxHP)] = 0;
		battleStatuses[ENUM_INT(BattleStatusType::Condition)] |= ENUM_INT(ConditionType::Die);
	}
	return battleStatuses;
}

#pragma mark - 初期化

/**
 *  コンストラクタ
 */
PlayerUnitEntity::PlayerUnitEntity() {
	id = "";
	name = "";
	unitId = 0;
	condition = 0;
	statuses.clear();
	for (int i = ENUM_INT(UnitStatusType::Lv);i <= ENUM_INT(UnitStatusType::Direction);i++) {
		statuses.push_back(0);
	}
	equipments.clear();
	for (int i = ENUM_INT(EquipmentType::Weapon);i <= ENUM_INT(EquipmentType::Accessory);i++) {
		equipments.push_back(-1);
	}
	skills.clear();
	items.clear();
}

/**
 *  デストラクタ
 */
PlayerUnitEntity::~PlayerUnitEntity() {
}

#pragma mark - JSON

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void PlayerUnitEntity::serialize(picojson::object &object) {
	object.insert(make_pair("id", picojson::value(id)));
	object.insert(make_pair("name", picojson::value(name)));
	object.insert(make_pair("unitId", picojson::value(unitId)));
	object.insert(make_pair("condition", picojson::value(condition)));
	picojson::array statuseList;
	for (auto it = statuses.begin(); it != statuses.end(); it++) {
		statuseList.push_back(picojson::value(*it));
	}
	object.insert(make_pair("statuses", picojson::value(statuseList)));
	picojson::array equipmentList;
	for (auto it = equipments.begin(); it != equipments.end(); it++) {
		statuseList.push_back(picojson::value(*it));
	}
	object.insert(make_pair("equipments", picojson::value(equipmentList)));
	picojson::array skillList;
	for (auto it = skills.begin(); it != skills.end(); it++) {
		skillList.push_back(picojson::value(*it));
	}
	object.insert(make_pair("skills", picojson::value(skillList)));
	picojson::array itemList;
	for (auto it = items.begin(); it != items.end(); it++) {
		picojson::object object;
		it->serialize(object);
		itemList.push_back(picojson::value(object));
	}
	object.insert(make_pair("items", picojson::value(itemList)));
}

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool PlayerUnitEntity::mapping(picojson::object &object) {
	if (object["id"].is<string>()) {
		id = object["id"].get<string>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "id");
		return false;
	}
	if (object["name"].is<string>()) {
		name = object["name"].get<string>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "name");
		return false;
	}
	if (object["unitId"].is<int>()) {
		unitId = object["unitId"].get<int>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "unitId");
		return false;
	}
	if (object["condition"].is<int>()) {
		condition = object["condition"].get<int>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "condition");
		return false;
	}
	if (object["statuses"].is<picojson::array>()) {
		statuses.clear();
		auto statusList = object["statuses"].get<picojson::array>();
		for (picojson::array::iterator it = statusList.begin(); it != statusList.end(); it++) {
			if (it->is<int>()) {
				auto status = (int)it->get<int>();
				statuses.push_back(status);
			} else {
				log(LogConst::jsonBadMappingError.c_str(), "statuses");
				return false;
			}
		}
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "statuses");
		return false;
	}
	if (object["equipments"].is<picojson::array>()) {
		equipments.clear();
		auto equipmentList = object["equipments"].get<picojson::array>();
		for (picojson::array::iterator it = equipmentList.begin(); it != equipmentList.end(); it++) {
			if (it->is<int>()) {
				auto equipment = it->get<int>();
				equipments.push_back(equipment);
			} else {
				log(LogConst::jsonBadMappingError.c_str(), "equipments");
				return false;
			}
		}
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "equipments");
		return false;
	}
	if (object["skills"].is<picojson::array>()) {
		skills.clear();
		auto skillList = object["skills"].get<picojson::array>();
		for (picojson::array::iterator it = skillList.begin(); it != skillList.end(); it++) {
			if (it->is<int>()) {
				auto skill = it->get<int>();
				skills.push_back(skill);
			} else {
				log(LogConst::jsonBadMappingError.c_str(), "skills");
				return false;
			}
		}
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "skills");
		return false;
	}
	if (object["items"].is<picojson::array>()) {
		items.clear();
		auto itemList = object["items"].get<picojson::array>();
		for (picojson::array::iterator it = itemList.begin(); it != itemList.end(); it++) {
			picojson::object &item = it->get<picojson::object>();
			PlayerItemEntity itemEntity;
			auto isSuccess = itemEntity.mapping(item);
			if (!isSuccess) {
				return false;
			}
			items.push_back(itemEntity);
		}
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "items");
		return false;
	}
	return true;
}
