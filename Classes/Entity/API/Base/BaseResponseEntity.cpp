//
//  BaseResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/18.
//
//

#include "BaseResponseEntity.h"

#include "LogConst.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
template<class T_META>
bool BaseResponseEntity<T_META>::mapping(picojson::object &object) {
	if (object["status"].is<picojson::object>()) {
		status.mapping(object["status"].get<picojson::object>());
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "status");
		return false;
	}
	if (object["meta"].is<picojson::object>()) {
		meta.mapping(object["meta"].get<picojson::object>());
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "meta");
		return false;
	}
	return true;
}

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool BaseStatusResponseEntity::mapping(picojson::object &object) {
	if (object["code"].is<double>()) {
		code = (int)object["code"].get<double>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "code");
		return false;
	}
	if (object["message"].is<string>()) {
		message = object["message"].get<string>();
	}
	return true;
}

/**
 *  コンストラクタ
 */
BaseStatusResponseEntity::BaseStatusResponseEntity() {
	code = 0;
	message = "";
}

/**
 *  デストラクタ
 */
BaseStatusResponseEntity::~BaseStatusResponseEntity() {
	
}
