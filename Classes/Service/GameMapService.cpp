//
//  GameMapService.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/09/04.
//
//

#include "GameMapService.h"

#include "GameDataService.h"
#include "../Manager/PlayerManager.h"

/// インスタンス
GameMapService *GameMapService::instance;

/// 画面のセンター
Point GameMapService::screenCenter;

#pragma mark - 初期化

/**
 *  コンストラクタ
 */
GameMapService::GameMapService() {
	
	/// スクリーンの真ん中を計算
	auto glview = Director::getInstance()->getOpenGLView();
	auto size = glview->getDesignResolutionSize();
	this->screenCenter.x = size.width / 2;
	this->screenCenter.y = size.height / 2;
}

/**
 *  デストラクタ
 */
GameMapService::~GameMapService() {
	instance = nullptr;
}

/**
 *  インスタンス取得
 *
 *  @return インスタンス
 */
GameMapService *GameMapService::sharedInstance() {
	static once_flag flag;
	call_once(flag, GameMapService::setupInstance);
	return instance;
}

/**
 *  インスタンスセットアップ
 */
void GameMapService::setupInstance() {
	instance = new GameMapService();
	if (instance == nullptr) {
		return;
	}
}

#pragma mark - 初期化

/**
 *  ニューゲーム
 */
void GameMapService::newGame() {

	auto service = GameDataService::sharedInstance();
	
	// プレイヤーEntity初期化
	playerEntity.initialize();
	// お金
	playerEntity.money = service->gameInfo.initMoney;
	// メンバー
	for (auto it = service->gameInfo.initMemberIds.begin(); it != service->gameInfo.initMemberIds.end(); it++) {
		if (*it != 0) {
			playerEntity.addUnit(*it);
		}
	}
	// 初期位置
	playerEntity.location.id = service->gameInfo.initMapId;
	playerEntity.location.x = service->gameInfo.initX;
	playerEntity.location.y = service->gameInfo.initY;
	screenLocation = GameMapService::buildPosition(Point(playerEntity.location.x * GameConst::mapOnePanelDot,
														 playerEntity.location.y * GameConst::mapOnePanelDot),
												   Point(playerEntity.location.x, playerEntity.location.y));
	// 移動タイプ
	playerEntity.moveType = MoveType::Walk;
	// 変数
	playerEntity.variables = service->getVariableInitValues();
	
	// マップ取得
	mapEntity = service->getMap(playerEntity.location.id);
}

/**
 *  コンティニューゲーム
 */
void GameMapService::continueGame() {
	
	// プレイヤーEntity初期化
	playerEntity.initialize();
	
	// 読み込み
	playerEntity = PlayerManager::load();

	// マップ取得
	mapEntity = GameDataService::sharedInstance()->getMap(playerEntity.location.id);
}

#pragma mark - マップ

/**
 *  位置情報取得
 *
 *  @param basePoint ベースドット座標
 *  @param unitPoint ユニットマップ座標
 *
 *  @return スクリーン座標
 */
Point GameMapService::buildPosition(const Point &basePoint, const Point &unitPoint) {
	return Point(screenCenter.x + ((int)unitPoint.x * GameConst::mapOnePanelDot) - basePoint.x + (GameConst::mapOnePanelDot / 2),
				 screenCenter.y + basePoint.y - ((int)unitPoint.y * GameConst::mapOnePanelDot) - (GameConst::mapOnePanelDot / 2));
}

/**
 *  位置情報取得(詳細)
 *
 *  @param basePoint ベースドット座標
 *  @param unitPoint ユニットドット座標
 *
 *  @return スクリーン座標
 */
Point GameMapService::buildPositionDetail(const Point &basePoint, const Point &unitPoint) {
	return Point(screenCenter.x + unitPoint.x - basePoint.x + (GameConst::mapOnePanelDot / 2),
				 screenCenter.y + basePoint.y - unitPoint.y - (GameConst::mapOnePanelDot / 2));
}

#pragma mark - 敵

/**
 *  遭遇敵情報取得
 *
 *  @param playerEntity プレイヤー情報
 *
 *  @return 遭遇敵情報
 */
vector<GameEnemyEntity> GameMapService::encoundEnemies() {
	return GameDataService::sharedInstance()->encoundEnemies(playerEntity);
}

/**
 *  敵に遭遇か
 *
 *  @return true: 遭遇、false: いない
 */
bool GameMapService::isEncount() {
	// レート
	if (mapEntity->enemyEncountRate <= (rand() % 100)) {
		return false;
	}
	// 敵
	return encoundEnemies().size() > 0;
}
