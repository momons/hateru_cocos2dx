//
//  PlayerMapEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/18.
//
//

#ifndef PlayerMapEntity_h
#define PlayerMapEntity_h

#include "cocos2d.h"

#include "picojson.h"

USING_NS_CC;
using namespace std;

/// プレイヤーマップEntity
class PlayerMapEntity final: public Ref {
public:
	
	/// マップID
	int id;
	/// X座標
	int x;
	/// Y座標
	int y;
	
	/**
	 *  コンストラクタ
	 */
	PlayerMapEntity();
	
	/**
	 *  デストラクタ
	 */
	~PlayerMapEntity();

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

#endif /* PlayerMapEntity_h */
