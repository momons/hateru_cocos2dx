//
//  GameCharaManager.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameCharaManager_h
#define GameCharaManager_h

#include <map>

#include "Entity/Game/Chara/GameCharaEntity.h"

using namespace std;

/// ゲームキャラマネージャ
class GameCharaManager final {
public:
	
	/**
	 *  読み込み
	 *
	 *  @return 取得データ
	 */
	static map<int, GameCharaEntity> load();
	
	/**
	 *  ファイルパス取得
	 *
	 *  @param imageId 画像Id
	 *
	 *  @return ファイルパス
	 */
	static string getImageFilePath(const int imageId);
	
private:
	
	/**
	 *  コンストラクタ
	 */
	GameCharaManager() {}
	
	/**
	 *  デストラクタ
	 */
	~GameCharaManager() {}
};

#endif /* GameCharaManager_h */
