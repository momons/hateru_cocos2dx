//
//  GameItemMixEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameItemMixEntity_h
#define GameItemMixEntity_h

#include "BaseGameEntity.h"

/// アイテム合成Entity
class GameItemMixEntity final: public BaseGameEntity {
public:
	
	/// アイテムID
	int itemId;
	/// 個数
	int value;
	
	/**
	 *  コンストラクタ
	 */
	GameItemMixEntity();
	
	/**
	 *  デストラクタ
	 */
	~GameItemMixEntity();
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 */
	void convertData(const unsigned char *data);
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data      バイナリデータ
	 *
	 *  @return Entity
	 */
	static GameItemMixEntity createEntity(const unsigned char *data);
	
private:
};

#endif /* GameItemMixEntity_h */
