//
//  PlayerTeleportEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/16.
//
//

#ifndef PlayerTeleportEntity_h
#define PlayerTeleportEntity_h

#include "cocos2d.h"

#include "picojson.h"

#include "PlayerMapEntity.h"

USING_NS_CC;
using namespace std;

/// プレイヤーテレポートEntity
class PlayerTeleportEntity final: public Ref {
public:
	
	/// 名前
	string name;
	/// マップId
	int mapId;
	/// 設置マップ
	vector<PlayerMapEntity> maps;
	
	/**
	 *  コンストラクタ
	 */
	PlayerTeleportEntity();
	
	/**
	 *  デストラクタ
	 */
	~PlayerTeleportEntity();

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

#endif /* PlayerTeleportEntity_h */
