//
//  ItemListGetRequestEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "ItemListGetRequestEntity.h"

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void ItemListGetParamsRequestEntity::serialize(picojson::object &object) {
	object.insert(make_pair("exchangeType", picojson::value(exchangeType)));
	object.insert(make_pair("itemKindIndex", picojson::value((double)itemKindIndex)));
	object.insert(make_pair("hopeItemKindIndex", picojson::value((double)hopeItemKindIndex)));
	object.insert(make_pair("offset", picojson::value((double)offset)));
	object.insert(make_pair("count", picojson::value((double)count)));
}

/**
 *  コンストラクタ
 */
ItemListGetParamsRequestEntity::ItemListGetParamsRequestEntity() {
	exchangeType = "";
	itemKindIndex = 0;
	hopeItemKindIndex = 0;
	offset = 0;
	count = 0;
}

/**
 *  デストラクタ
 */
ItemListGetParamsRequestEntity::~ItemListGetParamsRequestEntity() {
}