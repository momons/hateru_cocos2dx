//
//  DBBlacklistsManager.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/08.
//

#include "DBBlacklistsManager.h"

#include "Service/Firebase/Auth/AuthService.h"

database::DatabaseReference DBBlacklistsManager::ref() {
    return database->GetReference().Child(DBBaseManager::topFieldName.c_str()).Child("blacklists");
}

database::DatabaseReference DBBlacklistsManager::myRef() {
    auto userId = AuthService::sharedInstance()->userId();
    return ref().Child(userId);
}

void DBBlacklistsManager::readMy(const function<void(const vector<DBBlacklistEntity>)> handler) {
    
    auto dbref = myRef();
    auto query = dbref.OrderByChild("createdAt");
    auto result = query.GetValue();
    result.OnCompletion([handler](const Future<database::DataSnapshot> &result) {
        if (result.error() != kFutureStatusComplete) {
            printf("ERROR: GetValue() returned an invalid result.");
            handler(vector<DBBlacklistEntity>());
            return;
        }
        if (result.error() != database::kErrorNone) {
            printf("ERROR: GetValue() returned error %d: %s", result.error(), result.error_message());
            handler(vector<DBBlacklistEntity>());
            return;
        }
        
        auto snapshot = result.result();
        if (!snapshot->exists()) {
            handler(vector<DBBlacklistEntity>());
            return;
        }
        
        auto entities = vector<DBBlacklistEntity>();
        for (auto i = snapshot->children_count() - 1; i >= 0; i--) {
            auto entity = DBBlacklistEntity(&snapshot->children().at(i));
            entities.push_back(entity);
        }
        
        handler(entities);
    });
}

void DBBlacklistsManager::writeMy(const string &userId, const string &username) {
    auto dbref = myRef().Child(userId);
    auto entity = DBBlacklistEntity(userId, username, time(nullptr));
    dbref.UpdateChildren(entity.toVariants());
}

void DBBlacklistsManager::deleteMy(const string &userId) {
    auto dbref = myRef().Child(userId);
    dbref.RemoveValue();
}
