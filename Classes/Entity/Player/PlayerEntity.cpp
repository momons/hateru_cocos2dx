//
//  PlayerEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/16.
//
//

#include "PlayerEntity.h"

#include "Const/LogConst.h"
#include "Const/GameConst.h"
#include "Service/GameDataService.h"
#include "Entity/Game/Job/GameJobSkillEntity.h"

/**
 *  初期化
 */
void PlayerEntity::initialize() {
	isValid = false;
	id = "";
	name = "";
	saveToken = "";
	money = 0;
	units.clear();
	teleports.clear();
	cloakrooms.clear();
	variables.clear();
}

#pragma mark - ユニット

/**
 *  ユニット追加
 *
 *  @param unitId ユニットID
 */
void PlayerEntity::addUnit(const int unitId) {
	
	// ユニット情報取得
	auto charaEntity = service->charas[unitId];
	// 職業情報取得
	auto jobEntity = service->jobs[charaEntity.initJobId];
	
	PlayerUnitEntity unitEntity;
	
	// 職業情報からステータス設定
	unitEntity.unitId = unitId;
	unitEntity.statuses[ENUM_INT(UnitStatusType::Job)] = charaEntity.initJobId;
	for (int i = ENUM_INT(AddStatusType::MaxHP);i <= ENUM_INT(AddStatusType::Speed);i++) {
		unitEntity.statuses[ENUM_INT(UnitStatusType::MaxHP) + i] = jobEntity.statuses[i][0];
	}
	unitEntity.statuses[ENUM_INT(UnitStatusType::HP)] = unitEntity.statuses[ENUM_INT(UnitStatusType::MaxHP)];
	unitEntity.statuses[ENUM_INT(UnitStatusType::MP)] = unitEntity.statuses[ENUM_INT(UnitStatusType::MaxMP)];
	// アイテム追加
	for (auto it = charaEntity.initItemIds.begin();it != charaEntity.initItemIds.end();it++) {
		auto itemEntity = service->items[*it];
		unitEntity.addItem(*it, itemEntity.useCount, "");
	}
	// スキル反映
	for (auto it = jobEntity.skills.begin();it != jobEntity.skills.end();it++) {
		if (it->level != 0) {
			continue;
		}
		unitEntity.addSkill(it->skillId);
	}
	units.push_back(unitEntity);
}

#pragma mark - アイテム

/**
 *  持ちアイテムがフルか？
 *
 *  @return true: フル、false: まだまだ
 */
bool PlayerEntity::isFullItem() {
	
	for (auto it = units.begin();it != units.end();it++) {
		if (it->isFullItem()) {
			continue;
		}
		return false;
	}
	
	return true;
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
bool PlayerEntity::addItem(const int id, const int useCount, const string itemId) {

	for (auto it = units.begin();it != units.end();it++) {
		if (it->isFullItem()) {
			continue;
		}
		it->addItem(id, useCount, itemId);
		return false;
	}
	
	return true;
}

/**
 *  アイテム削除
 *
 *  @param id 削除アイテムID
 *
 *  @return true: あった、false: なかった
 */
bool PlayerEntity::removeItem(const int id) {
	
	for (auto it = units.begin();it != units.end();it++) {
		auto isSuccess = it->removeItem(id);
		if (isSuccess) {
			return true;
		}
	}
	
	return false;
}

#pragma mark - アイテム調合

/**
 *  現在のアイテムで調合できる一覧を取得する
 *
 *  @return アイテムIDリスト
 */
vector<int> PlayerEntity::validMixings() {
	
	// 初期化
	map<int, int> itemCount;
	for (int i = 1;i <= service->items.size();i++) {
		itemCount[i] = 0;
	}
	
	// 持ちアイテム数を集計する
	for (auto unitIt = units.begin();unitIt != units.end();unitIt++) {
		for (auto itemIt = unitIt->items.begin();itemIt != unitIt->items.end();itemIt++) {
			itemCount[itemIt->id] += 1;
		}
	}
	
	// 預かり所アイテム数を集計する
	for (auto itemIt = cloakrooms.begin();itemIt != cloakrooms.end();itemIt++) {
		itemCount[itemIt->id] += 1;
	}
	
	vector<int> mixings;
	for (int i = 1;i <= service->items.size();i++) {
		auto itemEntity = service->items[i];
		if (itemEntity.isValidMixings(itemCount)) {
			// 条件に達しているので追加
			mixings.push_back(i);
		}
	}
	
	return mixings;
}

#pragma mark - 預かり所

/**
 *  預かり所追加
 *
 *  @param id       追加アイテムID
 *  @param useCount 使用回数
 *  @param itemId   アイテムID
 */
void PlayerEntity::addCloakrooms(const int id, const int useCount, const string itemId) {
	auto itemEntity = PlayerItemEntity::createEntity(id, useCount, itemId);
	cloakrooms.push_back(itemEntity);
}

/**
 *  預かり所削除
 *
 *  @param id 削除アイテムID
 *
 *  @return true: あった、false: なかった
 */
bool PlayerEntity::removeCloakrooms(const int id) {
	// 検索
	auto it = find_if(begin(cloakrooms), end(cloakrooms),
						 [id] (PlayerItemEntity itemEntity) {
							 return itemEntity.id == id;
						 });
	if (it == end(cloakrooms)) {
		return false;
	}
	
	// 削除
	cloakrooms.erase(it);
	
	return true;
}

/**
 *  預かり所をソート
 */
void PlayerEntity::sortCloakrooms() {
	
	// 退避
	auto itemsBackup = cloakrooms;
	
	cloakrooms.clear();
	
	for (int type = ENUM_INT(ItemType::Normal);type <= ENUM_INT(ItemType::Skill);type++) {
		for (auto it = itemsBackup.begin();it != itemsBackup.end();it++) {
			auto itemEntity = service->items[it->id];
			if (itemEntity.type == (ItemType)type) {
				cloakrooms.push_back(*it);
			}
		}
	}
}

#pragma mark - 変数操作



#pragma mark - 初期化

/**
 *  コンストラクタ
 */
PlayerEntity::PlayerEntity() {
	initialize();
	service = GameDataService::sharedInstance();
}

/**
 *  デストラクタ
 */
PlayerEntity::~PlayerEntity() {
}

#pragma mark - JSON

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void PlayerEntity::serialize(picojson::object &object) {
	object.insert(make_pair("id", picojson::value(id)));
	object.insert(make_pair("name", picojson::value(name)));
	object.insert(make_pair("saveToken", picojson::value(saveToken)));
	picojson::object profileObj;
	profile.serialize(profileObj);
	object.insert(make_pair("profile", picojson::value(profileObj)));
	object.insert(make_pair("money", picojson::value(money)));
	picojson::array unitList;
	for (auto it = units.begin(); it != units.end(); it++) {
		picojson::object object;
		it->serialize(object);
		unitList.push_back(picojson::value(object));
	}
	object.insert(make_pair("units", picojson::value(unitList)));
	picojson::object loc;
	location.serialize(loc);
	object.insert(make_pair("location", picojson::value(loc)));
	picojson::array teleportList;
	for (auto it = teleports.begin(); it != teleports.end(); it++) {
		picojson::object object;
		it->serialize(object);
		teleportList.push_back(picojson::value(object));
	}
	object.insert(make_pair("teleports", picojson::value(teleportList)));
	picojson::object escapeLoc;
	escapeLocation.serialize(escapeLoc);
	object.insert(make_pair("escapeLocation", picojson::value(escapeLoc)));
	picojson::array cloakroomList;
	for (auto it = cloakrooms.begin(); it != cloakrooms.end(); it++) {
		picojson::object object;
		it->serialize(object);
		cloakroomList.push_back(picojson::value(object));
	}
	object.insert(make_pair("cloakrooms", picojson::value(cloakroomList)));
	picojson::array variableList;
	for (auto it = variables.begin(); it != variables.end(); it++) {
		picojson::object object;
		object.insert(make_pair("id", picojson::value(it->first)));
		object.insert(make_pair("value", picojson::value(it->second)));
		variableList.push_back(picojson::value(object));
	}
	object.insert(make_pair("variables", picojson::value(variableList)));
}

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool PlayerEntity::mapping(picojson::object &object) {
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
	if (object["saveToken"].is<string>()) {
		saveToken = object["saveToken"].get<string>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "saveToken");
		return false;
	}
	if (object["profile"].is<picojson::object>()) {
		auto profileObj = object["profile"].get<picojson::object>();
		auto isSuccess = profile.mapping(profileObj);
		if (!isSuccess) {
			return false;
		}
	}
	if (object["money"].is<int>()) {
		money = (int)object["money"].get<int>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "money");
		return false;
	}
	if (object["units"].is<picojson::array>()) {
		units.clear();
		auto unitList = object["units"].get<picojson::array>();
		for (picojson::array::iterator it = unitList.begin(); it != unitList.end(); it++) {
			auto unit = it->get<picojson::object>();
			PlayerUnitEntity unitEntity;
			auto isSuccess = unitEntity.mapping(unit);
			if (!isSuccess) {
				return false;
			}
			units.push_back(unitEntity);
		}
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "units");
		return false;
	}
	if (object["location"].is<picojson::object>()) {
		auto loc = object["location"].get<picojson::object>();
		auto isSuccess = location.mapping(loc);
		if (!isSuccess) {
			return false;
		}
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "location");
		return false;
	}
	if (object["teleports"].is<picojson::array>()) {
		teleports.clear();
		auto teleportList = object["teleports"].get<picojson::array>();
		for (picojson::array::iterator it = teleportList.begin(); it != teleportList.end(); it++) {
			picojson::object &teleport = it->get<picojson::object>();
			PlayerTeleportEntity teleportEntity;
			auto isSuccess = teleportEntity.mapping(teleport);
			if (!isSuccess) {
				return false;
			}
			teleports.push_back(teleportEntity);
		}
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "teleports");
		return false;
	}
	if (object["escapeLocation"].is<picojson::object>()) {
		auto loc = object["escapeLocation"].get<picojson::object>();
		auto isSuccess = escapeLocation.mapping(loc);
		if (!isSuccess) {
			return false;
		}
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "escapeLocation");
		return false;
	}
	if (object["cloakrooms"].is<picojson::array>()) {
		cloakrooms.clear();
		auto cloakroomList = object["cloakrooms"].get<picojson::array>();
		for (picojson::array::iterator it = cloakroomList.begin(); it != cloakroomList.end(); it++) {
			picojson::object &cloakroom = it->get<picojson::object>();
			PlayerItemEntity cloakroomEntity;
			auto isSuccess = cloakroomEntity.mapping(cloakroom);
			if (!isSuccess) {
				return false;
			}
			cloakrooms.push_back(cloakroomEntity);
		}
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "cloakrooms");
		return false;
	}
	if (object["variables"].is<picojson::array>()) {
		variables.clear();
		auto variableList = object["variables"].get<picojson::array>();
		for (picojson::array::iterator it = variableList.begin(); it != variableList.end(); it++) {
			picojson::object &variable = it->get<picojson::object>();
			int id = 0;
			int value = 0;
			if (variable["id"].is<int>()) {
				id = variable["id"].get<int>();
			} else {
				log(LogConst::jsonBadMappingError.c_str(), "variable_id");
				return false;
			}
			if (variable["value"].is<int>()) {
				money = variable["value"].get<int>();
			} else {
				log(LogConst::jsonBadMappingError.c_str(), "variable_value");
				return false;
			}
			variables[id] = value;
		}
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "variables");
		return false;
	}
	return true;
}
