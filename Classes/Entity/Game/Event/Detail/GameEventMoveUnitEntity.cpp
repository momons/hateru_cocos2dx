//
//  GameEventMoveUnitEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventMoveUnitEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventMoveUnitEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	/// 移動
	int count = (int)data[dataIndex];
	dataIndex += 1;
	moveTypes.clear();
	for (auto i = 0;i < count;i++) {
		moveTypes.push_back(static_cast<EventMoveType>(data[dataIndex]));
		dataIndex += 1;
	}
	
	return dataIndex;
}
