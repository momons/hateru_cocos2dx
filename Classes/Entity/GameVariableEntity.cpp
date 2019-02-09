//
//  GameVariableEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameVariableEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *  @param name 名前
 *
 *  @return Entity
 */
GameVariableEntity GameVariableEntity::convertData(const unsigned char *data, const string &name) {

	auto entity = GameVariableEntity();

	entity.name = name;
	entity.initValue = (int)data[0];
	
	return entity;
}