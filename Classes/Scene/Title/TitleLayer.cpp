//
//  TitleLayer.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/16.
//
//

#include "TitleLayer.h"

#include "../../Const/GameConst.h"
#include "../../Manager/GameCharaManager.h"
#include "../../Manager/GameEtcManager.h"

/**
 *  クラス作成
 *
 *  @return クラス
 */
TitleLayer *TitleLayer::create() {
	auto layer = new TitleLayer();
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
TitleLayer::TitleLayer() {
	
}

/**
 *  デストラクタ
 */
TitleLayer::~TitleLayer() {
	
}

/**
 *  レイヤー初期化
 */
void TitleLayer::initLayer() {
    
    auto screenSize = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
    // タイトル
    auto filePath = GameEtcManager::getImageFilePath(0);
    _titleSprite = Sprite::create(filePath);
    auto size = _titleSprite->getSpriteFrame()->getOriginalSize();
    _titleSprite->setPosition(screenSize.width / 2, screenSize.height / 2);
    addChild(_titleSprite, 20);
    
    // 気球
    filePath = GameCharaManager::getImageFilePath(54); // 気球
    _balloonSprite = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(filePath));
    _balloonSprite->setPosition(Point(rand() % (int)screenSize.width, rand() % (int)screenSize.height));
    addChild(_balloonSprite, 11);
    _balloonSpeed = Point((rand() % 2) == 0 ? 0.5 : -0.5, (rand() % 2) == 0 ? 0.5 : -0.5);
    
    // 気球の影
    _balloonShadow = DrawNode::create();
    _balloonShadow->drawDot(Point(0, 0), 10, Color4F(0, 0, 0, 0.5));
    _balloonShadow->setScaleY(0.5);
    _balloonShadow->setPosition(_balloonSprite->getPositionX(), _balloonSprite->getPositionY() - 40);
    addChild(_balloonShadow, 10);
}

/**
 *  レイヤーメイン処理
 */
void TitleLayer::layerMain() {
    
    // 気球移動
    auto screenSize = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();

    auto position = _balloonSprite->getPosition();
    position.x += _balloonSpeed.x;
    position.y += _balloonSpeed.y;

    if (position.x <= 0) {
        position.x = 0;
        _balloonSpeed.x = 0.5;
    } else if (position.x >= screenSize.width) {
        position.x = screenSize.width;
        _balloonSpeed.x = -0.5;
    }
    if (position.y <= 0) {
        position.y = 0;
        _balloonSpeed.y = 0.5;
    } else if (position.y >= screenSize.height) {
        position.y = screenSize.height;
        _balloonSpeed.y = -0.5;
    }   

    _balloonSprite->setPosition(position);
    _balloonShadow->setPosition(position.x, position.y - 40);
}
