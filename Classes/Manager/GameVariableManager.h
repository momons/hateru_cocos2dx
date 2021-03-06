//
//  GameVariableManager.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameVariableManager_h
#define GameVariableManager_h

#include <map>

#include "Entity/Game/Variable/GameVariableEntity.h"

using namespace std;

/// ゲーム変数マネージャ
class GameVariableManager final {
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
