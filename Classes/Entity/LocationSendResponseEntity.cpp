//
//  LocationSendResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "LocationSendResponseEntity.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool LocationSendMetaResponseEntity::mapping(picojson::object &object) {
	return true;
}