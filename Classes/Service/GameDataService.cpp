//
//  GameDataService.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameDataService.h"

#include <mutex>

#include "../Manager/GameInfoManager.h"
#include "../Manager/GameMapManager.h"
#include "../Manager/GameMapChipGroupManager.h"
#include "../Manager/GameEnemyManager.h"
#include "../Entity/Game/Enemy/GameEnemyEntity.h"
#include "../Manager/GameCharaManager.h"
#include "../Manager/GameItemManager.h"
#include "../Manager/GameJobManager.h"
#include "../Manager/GameSkillManager.h"
#include "../Manager/GameVariableManager.h"

/// インスタンス
GameDataService *GameDataService::instance;

#pragma mark - 初期化

/**
 *  コンストラクタ
 */
GameDataService::GameDataService() {
}

/**
 *  デストラクタ
 */
GameDataService::~GameDataService() {
	instance = nullptr;
}

/**
 *  インスタンス取得
 *
 *  @return インスタンス
 */
GameDataService *GameDataService::sharedInstance() {
	static once_flag flag;
	call_once(flag, GameDataService::setupInstance);
	return instance;
}

/**
 *  インスタンスセットアップ
 */
void GameDataService::setupInstance() {
	instance = new GameDataService();
	if (instance == nullptr) {
		return;
	}
 
	// 初期化
	instance->mapId = -1;
	
	// ゲーム情報取得
	instance->loadAll();
}

#pragma mark - 読み込み

/**
 *  全ての情報を取得する
 */
void GameDataService::loadAll() {
	// ゲーム情報
	gameInfo = GameInfoManager::load();
	// マップチップグループ情報
	mapChipGroups = GameMapChipGroupManager::load();
	/// 敵情報
	enemies = GameEnemyManager::load();
	/// キャラ情報
	charas = GameCharaManager::load();
	/// アイテム情報
	items = GameItemManager::load();
	/// 職業情報
	jobs = GameJobManager::load();
	/// 特技情報
	skills = GameSkillManager::load();
	/// 変数情報
	variables = GameVariableManager::load();
}

#pragma mark - Getter

/**
 *  マップ取得
 *
 *  @param id ID
 *
 *  @return マップ
 */
GameMapEntity *GameDataService::getMap(const int id) {
	if (mapId != id) {
		mapId = id;
		gameMap = GameMapManager::load(id);
	}
	return &gameMap;
}

/**
 *  遭遇敵情報取得
 *
 *  @param playerEntity プレイヤー情報
 *
 *  @return 遭遇敵情報
 */
vector<GameEnemyEntity> GameDataService::encoundEnemies(const PlayerEntity &playerEntity) {

	vector<GameEnemyEntity> encountEnemies;
	for (auto it = enemies.begin();it != enemies.end();it++) {
		if (it->second.isEncount(playerEntity)) {
			encountEnemies.push_back(it->second);
		}
	}
	return encountEnemies;
}

/**
 *  変数の初期取得
 *
 *  @return 変数の初期情報
 */
map<int, int> GameDataService::getVariableInitValues() {
	
	map<int, int> initValues;

	for (auto it = variables.begin(); it != variables.end(); it++) {
		initValues[it->first] = it->second.initValue;
	}
	
	return initValues;
}


