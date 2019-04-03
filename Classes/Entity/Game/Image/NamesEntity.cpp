//
//  NamesEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/18.
//
//

#include "NamesEntity.h"

#include "SJISUtil.h"
#include "StringUtil.h"


/**
 *  コンストラクタ
 */
NamesEntity::NamesEntity() {
	names.clear();
}

/**
 *  デストラクタ
 */
NamesEntity::~NamesEntity() {
	
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *  @param len  データ長
 */
void NamesEntity::convertData(const unsigned char *data, size_t len) {
	
	// UTF8に変換
	string inStr = SJISUtil::convertUTF8(data, len);
	
	// 分割
	names.clear();
	vector<string> line;
	StringUtil::split(line, inStr, "\r\n");
	for (auto it = line.begin(); it != line.end(); it++) {
		if (it->length() <= 0) {
			continue;
		}
		names.push_back(*it);
	}
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *  @param len  データ長
 *
 *  @return Entity
 */
NamesEntity NamesEntity::createEntity(const unsigned char *data, size_t len) {
	auto entity = NamesEntity();
	entity.convertData(data, len);
	return entity;
}