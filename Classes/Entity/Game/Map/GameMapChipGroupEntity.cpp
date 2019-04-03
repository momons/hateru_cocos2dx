//
//  GameMapChipGpEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameMapChipGroupEntity.h"


/**
 *  コンストラクタ
 */
GameMapChipGroupEntity::GameMapChipGroupEntity() {
	name = "";
	memset(imageId, 0x00, sizeof(imageId));
}

/**
 *  デストラクタ
 */
GameMapChipGroupEntity::~GameMapChipGroupEntity() {
	
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *  @param name 名前
 */
void GameMapChipGroupEntity::convertData(const unsigned char *data, const string &name) {
	
	auto dataIndex = 0;
	
	// 名前
	this->name = name;
	// 画像Id
	for (auto i = 0;i < GameConst::mapChipValueMax;i++) {
		imageId[i] = (int)data[dataIndex];
		dataIndex += 1;
	}
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *  @param name 名前
 *
 *  @return Entity
 */
GameMapChipGroupEntity GameMapChipGroupEntity::createEntity(const unsigned char *data, const string &name) {
	auto entity = GameMapChipGroupEntity();
	entity.convertData(data, name);
	return entity;
}
