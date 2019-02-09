//
//  GameMapChipEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameMapChipEntity_h
#define GameMapChipEntity_h

#include "BaseGameEntity.h"

/// マップチップEntity
class GameMapChipEntity final: public BaseGameEntity {
public:
	
	/// 下チップID
	int downChipId;
	/// 上チップID
	int upChipId;
	/// イベントId
	int eventId;
	/// 通行禁止
	bool isNotPassWalk;
	/// 船通行禁止
	bool isNotPassShip;
	/// 飛行通行禁止
	bool isNotPassFlyShip;
	/// 透過
	bool isUpChipClear;
	
	/**
	 *  コンストラクタ
	 */
	GameMapChipEntity();
	
	/**
	 *  デストラクタ
	 */
	~GameMapChipEntity();
	
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
	static GameMapChipEntity createEntity(const unsigned char *data);
	
private:
};

#endif /* GameMapChipEntity_h */
