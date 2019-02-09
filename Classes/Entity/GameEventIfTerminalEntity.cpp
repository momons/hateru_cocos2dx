//
//  GameEventIfTerminalEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventIfTerminalEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventIfTerminalEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// キャリアタイプ
	careerType = data[dataIndex];
	dataIndex += 1;
	
	return dataIndex;
}
