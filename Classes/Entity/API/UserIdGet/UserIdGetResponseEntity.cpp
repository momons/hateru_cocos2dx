//
//  UserIdGetResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/01.
//
//

#include "UserIdGetResponseEntity.h"

#include "LogConst.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool UserIdGetMetaResponseEntity::mapping(picojson::object &object) {
	if (object["userId"].is<string>()) {
		userId = object["userId"].get<string>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "userId");
		return false;
	}
	return true;
}

/**
 *  コンストラクタ
 */
UserIdGetMetaResponseEntity::UserIdGetMetaResponseEntity() {
	userId = "";
}

/**
 *  デストラクタ
 */
UserIdGetMetaResponseEntity::~UserIdGetMetaResponseEntity() {
	
}
