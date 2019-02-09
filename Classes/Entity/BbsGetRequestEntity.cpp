//
//  BbsGetRequestEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "BbsGetRequestEntity.h"

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void BbsGetParamsRequestEntity::serialize(picojson::object &object) {
	object.insert(make_pair("bbsCode", picojson::value(bbsCode)));
	object.insert(make_pair("offset", picojson::value((double)offset)));
	object.insert(make_pair("count", picojson::value((double)count)));
}

/**
 *  コンストラクタ
 */
BbsGetParamsRequestEntity::BbsGetParamsRequestEntity() {
	bbsCode = "";
	offset = 0;
	count = 0;
}

/**
 *  デストラクタ
 */
BbsGetParamsRequestEntity::~BbsGetParamsRequestEntity() {
}
