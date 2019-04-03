//
//  ProfileGetRequestEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "ProfileGetRequestEntity.h"

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void ProfileGetParamsRequestEntity::serialize(picojson::object &object) {
	object.insert(make_pair("userCode", picojson::value(userCode)));
}

/**
 *  コンストラクタ
 */
ProfileGetParamsRequestEntity::ProfileGetParamsRequestEntity() {
	userCode = "";
}

/**
 *  デストラクタ
 */
ProfileGetParamsRequestEntity::~ProfileGetParamsRequestEntity() {
}

