//
//  MapLayer.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/10.
//
//

#include "MapLayer.h"

#include "GameMapService.h"
#include "GameMapEntity.h"
#include "GameMapManager.h"

/**
 *  クラス作成
 *
 *  @return クラス
 */
MapLayer *MapLayer::create() {
	auto layer = new MapLayer();
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
MapLayer::MapLayer() {
	downChips = nullptr;
	upChips = nullptr;
	width = 0;
	height = 0;
}

/**
 *  デストラクタ
 */
MapLayer::~MapLayer() {
	// 解放
	freeSprites();
}

/**
 *  セットアップ
 *
 *  @param mapEntity マップEntity
 */
void MapLayer::setupMapLayer(const GameMapEntity *mapEntity) {
	
	// 解放
	freeSprites();

	// 退避
	width = mapEntity->width;
	height = mapEntity->height;
	
	// メモリ確保
	int size = mapEntity->width * mapEntity->height * sizeof(Sprite*);
	downChips = (Sprite**)malloc(size);
	memset(downChips, 0x00, size);
	upChips = (Sprite**)malloc(size);
	memset(upChips, 0x00, size);
	
	// 背景色設定
	setBackgroundColor(Color4B((mapEntity->backgroundColor >> 16) & 0xff, (mapEntity->backgroundColor >> 8) & 0xff, mapEntity->backgroundColor & 0xff, 0xff));
	
	if (mapEntity->mapType == MapType::Normal) {
		// 通常
		setupNormalMap(mapEntity);
	} else {
		// 自動マップ
		setupAutoMap(mapEntity);
	}
	
	// 初期ポジション設定
	setUnitPosition(Point(0, 0));
}

/**
 *  ユニットのポジション設定
 *
 *  @param position ポジション
 */
void MapLayer::setUnitPosition(Point position) {
	// ポジション移動
	for(auto j = 0;j < height;j++){
		for(auto i = 0;i < width;i++){
			int mapIndex = j * width + i;
			// 座標計算
			Point point = GameMapService::buildPosition(position, Point(i, j));
			// 下チップ
			if(downChips[mapIndex] != nullptr){
				downChips[mapIndex]->setPosition(point);
			}
			// 上チップ
			if(upChips[mapIndex] != nullptr){
				upChips[mapIndex]->setPosition(point);
			}
		}
	}
}

/**
 *  レイヤー初期化
 */
void MapLayer::initLayer() {

	// 初期化
	downChips = nullptr;
	upChips = nullptr;
}

/**
 *  レイヤーメイン処理
 */
void MapLayer::layerMain() {
	
}

/**
 *  通常マップセットアップ
 *
 *  @param mapEntity マップEntity
 */
void MapLayer::setupNormalMap(const GameMapEntity *mapEntity) {
	int index = 0;
	for (auto it = mapEntity->mapChips.begin();it != mapEntity->mapChips.end();it++) {
		// 下チップ
		if (it->downChipId != 0) {
			int mapChipIndex =  mapEntity->downMapChips[it->downChipId - 1];
			if (mapChipIndex != 255) {
				downChips[index] = Sprite::createWithSpriteFrame(getSpriteFrame(mapChipIndex));
//                downChips[index]->setScale(GameConst::spriteScale);
				addChild(downChips[index], GameConst::zSortDownMapChip);
			}
		}
		// 上チップ
		if (it->upChipId != 0 && !it->isUpChipClear) {
			int mapChipIndex = mapEntity->upMapChips[it->upChipId - 1];
			if (mapChipIndex != 255) {
				upChips[index] = Sprite::createWithSpriteFrame(getSpriteFrame(mapChipIndex));
//                upChips[index]->setScale(GameConst::spriteScale);
				addChild(upChips[index], GameConst::zSortUpMapChip);
			}
		}
		index += 1;
	}
}

/**
 *  自動マップセットアップ
 *
 *  @param mapEntity マップEntity
 */
void MapLayer::setupAutoMap(const GameMapEntity *mapEntity) {

	
	
}

/**
 *  SpriteFrame取得
 *
 *  @param imageId 画像ID
 *
 *  @return SpriteFrame
 */
SpriteFrame *MapLayer::getSpriteFrame(const int imageId) {
	auto filePath = GameMapManager::getImageFilePath(imageId);
	auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(filePath);
	return frame;
}


/**
 *  スプライト情報解放
 */
void MapLayer::freeSprites() {
	if (downChips != nullptr) {
		free(downChips);
		downChips = nullptr;
	}
	if (upChips != nullptr) {
		free(upChips);
		upChips = nullptr;
	}
}
