//
//  GameEnemyEncountEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/27.
//
//

#include "GameEnemyEncountEntity.h"

#include "PlayerMapEntity.h"

/**
 *  範囲チェック
 *
 *  @param locationEntity プレイヤー位置Entity
 *
 *  @return true: 範囲内、false: 範囲外
 */
bool GameEnemyEncountEntity::isInRange(const PlayerMapEntity &mapEntity) {
	return  (mapId == mapEntity.id &&
			 x <= mapEntity.x && mapEntity.x < x + width &&
			 y <= mapEntity.y && mapEntity.y < y + height);
}

/**
 *  コンストラクタ
 */
GameEnemyEncountEntity::GameEnemyEncountEntity() {
	mapId = 0;
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}

/**
 *  デストラクタ
 */
GameEnemyEncountEntity::~GameEnemyEncountEntity() {
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEnemyEncountEntity::convertData(const unsigned char *data) {
	
	auto dataIndex = 0;
	
	// マップ
	mapId = (int)data[dataIndex];
	dataIndex += 1;
	// X
	x = (int)data[dataIndex];
	dataIndex += 1;
	// Y
	y = (int)data[dataIndex];
	dataIndex += 1;
	// 幅
	width = (int)data[dataIndex];
	dataIndex += 1;
	// 高さ
	height = (int)data[dataIndex];
	dataIndex += 1;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return Entity
 */
GameEnemyEncountEntity GameEnemyEncountEntity::createEntity(const unsigned char *data) {
	auto entity = GameEnemyEncountEntity();
	entity.convertData(data);
	return entity;
}