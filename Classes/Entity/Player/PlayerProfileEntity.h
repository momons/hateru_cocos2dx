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

#include "Util/picojson.h"

USING_NS_CC;
using namespace std;

/// プレイヤープロフィールEntity
class PlayerProfileEntity final: public Ref {
public:
	
	/**
	 *  コンストラクタ
	 */
	PlayerProfileEntity();
	
	/**
	 *  デストラクタ
	 */
    ~PlayerProfileEntity() {};
	
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

    /**
     *  性別 setter/getter
     */
    void setGender(const int gender);
    int gender();

    /**
     *  年齢 setter/getter
     */
    void setAge(const int age);
    int age();

    /**
     *  住所 setter/getter
     */
    void setAddress(const int adress);
    int address();

    /**
     *  血液型 setter/getter
     */
    void setBlood(const int blood);
    int blood();

    /**
     *  星座 setter/getter
     */
    void setConstellation(const int constellation);
    int constellation();

private:
	
    /// 性別
    int _gender;
    /// 年齢
    int _age;
    /// 住所
    int _address;
    /// 血液型
    int _blood;
    /// 星座
    int _constellation;

};

#endif /* PlayerProfileEntity_h */
