//
//  CharaGetResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "CharaGetResponseEntity.h"

#include "LogConst.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool CharaGetMetaResponseEntity::mapping(picojson::object &object) {
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
	if (object["statusData"].is<string>()) {
		statusData = object["statusData"].get<string>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "statusData");
		return false;
	}
	return true;
}

/**
 *  コンストラクタ
 */
CharaGetMetaResponseEntity::CharaGetMetaResponseEntity() {
	userCode = "";
	userName = "";
	statusData = "";
}

/**
 *  デストラクタ
 */
CharaGetMetaResponseEntity::~CharaGetMetaResponseEntity() {
}

