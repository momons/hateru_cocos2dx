//
//  GameEventShowImageEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventShowImageEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventShowImageEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 表示/非表示
	isShow = data[dataIndex] != 0;
	dataIndex += 1;
	// 画像Id
	imageId = (int)data[dataIndex];
	dataIndex += 1;
	
	return dataIndex;
}
