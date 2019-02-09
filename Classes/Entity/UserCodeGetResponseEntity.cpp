//
//  UserCodeGetResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/01.
//
//

#include "UserCodeGetResponseEntity.h"

#include "LogConst.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool UserCodeGetMetaResponseEntity::mapping(picojson::object &object) {
	if (object["userCode"].is<string>()) {
		userCode = object["userCode"].get<string>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "userCode");
		return false;
	}
	return true;
}

/**
 *  コンストラクタ
 */
UserCodeGetMetaResponseEntity::UserCodeGetMetaResponseEntity() {
	userCode = "";
}

/**
 *  デストラクタ
 */
UserCodeGetMetaResponseEntity::~UserCodeGetMetaResponseEntity() {
	
}
