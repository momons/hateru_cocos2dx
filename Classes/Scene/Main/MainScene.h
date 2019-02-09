//
//  MainScene.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/16.
//
//

#ifndef MainScene_h
#define MainScene_h

#include "BaseScene.h"

/** ゲームステータス */
typedef enum {
	MainSceneGameModeSplash		=	0,	/// スプラッシュ画面
	MainSceneGameModeTitle,				/// タイトル画面
	MainSceneGameModeSelectStage,		/// ステージ選択画面
	MainSceneGameModeGame,				/// ゲーム画面
	MainSceneGameModeMenu,				/// メニュー画面
	MainSceneGameModeRanking,			/// ランキング画面
	MainSceneGameModeConfig,			/// 設定画面
	MainSceneGameModeOperateConfig,		/// 操作設定画面
} MainSceneGameMode;

class MainScene: public BaseScene {
	
public:

	/**
	 *  デストラクタ
	 */
	~MainScene();
	
	/**
	 *  インスタンスシェア
	 *
	 *  @return インスタンス
	 */
	static MainScene *sharedInstance();
	
	/**
	 *  ゲームスタート
	 */
	void startGame();

	/**
	 *  クラス作成(autorelease)
	 */
	CREATE_FUNC(MainScene);

private:
	
	/// インスタンス
	static MainScene *mainSceneInstance;
	
	/// ゲームモード
	MainSceneGameMode gameMode;
	
	/// 前回のゲームモード
	MainSceneGameMode gameModeBefore;
	
	/**
	 *  コンストラクタ
	 */
	MainScene();
	
	/**
	 *  インスタンス設定
	 */
	static void setupInstance();

	/**
	 *  モード初期化
	 *
	 *  @param mode モード
	 */
	void initMode(MainSceneGameMode mode, int updateFlag);
	
	/**
	 *  更新処理
	 *
	 *  @param delta デルタ
	 */
	void update(float delta) override;

};


#endif /* MainScene_h */
