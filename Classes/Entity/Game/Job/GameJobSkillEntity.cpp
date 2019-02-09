//
//  GameJobSkillEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameJobSkillEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data      バイナリデータ
 */
void GameJobSkillEntity::convertData(const unsigned char *data) {
	
	auto dataIndex = 0;
	
	// 会得レベル
	level = (int)data[dataIndex];
	dataIndex += 1;
	// 会得スキル
	skillId = (int)data[dataIndex];
	dataIndex += 1;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return Entity
 */
GameJobSkillEntity GameJobSkillEntity::createEntity(const unsigned char *data) {
	auto entity = GameJobSkillEntity();
	entity.convertData(data);
	return entity;
}