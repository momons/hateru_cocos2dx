//
//  DBBaseManager.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/05.
//

#include "DBBaseManager.h"

#include "Service/Firebase/FirebaseService.h"

const string DBBaseManager::topFieldName = "hateru";

DBBaseManager::DBBaseManager() {
    database = database::Database::GetInstance(FirebaseService::sharedInstance()->app());
}
