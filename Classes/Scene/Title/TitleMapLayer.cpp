//
//  TitleMapLayer.cpp
//  hateru
//
//  Created by HaraKazunari on 2017/09/07.
//
//

#include "TitleMapLayer.h"

#include "GameConst.h"
#include "GameMapManager.h"

/**
 *  クラス作成
 *
 *  @return クラス
 */
TitleMapLayer *TitleMapLayer::create() {
	auto layer = new TitleMapLayer();
	if(layer && layer->init()){
		layer->Layer::autorelease();
		layer->initLayer();
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
TitleMapLayer::TitleMapLayer() {

	// 初期化
	chips = nullptr;
}

/**
 *  デストラクタ
 */
TitleMapLayer::~TitleMapLayer() {
	// 解放
	if (chips != nullptr) {
		free(chips);
		chips = nullptr;
	}
}

/**
 *  レイヤー初期化
 */
void TitleMapLayer::initLayer() {

	setBackgroundColor(Color4B(0, 0, 0, 0));

	// 幅、高さ計算
	auto glview = Director::getInstance()->getOpenGLView();
	auto screenSize = glview->getDesignResolutionSize();
	mapWidth = (int)ceil(screenSize.width / (GameConst::mapOnePanelDot * GameConst::spriteScale));
	mapHeight = (int)ceil(screenSize.height / (GameConst::mapOnePanelDot * GameConst::spriteScale)) + 2;
	
	// メモリ確保
	int size = mapWidth * mapHeight * sizeof(Sprite*);
	chips = (Sprite**)malloc(size);
	memset(chips, 0x00, size);
	
	// スプライト設定
	int index = 0;
	for (auto i = 0;i < mapWidth;i++) {
		for (auto j = 0;j < mapHeight;j++) {
			auto filePath = GameMapManager::getImageFilePath(11);
			chips[index] = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(filePath));
			chips[index]->setPosition(Point(j * GameConst::mapOnePanelDot, i * GameConst::mapOnePanelDot));
			chips[index]->setScale(GameConst::spriteScale);
			addChild(chips[index]);
			index += 1;
		}
	}
}

/**
 *  レイヤーメイン処理
 */
void TitleMapLayer::layerMain() {
	
}
