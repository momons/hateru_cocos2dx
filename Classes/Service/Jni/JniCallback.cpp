//
// Created by Kazunari Hara on 2019/04/15.
//

#include "JniCallback.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "Service/Firebase/Auth/AuthService.h"
#include "Manager/Database/DBDevicesManager.h"
#include "Manager/Config/ConfigManager.h"
#endif

AuthDelegate *JniCallback::delegate = nullptr;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
extern "C" {

JNIEXPORT void JNICALL
Java_com_nikuq_hateru_firebase_auth_GoogleAuth_onCompletion(JNIEnv *env, jobject thiz, jboolean success) {
    if (JniCallback::delegate != nullptr) {
        JniCallback::delegate->onCompletionGoogleAuth(success == JNI_TRUE);
    }
}

JNIEXPORT void JNICALL
Java_com_nikuq_hateru_firebase_auth_FacebookAuth_onCompletion(JNIEnv *env, jobject thiz, jboolean success) {
    if (JniCallback::delegate != nullptr) {
        JniCallback::delegate->onCompletionFacebookAuth(success == JNI_TRUE);
    }
}

JNIEXPORT void JNICALL
Java_com_nikuq_hateru_firebase_auth_TwitterAuth_onCompletion(JNIEnv *env, jobject thiz, jboolean success) {
    if (JniCallback::delegate != nullptr) {
        JniCallback::delegate->onCompletionTwitterAuth(success == JNI_TRUE);
    }
}

JNIEXPORT void JNICALL
Java_com_nikuq_hateru_firebase_service_FCMService_writeToken(JNIEnv *env, jobject thiz, jstring token) {
    const char *charToken = env->GetStringUTFChars(token, 0);
    ConfigManager::sharedInstance()->setFirebaseRegisterToken(charToken);
}
}
#endif
