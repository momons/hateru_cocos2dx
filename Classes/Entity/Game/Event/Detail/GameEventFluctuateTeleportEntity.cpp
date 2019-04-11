//
//  GameEventFluctuateTeleportEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventFluctuateTeleportEntity.h"

#include "../../../../Util/SJISUtil.h"
#include "../../../../Util/StringUtil.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventFluctuateTeleportEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 追加削除
	isRemove = data[dataIndex] != 0;
	dataIndex += 1;
	// 対象マップId
	mapId = (int)data[dataIndex];
	dataIndex += 1;
	// 飛ぶ位置
	jumpMapIds.clear();
	jumpXs.clear();
	jumpYs.clear();
	for (auto i = ENUM_INT(MoveType::Walk);i <= ENUM_INT(MoveType::FlyShip);i++) {
		// マップId
		jumpMapIds.push_back((int)data[dataIndex]);
		dataIndex += 1;
		// X座標
		jumpXs.push_back((int)data[dataIndex]);
		dataIndex += 1;
		// Y座標
		jumpYs.push_back((int)data[dataIndex]);
		dataIndex += 1;
	}
	// 表示名
	name = StringUtil::trim(SJISUtil::convertUTF8(&data[dataIndex], 16));
	dataIndex += 16;

	return dataIndex;
}
