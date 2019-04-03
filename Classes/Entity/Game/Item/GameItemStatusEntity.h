//
//  GameItemStatusEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameItemStatusEntity_h
#define GameItemStatusEntity_h

#include "BaseGameEntity.h"

/// アイテムステータスEntity
class GameItemStatusEntity final: public BaseGameEntity {
public:
	
	/// ステータス種別
	ItemStatusType status;
	/// 変化値
	int value;
	
	/**
	 *  コンストラクタ
	 */
	GameItemStatusEntity();
	
	/**
	 *  デストラクタ
	 */
	~GameItemStatusEntity();
	
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
	static GameItemStatusEntity createEntity(const unsigned char *data);
	
private:
};

#endif /* GameItemStatusEntity_h */
