//
//  ItemGetResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "ItemGetResponseEntity.h"

#include "LogConst.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool ItemGetMetaResponseEntity::mapping(picojson::object &object) {
	if (object["itemKindIndex"].is<double>()) {
		itemKindIndex = (int)object["itemKindIndex"].get<double>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "itemKindIndex");
		return false;
	}
	if (object["itemCode"].is<string>()) {
		itemCode = object["itemCode"].get<string>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "itemCode");
		return false;
	}
	return true;
}

/**
 *  コンストラクタ
 */
ItemGetMetaResponseEntity::ItemGetMetaResponseEntity() {
	itemKindIndex = 0;
	itemCode = "";
}

/**
 *  デストラクタ
 */
ItemGetMetaResponseEntity::~ItemGetMetaResponseEntity() {
}
