//
//  GameItemMixEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameItemMixEntity.h"

/**
 *  コンストラクタ
 */
GameItemMixEntity::GameItemMixEntity() {
	itemId = 0;
	value = 0;
}

/**
 *  デストラクタ
 */
GameItemMixEntity::~GameItemMixEntity() {
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data      バイナリデータ
 */
void GameItemMixEntity::convertData(const unsigned char *data) {
	
	auto dataIndex = 0;
	
	// アイテムID
	itemId = (int)data[dataIndex];
	dataIndex += 1;
	// 値
	value = (int)data[dataIndex];
	dataIndex += 1;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data      バイナリデータ
 *
 *  @return Entity
 */
GameItemMixEntity GameItemMixEntity::createEntity(const unsigned char *data) {
	auto entity = GameItemMixEntity();
	entity.convertData(data);
	return entity;
}