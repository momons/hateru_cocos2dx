//
//  GameEnemyEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/27.
//
//

#ifndef GameEnemyEntity_h
#define GameEnemyEntity_h

#include "BaseGameEntity.h"
#include "GameEnemyItemEntity.h"
#include "GameEnemyEncountEntity.h"

class PlayerEntity;

/// 敵Entity
class GameEnemyEntity final: public BaseGameEntity {
public:
	
	/// 名前
	string name;
	/// 画像
	int imageId;
	/// ステータス
	vector<int> statuses;
	/// 獲得アイテム
	GameEnemyItemEntity item;
	/// 攻撃パターン
	vector<int> attackPattern;
	/// 出現座標
	vector<GameEnemyEncountEntity> encounts;
	/// 出現属性
	vector<bool> isEncountType;
	
	/**
	 *  遭遇チェック
	 *
	 *  @param playerEntity プレイヤーEntity
	 *
	 *  @return true: 遭遇、false: 遭遇なし
	 */
	bool isEncount(const PlayerEntity &playerEntity);
	
	/**
	 *  バトルステータス取得
	 *
	 *  @return バトルステータス
	 */
	vector<int> battleStatues();
	
	/**
	 *  コンストラクタ
	 */
	GameEnemyEntity();
	
	/**
	 *  デストラクタ
	 */
	~GameEnemyEntity();
	
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
	static GameEnemyEntity createEntity(const unsigned char *data);
	
private:
};

#endif /* GameEnemyEntity_h */
