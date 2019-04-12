//
//  DBLocationsManager.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/05.
//

#ifndef DBLocationsManager_h
#define DBLocationsManager_h

#include "DBBaseManager.h"
#include "Entity/Database/DBLocationEntity.h"
#include "Entity/Player/PlayerMapEntity.h"

using namespace std;

/// プロフィールデータベースマネージャ
class DBLocationsManager final: DBBaseManager {
public:
    
    /**
     *  コンストラクタ
     */
    DBLocationsManager() {}
    
    /**
     *  デストラクタ
     */
    ~DBLocationsManager() {}
    
    /**
     *  位置情報読み込み
     *
     *  @param userId  ユーザーID
     *  @param handler 完了ハンドラ (データ有無、プロフィール)
     */
    void read(const string &userId, const function<void(const bool, const DBLocationEntity)> handler);
    
    /**
     *  自分の位置情報保存
     *
     *  @param username ユーザー名
     *  @param map      マップEntity
     *  @param message  メッセージ
     */
    void writeMy(const string &username, PlayerMapEntity *map, const string &message);
    
    /**
     *  自分の位置情報削除
     */
    void deleteMy();
    
private:
    
    /**
     *  位置情報のリファレンス取得
     *
     *  @return 位置情報のリファレンス
     */
    database::DatabaseReference ref();
    
    /**
     *  自分の位置情報のリファレンス取得
     *
     *  @return 自分の位置情報のリファレンス
     */
    database::DatabaseReference myRef();
    
};

#endif /* DBLocationsManager_h */
