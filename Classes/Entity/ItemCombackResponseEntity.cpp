//
//  ItemCombackResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/18.
//
//

#include "ItemCombackResponseEntity.h"

#include "LogConst.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool ItemCombackMetaResponseEntity::mapping(picojson::object &object) {
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
ItemCombackMetaResponseEntity::ItemCombackMetaResponseEntity() {
	itemKindIndex = 0;
	itemCode = "";
}

/**
 *  デストラクタ
 */
ItemCombackMetaResponseEntity::~ItemCombackMetaResponseEntity() {
}
