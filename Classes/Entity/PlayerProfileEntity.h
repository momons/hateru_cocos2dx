//
//  PlayerProfileEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/29.
//
//

#ifndef PlayerProfileEntity_h
#define PlayerProfileEntity_h

#include "cocos2d.h"

#include "picojson.h"

USING_NS_CC;
using namespace std;

/// プレイヤープロフィールEntity
class PlayerProfileEntity final: public Ref {
public:
	
	/// 性別
	int gender;
	/// 年齢
	int age;
	/// 住所
	int address;
	/// 血液型
	int blood;
	/// 星座
	int constellation;
	
	/**
	 *  コンストラクタ
	 */
	PlayerProfileEntity();
	
	/**
	 *  デストラクタ
	 */
	~PlayerProfileEntity();
	
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

#endif /* PlayerProfileEntity_h */
