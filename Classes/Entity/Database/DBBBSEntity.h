//
//  DBBBSEntity.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/08.
//

#ifndef DBBBSEntity_h
#define DBBBSEntity_h

#include "firebase/database.h"

using namespace std;
using namespace firebase;

/// 掲示板ベースエンティティ
class DBBBSEntity final {
public:
    
    /**
     * コンストラクタ
     */
    DBBBSEntity();
    
    /**
     * コンストラクタ
     *
     *  @param snapshot スナップショット
     */
    DBBBSEntity(const database::DataSnapshot *snapshot);
    
    /**
     * コンストラクタ
     *
     *  @param saveData   セーブデータ
     *  @param checkDigit チェックデジット
     */
    DBBBSEntity(const string &saveData, const string &checkDigit);
    
    /**
     * デストラクタ
     */
    ~DBBBSEntity() {};
    
    /**
     * map<string, Variant>に変換
     *
     *  @return map<string, Variant>
     */
    map<string, Variant> toVariants();
    
    /**
     *  メッセージID setter/getter
     */
    void setMessageId(const string &messageId);
    string messageId();
    
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
     *  メッセージ setter/getter
     */
    void setMessage(const string &message);
    string message();
    
    /**
     *  作成日時 setter/getter
     */
    void setCreatedAt(const int createdAt);
    int createdAt();

private:
    
    /// メッセージID
    string _messageId;
    /// ユーザーID
    string _userId;
    /// ユーザー名
    string _username;
    /// メッセージ
    string _message;
    /// 作成日時
    int _createdAt;

};


#endif /* DBBBSEntity_h */
