//
//  GameBattleService.h
//  hateru
//
//  Created by HaraKazunari on 2016/09/04.
//
//

#ifndef GameBattleService_h
#define GameBattleService_h

#include "BaseService.h"

#include "GameEnemyEntity.h"

/// ゲームバトルサービス
class GameBattleService final: BaseService {
public:
	
	/**
	 *  デストラクタ
	 */
	~GameBattleService();
	
	/**
	 *  インスタンスシェア
	 *
	 *  @return インスタンス
	 */
	static GameBattleService *sharedInstance();

	/**
	 *  セットアップ
	 *
	 *  @param isEvent イベントバトル
	 *  @param enemies 敵
	 */
	void setup(const bool isEvent, vector<GameEnemyEntity> &enemies);
	
private:
	
	/// インスタンス
	static GameBattleService *instance;

	/// 敵キャラ種別
	vector<int> enemyIds;
	
	/// 名前
	vector<string> unitNames;
	/// ステータス
	vector<vector<int>> unitStatuses;
	
	/// 獲得経験値
	int exp;
	/// 獲得お金
	int money;
	
	
	/**
	 *  コンストラクタ
	 */
	GameBattleService();
	
	/**
	 *  インスタンスセットアップ
	 */
	static void setupInstance();
	
	/**
	 *  プレイヤーのステータスを反映
	 */
	void setupPlayerStatus();
	
};

#endif /* GameBattleService_h */
