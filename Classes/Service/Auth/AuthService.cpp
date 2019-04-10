//
//  AuthService.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/03.
//

#include "AuthService.h"

#include "GoogleSignInServiceWrap.h"
#include "FacebookSignInServiceWrap.h"
#include "TwitterSignInServiceWrap.h"

AuthService *AuthService::instance;

AuthService::AuthService() {
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    app = App::Create(firebase::AppOptions());
#else
    app = App::Create(firebase::AppOptions(), my_jni_env, my_activity);
#endif
    
    auth = auth::Auth::GetAuth(app);
}

AuthService *AuthService::sharedInstance() {
    static once_flag flag;
    call_once(flag, setupInstance);
    return instance;
}

void AuthService::setupInstance() {
    instance = new AuthService();
}

// MARK:- サインアップ

void AuthService::signUpByEmail(const string email, const string password, const function<void(bool)> handler) {
    auto result = auth->CreateUserWithEmailAndPassword(email.c_str(), password.c_str());
    result.OnCompletion([handler](const Future<auth::User *> &result) {
        if (result.error() != auth::kAuthErrorNone) {
            printf("failed Sign in '%s'\n", result.error_message());
            handler(false);
            return;
        }
        handler(true);
    });
}

// MARK:- サインイン

void AuthService::signInByEmail(const string email, const string password, const function<void(bool)> handler) {
    auto result = auth->SignInWithEmailAndPassword(email.c_str(), password.c_str());
    result.OnCompletion([handler](const Future<auth::User *> &result) {
        if (result.error() != auth::kAuthErrorNone) {
            printf("failed Sign in '%s'\n", result.error_message());
            handler(false);
            return;
        }
        handler(true);
    });
}

void AuthService::signInByGoogle(const function<void(bool)> handler) {
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    auto service = GoogleSignInServiceWrap();
    service.signIn(handler);
#else
    handler(false);
#endif
}

void AuthService::signInByFacebook(const function<void(bool)> handler) {
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    auto service = FacebookSignInServiceWrap();
    service.signIn(handler);
#else
    handler(false);
#endif
}

void AuthService::signInByTwitter(const function<void(bool)> handler) {
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    auto service = TwitterSignInServiceWrap();
    service.signIn(handler);
#else
    handler(false);
#endif
}

// MARK:- サインアウト

void AuthService::signOut() {
    auth->SignOut();
}

// MARK:- その他

bool AuthService::isLoggedIn() {
    return auth->current_user() != nullptr;
}

string AuthService::userId() {
    auto user = auth->current_user();
    if (user == nullptr) {
        return "";
    }
    return user->uid();
}
