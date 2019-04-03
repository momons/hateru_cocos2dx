//
//  GameItemStatusEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameItemStatusEntity.h"


/**
 *  コンストラクタ
 */
GameItemStatusEntity::GameItemStatusEntity() {
	status = ItemStatusType::HP;
	value = 0;
}

/**
 *  デストラクタ
 */
GameItemStatusEntity::~GameItemStatusEntity() {
	
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data      バイナリデータ
 */
void GameItemStatusEntity::convertData(const unsigned char *data) {
	
	auto dataIndex = 0;
	
	// ステータス
	status = (ItemStatusType)data[dataIndex];
	dataIndex += 1;
	// 値
	value = (int)data[dataIndex] * 0x100 + (int)data[dataIndex + 1];
	value -= 30000;
	dataIndex += 2;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data      バイナリデータ
 *
 *  @return Entity
 */
GameItemStatusEntity GameItemStatusEntity::createEntity(const unsigned char *data) {
	auto entity = GameItemStatusEntity();
	entity.convertData(data);
	return entity;
}
