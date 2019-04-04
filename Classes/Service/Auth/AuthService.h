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
using namespace firebase;

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
     *  メールでサインアップ
     *
     *  @param email    メールアドレス
     *  @param password パスワード
     *  @param handler  完了ハンドラ true:成功、false:失敗
     */
    void SignUpByEmail(const string email, const string password, const function<void(bool)> handler);

    /**
     *  メールでサインイン
     *
     *  @param email    メールアドレス
     *  @param password パスワード
     *  @param handler  完了ハンドラ true:成功、false:失敗
     */
    void SignInByEmail(const string email, const string password, const function<void(bool)> handler);

    /**
     *  Googleでサインイン
     *
     *  @param idToken  IDトークン
     *  @param handler  完了ハンドラ true:成功、false:失敗
     */
    void SignInByGoogle(const string idToken, const function<void(bool)> handler);
    
    /**
     *  Facebookでサインイン
     *
     *  @param accessToken  アクセストークン
     *  @param handler      完了ハンドラ true:成功、false:失敗
     */
    void SignInByFacebook(const string accessToken, const function<void(bool)> handler);
    
    /**
     *  Twitterでサインイン
     *
     *  @param token   トークン
     *  @param secret  シークレット
     *  @param handler 完了ハンドラ true:成功、false:失敗
     */
    void SignInByTwitter(const string token, const string secret, const function<void(bool)> handler);

    /**
     *  サインアウト
     */
    void SignOut();

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

private:
    
    /// インスタンス
    static AuthService *instance;
    
    // Firebaseインスタンス
    App *app;
    // 認証インスタンス
    auth::Auth *auth;
    
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
