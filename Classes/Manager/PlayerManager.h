//
//  PlayerManager.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/18.
//
//

#ifndef PlayerManager_h
#define PlayerManager_h

#include "BaseManager.h"

#include "PlayerEntity.h"
#include "PlayerEncryptEntity.h"

/// プレイヤーマネージャ
class PlayerManager final: BaseManager {
public:
	
	/**
	 *  読み込み
	 *
	 *  @return 取得データ
	 */
	static PlayerEntity load();

	/**
	 *  暗号化データを読み込み
	 *
	 *  @return 取得データ
	 */
	static PlayerEncryptEntity loadEncrypt();

	/**
	 *  保存
	 *
	 *  @param entity プレイヤー情報
	 */
	static void save(PlayerEntity &entity);
	
private:
	
	/**
	 *  コンストラクタ
	 */
	PlayerManager() {}
	
	/**
	 *  デストラクタ
	 */
	~PlayerManager() {}
};


#endif /* PlayerManager_h */
