//
//  GameEnemyManager.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/27.
//
//

#ifndef GameEnemyManager_h
#define GameEnemyManager_h

#include <map>

using namespace std;

class GameEnemyEntity;

/// 敵キャラマネージャ
class GameEnemyManager final {
public:
	
	/**
	 *  読み込み
	 *
	 *  @return 取得データ
	 */
	static map<int, GameEnemyEntity> load();
	
private:
	
	/**
	 *  コンストラクタ
	 */
	GameEnemyManager() {}
	
	/**
	 *  デストラクタ
	 */
	~GameEnemyManager() {}
};

#endif /* GameEnemyManager_h */
