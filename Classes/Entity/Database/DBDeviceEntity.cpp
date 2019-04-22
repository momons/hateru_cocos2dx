//
//  DBDeviceEntity.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/18.
//

#include "DBDeviceEntity.h"

DBDeviceEntity::DBDeviceEntity() {
    _token = "";
}

DBDeviceEntity::DBDeviceEntity(const string &token) {
    DBDeviceEntity();
    setToken(token);
}

map<string, Variant> DBDeviceEntity::toVariants() {
    map<string, Variant> variants;
    variants[_token] = _token;
    return variants;
}

void DBDeviceEntity::setToken(const string &token) {
    _token = token;
}
string DBDeviceEntity::token() {
    return _token;
}
