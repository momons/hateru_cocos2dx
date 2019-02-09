//
//  TitleLayer.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/16.
//
//

#include "TitleLayer.h"

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
	
}

/**
 *  レイヤーメイン処理
 */
void TitleLayer::layerMain() {
	
}
