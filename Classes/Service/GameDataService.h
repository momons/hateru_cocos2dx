//
//  GameDataService.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameDataService_h
#define GameDataService_h

#include "BaseService.h"
#include "GameInfoEntity.h"
#include "GameMapEntity.h"
#include "GameMapChipGroupEntity.h"
#include "GameEnemyEntity.h"
#include "GameCharaEntity.h"
#include "GameItemEntity.h"
#include "GameJobEntity.h"
#include "GameSkillEntity.h"
#include "GameVariableEntity.h"

/// ゲームデータサービス
class GameDataService final: BaseService {
public:
	
	/// ゲーム情報
	GameInfoEntity gameInfo;
	/// マップ情報
	int mapId;
	GameMapEntity gameMap;
	/// マップチップ情報
	map<int, GameMapChipGroupEntity> mapChipGroups;
	/// 敵情報
	map<int, GameEnemyEntity> enemies;
	/// キャラ情報
	map<int, GameCharaEntity> charas;
	/// アイテム情報
	map<int, GameItemEntity> items;
	/// 職業情報
	map<int, GameJobEntity> jobs;
	/// 特技情報
	map<int, GameSkillEntity> skills;
	/// 変数情報
	map<int, GameVariableEntity> variables;
	
	/**
	 *  デストラクタ
	 */
	~GameDataService();
	
	/**
	 *  インスタンスシェア
	 *
	 *  @return インスタンス
	 */
	static GameDataService *sharedInstance();
	
	/**
	 *  マップ取得
	 *
	 *  @param id ID
	 *
	 *  @return マップ
	 */
	GameMapEntity *getMap(const int id);
	
	/**
	 *  遭遇敵情報取得
	 *
	 *  @param playerEntity プレイヤー情報
	 *
	 *  @return 遭遇敵情報
	 */
	vector<GameEnemyEntity> encoundEnemies(const PlayerEntity &playerEntity);
	
	/**
	 *  変数の初期取得
	 *
	 *  @return 変数の初期情報
	 */
	map<int, int> getVariableInitValues();
	
private:
	
	/// インスタンス
	static GameDataService *instance;
	
	/**
	 *  コンストラクタ
	 */
	GameDataService();
	
	/**
	 *  インスタンスセットアップ
	 */
	static void setupInstance();
	
	/**
	 *  全ての情報を取得する
	 */
	void loadAll();
};

#endif /* GameDataService_h */
