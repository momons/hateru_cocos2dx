//
//  FirebaseService.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/10.
//

#include "FirebaseService.h"

FirebaseService *FirebaseService::instance;

FirebaseService::FirebaseService() {
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    _app = App::Create(firebase::AppOptions());
#else
    _app = App::Create(firebase::AppOptions(), my_jni_env, my_activity);
#endif
}

FirebaseService *FirebaseService::sharedInstance() {
    static once_flag flag;
    call_once(flag, setupInstance);
    return instance;
}

void FirebaseService::setupInstance() {
    instance = new FirebaseService();
}

App *FirebaseService::app() {
    return _app;
}
