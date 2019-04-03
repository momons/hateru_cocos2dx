//
//  GameCharaEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameCharaEntity.h"

#include "SJISUtil.h"
#include "StringUtil.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameCharaEntity::convertData(const unsigned char *data) {
	
	auto dataIndex = 0;
	
	// 名前
	name = StringUtil::trim(SJISUtil::convertUTF8(&data[dataIndex], 16));
	dataIndex += 16;
	// 初期職業
	initJobId = (int)data[dataIndex];
	dataIndex += 1;
	// 画像
	imageIds.clear();
	for (auto i = 0;i < 8;i++) {
		imageIds.push_back((int)data[dataIndex]);
		dataIndex += 1;
	}
	// 初期所持アイテム
	auto count = (int)data[dataIndex];
	dataIndex += 1;
	initItemIds.clear();
	for (auto i = 0;i < count;i++) {
		initItemIds.push_back((int)data[dataIndex]);
		dataIndex += 1;
	}
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return Entity
 */
GameCharaEntity GameCharaEntity::createEntity(const unsigned char *data) {
	auto entity = GameCharaEntity();
	entity.convertData(data);
	return entity;
}