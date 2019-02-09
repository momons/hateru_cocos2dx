//
//  GameEventEncountRateEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventEncountRateEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventEncountRateEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	/// 敵出現率
	encoundRate = (int)data[dataIndex];
	dataIndex += 1;
	
	return dataIndex;
}
