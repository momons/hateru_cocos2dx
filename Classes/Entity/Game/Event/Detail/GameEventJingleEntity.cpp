//
//  GameEventJingleEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventJingleEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventJingleEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// サウンドId
	soundId = data[dataIndex];
	dataIndex += 1;
	// ウエイト/スルー
	isWait = data[dataIndex] != 0;
	dataIndex += 1;
	
	return dataIndex;
}
