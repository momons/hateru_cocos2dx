//
//  GameInfoEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameInfoEntity.h"

#include "SJISUtil.h"

/**
 *  コンストラクタ
 */
GameInfoEntity::GameInfoEntity() {
	initMoney = 0;
	moneyUnit = "";
	initMapId = 0;
	initX = 0;
	initY = 0;
	initMemberIds.clear();
	shipUnitId = 0;
	flyShipUnitId = 0;
	shipSoundId = 0;
	flyShipSoundId = 0;
	innSoundId = 0;
	levelUpSoundId = 0;
	battleEndSoundId = 0;
}

/**
 *  デストラクタ
 */
GameInfoEntity::~GameInfoEntity() {
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameInfoEntity::convertData(const unsigned char *data) {

	auto dataIndex = 0;

	// 初期所持金
	initMoney = (int)data[dataIndex] * 0x100 + (int)data[dataIndex+1];
	dataIndex += 2;
	// お金単位
	moneyUnit = SJISUtil::convertUTF8(&data[dataIndex], 4);
	dataIndex += 4;
	// 初期位置マップ
	initMapId = (int)data[dataIndex] + 1;
	dataIndex += 1;
	// 初期位置X
	initX = (int)data[dataIndex];
	dataIndex += 1;
	// 初期位置Y
	initY = (int)data[dataIndex];
	dataIndex += 1;
	// 初期メンバ
	initMemberIds.clear();
	for (int i = 0;i < GameConst::initMemberCount;i++) {
		initMemberIds.push_back((int)data[dataIndex]);
		dataIndex += 1;
	}
	// 船
	shipUnitId = (int)data[dataIndex];
	dataIndex += 1;
	// 飛行船
	flyShipUnitId = (int)data[dataIndex];
	dataIndex += 1;
	// 音楽、船
	shipSoundId = (int)data[dataIndex];
	dataIndex += 1;
	// 音楽、飛行船
	flyShipSoundId = (int)data[dataIndex];
	dataIndex += 1;
	// 音楽、宿屋
	innSoundId = (int)data[dataIndex];
	dataIndex += 1;
	// 音楽、レベルアップ
	levelUpSoundId = (int)data[dataIndex];
	dataIndex += 1;
	// 音楽、戦闘終了
	battleEndSoundId = (int)data[dataIndex];
	dataIndex += 1;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return Entity
 */
GameInfoEntity GameInfoEntity::createEntity(const unsigned char *data) {
	auto entity = GameInfoEntity();
	entity.convertData(data);
	return entity;
}

