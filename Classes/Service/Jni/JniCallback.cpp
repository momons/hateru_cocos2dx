//
// Created by Kazunari Hara on 2019/04/15.
//

#include "JniCallback.h"

#include <jni.h>

AuthDelegate *JniCallback::delegate = nullptr;

extern "C" {

JNIEXPORT void JNICALL
Java_com_nikuq_hateru_firebase_auth_FacebookAuth_onCompletion(JNIEnv *env, jobject thiz, jboolean success) {
    if (JniCallback::delegate != nullptr) {
        JniCallback::delegate->onCompletionFacebookAuth(success == JNI_TRUE);
    }
}

JNIEXPORT void JNICALL
Java_com_nikuq_hateru_firebase_auth_GoogleAuth_onCompletion(JNIEnv *env, jobject thiz, jboolean success) {

}

JNIEXPORT void JNICALL
Java_com_nikuq_hateru_firebase_auth_TwitterAuth_onCompletion(JNIEnv *env, jobject thiz, jboolean success) {

}

}