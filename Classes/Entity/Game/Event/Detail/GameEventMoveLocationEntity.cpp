//
//  GameEventMoveLocationEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventMoveLocationEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventMoveLocationEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// マップID
	mapId = (int)data[dataIndex];
	dataIndex += 1;
	// X座標
	x = (int)data[dataIndex];
	dataIndex += 1;
	// Y座標
	y = (int)data[dataIndex];
	dataIndex += 1;
	
	return dataIndex;
}
