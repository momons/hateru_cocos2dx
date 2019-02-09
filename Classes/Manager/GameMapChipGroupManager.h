//
//  GameMapChipGroupManager.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/07.
//
//

#ifndef GameMapChipGroupManager_h
#define GameMapChipGroupManager_h

#include "BaseManager.h"
#include "GameMapChipGroupEntity.h"

/// ゲームマップチップグループマネージャ
class GameMapChipGroupManager final: BaseManager {
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
