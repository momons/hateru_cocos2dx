//
//  SplashScene.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/10.
//
//

#include "SplashScene.h"
#include "SplashLayer.h"
#include <mutex>

#include "Const/GameConst.h"
#include "Const/FileConst.h"

#include "Scene/Title/TitleScene.h"

/// インスタンス
SplashScene *SplashScene::instance;

/**
 *  インストラクタ
 */
SplashScene::SplashScene() {
	
	// キャッシュ読込
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(FileConst::gameImagesFileName);
	
	// レイヤー貼り付け
	auto layer = SplashLayer::create();
	addChild(layer);
}

/**
 *  デストラクタ
 */
SplashScene::~SplashScene() {
	
}

/**
 *  インスタンスシェア
 *
 *  @return インスタンス
 */
SplashScene *SplashScene::sharedInstance() {
	static once_flag flag;
	call_once(flag, setupInstance);
	return instance;
}

/**
 *  インスタンス設定
 */
void SplashScene::setupInstance() {
	instance = (SplashScene *)create();
}
