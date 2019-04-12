//
//  DBCharactersManager.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/09.
//

#include "DBCharactersManager.h"

#include "Service/Firebase/Auth/AuthService.h"

database::DatabaseReference DBCharactersManager::ref() {
    return database->GetReference().Child(DBBaseManager::topFieldName.c_str()).Child("characters");
}

database::DatabaseReference DBCharactersManager::myRef() {
    auto userId = AuthService::sharedInstance()->userId();
    return ref().Child(userId);
}

void DBCharactersManager::read(const string &userId, const function<void(const bool, const DBCharacterEntity)> handler) {
    
    auto dbref = ref().Child(userId);
    auto result = dbref.GetValue();
    result.OnCompletion([handler](const Future<database::DataSnapshot> &result) {
        if (result.error() != kFutureStatusComplete) {
            printf("ERROR: GetValue() returned an invalid result.");
            handler(false, DBCharacterEntity());
            return;
        }
        if (result.error() != database::kErrorNone) {
            printf("ERROR: GetValue() returned error %d: %s", result.error(), result.error_message());
            handler(false, DBCharacterEntity());
            return;
        }
        
        auto snapshot = result.result();
        if (!snapshot->exists()) {
            handler(false, DBCharacterEntity());
            return;
        }
        
        auto entity = DBCharacterEntity(snapshot);
        handler(true, entity);
    });
}

void DBCharactersManager::writeMy(const string &statusData, const string &checkDigit) {
    auto dbref = myRef();
    auto entity = DBCharacterEntity(statusData, checkDigit);
    dbref.UpdateChildren(entity.toVariants());
}

void DBCharactersManager::deleteMy() {
    auto dbref = myRef();
    dbref.RemoveValue();
}
