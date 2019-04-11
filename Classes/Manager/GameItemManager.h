//
//  GameItemManager.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameItemManager_h
#define GameItemManager_h

#include "../Entity/Game/Item/GameItemEntity.h"

/// ゲームアイテムマネージャ
class GameItemManager final {
public:
	
	/**
	 *  読み込み
	 *
	 *  @return 取得データ
	 */
	static map<int, GameItemEntity> load();
	
	/**
	 *  ファイルパス取得
	 *
	 *  @param imageId 画像Id
	 *
	 *  @return ファイルパス
	 */
	static string getImageFilePath(int imageId);
	
private:
	
	/**
	 *  コンストラクタ
	 */
	GameItemManager() {}
	
	/**
	 *  デストラクタ
	 */
	~GameItemManager() {}
};

#endif /* GameItemManager_h */
