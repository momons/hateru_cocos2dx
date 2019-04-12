//
//  DBBlacklistsManager.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/08.
//

#ifndef DBBlacklistsManager_h
#define DBBlacklistsManager_h

#include "DBBaseManager.h"
#include "Entity/Database/DBBlacklistEntity.h"

using namespace std;

/// ブラックリストデータベースマネージャ
class DBBlacklistsManager final: DBBaseManager {
public:
    
    /**
     *  コンストラクタ
     */
    DBBlacklistsManager() {}
    
    /**
     *  デストラクタ
     */
    ~DBBlacklistsManager() {}
    
    /**
     *  自分のブラックリスト読み込み
     *
     *  @param handler 完了ハンドラ (ブラックリスト)
     */
    void readMy(const function<void(const vector<DBBlacklistEntity>)> handler);
    
    /**
     *  指定ユーザーIDをブラックリストに追加する
     *
     *  @param userId   ユーザーID
     *  @param username ユーザー名
     */
    void writeMy(const string &userId, const string &username);
    
    /**
     *  指定ユーザーIDをブラックリストから削除する
     *
     *  @param userId   ユーザーID
     */
    void deleteMy(const string &userId);
    
private:
    
    /**
     *  ブラックリストのリファレンス取得
     *
     *  @return ブラックリストのリファレンス
     */
    database::DatabaseReference ref();
    
    /**
     *  自分のブラックリストのリファレンス取得
     *
     *  @return 自分のブラックリストのリファレンス
     */
    database::DatabaseReference myRef();
    
};

#endif /* DBBlacklistsManager_h */
