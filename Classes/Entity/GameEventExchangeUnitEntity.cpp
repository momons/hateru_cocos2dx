//
//  GameEventExchangeUnitEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventExchangeUnitEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventExchangeUnitEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 入替タイプ
	exchangeType = static_cast<ExchangeUnitType>(data[dataIndex]);
	dataIndex += 1;
	// 外すキャラId
	removeCharaId = (int)data[dataIndex];
	dataIndex += 1;
	// 追加キャラId
	addCharaId = (int)data[dataIndex];
	dataIndex += 1;
	
	return dataIndex;
}
