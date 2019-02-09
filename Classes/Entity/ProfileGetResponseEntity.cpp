//
//  ProfileGetResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "ProfileGetResponseEntity.h"

#include "LogConst.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool ProfileGetMetaResponseEntity::mapping(picojson::object &object) {
	if (object["userCode"].is<string>()) {
		userCode = object["userCode"].get<string>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "userCode");
		return false;
	}
	if (object["userName"].is<string>()) {
		userName = object["userName"].get<string>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "userName");
		return false;
	}
	if (object["profileData"].is<string>()) {
		profileData = object["profileData"].get<string>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "profileData");
		return false;
	}
	return true;
}

/**
 *  コンストラクタ
 */
ProfileGetMetaResponseEntity::ProfileGetMetaResponseEntity() {
	userCode = "";
	userName = "";
	profileData = "";
}

/**
 *  デストラクタ
 */
ProfileGetMetaResponseEntity::~ProfileGetMetaResponseEntity() {
}

