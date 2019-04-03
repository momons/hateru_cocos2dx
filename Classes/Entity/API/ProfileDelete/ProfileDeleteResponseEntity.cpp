//
//  ProfileDeleteResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "ProfileDeleteResponseEntity.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool ProfileDeleteMetaResponseEntity::mapping(picojson::object &object) {
	return true;
}