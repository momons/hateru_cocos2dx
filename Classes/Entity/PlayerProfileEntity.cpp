//
//  PlayerProfileEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/29.
//
//

#include "PlayerProfileEntity.h"

#include "LogConst.h"

/**
 *  コンストラクタ
 */
PlayerProfileEntity::PlayerProfileEntity() {
	gender = 0;
	age = 0;
	address = 0;
	blood = 0;
	constellation = 0;
}

/**
 *  デストラクタ
 */
PlayerProfileEntity::~PlayerProfileEntity() {
}

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void PlayerProfileEntity::serialize(picojson::object &object) {
	object.insert(make_pair("gender", picojson::value(gender)));
	object.insert(make_pair("age", picojson::value(age)));
	object.insert(make_pair("address", picojson::value(address)));
	object.insert(make_pair("blood", picojson::value(blood)));
	object.insert(make_pair("constellation", picojson::value(constellation)));
}

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool PlayerProfileEntity::mapping(picojson::object &object) {
	if (object["gender"].is<int>()) {
		gender = object["gender"].get<int>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "gender");
		return false;
	}
	if (object["age"].is<int>()) {
		age = object["age"].get<int>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "age");
		return false;
	}
	if (object["address"].is<int>()) {
		address = object["address"].get<int>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "address");
		return false;
	}
	if (object["blood"].is<int>()) {
		blood = object["blood"].get<int>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "blood");
		return false;
	}
	if (object["constellation"].is<int>()) {
		constellation = object["constellation"].get<int>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "constellation");
		return false;
	}
	return true;
}
