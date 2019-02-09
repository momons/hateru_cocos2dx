//
//  ItemCombackRequestEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/18.
//
//

#include "ItemCombackRequestEntity.h"

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void ItemCombackParamsRequestEntity::serialize(picojson::object &object) {
	object.insert(make_pair("exchangeToken", picojson::value(exchangeToken)));
}

/**
 *  コンストラクタ
 */
ItemCombackParamsRequestEntity::ItemCombackParamsRequestEntity() {
	exchangeToken = "";
}

/**
 *  デストラクタ
 */
ItemCombackParamsRequestEntity::~ItemCombackParamsRequestEntity() {
}