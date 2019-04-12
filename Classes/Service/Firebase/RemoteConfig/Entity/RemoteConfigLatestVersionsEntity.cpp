//
//  RemoteConfigLatestVersionsEntity.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/10.
//

#include "RemoteConfigLatestVersionsEntity.h"

#include "cocos2d.h"
#include "Const/LogConst.h"

USING_NS_CC;

RemoteConfigLatestVersionsEntity::RemoteConfigLatestVersionsEntity() {
    _ios = 0;
    _android = 0;
}

bool RemoteConfigLatestVersionsEntity::mapping(picojson::object &object) {
    if (object["ios"].is<int>()) {
        _ios = object["ios"].get<int>();
    } else {
        log(LogConst::jsonBadMappingError.c_str(), "ios");
        return false;
    }
    if (object["android"].is<int>()) {
        _ios = object["android"].get<int>();
    } else {
        log(LogConst::jsonBadMappingError.c_str(), "android");
        return false;
    }
    return true;
}

int RemoteConfigLatestVersionsEntity::ios() {
    return _ios;
}

int RemoteConfigLatestVersionsEntity::android() {
    return _android;
}
