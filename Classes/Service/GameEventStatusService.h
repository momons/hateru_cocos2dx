//
//  GameEventStatusService.h
//  hateru
//
//  Created by HaraKazunari on 2017/01/26.
//
//

#ifndef GameEventStatusService_h
#define GameEventStatusService_h

class GameEventService;
class PlayerEntity;
class GameMapEntity;
class GameEventBaseEntity;

/// ゲームイベント ステータス関連サービス
class GameEventStatusService final {
public:

#pragma mark - 初期化
	
	/**
	 *  コンストラクタ
	 *
	 *  @param eventService イベントサービス
	 */
	GameEventStatusService(GameEventService *eventService);
	
	/**
	 *  デストラクタ
	 */
	~GameEventStatusService();

	/**
	 *  ステータス増減
	 *
	 *  @param target           ターゲット
	 *  @param maxStatusType    最大ステータスタイプ
	 *  @param changeStatusType 変化ステータスタイプ
	 *  @param value            値
	 */
	void fluctuateStatus(int target, int maxStatusType, int changeStatusType, int value);
	
	/**
	 *  HP増減
	 *
	 *  @param entity イベント詳細Entity
	 */
	void fluctuateHP(GameEventBaseEntity *entity);
	
	/**
	 *  MP増減
	 *
	 *  @param entity イベント詳細Entity
	 */
	void fluctuateMP(GameEventBaseEntity *entity);
	
	/**
	 *  所持金増減
	 *
	 *  @param entity イベント詳細Entity
	 *
	 *  @return 終了フラグ
	 */
	bool fluctuateGold(GameEventBaseEntity *entity);
	
	/**
	 *  アイテム増減
	 *
	 *  @param entity イベント詳細Entity
	 *
	 *  @return 終了フラグ
	 */
	bool fluctuateItem(GameEventBaseEntity *entity);
	
private:
	
	/// イベントサービス
	GameEventService *eventService;

};

#endif /* GameEventStatusService_h */
