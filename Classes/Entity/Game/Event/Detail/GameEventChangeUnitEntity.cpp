//
//  GameEventChangeUnitEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventChangeUnitEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventChangeUnitEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 画像使用
	isUseImage = data[dataIndex] != 0;
	dataIndex += 1;
	// キャラID
	charaId = (int)data[dataIndex];
	dataIndex += 1;
	
	return dataIndex;
}
