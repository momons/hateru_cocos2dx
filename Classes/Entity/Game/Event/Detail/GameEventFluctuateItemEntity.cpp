//
//  GameEventFluctuateItemEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventFluctuateItemEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventFluctuateItemEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 増減タイプ
	fluctuateType = static_cast<FluctuateType>(data[dataIndex]);
	dataIndex += 1;
	// 値
	itemId = (int)data[dataIndex];
	dataIndex += 1;
	
	return dataIndex;
}
