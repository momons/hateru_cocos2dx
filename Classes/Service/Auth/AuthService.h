//
//  AuthService.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/03.
//

#ifndef AuthService_h
#define AuthService_h

#include "firebase/app.h"
#include "firebase/auth.h"

using namespace std;

/// 認証サービスクラス
class AuthService final {
public:
    
    /**
     *  インスタンスシェア
     *
     *  @return インスタンス
     */
    static AuthService *sharedInstance();
    
    /**
     *  デストラクタ
     */
    ~AuthService() {}
    
    /**
     *  ログイン可否
     *
     *  @return true:ログイン中、false:非ログイン
     */
    bool isLoggedIn();
    
    /**
     *  ユーザーID取得
     *
     *  @return ユーザーID
     */
    string userId();
    
    /**
     *  ログアウト
     */
    void Logout();

private:
    
    /// インスタンス
    static AuthService *instance;
    
    // Firebaseインスタンス
    firebase::App *app;
    // 認証インスタンス
    firebase::auth::Auth *auth;
    
    /**
     *  インストラクタ
     */
    AuthService();
    
    /**
     *  インスタンス設定
     */
    static void setupInstance();
};

#endif /* AuthService_h */
