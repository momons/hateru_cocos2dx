//
//  GameEventItemShopEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventItemShopEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventItemShopEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 数取得
	int count = (int)data[dataIndex];
	dataIndex += 1;
	itemIds.clear();
	for (auto i = 0;i < count;i++) {
		// 売りアイテムId
		itemIds.push_back((int)data[dataIndex]);
		dataIndex += 1;
	}
	
	return dataIndex;
}
