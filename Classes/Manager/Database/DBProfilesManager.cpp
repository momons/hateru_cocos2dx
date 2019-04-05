//
//  DBProfilesManager.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/05.
//

#include "DBProfilesManager.h"

#include "AuthService.h"

database::DatabaseReference DBProfilesManager::profilesRef() {
    return database->GetReference().Child(DBBaseManager::topFieldName.c_str()).Child("profiles");
}

database::DatabaseReference DBProfilesManager::myProfilesRef() {
    auto userId = AuthService::sharedInstance()->userId();
    return profilesRef().Child(userId);
}

void DBProfilesManager::read(const string &userId, const function<void(const bool, const DBProfileEntity)> handler) {
    
    auto dbref = profilesRef().Child(userId);
    auto result = dbref.GetValue();
    result.OnCompletion([handler](const Future<database::DataSnapshot> &result) {
        if (result.error() != kFutureStatusComplete) {
            printf("ERROR: GetValue() returned an invalid result.");
            handler(false, DBProfileEntity());
            return;
        }
        if (result.error() != database::kErrorNone) {
            printf("ERROR: GetValue() returned error %d: %s", result.error(), result.error_message());
            handler(false, DBProfileEntity());
            return;
        }
        
        auto snapshot = result.result();
        if (!snapshot->exists()) {
            handler(false, DBProfileEntity());
            return;
        }
        
        auto entity = DBProfileEntity(snapshot);
        handler(true, entity);
    });
}

void DBProfilesManager::writeMy(const string &username, PlayerProfileEntity *profile) {
    auto dbref = myProfilesRef();
    auto entity = DBProfileEntity(username, profile);
    dbref.UpdateChildren(entity.toVariants());
}

void DBProfilesManager::deleteMy() {
    auto dbref = myProfilesRef();
    dbref.RemoveValue();
}
