//
//  DBLocationEntity.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/05.
//

#include "DBLocationEntity.h"

#include "../../Const/ProfileConst.h"
#include "../../Entity/Player/PlayerMapEntity.h"

DBLocationEntity::DBLocationEntity() {
    _username = "";
    _mapId = 0;
    _x = 0;
    _y = 0;
    _message = "";
}

DBLocationEntity::DBLocationEntity(const database::DataSnapshot *snapshot) {
    
    DBLocationEntity();
    
    if (!snapshot->exists()) {
        // データなし
        return;
    }
    
    auto username = snapshot->Child("username").value();
    if (username.is_mutable_string()) {
        setUsername(username.mutable_string());
    }
    auto mapId = snapshot->Child("mapId").value();
    if (mapId.is_int64()) {
        setMapId(static_cast<int>(mapId.int64_value()));
    }
    auto x = snapshot->Child("x").value();
    if (x.is_int64()) {
        setX(static_cast<int>(x.int64_value()));
    }
    auto y = snapshot->Child("y").value();
    if (y.is_int64()) {
        setY(static_cast<int>(y.int64_value()));
    }
    auto message = snapshot->Child("message").value();
    if (message.is_mutable_string()) {
        setMessage(message.mutable_string());
    }
}

DBLocationEntity::DBLocationEntity(const string &username, PlayerMapEntity *map, const string &message) {
    DBLocationEntity();
    setUsername(username);
    setMapId(map->id);
    setX(map->x);
    setY(map->y);
    setMessage(message);
}

map<string, Variant> DBLocationEntity::toVariants() {
    map<string, Variant> variants;
    variants["username"] = _username;
    variants["mapId"] = _mapId;
    variants["x"] = _x;
    variants["y"] = _y;
    variants["message"] = _message;
    return variants;
}

void DBLocationEntity::setUsername(const string &username) {
    _username = username;
}
string DBLocationEntity::username() {
    return _username;
}

void DBLocationEntity::setMapId(const int mapId) {
    _mapId = mapId;
}
int DBLocationEntity::mapId() {
    return _mapId;
}

void DBLocationEntity::setX(const int x) {
    _x = x;
}
int DBLocationEntity::x() {
    return _x;
}

void DBLocationEntity::setY(const int y) {
    _y = y;
}
int DBLocationEntity::y() {
    return _y;
}

void DBLocationEntity::setMessage(const string &message) {
    _message = message;
}
string DBLocationEntity::message() {
    return _message;
}
