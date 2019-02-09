//
//  MapUpLayer.cpp
//  hateru
//
//  Created by HaraKazunari on 2017/01/09.
//
//

#include "MapUpLayer.h"

#include "GameMapService.h"
#include "GameMapEntity.h"
#include "GameMapManager.h"

/**
 *  クラス作成
 *
 *  @return クラス
 */
MapUpLayer *MapUpLayer::create() {
	auto layer = new MapUpLayer();
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
MapUpLayer::MapUpLayer() {
	chips = nullptr;
	width = 0;
	height = 0;
}

/**
 *  デストラクタ
 */
MapUpLayer::~MapUpLayer() {
	// 解放
	freeSprites();
}

/**
 *  セットアップ
 *
 *  @param mapEntity マップEntity
 */
void MapUpLayer::setupMapUpLayer(const GameMapEntity *mapEntity) {
	
	// 解放
	freeSprites();
	
	// 退避
	width = mapEntity->width;
	height = mapEntity->height;
	
	// メモリ確保
	int size = mapEntity->width * mapEntity->height * sizeof(Sprite*);
	chips = (Sprite**)malloc(size);
	memset(chips, 0x00, size);
	
	// 画像読み込み
	int index = 0;
	for (auto it = mapEntity->mapChips.begin();it != mapEntity->mapChips.end();it++) {
		// チップ
		if (it->upChipId != 0 && it->isUpChipClear) {
			int mapChipIndex =  mapEntity->upMapChips[it->upChipId - 1];
			if (mapChipIndex != 255) {
				chips[index] = Sprite::createWithSpriteFrame(getSpriteFrame(mapChipIndex));
				chips[index]->setScale(GameConst::spriteScale);
				addChild(chips[index], 0);
			}
		}
		index += 1;
	}
	
	// 初期ポジション設定
	setUnitPosition(Point(0, 0));
}

/**
 *  ユニットのポジション設定
 *
 *  @param position ポジション
 */
void MapUpLayer::setUnitPosition(Point position) {
	// ポジション移動
	for(auto j = 0;j < height;j++){
		for(auto i = 0;i < width;i++){
			int mapIndex = j * width + i;
			// 座標計算
			Point point = GameMapService::buildPosition(position, Point(i, j));
			// チップ
			if(chips[mapIndex] != nullptr){
				chips[mapIndex]->setPosition(point);
			}
		}
	}
}

/**
 *  レイヤー初期化
 */
void MapUpLayer::initLayer() {
	// 初期化
	chips = nullptr;
}

/**
 *  レイヤーメイン処理
 */
void MapUpLayer::layerMain() {
	
}

/**
 *  SpriteFrame取得
 *
 *  @param imageId 画像ID
 *
 *  @return SpriteFrame
 */
SpriteFrame *MapUpLayer::getSpriteFrame(const int imageId) {
	auto filePath = GameMapManager::getImageFilePath(imageId);
	auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(filePath);
	return frame;
}

/**
 *  スプライト情報解放
 */
void MapUpLayer::freeSprites() {
	if (chips != nullptr) {
		free(chips);
		chips = nullptr;
	}
}
