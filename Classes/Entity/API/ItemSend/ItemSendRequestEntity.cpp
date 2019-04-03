//
//  ItemSendRequestEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/18.
//
//

#include "ItemSendRequestEntity.h"

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void ItemSendParamsRequestEntity::serialize(picojson::object &object) {
	object.insert(make_pair("itemKindIndex", picojson::value((double)itemKindIndex)));
	object.insert(make_pair("itemCode", picojson::value(itemCode)));
	object.insert(make_pair("hopeItemKindIndex", picojson::value((double)hopeItemKindIndex)));
	object.insert(make_pair("partnerUserCode", picojson::value(partnerUserCode)));
	object.insert(make_pair("password", picojson::value(password)));
}

/**
 *  コンストラクタ
 */
ItemSendParamsRequestEntity::ItemSendParamsRequestEntity() {
	itemKindIndex = 0;
	itemCode = "";
	hopeItemKindIndex = 0;
	partnerUserCode = "";
	password = "";
}

/**
 *  デストラクタ
 */
ItemSendParamsRequestEntity::~ItemSendParamsRequestEntity() {
}