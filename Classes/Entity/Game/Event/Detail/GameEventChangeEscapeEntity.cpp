//
//  GameEventChangeEscapeEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventChangeEscapeEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventChangeEscapeEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 有効/無効
	isValid = data[dataIndex] != 0;
	dataIndex += 1;
	
	return dataIndex;
}
