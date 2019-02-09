//
//  GameMapService.h
//  hateru
//
//  Created by HaraKazunari on 2016/09/04.
//
//

#ifndef GameMapService_h
#define GameMapService_h

#include "BaseService.h"

#include "PlayerEntity.h"
#include "GameMapEntity.h"
#include "GameEnemyEntity.h"

/// ゲームマップサービス
class GameMapService final: BaseService {
public:
	
	/// プレイヤーEntity
	PlayerEntity playerEntity;
	
	/// マップEntity
	GameMapEntity *mapEntity;
	
	/// スクリーン座標
	Point screenLocation;
	
	/**
	 *  デストラクタ
	 */
	~GameMapService();
	
	/**
	 *  インスタンスシェア
	 *
	 *  @return インスタンス
	 */
	static GameMapService *sharedInstance();
	
	/**
	 *  ニューゲーム
	 */
	void newGame();
	
	/**
	 *  コンティニューゲーム
	 */
	void continueGame();
	
	/**
	 *  位置情報取得
	 *
	 *  @param basePoint ベースドット座標
	 *  @param unitPoint ユニットマップ座標
	 *
	 *  @return スクリーン座標
	 */
	static Point buildPosition(const Point &basePoint, const Point &unitPoint);

	/**
	 *  位置情報取得(詳細)
	 *
	 *  @param basePoint ベースドット座標
	 *  @param unitPoint ユニットドット座標
	 *
	 *  @return スクリーン座標
	 */
	static Point buildPositionDetail(const Point &basePoint, const Point &unitPoint);

private:
	
	/// スクリーンの真ん中
	static Point screenCenter;
	
	/// インスタンス
	static GameMapService *instance;
	
	/**
	 *  コンストラクタ
	 */
	GameMapService();
	
	/**
	 *  インスタンスセットアップ
	 */
	static void setupInstance();
	
	/**
	 *  遭遇敵情報取得
	 *
	 *  @return 遭遇敵情報
	 */
	vector<GameEnemyEntity> encoundEnemies();
	
	/**
	 *  敵に遭遇か
	 *
	 *  @return true: 遭遇、false: いない
	 */
	bool isEncount();
	
};

#endif /* GameMapService_h */
