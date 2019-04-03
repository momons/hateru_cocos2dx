//
//  GameEventChangeBGMEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventChangeBGMEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventChangeBGMEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 変数ID
	play = data[dataIndex] != 0;
	dataIndex += 1;
	// 値
	soundId = (int)data[dataIndex];
	dataIndex += 1;
	// 操作タイプ
	fieldType = static_cast<SoundFieldType>(data[dataIndex]);
	dataIndex += 1;
	
	return dataIndex;
}
