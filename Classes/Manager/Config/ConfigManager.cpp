//
//  ConfigManager.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/22.
//

#include "ConfigManager.h"

#include "cocos2d.h"
#include <mutex>
#include "Const/FileConst.h"

USING_NS_CC;

ConfigManager *ConfigManager::instance;

ConfigManager *ConfigManager::sharedInstance() {
    static once_flag flag;
    call_once(flag, setupInstance);
    return instance;
}

void ConfigManager::setupInstance() {
    instance = new ConfigManager();
}

void ConfigManager::setFirebaseRegisterToken(const string &token) {
    auto userDef = UserDefault::getInstance();
    userDef->setStringForKey("firebaseRegisterToken", token);
}

string ConfigManager::firebaseRegisterToken() {
    auto userDef = UserDefault::getInstance();
    auto token = userDef->getStringForKey("firebaseRegisterToken");
    return token;
}
