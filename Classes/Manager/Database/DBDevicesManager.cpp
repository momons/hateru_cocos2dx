//
//  DBDevicesManager.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/18.
//

#include "DBDevicesManager.h"

#include "Service/Firebase/Auth/AuthService.h"

database::DatabaseReference DBDevicesManager::ref() {
    return database->GetReference().Child(DBBaseManager::topFieldName.c_str()).Child("devices");
}

database::DatabaseReference DBDevicesManager::myRef() {
    auto userId = AuthService::sharedInstance()->userId();
    return ref().Child(userId);
}

void DBDevicesManager::writeMy(const string &token) {
    auto dbref = myRef();
    auto entity = DBDeviceEntity(token);
    dbref.UpdateChildren(entity.toVariants());
}
