//
//  GameEnemyItemEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/27.
//
//

#ifndef GameEnemyItemEntity_h
#define GameEnemyItemEntity_h

#include "BaseGameEntity.h"

/// 敵 獲得アイテムEntity
class GameEnemyItemEntity final: public BaseGameEntity {
public:
	
	/// 獲得フラグ
	bool isWon;
	/// 獲得率
	int rate;
	/// 獲得アイテム
	int itemId;
	
	/**
	 *  コンストラクタ
	 */
	GameEnemyItemEntity();
	
	/**
	 *  デストラクタ
	 */
	~GameEnemyItemEntity();
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 */
	void convertData(const unsigned char *data);
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *
	 *  @return Entity
	 */
	static GameEnemyItemEntity createEntity(const unsigned char *data);
	
private:
};

#endif /* GameEnemyItemEntity_h */
