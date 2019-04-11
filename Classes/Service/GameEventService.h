//
//  GameEventService.h
//  hateru
//
//  Created by HaraKazunari on 2017/01/17.
//
//

#ifndef GameEventService_h
#define GameEventService_h

#include <map>
#include "../Const/GameConst.h"

class GameEventStatusService;
class GameEventVariableService;
class PlayerEntity;
class GameMapEntity;
class GameEventEntity;
class GameEventBaseEntity;

using namespace std;

/// ゲームイベントサービス
class GameEventService final {
public:
	
	/// プレイヤー情報
	PlayerEntity *playerEntity;
	/// マップ情報
	GameMapEntity *mapEntity;
	
	/// イベント情報
	map<int, GameEventEntity> events;
	
	/// 現在実行中のイベントインデックス
	int executeEventIndex;
	/// 詳細実行中インデックス
	int executeEventDetailIndex;
	/// 作業用カウント1
	int executeEventCount1;
	/// 作業用カウント2
	int executeEventCount2;
	
	/// 順番待ちのイベント
	vector<int> waitingEventIndexs;

#pragma mark - 初期化
	
	/**
	 *  コンストラクタ
	 *
	 *  @param playerEntity プレイヤーデータ
	 *  @param mapEntity    マップ
	 *  @param events       イベント群
	 */
	GameEventService(PlayerEntity *playerEntity, GameMapEntity *mapEntity, map<int, GameEventEntity> &events);

	/**
	 *  デストラクタ
	 */
	~GameEventService();

	/**
	 *  イベント初期化
	 */
	void initEvents();
	
#pragma mark - 実行

	/**
	 *  イベント実行
	 */
	void executeEvents();

	/**
	 *  イベント指定実行
	 *
	 *  @param eventIndex イベントインデックス
	 */
	void executeEvent(int eventIndex);

#pragma mark - メッセージ
	
	/**
	 *  メッセージ表示
	 *
	 *  @param message メッセージ
	 */
	void showMessage(string message);

private:
	
	/// ステータスイベント
	GameEventStatusService *statusService;
	/// 変数イベント
	GameEventVariableService *variableService;
	
	/**
	 *  イベント指定開始
	 *
	 *  @param eventIndex イベントインデックス
	 */
	void runEvent(int eventIndex);
	
#pragma mark -  乱数

	/**
	 *  乱数と内容を比較 SubSubIfRand
	 *
	 *  @param value 値
	 *
	 *  @return 比較可否
	 */
	bool compareRandom(int value);

};


#endif /* GameEventService_h */
