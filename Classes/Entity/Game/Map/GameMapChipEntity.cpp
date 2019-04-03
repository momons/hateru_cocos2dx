//
//  GameMapChipEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameMapChipEntity.h"

/**
 *  コンストラクタ
 */
GameMapChipEntity::GameMapChipEntity() {
	downChipId = 0;
	upChipId = 0;
	eventId = 0;
	isNotPassWalk = false;
	isNotPassShip = false;
	isNotPassFlyShip = false;
	isUpChipClear = false;
}

/**
 *  デストラクタ
 */
GameMapChipEntity::~GameMapChipEntity() {
	
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameMapChipEntity::convertData(const unsigned char *data) {
	
	int mapData = (data[0] << 16) | (data[1] << 8) | data[2];

	// 下チップ
	downChipId = mapData & 0x3f;
	// 上チップ
	upChipId = (mapData >> 6) & 0x3f;
	// イベント
	eventId = (mapData >> 12) & 0x3f;
	// 通行禁止
	isNotPassWalk = ((mapData >> 18) & 0x1) != 0;
	// 船通行禁止
	isNotPassShip = ((mapData >> 19) & 0x1) != 0;
	// 飛行通行禁止
	isNotPassFlyShip = ((mapData >> 20) & 0x1) != 0;
	// 透過情報
	isUpChipClear = ((mapData >> 21) & 0x7) != 0;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return Entity
 */
GameMapChipEntity GameMapChipEntity::createEntity(const unsigned char *data) {
	auto entity = GameMapChipEntity();
	entity.convertData(data);
	return entity;
}
