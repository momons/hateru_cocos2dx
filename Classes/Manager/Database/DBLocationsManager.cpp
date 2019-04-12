//
//  DBLocationsManager.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/05.
//

#include "DBLocationsManager.h"

#include "Service/Firebase/Auth/AuthService.h"

database::DatabaseReference DBLocationsManager::ref() {
    return database->GetReference().Child(DBBaseManager::topFieldName.c_str()).Child("locations");
}

database::DatabaseReference DBLocationsManager::myRef() {
    auto userId = AuthService::sharedInstance()->userId();
    return ref().Child(userId);
}

void DBLocationsManager::read(const string &userId, const function<void(const bool, const DBLocationEntity)> handler) {
    
//    auto dbref = ref().Child(userId);
//    auto result = dbref.GetValue();
//    result.OnCompletion([handler](const Future<database::DataSnapshot> &result) {
//        if (result.error() != kFutureStatusComplete) {
//            printf("ERROR: GetValue() returned an invalid result.");
//            handler(false, DBProfileEntity());
//            return;
//        }
//        if (result.error() != database::kErrorNone) {
//            printf("ERROR: GetValue() returned error %d: %s", result.error(), result.error_message());
//            handler(false, DBProfileEntity());
//            return;
//        }
//
//        auto snapshot = result.result();
//        if (!snapshot->exists()) {
//            handler(false, DBProfileEntity());
//            return;
//        }
//
//        auto entity = DBProfileEntity(snapshot);
//        handler(true, entity);
//    });
}

void DBLocationsManager::writeMy(const string &username, PlayerMapEntity *map, const string &message) {
    auto dbref = myRef();
    auto entity = DBLocationEntity(username, map, message);
    dbref.UpdateChildren(entity.toVariants());
}

void DBLocationsManager::deleteMy() {
    auto dbref = myRef();
    dbref.RemoveValue();
}
