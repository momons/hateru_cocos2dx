//
//  GameVariableManager.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameVariableManager_h
#define GameVariableManager_h

#include "BaseManager.h"
#include "GameVariableEntity.h"

/// ゲーム変数マネージャ
class GameVariableManager final: BaseManager {
public:

	/**
	 *  読み込み
	 *
	 *  @return 取得データ
	 */
	static map<int, GameVariableEntity> load();
	
private:
	
	/**
	 *  コンストラクタ
	 */
	GameVariableManager() {}
	
	/**
	 *  デストラクタ
	 */
	~GameVariableManager() {}
};

#endif /* GameVariableManager_h */
