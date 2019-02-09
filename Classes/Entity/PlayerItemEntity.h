//
//  PlayerItemEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/16.
//
//

#ifndef PlayerItemEntity_h
#define PlayerItemEntity_h

#include "cocos2d.h"

#include "picojson.h"

class PlayerUnitEntity;

USING_NS_CC;
using namespace std;

/// プレイヤーアイテムEntity
class PlayerItemEntity final: public Ref {
public:
	
	/// アイテムID
	int id;
	/// 使用回数
	int useCount;
	/// アイテムID
	string itemId;
	
	/**
	 *  アイテムEntity作成
	 *
	 *  @param id       ID
	 *  @param useCount 使用回数
	 *  @param itemId   アイテムID
	 *
	 *  @return PlayerItemEntity
	 */
	static PlayerItemEntity createEntity(const int id, const int useCount, const string itemId);
	
	/**
	 *  装備可能か
	 *
	 *  @param unitEntity ユニットEntity
	 *
	 *  @return true: 装備可能、false: 装備不可
	 */
	bool isCanEquipped(const PlayerUnitEntity &unitEntity);
	
	/**
	 *  コンストラクタ
	 */
	PlayerItemEntity();
	
	/**
	 *  デストラクタ
	 */
	~PlayerItemEntity();

	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
	
	/**
	 *  マッピング
	 *
	 *  @param object JSONオブジェクト
	 *
	 *  @return マッピング可否
	 */
	bool mapping(picojson::object &object);
	
private:
	
};

#endif /* PlayerItemEntity_h */
