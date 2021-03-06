//
//  DBBBSEntity.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/08.
//

#include "DBBBSEntity.h"

DBBBSEntity::DBBBSEntity() {
    _messageId = "";
    _userId = "";
    _username = "";
    _message = "";
    _createdAt = 0;
    _updatedAt = 0;
}

DBBBSEntity::DBBBSEntity(const database::DataSnapshot *snapshot) {
    
    DBBBSEntity();
    
    if (!snapshot->exists()) {
        // データなし
        return;
    }
    
    auto messageId = snapshot->Child("messageId").value();
    if (messageId.is_mutable_string()) {
        setMessageId(messageId.mutable_string());
    }
    auto userId = snapshot->Child("userId").value();
    if (userId.is_mutable_string()) {
        setUserId(userId.mutable_string());
    }
    auto username = snapshot->Child("username").value();
    if (username.is_mutable_string()) {
        setUsername(username.mutable_string());
    }
    auto message = snapshot->Child("message").value();
    if (message.is_mutable_string()) {
        setMessage(message.mutable_string());
    }
    auto createdAt = snapshot->Child("createdAt").value();
    if (createdAt.is_int64()) {
        setCreatedAt(static_cast<int>(createdAt.int64_value()));
    }
    auto updatedAt = snapshot->Child("updatedAt").value();
    if (updatedAt.is_int64()) {
        setUpdatedAt(static_cast<int>(updatedAt.int64_value()));
    }
}

DBBBSEntity::DBBBSEntity(const string &messageId, const string &userId) {
    DBBBSEntity();
    setMessageId(messageId);
    setUserId(userId);
}

map<string, Variant> DBBBSEntity::toVariants() {
    map<string, Variant> variants;
    variants["messageId"] = _messageId;
    variants["userId"] = _userId;
    variants["username"] = _username;
    variants["message"] = _message;
    variants["createdAt"] = static_cast<int64_t>(_createdAt);
    variants["updatedAt"] = static_cast<int64_t>(_updatedAt);
    return variants;
}

void DBBBSEntity::setMessageId(const string &messageId) {
    _messageId = messageId;
}
string DBBBSEntity::messageId() {
    return _messageId;
}

void DBBBSEntity::setUserId(const string &userId) {
    _userId = userId;
}
string DBBBSEntity::userId() {
    return _userId;
}

void DBBBSEntity::setUsername(const string &username) {
    _username = username;
}
string DBBBSEntity::username() {
    return _username;
}

void DBBBSEntity::setMessage(const string &message) {
    _message = message;
}
string DBBBSEntity::message() {
    return _message;
}

void DBBBSEntity::setCreatedAt(const time_t createdAt) {
    _createdAt = createdAt;
}
time_t DBBBSEntity::createdAt() {
    return _createdAt;
}

void DBBBSEntity::setUpdatedAt(const time_t updatedAt) {
    _updatedAt = updatedAt;
}
time_t DBBBSEntity::updatedAt() {
    return _updatedAt;
}
