//
//  GameEnemyEncountEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/27.
//
//

#ifndef GameEnemyEncountEntity_h
#define GameEnemyEncountEntity_h

#include "BaseGameEntity.h"

class PlayerMapEntity;

/// 敵 遭遇Entity
class GameEnemyEncountEntity final: public BaseGameEntity {
public:
	
	/// マップ
	int mapId;
	/// X
	int x;
	/// Y
	int y;
	/// 幅
	int width;
	/// 高さ
	int height;
	
	/**
	 *  範囲チェック
	 *
	 *  @param mapEntity プレイヤー位置Entity
	 *
	 *  @return true: 範囲内、false: 範囲外
	 */
	bool isInRange(const PlayerMapEntity &mapEntity);
	
	/**
	 *  コンストラクタ
	 */
	GameEnemyEncountEntity();
	
	/**
	 *  デストラクタ
	 */
	~GameEnemyEncountEntity();
	
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
	static GameEnemyEncountEntity createEntity(const unsigned char *data);
	
private:
};

#endif /* GameEnemyEncountEntity_h */
