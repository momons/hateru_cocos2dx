//
//  DBSavesManager.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/08.
//

#include "DBSavesManager.h"

#include "Service/Firebase/Auth/AuthService.h"

database::DatabaseReference DBSavesManager::ref() {
    return database->GetReference().Child(DBBaseManager::topFieldName.c_str()).Child("saves");
}

database::DatabaseReference DBSavesManager::myRef() {
    auto userId = AuthService::sharedInstance()->userId();
    return ref().Child(userId);
}

void DBSavesManager::readMy(const function<void(const bool, const DBSaveEntity)> handler) {
    
    auto dbref = myRef();
    auto result = dbref.GetValue();
    result.OnCompletion([handler](const Future<database::DataSnapshot> &result) {
        if (result.error() != kFutureStatusComplete) {
            printf("ERROR: GetValue() returned an invalid result.");
            handler(false, DBSaveEntity());
            return;
        }
        if (result.error() != database::kErrorNone) {
            printf("ERROR: GetValue() returned error %d: %s", result.error(), result.error_message());
            handler(false, DBSaveEntity());
            return;
        }
        
        auto snapshot = result.result();
        if (!snapshot->exists()) {
            handler(false, DBSaveEntity());
            return;
        }
        
        auto entity = DBSaveEntity(snapshot);
        handler(true, entity);
    });
}

void DBSavesManager::writeMy(const string &saveData, const string &checkDigit) {
    auto dbref = myRef();
    auto entity = DBSaveEntity(saveData, checkDigit);
    dbref.UpdateChildren(entity.toVariants());
}

void DBSavesManager::deleteMy() {
    auto dbref = myRef();
    dbref.RemoveValue();
}
