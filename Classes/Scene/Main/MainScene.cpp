//
//  MainScene.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/16.
//
//

#include "MainScene.h"

#include "Scene/Map/MapLayer.h"
#include "Scene/Map/UnitLayer.h"

#include "Service/GameMapService.h"

#include <mutex>

/// メインシーンインスタンス
MainScene *MainScene::mainSceneInstance = nullptr;

/**
 *  コンストラクタ
 */
MainScene::MainScene() {

	auto service = GameMapService::sharedInstance();
	service->newGame();

	auto mapLayer = MapLayer::create();
	mapLayer->setupMapLayer(service->mapEntity);
	mapLayer->setUnitPosition(service->screenLocation);
	this->addChild(mapLayer, 0);
	
	auto unitLayer = UnitLayer::create();
	unitLayer->setupUnitLayer(&service->playerEntity, service->mapEntity);
	unitLayer->setUnitPosition(service->screenLocation);
	this->addChild(unitLayer, 1);
}

/**
 *  デストラクタ
 */
MainScene::~MainScene() {
}

/**
 *  インスタンスシェア
 *
 *  @return インスタンス
 */
MainScene *MainScene::sharedInstance() {
	static once_flag flag;
	call_once(flag, setupInstance);
	return mainSceneInstance;
}

/**
 *  インスタンス設定
 */
void MainScene::setupInstance() {
	mainSceneInstance = (MainScene *)create();
}

/**
 *  ゲームスタート
 */
void MainScene::startGame() {
	this->scheduleUpdate();
}

/**
 初期化

 @param mode ゲームモード
 @param updateFlag 更新フラグ
 */
void MainScene::initMode(
						 MainSceneGameMode mode,
						 int updateFlag
						 )
{
	// モード退避
	gameModeBefore = gameMode;
	gameMode = mode;
	
	switch(mode){
		case MainSceneGameModeSplash:
			break;
		default:
			break;
	}
}

/**
 *  更新処理
 *
 *  @param delta デルタ
 */
void MainScene::update(float delta) {
	
}
