//
//  GameEventSettingShipEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventSettingShipEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventSettingShipEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	/// 乗り物タイプ
	vehicleType = static_cast<VehicleType>(data[dataIndex]);
	dataIndex += 1;
	/// 表示/非表示
	isShow = data[dataIndex] != 0;
	dataIndex += 1;
	/// マップId
	mapId = (int)data[dataIndex];
	dataIndex += 1;
	/// X座標
	x = (int)data[dataIndex];
	dataIndex += 1;
	/// Y座標
	y = (int)data[dataIndex];
	dataIndex += 1;

	return dataIndex;
}
