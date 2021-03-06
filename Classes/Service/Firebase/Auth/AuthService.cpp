//
//  AuthService.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/03.
//

#include "AuthService.h"

#include "cocos2d.h"
#include <mutex>
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#endif
#include "Service/Jni/JniCallback.h"

USING_NS_CC;

#include "Service/Firebase/FirebaseService.h"
#include "Manager/Database/DBDevicesManager.h"
#include "Manager/Config/ConfigManager.h"
#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)
#include "GoogleSignInServiceWrap.h"
#include "FacebookSignInServiceWrap.h"
#include "TwitterSignInServiceWrap.h"
#endif

AuthService *AuthService::instance;

AuthService::AuthService() {
    _auth = auth::Auth::GetAuth(FirebaseService::sharedInstance()->app());
    _auth->AddAuthStateListener(this);
    // デリゲート設定
    JniCallback::delegate = this;
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
    auto result = _auth->CreateUserWithEmailAndPassword(email.c_str(), password.c_str());
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
    auto result = _auth->SignInWithEmailAndPassword(email.c_str(), password.c_str());
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
#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)
    auto service = GoogleSignInServiceWrap();
    service.signIn(handler);
#else
    _handler = handler;

    auto env = JniHelper::getEnv();
    auto vm = JniHelper::getJavaVM();

    auto clazz = env->FindClass("org/cocos2dx/cpp/AppActivity");
    auto methodId = env->GetMethodID(clazz, "googleSignIn", "()V");
    env->CallVoidMethod(JniHelper::getActivity(), methodId);
#endif
}

void AuthService::onCompletionGoogleAuth(const bool success) {
    if (_handler != nullptr) {
        _handler(success);
    }
}

void AuthService::signInByFacebook(const function<void(bool)> handler) {
#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)
    auto service = FacebookSignInServiceWrap();
    service.signIn(handler);
#else
    _handler = handler;

    auto env = JniHelper::getEnv();
    auto vm = JniHelper::getJavaVM();

    auto clazz = env->FindClass("org/cocos2dx/cpp/AppActivity");
    auto methodId = env->GetMethodID(clazz, "facebookSignIn", "()V");
    env->CallVoidMethod(JniHelper::getActivity(), methodId);
#endif
}

void AuthService::onCompletionFacebookAuth(const bool success) {
    if (_handler != nullptr) {
        _handler(success);
    }
}

void AuthService::signInByTwitter(const function<void(bool)> handler) {
#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)
    auto service = TwitterSignInServiceWrap();
    service.signIn(handler);
#else
    _handler = handler;

    auto env = JniHelper::getEnv();
    auto vm = JniHelper::getJavaVM();

    auto clazz = env->FindClass("org/cocos2dx/cpp/AppActivity");
    auto methodId = env->GetMethodID(clazz, "twitterSignIn", "()V");
    env->CallVoidMethod(JniHelper::getActivity(), methodId);
#endif
}

void AuthService::onCompletionTwitterAuth(const bool success) {
    if (_handler != nullptr) {
        _handler(success);
    }
}

void AuthService::OnAuthStateChanged(auth::Auth *auth) {
    auto user = auth->current_user();
    if (user != nullptr) {
        log("OnAuthStateChanged: signed_in %s", user->uid().c_str());
        
        // FCMトークンが取れていれば登録する
        auto token = ConfigManager::sharedInstance()->firebaseRegisterToken();
        if (!token.empty()) {
            DBDevicesManager manager;
            manager.writeMy(token);
        }
        
    } else {
        log("OnAuthStateChanged: signed_out");
    }
}

// MARK:- サインアウト

void AuthService::signOut() {
    _auth->SignOut();
}

// MARK:- その他

bool AuthService::isLoggedIn() {
    return _auth->current_user() != nullptr;
}

string AuthService::userId() {
    auto user = _auth->current_user();
    if (user == nullptr) {
        return "";
    }
    return user->uid();
}
