//
//  GameEventFluctuateHPEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventFluctuateHPEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventFluctuateHPEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// ターゲット
	target = (int)data[dataIndex];
	dataIndex += 1;
	// 増減タイプ
	fluctuateType = static_cast<FluctuateType>(data[dataIndex]);
	dataIndex += 1;
	// 値
	value = (int)data[dataIndex] * 0x100 + (int)data[dataIndex + 1];
	dataIndex += 2;
	
	return dataIndex;
}
