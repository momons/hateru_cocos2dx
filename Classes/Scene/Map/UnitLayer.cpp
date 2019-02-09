//
//  UnitLayer.cpp
//  hateru
//
//  Created by HaraKazunari on 2017/08/22.
//
//

#include "UnitLayer.h"

#include "GameMapService.h"
#include "GameDataService.h"
#include "PlayerEntity.h"
#include "GameMapEntity.h"
#include "UnitSprite.h"

/**
 *  クラス作成
 *
 *  @return クラス
 */
UnitLayer *UnitLayer::create() {
	auto layer = new UnitLayer();
	if(layer && layer->init()){
		layer->Layer::autorelease();
		return layer;
	}else {
		delete layer;
		layer = nullptr;
		return nullptr;
	}
}

/**
 *  コンストラクタ
 */
UnitLayer::UnitLayer() {
	units = nullptr;
	unitCount = 0;
}

/**
 *  デストラクタ
 */
UnitLayer::~UnitLayer() {
	// 解放
	freeSprites();
}

/**
 *  セットアップ
 *
 *  @param playerEntity プレイヤーEntity
 *  @param mapEntity    マップEntity
 */
void UnitLayer::setupUnitLayer(PlayerEntity *playerEntity, GameMapEntity *mapEntity) {
	
	// 解放
	freeSprites();
	
	// メモリ確保
	unitCount = GameConst::maxParty + (int)mapEntity->events.size();
	int size = unitCount * sizeof(UnitSprite*);
	units = (UnitSprite**)malloc(size);
	memset(units, 0x00, size);
	
	// 操作キャラを設定
	auto dataService = GameDataService::sharedInstance();
	for (auto i = 0;i < playerEntity->units.size();i++) {
		units[i] = UnitSprite::create(dataService->charas[playerEntity->units[i].unitId]);
		units[i]->setMapLocation(playerEntity->location.x, playerEntity->location.y);
		units[i]->setScale(GameConst::spriteScale);
		addChild(units[i]);
	}
	
	// イベントキャラ
	for (auto i = 0;i < (int)mapEntity->events.size();i++) {
		if (!mapEntity->events[i].isUseUnit && mapEntity->events[i].workStatus == EventWorkStatus::Valid) {
			units[i] = UnitSprite::create(dataService->charas[mapEntity->events[i].charaId]);
			units[i]->setMapLocation(mapEntity->events[i].mapX, mapEntity->events[i].mapY);
			units[i]->setScale(GameConst::spriteScale);
			addChild(units[i]);
		}
	}
	
	// 初期ポジション設定
	setUnitPosition(Point(0, 0));
}

/**
 *  ユニットのポジション設定
 *
 *  @param position ポジション
 */
void UnitLayer::setUnitPosition(Point position) {
	// ポジション移動
	for (auto i = 0;i < unitCount;i++) {
		if(units[i] == nullptr){
			continue;
		}
		// 座標計算
		Point point = GameMapService::buildPositionDetail(position, Point(units[i]->x, units[i]->y));
		// チップ
		units[i]->setPosition(point);
		units[i]->setLocalZOrder(units[i]->mapY);
	}
}

/**
 *  レイヤー初期化
 */
void UnitLayer::initLayer() {
	// 初期化
	units = nullptr;
	unitCount = 0;
}

/**
 *  レイヤーメイン処理
 */
void UnitLayer::layerMain() {
	
}

/**
 *  スプライト情報解放
 */
void UnitLayer::freeSprites() {
	if (units != nullptr) {
		free(units);
		units = nullptr;
	}
}
