//
//  GameEventBattleEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventBattleEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventBattleEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 結果退避変数Id TODO:本当は2バイトにしないといけない。
	variableId = (int)data[dataIndex];
	dataIndex += 1;
	// 数取得
	int count = (int)data[dataIndex];
	dataIndex += 1;
	enemyIds.clear();
	for (auto i = 0;i < count;i++) {
		// 敵Id
		enemyIds.push_back((int)data[dataIndex]);
		dataIndex += 1;
	}
	
	return dataIndex;
}
