//
//  AuthService.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/03.
//

#ifndef AuthService_h
#define AuthService_h

#include "firebase/auth.h"

#include "AuthDelegate.h"

using namespace std;
using namespace firebase;

/// 認証サービスクラス
class AuthService final: AuthDelegate, auth::AuthStateListener {
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
    void signUpByEmail(const string email, const string password, const function<void(bool)> handler);

    /**
     *  メールでサインイン
     *
     *  @param email    メールアドレス
     *  @param password パスワード
     *  @param handler  完了ハンドラ true:成功、false:失敗
     */
    void signInByEmail(const string email, const string password, const function<void(bool)> handler);

    /**
     *  Googleでサインイン
     *
     *  @param handler     完了ハンドラ true:成功、false:失敗
     */
    void signInByGoogle(const function<void(bool)> handler);
    
    /**
     *  Facebookでサインイン
     *
     *  @param handler      完了ハンドラ true:成功、false:失敗
     */
    void signInByFacebook(const function<void(bool)> handler);
    
    /**
     *  Twitterでサインイン
     *
     *  @param handler 完了ハンドラ true:成功、false:失敗
     */
    void signInByTwitter(const function<void(bool)> handler);

    /**
     *  サインアウト
     */
    void signOut();

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
     *  Google認証完了通知
     *
     *  @param success true:認証OK、false:認証NG
     */
    void onCompletionGoogleAuth(const bool success) override;

    /**
     *  Facebook認証完了通知
     *
     *  @param success true:認証OK、false:認証NG
     */
     void onCompletionFacebookAuth(const bool success) override;

    /**
     *  Twitter認証完了通知
     *
     *  @param success true:認証OK、false:認証NG
     */
    void onCompletionTwitterAuth(const bool success) override;

    /**
     *  認証状態が変わったときのコールバック
     *
     *  @param auth 認証情報
     */
    void OnAuthStateChanged(auth::Auth *auth) override;

private:
    
    /// インスタンス
    static AuthService *instance;
    
    /// 認証インスタンス
    auth::Auth *_auth;

    /// 認証用コールバック
    function<void(bool)> _handler;
    
    /**
     *  インストラクタ
     */
    AuthService();
    
    /**
     *  インスタンス設定
     */
    static void setupInstance();

    /**
     *  トークン取得
     *
     *  @param handler トークン、""は失敗
     */
    void fetchToken(const function<void(string)> handler);
};

#endif /* AuthService_h */
