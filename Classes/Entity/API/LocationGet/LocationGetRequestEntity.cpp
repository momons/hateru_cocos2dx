//
//  LocationGetRequestEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "LocationGetRequestEntity.h"

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void LocationGetParamsRequestEntity::serialize(picojson::object &object) {
	object.insert(make_pair("mapIndex", picojson::value((double)mapIndex)));
	object.insert(make_pair("x", picojson::value((double)x)));
	object.insert(make_pair("y", picojson::value((double)y)));
}

/**
 *  コンストラクタ
 */
LocationGetParamsRequestEntity::LocationGetParamsRequestEntity() {
	mapIndex = 0;
	x = 0;
	y = 0;
}

/**
 *  デストラクタ
 */
LocationGetParamsRequestEntity::~LocationGetParamsRequestEntity() {
}