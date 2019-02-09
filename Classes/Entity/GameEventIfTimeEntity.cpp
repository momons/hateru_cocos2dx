//
//  GameEventIfTimeEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventIfTimeEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventIfTimeEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	/// 日時時間タイプ
	dateTimeTypes.clear();
	for (int i = ENUM_INT(DateTimeType::Month);i <= ENUM_INT(DateTimeType::Week);i++) {
		dateTimeTypes.push_back(static_cast<DateTimeType>(data[dataIndex]));
		dataIndex += 1;
	}
	
	return dataIndex;
}
