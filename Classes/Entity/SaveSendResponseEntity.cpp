//
//  SaveSendResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "SaveSendResponseEntity.h"

#include "LogConst.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool SaveSendMetaResponseEntity::mapping(picojson::object &object) {
	if (object["saveToken"].is<string>()) {
		saveToken = object["saveToken"].get<string>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "saveToken");
		return false;
	}
	return true;
}

/**
 *  コンストラクタ
 */
SaveSendMetaResponseEntity::SaveSendMetaResponseEntity() {
	saveToken = "";
}

/**
 *  デストラクタ
 */
SaveSendMetaResponseEntity::~SaveSendMetaResponseEntity() {
}

