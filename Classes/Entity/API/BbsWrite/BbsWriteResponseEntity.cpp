//
//  BbsWriteResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "BbsWriteResponseEntity.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool BbsWriteMetaResponseEntity::mapping(picojson::object &object) {
	return true;
}