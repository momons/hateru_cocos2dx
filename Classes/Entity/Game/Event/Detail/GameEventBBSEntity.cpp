//
//  GameEventBBSEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventBBSEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventBBSEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	/// 掲示板種類 (使用していない)
	dataIndex += 1;
	
	return dataIndex;
}
