//
//  AuthService.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/03.
//

#include "AuthService.h"

/// インスタンス
AuthService *AuthService::instance;

/**
 *  インストラクタ
 */
AuthService::AuthService() {
    
#if defined(__ANDROID__)
    app = firebase::App::Create(firebase::AppOptions(), my_jni_env, my_activity);
#else
    app = firebase::App::Create(firebase::AppOptions());
#endif  // defined(__ANDROID__)
    
    auth = firebase::auth::Auth::GetAuth(app);
    //    auto auth = new firebase::auth::Auth;
    //    firebase::Future<firebase::auth::User*> result = auth->CreateUserWithEmailAndPassword("a", "b");
}

/**
 *  インスタンスシェア
 *
 *  @return インスタンス
 */
AuthService *AuthService::sharedInstance() {
    static once_flag flag;
    call_once(flag, setupInstance);
    return instance;
}

/**
 *  インスタンス設定
 */
void AuthService::setupInstance() {
    instance = new AuthService();
}

/**
 *  ログイン可否
 *
 *  @return true:ログイン中、false:非ログイン
 */
bool AuthService::isLoggedIn() {
    return auth->current_user() != nullptr;
}

/**
 *  ユーザーID取得
 *
 *  @return ユーザーID
 */
string AuthService::userId() {
    auto user = auth->current_user();
    if (user == nullptr) {
        return "";
    }
    return user->uid();
}

/**
 *  ログアウト
 */
void AuthService::Logout() {
    auth->SignOut();
}
