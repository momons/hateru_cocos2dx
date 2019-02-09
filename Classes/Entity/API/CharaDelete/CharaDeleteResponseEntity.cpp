//
//  CharaDeleteResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "CharaDeleteResponseEntity.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool CharaDeleteMetaResponseEntity::mapping(picojson::object &object) {
	return true;
}