//
//  DBBlacklistEntity.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/08.
//

#ifndef DBBlacklistEntity_h
#define DBBlacklistEntity_h

#include "firebase/database.h"

using namespace std;
using namespace firebase;

/// ブラックリストデータベースエンティティ
class DBBlacklistEntity final {
public:
    
    /**
     * コンストラクタ
     */
    DBBlacklistEntity();
    
    /**
     * コンストラクタ
     *
     *  @param snapshot スナップショット
     */
    DBBlacklistEntity(const database::DataSnapshot *snapshot);
    
    /**
     * コンストラクタ
     *
     *  @param userId    ユーザーID
     *  @param username  ユーザー名
     *  @param createdAt 作成日時
     */
    DBBlacklistEntity(const string &userId, const string &username, const time_t createdAt);
    
    /**
     * デストラクタ
     */
    ~DBBlacklistEntity() {};
    
    /**
     * map<string, Variant>に変換
     *
     *  @return map<string, Variant>
     */
    map<string, Variant> toVariants();
    
    /**
     *  ユーザーID setter/getter
     */
    void setUserId(const string &userId);
    string userId();
    
    /**
     *  ユーザー名 setter/getter
     */
    void setUsername(const string &username);
    string username();
    
    /**
     *  作成日時 setter/getter
     */
    void setCreatedAt(const time_t createdAt);
    time_t createdAt();

private:
    
    /// ユーザーID
    string _userId;
    /// ユーザー名
    string _username;
    /// 作成日時
    time_t _createdAt;
    
};

#endif /* DBBlacklistEntity_h */
