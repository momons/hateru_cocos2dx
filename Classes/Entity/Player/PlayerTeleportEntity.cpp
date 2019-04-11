//
//  PlayerTeleportEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/16.
//
//

#include "PlayerTeleportEntity.h"

#include "cocos2d.h"

#include "../../Const/LogConst.h"
#include "../../Entity/Player/PlayerMapEntity.h"

USING_NS_CC;

/**
 *  コンストラクタ
 */
PlayerTeleportEntity::PlayerTeleportEntity() {
	name = "";
	mapId = 0;
	maps.clear();
}

/**
 *  デストラクタ
 */
PlayerTeleportEntity::~PlayerTeleportEntity() {
}

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void PlayerTeleportEntity::serialize(picojson::object &object) {
	object.insert(make_pair("name", picojson::value(name)));
	object.insert(make_pair("mapId", picojson::value(mapId)));
	picojson::array mapList;
	for (auto it = maps.begin(); it != maps.end(); it++) {
		picojson::object object;
		it->serialize(object);
		mapList.push_back(picojson::value(object));
	}
	object.insert(make_pair("maps", picojson::value(mapList)));
}

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool PlayerTeleportEntity::mapping(picojson::object &object) {
	if (object["name"].is<string>()) {
		name = object["name"].get<string>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "name");
		return false;
	}
	if (object["mapId"].is<int>()) {
		mapId = object["mapId"].get<int>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "mapId");
		return false;
	}
	if (object["maps"].is<picojson::array>()) {
		maps.clear();
		auto mapList = object["maps"].get<picojson::array>();
		for (picojson::array::iterator it = mapList.begin(); it != mapList.end(); it++) {
			picojson::object &map = it->get<picojson::object>();
			PlayerMapEntity mapEntity;
			auto isSuccess = mapEntity.mapping(map);
			if (!isSuccess) {
				return false;
			}
			maps.push_back(mapEntity);
		}
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "maps");
		return false;
	}
	return true;
}
