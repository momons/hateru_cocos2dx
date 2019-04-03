//
//  GameEventGettingOnOffEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventGettingOnOffEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventGettingOnOffEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	/// 乗り物タイプ
	vehicleType = static_cast<VehicleType>(data[dataIndex]);
	dataIndex += 1;
	// 乗り降り
	isGetOff = data[dataIndex] != 0;
	dataIndex += 1;
	
	return dataIndex;
}
