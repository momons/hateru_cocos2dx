//
//  GameJobManager.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameJobManager_h
#define GameJobManager_h

#include <map>

using namespace std;

class GameJobEntity;

/// ゲーム職業マネージャ
class GameJobManager final {
public:
	
	/**
	 *  読み込み
	 *
	 *  @return 取得データ
	 */
	static map<int, GameJobEntity> load();
	
private:
	
	/**
	 *  コンストラクタ
	 */
	GameJobManager() {}
	
	/**
	 *  デストラクタ
	 */
	~GameJobManager() {}
};

#endif /* GameJobManager_h */
