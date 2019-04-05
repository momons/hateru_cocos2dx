//
//  DBProfileEntity.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/05.
//

#ifndef DBProfileEntity_h
#define DBProfileEntity_h

#include "firebase/database.h"

#include "PlayerProfileEntity.h"

using namespace std;
using namespace firebase;

/// プロフィールデータベースエンティティ
class DBProfileEntity final {
public:
    
    /**
     * コンストラクタ
     */
    DBProfileEntity();
    
    /**
     * コンストラクタ
     *
     *  @param snapshot スナップショット
     */
    DBProfileEntity(const database::DataSnapshot *snapshot);
    
    /**
     * コンストラクタ
     *
     *  @param username ユーザー名
     *  @param profile  プロフィールEntity
     */
    DBProfileEntity(const string &username, PlayerProfileEntity *profile);
    
    /**
     * デストラクタ
     */
    ~DBProfileEntity() {};

    /**
     * map<string, Variant>に変換
     *
     *  @return map<string, Variant>
     */
    map<string, Variant> toVariants();
    
    /**
     *  ユーザー名 setter/getter
     */
    void setUsername(const string &username);
    string username();
    
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

    // ユーザー名
    string _username;
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

#endif /* DBProfileEntity_h */
