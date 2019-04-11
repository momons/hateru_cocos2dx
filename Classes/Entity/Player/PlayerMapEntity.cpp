//
//  PlayerMapEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/18.
//
//

#include "PlayerMapEntity.h"

#include "cocos2d.h"

#include "LogConst.h"

USING_NS_CC;


/**
 *  コンストラクタ
 */
PlayerMapEntity::PlayerMapEntity() {
	id = 0;
	x = 0;
	y = 0;
}

/**
 *  デストラクタ
 */
PlayerMapEntity::~PlayerMapEntity() {
}

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void PlayerMapEntity::serialize(picojson::object &object) {
	object.insert(make_pair("id", picojson::value(id)));
	object.insert(make_pair("x", picojson::value(x)));
	object.insert(make_pair("y", picojson::value(y)));
}

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool PlayerMapEntity::mapping(picojson::object &object) {
	if (object["id"].is<int>()) {
		id = object["id"].get<int>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "id");
		return false;
	}
	if (object["x"].is<int>()) {
		x = object["x"].get<int>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "x");
		return false;
	}
	if (object["y"].is<int>()) {
		y = object["y"].get<int>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "y");
		return false;
	}
	return true;
}
