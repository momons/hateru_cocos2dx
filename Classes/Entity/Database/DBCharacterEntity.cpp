//
//  DBCharacterEntity.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/08.
//

#include "DBCharacterEntity.h"

#include "../../Const/ProfileConst.h"

DBCharacterEntity::DBCharacterEntity() {
    _statusData = "";
    _checkDigit = "";
}

DBCharacterEntity::DBCharacterEntity(const database::DataSnapshot *snapshot) {
    
    DBCharacterEntity();
    
    if (!snapshot->exists()) {
        // データなし
        return;
    }
    
    auto statusData = snapshot->Child("statusData").value();
    if (statusData.is_mutable_string()) {
        setStatusData(statusData.mutable_string());
    }
    auto checkDigit = snapshot->Child("checkDigit").value();
    if (checkDigit.is_mutable_string()) {
        setCheckDigit(checkDigit.mutable_string());
    }
}

DBCharacterEntity::DBCharacterEntity(const string &statusData, const string &checkDigit) {
    DBCharacterEntity();
    setStatusData(statusData);
    setCheckDigit(checkDigit);
}

map<string, Variant> DBCharacterEntity::toVariants() {
    map<string, Variant> variants;
    variants["statusData"] = _statusData;
    variants["checkDigit"] = _checkDigit;
    return variants;
}

void DBCharacterEntity::setStatusData(const string &statusData) {
    _statusData = statusData;
}
string DBCharacterEntity::statusData() {
    return _statusData;
}

void DBCharacterEntity::setCheckDigit(const string &checkDigit) {
    _checkDigit = checkDigit;
}
string DBCharacterEntity::checkDigit() {
    return _checkDigit;
}
