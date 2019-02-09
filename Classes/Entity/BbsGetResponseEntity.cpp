//
//  BbsGetResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "BbsGetResponseEntity.h"

#include "LogConst.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool BbsGetDetailResponseEntity::mapping(picojson::object &object) {
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
	if (object["messageCode"].is<string>()) {
		messageCode = object["messageCode"].get<string>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "messageCode");
		return false;
	}
	if (object["messageType"].is<string>()) {
		messageType = object["messageType"].get<string>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "messageType");
		return false;
	}
	if (object["messageData"].is<string>()) {
		messageType = object["messageData"].get<string>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "messageData");
		return false;
	}
	if (object["createAt"].is<string>()) {
		createAt = object["createAt"].get<string>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "createAt");
		return false;
	}
	return true;
}

/**
 *  コンストラクタ
 */
BbsGetDetailResponseEntity::BbsGetDetailResponseEntity() {
	userCode = "";
	userName = "";
	messageCode = "";
	messageType = "";
	messageData = "";
	createAt = "";
}

/**
 *  デストラクタ
 */
BbsGetDetailResponseEntity::~BbsGetDetailResponseEntity() {
}

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool BbsGetMetaResponseEntity::mapping(picojson::object &object) {
	if (object["bbsCode"].is<string>()) {
		bbsCode = object["bbsCode"].get<string>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "bbsCode");
		return false;
	}
	if (object["messages"].is<picojson::array>()) {
		messages.clear();
		auto locationArray = object["messages"].get<picojson::array>();
		for (picojson::array::iterator it = locationArray.begin(); it != locationArray.end(); it++) {
			auto location = it->get<picojson::object>();
			BbsGetDetailResponseEntity bbsEntity;
			auto isSuccess = bbsEntity.mapping(location);
			if (!isSuccess) {
				return false;
			}
			messages.push_back(bbsEntity);
		}
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "messages");
		return false;
	}
	return true;
}

/**
 *  コンストラクタ
 */
BbsGetMetaResponseEntity::BbsGetMetaResponseEntity() {
	bbsCode = "";
	messages.clear();
}

/**
 *  デストラクタ
 */
BbsGetMetaResponseEntity::~BbsGetMetaResponseEntity() {
}
