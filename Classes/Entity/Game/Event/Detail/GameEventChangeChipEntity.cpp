//
//  GameEventChangeChipEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventChangeChipEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventChangeChipEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 通行禁止
	isNotPassWalk = data[dataIndex] != 0;
	dataIndex += 1;
	// 上下チップ
	isUpChip = data[dataIndex] != 0;
	dataIndex += 1;
	// チップ
	chipId = (int)data[dataIndex];
	dataIndex += 1;
	// X座標
	x = (int)data[dataIndex];
	dataIndex += 1;
	// Y座標
	y = (int)data[dataIndex];
	dataIndex += 1;
	// 船通行禁止
	isNotPassShip = data[dataIndex] != 0;
	dataIndex += 1;
	// 飛行通行禁止
	isNotPassFlyShip = data[dataIndex] != 0;
	dataIndex += 1;
	
	return dataIndex;
}
