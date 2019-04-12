//
//  GameEventVariableService.h
//  hateru
//
//  Created by HaraKazunari on 2017/01/26.
//
//

#ifndef GameEventVariableService_h
#define GameEventVariableService_h

#include "Const/GameConst.h"

class GameEventService;
class PlayerEntity;
class GameMapEntity;
class GameEventBaseEntity;

/// ゲームイベント ステータス関連サービス
class GameEventVariableService final {
public:
	
#pragma mark - 初期化
	
	/**
	 *  コンストラクタ
	 *
	 *  @param eventService イベントサービス
	 */
	GameEventVariableService(GameEventService *eventService);
	
	/**
	 *  デストラクタ
	 */
	~GameEventVariableService();
	
	/**
	 *  変数操作 SubSetNum
	 *
	 *  @param entity イベント詳細Entity
	 */
	void operateVariable(GameEventBaseEntity *entity);
	
	/**
	 *  変数の内容を比較 SubIf
	 *
	 *  @param valueSource      元値
	 *  @param valueDestination 比較値
	 *  @param formulaType      比較式
	 *
	 *  @return 比較可否
	 */
	bool compareVariable(int valueSource, int valueDestination, IfFormulaType formulaType);

private:
	
	/// イベントサービス
	GameEventService *eventService;
	
};

#endif /* GameEventVariableService_h */
