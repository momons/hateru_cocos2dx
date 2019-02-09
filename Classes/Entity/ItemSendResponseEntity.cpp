//
//  ItemSendResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/18.
//
//

#include "ItemSendResponseEntity.h"

#include "LogConst.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool ItemSendMetaResponseEntity::mapping(picojson::object &object) {
	if (object["exchangeToken"].is<string>()) {
		exchangeToken = object["exchangeToken"].get<string>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "exchangeToken");
		return false;
	}
	return true;
}

/**
 *  コンストラクタ
 */
ItemSendMetaResponseEntity::ItemSendMetaResponseEntity() {
	exchangeToken = "";
}

/**
 *  デストラクタ
 */
ItemSendMetaResponseEntity::~ItemSendMetaResponseEntity() {
}
