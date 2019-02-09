//
//  TokenGetResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/18.
//
//

#include "TokenGetResponseEntity.h"

#include "LogConst.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool TokenGetMetaResponseEntity::mapping(picojson::object &object) {
	if (object["accessToken"].is<string>()) {
		accessToken = object["accessToken"].get<string>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "accessToken");
		return false;
	}
	return true;
}

/**
 *  コンストラクタ
 */
TokenGetMetaResponseEntity::TokenGetMetaResponseEntity() {
	accessToken = "";
}

/**
 *  デストラクタ
 */
TokenGetMetaResponseEntity::~TokenGetMetaResponseEntity() {
	
}
