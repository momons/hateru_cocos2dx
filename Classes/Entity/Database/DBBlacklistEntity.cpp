//
//  DBBlacklistEntity.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/08.
//

#include "DBBlacklistEntity.h"

DBBlacklistEntity::DBBlacklistEntity() {
    _userId = "";
    _username = "";
    _createdAt = 0;
}

DBBlacklistEntity::DBBlacklistEntity(const database::DataSnapshot *snapshot) {
    
    DBBlacklistEntity();
    
    if (!snapshot->exists()) {
        // データなし
        return;
    }
    
    auto userId = snapshot->Child("userId").value();
    if (userId.is_mutable_string()) {
        setUserId(userId.mutable_string());
    }
    auto username = snapshot->Child("username").value();
    if (username.is_mutable_string()) {
        setUsername(username.mutable_string());
    }
    auto createdAt = snapshot->Child("createdAt").value();
    if (createdAt.is_int64()) {
        setCreatedAt(static_cast<long>(createdAt.int64_value()));
    }
}

DBBlacklistEntity::DBBlacklistEntity(const string &userId, const string &username, const time_t createdAt) {
    DBBlacklistEntity();
    setUserId(userId);
    setUsername(username);
    setCreatedAt(createdAt);
}

map<string, Variant> DBBlacklistEntity::toVariants() {
    map<string, Variant> variants;
    variants["userId"] = _userId;
    variants["username"] = _username;
    variants["createdAt"] = static_cast<int64_t>(_createdAt);
    return variants;
}

void DBBlacklistEntity::setUserId(const string &userId) {
    _userId = userId;
}
string DBBlacklistEntity::userId() {
    return _userId;
}

void DBBlacklistEntity::setUsername(const string &username) {
    _username = username;
}
string DBBlacklistEntity::username() {
    return _username;
}

void DBBlacklistEntity::setCreatedAt(const time_t createdAt) {
    _createdAt = createdAt;
}
time_t DBBlacklistEntity::createdAt() {
    return _createdAt;
}
