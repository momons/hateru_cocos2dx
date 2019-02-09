//
//  LocationSendRequestEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "LocationSendRequestEntity.h"

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void LocationSendParamsRequestEntity::serialize(picojson::object &object) {
	object.insert(make_pair("message", picojson::value(message)));
	object.insert(make_pair("mapIndex", picojson::value((double)mapIndex)));
	object.insert(make_pair("x", picojson::value((double)x)));
	object.insert(make_pair("y", picojson::value((double)y)));
	object.insert(make_pair("otherInfos", picojson::value(otherInfos)));
}

/**
 *  コンストラクタ
 */
LocationSendParamsRequestEntity::LocationSendParamsRequestEntity() {
	message = "";
	mapIndex = 0;
	x = 0;
	y = 0;
	otherInfos = "";
}

/**
 *  デストラクタ
 */
LocationSendParamsRequestEntity::~LocationSendParamsRequestEntity() {
}