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
    auto screenSize = Director::getInstance()->getOpenGLView()->getFrameSize();
	mapSizeWidth = (int)(screenSize.width / GameConst::mapOnePanelDot) + 3;
	mapSizeHeight = (int)(screenSize.height / GameConst::mapOnePanelDot) + 3;
    worldSize.width = mapSizeWidth * GameConst::mapOnePanelDot;
    worldSize.height = mapSizeHeight * GameConst::mapOnePanelDot;

	// メモリ確保
	int size = mapSizeWidth * mapSizeHeight * sizeof(Sprite*);
	chips = (Sprite**)malloc(size);
	memset(chips, 0x00, size);
	
	// スプライト設定
	int index = 0;
    float x = 0;
	for (auto i = 0;i < mapSizeWidth;i++) {
        float y = 0;
		for (auto j = 0;j < mapSizeHeight;j++) {
			auto filePath = GameMapManager::getImageFilePath(11); // 海
			chips[index] = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(filePath));
			chips[index]->setPosition(Point(x, y));
			addChild(chips[index], 0);
			index += 1;
            y += GameConst::mapOnePanelDot;
		}
        x += GameConst::mapOnePanelDot;
	}
}

/**
 *  レイヤーメイン処理
 */
void TitleMapLayer::layerMain() {
    auto position = getPosition();
    position.x -= 1;
    position.y -= 1;
    if (position.x < -GameConst::mapOnePanelDot) {
        position.x += GameConst::mapOnePanelDot;
    }
    if (position.y < -GameConst::mapOnePanelDot) {
        position.y += GameConst::mapOnePanelDot;
    }
    setPosition(position);
}
