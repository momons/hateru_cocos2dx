//
//  AuthService.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/03.
//

#include "AuthService.h"

AuthService *AuthService::instance;

AuthService::AuthService() {
    
#if defined(__ANDROID__)
    app = App::Create(firebase::AppOptions(), my_jni_env, my_activity);
#else
    app = App::Create(firebase::AppOptions());
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

void AuthService::signInByGoogle(const string idToken, const function<void(bool)> handler) {
    auto credential = auth::GoogleAuthProvider::GetCredential(idToken.c_str(), nullptr);
    auto result = auth->SignInWithCredential(credential);
    result.OnCompletion([handler](const Future<auth::User *> &result) {
        if (result.error() != auth::kAuthErrorNone) {
            printf("failed Sign in '%s'\n", result.error_message());
            handler(false);
            return;
        }
        handler(true);
    });
}

void AuthService::signInByFacebook(const string accessToken, const function<void(bool)> handler) {
    auto credential = auth::FacebookAuthProvider::GetCredential(accessToken.c_str());
    auto result = auth->SignInWithCredential(credential);
    result.OnCompletion([handler](const Future<auth::User *> &result) {
        if (result.error() != auth::kAuthErrorNone) {
            printf("failed Sign in '%s'\n", result.error_message());
            handler(false);
            return;
        }
        handler(true);
    });
}

void AuthService::signInByTwitter(const string token, const string secret, const function<void(bool)> handler) {
    auto credential = auth::TwitterAuthProvider::GetCredential(token.c_str(), secret.c_str());
    auto result = auth->SignInWithCredential(credential);
    result.OnCompletion([handler](const Future<auth::User *> &result) {
        if (result.error() != auth::kAuthErrorNone) {
            printf("failed Sign in '%s'\n", result.error_message());
            handler(false);
            return;
        }
        handler(true);
    });
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
