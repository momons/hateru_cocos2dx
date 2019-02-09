//
//  CharaGetRequestEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "CharaGetRequestEntity.h"

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void CharaGetParamsRequestEntity::serialize(picojson::object &object) {
	object.insert(make_pair("userCode", picojson::value(userCode)));
}

/**
 *  コンストラクタ
 */
CharaGetParamsRequestEntity::CharaGetParamsRequestEntity() {
	userCode = "";
}

/**
 *  デストラクタ
 */
CharaGetParamsRequestEntity::~CharaGetParamsRequestEntity() {
}
