//
//  SplashLayer.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/16.
//
//

#include "SplashLayer.h"

#include "../../Const/GameConst.h"
#include "../Title/TitleScene.h"

/**
 *  クラス作成
 *
 *  @return クラス
 */
SplashLayer *SplashLayer::create() {
	auto layer = new SplashLayer();
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
SplashLayer::SplashLayer() {
	
}

/**
 *  デストラクタ
 */
SplashLayer::~SplashLayer() {
	
}

/**
 *  レイヤー初期化
 */
void SplashLayer::initLayer() {
	
	setBackgroundColor(Color4B(255, 255, 255, 255));
	
	count = 0;
}

/**
 *  レイヤーメイン処理
 */
void SplashLayer::layerMain() {
	
	count += 1;
	if (count >= GameConst::frameRate) {
		Director::getInstance()->replaceScene(TransitionFadeTR::create(1.0f, TitleScene::sharedInstance()));
	}
}

