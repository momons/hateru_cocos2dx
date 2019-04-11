//
//  DBProfilesManager.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/05.
//

#ifndef DBProfilesManager_h
#define DBProfilesManager_h

#include "DBBaseManager.h"
#include "../../Entity/Database/DBProfileEntity.h"
#include "../../Entity/Player/PlayerProfileEntity.h"

using namespace std;

/// プロフィールデータベースマネージャ
class DBProfilesManager final: DBBaseManager {
public:
    
    /**
     *  コンストラクタ
     */
    DBProfilesManager() {}
    
    /**
     *  デストラクタ
     */
    ~DBProfilesManager() {}
    
    /**
     *  プロフィール読み込み
     *
     *  @param userId  ユーザーID
     *  @param handler 完了ハンドラ (データ有無、プロフィール)
     */
    void read(const string &userId, const function<void(const bool, const DBProfileEntity)> handler);
    
    /**
     *  自分のプロフィール保存
     *
     *  @param username ユーザー名
     *  @param profile  プロフィール
     */
    void writeMy(const string &username, PlayerProfileEntity *profile);
    
    /**
     *  自分のプロフィール削除
     */
    void deleteMy();
    
private:
    
    /**
     *  プロフィール情報のリファレンス取得
     *
     *  @return プロフィール情報のリファレンス
     */
    database::DatabaseReference ref();
    
    /**
     *  自分のプロフィール情報のリファレンス取得
     *
     *  @return 自分のプロフィール情報のリファレンス
     */
    database::DatabaseReference myRef();

};

#endif /* DBProfilesManager_h */
