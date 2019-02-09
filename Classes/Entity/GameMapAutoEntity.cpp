//
//  GameMapAutoEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/06.
//
//

#include "GameMapAutoEntity.h"

/**
 *  コンストラクタ
 */
GameMapAutoEntity::GameMapAutoEntity() {
	stratum = 0;
	downChipIds.clear();
	upChipIds.clear();
	enemyIds.clear();
	itemIds.clear();
}

/**
 *  デストラクタ
 */
GameMapAutoEntity::~GameMapAutoEntity() {
	
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameMapAutoEntity::convertData(const unsigned char *data) {
	
	auto dataIndex = 0;
	
	// 階層
	stratum = (int)data[dataIndex];
	dataIndex += 1;
	// チップグループ
	downChipIds.clear();
	upChipIds.clear();
	for (auto i = 0;i < stratum;i++) {
		// 下チップ
		downChipIds.push_back((int)data[dataIndex]);
		dataIndex += 1;
		// 読み飛ばし
		dataIndex += 3;
		// 上チップ
		upChipIds.push_back((int)data[dataIndex]);
		dataIndex += 1;
		// 読み飛ばし
		dataIndex += 3;
	}
	// 敵情報
	enemyIds.clear();
	for (auto i = 0;i < stratum;i++) {
		for (auto j = 0;j < 5;j++) {
			enemyIds.push_back((int)data[dataIndex]);
			dataIndex++;
		}
	}
	// 宝情報
	itemIds.clear();
	for (auto i = 0;i < stratum;i++) {
		for (auto j = 0;j < 5;j++) {
			itemIds.push_back((int)data[dataIndex]);
			dataIndex++;
		}
	}
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return Entity
 */
GameMapAutoEntity GameMapAutoEntity::createEntity(const unsigned char *data) {
	auto entity = GameMapAutoEntity();
	entity.convertData(data);
	return entity;
}