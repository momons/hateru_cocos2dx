//
//  PlayerItemEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/16.
//
//

#include "PlayerItemEntity.h"

#include "Const/LogConst.h"
#include "Util/UUIDUtil.h"
#include "Service/GameDataService.h"
#include "Entity/Player/PlayerUnitEntity.h"

/**
 *  アイテムEntity作成
 *
 *  @param id       ID
 *  @param useCount 使用回数
 *  @param itemId   アイテムID
 *
 *  @return PlayerItemEntity
 */
PlayerItemEntity PlayerItemEntity::createEntity(const int id, const int useCount, const string itemId) {
	
	PlayerItemEntity itemEntity;
	itemEntity.id = id;
	itemEntity.useCount = useCount;
	if (itemId.empty()) {
		itemEntity.itemId = UUIDUtil::create();
	} else {
		itemEntity.itemId = itemId;
	}

	return itemEntity;
}

/**
 *  装備可能か
 *
 *  @param unitEntity ユニットEntity
 *
 *  @return true: 装備可能、false: 装備不可
 */
bool PlayerItemEntity::isCanEquipped(const PlayerUnitEntity &unitEntity) {
	// アイテム情報取得
	auto itemEntity = GameDataService::sharedInstance()->items[id];
	// 装備可能　＆　職業別に装備可能
	return itemEntity.isCanEquipped && itemEntity.equipmentJobs[unitEntity.statuses[ENUM_INT(UnitStatusType::Job)] - 1];
}

/**
 *  コンストラクタ
 */
PlayerItemEntity::PlayerItemEntity() {
	id = 0;
	useCount = 0;
	itemId = "";
}

/**
 *  デストラクタ
 */
PlayerItemEntity::~PlayerItemEntity() {
}

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void PlayerItemEntity::serialize(picojson::object &object) {
	object.insert(make_pair("id", picojson::value(id)));
	object.insert(make_pair("useCount", picojson::value(useCount)));
	object.insert(make_pair("itemId", picojson::value(itemId)));
}

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool PlayerItemEntity::mapping(picojson::object &object) {
	if (object["id"].is<int>()) {
		id = object["id"].get<int>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "id");
		return false;
	}
	if (object["useCount"].is<int>()) {
		useCount = object["useCount"].get<int>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "useCount");
		return false;
	}
	if (object["itemId"].is<string>()) {
		itemId = object["itemId"].get<string>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "itemId");
		return false;
	}
	return true;
}
