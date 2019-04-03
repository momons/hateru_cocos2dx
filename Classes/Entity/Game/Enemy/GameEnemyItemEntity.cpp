//
//  GameEnemyItemEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/27.
//
//

#include "GameEnemyItemEntity.h"

/**
 *  コンストラクタ
 */
GameEnemyItemEntity::GameEnemyItemEntity() {
	isWon = false;
	rate = 0;
	itemId = 0;
}

/**
 *  デストラクタ
 */
GameEnemyItemEntity::~GameEnemyItemEntity() {
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEnemyItemEntity::convertData(const unsigned char *data) {
	
	auto dataIndex = 0;
	
	// 獲得フラグ
	isWon = (data[dataIndex] == 1);
	dataIndex += 1;
	// 獲得率
	rate = (int)data[dataIndex];
	dataIndex += 1;
	// 獲得アイテム
	itemId = (int)data[dataIndex];
	dataIndex += 1;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return Entity
 */
GameEnemyItemEntity GameEnemyItemEntity::createEntity(const unsigned char *data) {
	auto entity = GameEnemyItemEntity();
	entity.convertData(data);
	return entity;
}