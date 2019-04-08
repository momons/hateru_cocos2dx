//
//  DBLocationEntity.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/05.
//

#ifndef DBLocationEntity_h
#define DBLocationEntity_h

#include "firebase/database.h"

#include "PlayerMapEntity.h"

using namespace std;
using namespace firebase;

/// 位置情報データベースエンティティ
class DBLocationEntity final {
public:
    
    /**
     * コンストラクタ
     */
    DBLocationEntity();
    
    /**
     * コンストラクタ
     *
     *  @param snapshot スナップショット
     */
    DBLocationEntity(const database::DataSnapshot *snapshot);
    
    /**
     * コンストラクタ
     *
     *  @param username ユーザー名
     *  @param map      マップEntity
     *  @param message  メッセージ
     */
    DBLocationEntity(const string &username, PlayerMapEntity *map, const string &message);
    
    /**
     * デストラクタ
     */
    ~DBLocationEntity() {};
    
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
     *  マップID setter/getter
     */
    void setMapId(const int mapId);
    int mapId();
    
    /**
     *  X座標 setter/getter
     */
    void setX(const int x);
    int x();
    
    /**
     *  Y座標 setter/getter
     */
    void setY(const int y);
    int y();
    
    /**
     *  メッセージ setter/getter
     */
    void setMessage(const string &message);
    string message();
    
private:
    
    // ユーザー名
    string _username;
    /// マップID
    int _mapId;
    /// X座標
    int _x;
    /// Y座標
    int _y;
    /// メッセージ
    string _message;
    
};

#endif /* DBLocationEntity_h */
