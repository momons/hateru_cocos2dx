//
//  GameMapChipGroupManager.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/07.
//
//

#ifndef GameMapChipGroupManager_h
#define GameMapChipGroupManager_h

#include <map>

#include "Entity/Game/Map/GameMapChipGroupEntity.h"

using namespace std;

/// ゲームマップチップグループマネージャ
class GameMapChipGroupManager final {
public:
	
	/**
	 *  読み込み
	 *
	 *  @return 取得データ
	 */
	static map<int, GameMapChipGroupEntity> load();
	
private:
	
	/**
	 *  コンストラクタ
	 */
	GameMapChipGroupManager() {}
	
	/**
	 *  デストラクタ
	 */
	~GameMapChipGroupManager() {}
};


#endif /* GameMapChipGroupManager_h */
