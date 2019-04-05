//
//  RealtimeDatabaseService.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/04.
//

#ifndef RealtimeDatabaseService_h
#define RealtimeDatabaseService_h

#include "firebase/app.h"
#include "firebase/auth.h"
#include "firebase/database.h"

#include "LocationGetResponseEntity.h"
#include "PlayerProfileEntity.h"

using namespace std;
using namespace firebase;

/// リアルタイムDBサービスクラス
class RealtimeDatabaseService final {
public:
    
    /**
     *  インスタンスシェア
     *
     *  @return インスタンス
     */
    static RealtimeDatabaseService *sharedInstance();
    
    /**
     *  デストラクタ
     */
    ~RealtimeDatabaseService() {}
    

    /**
     *  周辺情報取得
     *
     *  @param mapType     マップタイプ
     *  @param x           X座標
     *  @param y           Y座標
     */
    void readLocation(const int mapType, const int x, const int y);

    /**
     *  位置情報保存
     *
     *  @param username    ユーザー名
     *  @param mapType     マップタイプ
     *  @param x           X座標
     *  @param y           Y座標
     *  @param message     メッセージ
     *  @param other_infos 追加情報
     */
    void writeMyLocation(const string username, const int mapType, const int x, const int y, const string message, const string otherInfos);

    /**
     *  位置情報削除
     */
    void deleteMyLocation();

    /**
     *  プロフィール読み込み
     *
     *  @param userId  ユーザーID
     *  @param handler 完了ハンドラ (データ有無、プロフィール)
     */
    void readProfile(const string userId, const function<void(const bool, const PlayerProfileEntity)> handler);

    /**
     *  プロフィール保存
     *
     *  @param username ユーザー名
     *  @param profile  プロフィール
     */
    void writeMyPrpfole(const string username,  PlayerProfileEntity *profile);

    /**
     *  プロフィール削除
     */
    void deleteMyPrpfole();
    
private:
    
    /// インスタンス
    static RealtimeDatabaseService *instance;

    /// 最上位フィールド名
    static const string topFieldName;
    
    /// Firebaseインスタンス
    App *app;
    /// DBインスタンス
    database::Database *database;
    
    /**
     *  インストラクタ
     */
    RealtimeDatabaseService();
    
    /**
     *  インスタンス設定
     */
    static void setupInstance();
    
    /**
     *  位置情報のリファレンス取得
     *
     *  @return 位置情報のリファレンス
     */
    database::DatabaseReference locationsRef();
    
    /**
     *  自分の位置情報のリファレンス取得
     *
     *  @return 自分の位置情報のリファレンス
     */
    database::DatabaseReference myLocationsRef();

    /**
     *  プロフィール情報のリファレンス取得
     *
     *  @return プロフィール情報のリファレンス
     */
    database::DatabaseReference profilesRef();
    
    /**
     *  自分のプロフィール情報のリファレンス取得
     *
     *  @return 自分のプロフィール情報のリファレンス
     */
    database::DatabaseReference myProfilesRef();

};


#endif /* RealtimeDatabaseService_h */
