//
//  DBBaseManager.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/05.
//

#include "DBBaseManager.h"

const string DBBaseManager::topFieldName = "hateru";

DBBaseManager::DBBaseManager() {
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    auto app = App::Create(firebase::AppOptions());
#else
    auto app = App::Create(firebase::AppOptions(), my_jni_env, my_activity);
#endif
    database = database::Database::GetInstance(app);
}
