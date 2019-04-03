//
//  CharaSendResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "CharaSendResponseEntity.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool CharaSendMetaResponseEntity::mapping(picojson::object &object) {
	return true;
}