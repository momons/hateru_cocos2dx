//
//  DBBaseManager.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/05.
//

#include "DBBaseManager.h"

const string DBBaseManager::topFieldName = "hateru";

DBBaseManager::DBBaseManager() {
#if defined(__ANDROID__)
    auto app = App::Create(firebase::AppOptions(), my_jni_env, my_activity);
#else
    auto app = App::Create(firebase::AppOptions());
#endif
    database = database::Database::GetInstance(app);
}
