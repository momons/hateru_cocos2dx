//
//  BattleLayer.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/10.
//
//

#include "BattleLayer.h"

/**
 *  クラス作成
 *
 *  @return クラス
 */
BattleLayer *BattleLayer::create() {
	auto layer = new BattleLayer();
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
BattleLayer::BattleLayer() {
	
}

/**
 *  デストラクタ
 */
BattleLayer::~BattleLayer() {
	
}

/**
 *  レイヤー初期化
 */
void BattleLayer::initLayer() {
	
}

/**
 *  レイヤーメイン処理
 */
void BattleLayer::layerMain() {
	
}