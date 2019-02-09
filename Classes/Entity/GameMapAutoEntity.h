//
//  GameMapAutoEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/06.
//
//

#ifndef GameMapAutoEntity_h
#define GameMapAutoEntity_h

#include "BaseGameEntity.h"

/// 自動マップEntity
class GameMapAutoEntity final: public BaseGameEntity {
public:
	
	/// 階層
	int stratum;
	/// 下チップID
	vector<int> downChipIds;
	/// 上チップID
	vector<int> upChipIds;
	/// 敵情報
	vector<int> enemyIds;
	/// 宝情報
	vector<int> itemIds;
	
	/**
	 *  コンストラクタ
	 */
	GameMapAutoEntity();
	
	/**
	 *  デストラクタ
	 */
	~GameMapAutoEntity();
	
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
	static GameMapAutoEntity createEntity(const unsigned char *data);
	
private:
};


#endif /* GameMapAutoEntity_h */
