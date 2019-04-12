//
//  FirebaseService.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/10.
//

#include "FirebaseService.h"

#include "cocos2d.h"
#include <mutex>

USING_NS_CC;

FirebaseService *FirebaseService::instance;

FirebaseService::FirebaseService() {
    
#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)
    _app = App::Create(firebase::AppOptions());
#else
    _app = App::Create(firebase::AppOptions(), JniHelper::getEnv(), JniHelper::getActivity());
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
