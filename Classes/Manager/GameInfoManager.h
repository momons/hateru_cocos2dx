//
//  GameInfoManager.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameInfoManager_h
#define GameInfoManager_h

#include "../Entity/Game/Info/GameInfoEntity.h"

/// ゲーム情報マネージャ
class GameInfoManager final {
public:
	
	/**
	 *  読み込み
	 *
	 *  @return 取得データ
	 */
	static GameInfoEntity load();
	
private:
	
	/**
	 *  コンストラクタ
	 */
	GameInfoManager() {}
	
	/**
	 *  デストラクタ
	 */
	~GameInfoManager() {}
};

#endif /* GameInfoManager_h */
