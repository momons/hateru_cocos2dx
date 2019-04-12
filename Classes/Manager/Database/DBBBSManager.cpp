//
//  DBBBSManager.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/08.
//

#include "DBBBSManager.h"

#include "Service/Firebase/Auth/AuthService.h"

database::DatabaseReference DBBBSManager::ref() {
    return database->GetReference().Child(DBBaseManager::topFieldName.c_str()).Child("bbs");
}

database::DatabaseReference DBBBSManager::myRef() {
    auto userId = AuthService::sharedInstance()->userId();
    return ref().Child(userId);
}

void DBBBSManager::readMy(const function<void(const bool, const DBBBSEntity)> handler) {
    
    auto dbref = myRef();
    auto result = dbref.GetValue();
    result.OnCompletion([handler](const Future<database::DataSnapshot> &result) {
        if (result.error() != kFutureStatusComplete) {
            printf("ERROR: GetValue() returned an invalid result.");
            handler(false, DBBBSEntity());
            return;
        }
        if (result.error() != database::kErrorNone) {
            printf("ERROR: GetValue() returned error %d: %s", result.error(), result.error_message());
            handler(false, DBBBSEntity());
            return;
        }
        
        auto snapshot = result.result();
        if (!snapshot->exists()) {
            handler(false, DBBBSEntity());
            return;
        }
        
        auto entity = DBBBSEntity(snapshot);
        handler(true, entity);
    });
}

void DBBBSManager::writeMy(const string &saveData, const string &checkDigit) {
    auto dbref = myRef();
    auto entity = DBBBSEntity(saveData, checkDigit);
    dbref.UpdateChildren(entity.toVariants());
}

void DBBBSManager::deleteMy() {
    auto dbref = myRef();
    dbref.RemoveValue();
}
