//
//  DBSaveEntity.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/08.
//

#include "DBSaveEntity.h"

DBSaveEntity::DBSaveEntity() {
    _saveData = "";
    _checkDigit = "";
}

DBSaveEntity::DBSaveEntity(const database::DataSnapshot *snapshot) {
    
    DBSaveEntity();
    
    if (!snapshot->exists()) {
        // データなし
        return;
    }
    
    auto saveData = snapshot->Child("saveData").value();
    if (saveData.is_mutable_string()) {
        setSaveData(saveData.mutable_string());
    }
    auto checkDigit = snapshot->Child("checkDigit").value();
    if (checkDigit.is_mutable_string()) {
        setCheckDigit(checkDigit.mutable_string());
    }
}

DBSaveEntity::DBSaveEntity(const string &saveData, const string &checkDigit) {
    DBSaveEntity();
    setSaveData(saveData);
    setCheckDigit(checkDigit);
}

map<string, Variant> DBSaveEntity::toVariants() {
    map<string, Variant> variants;
    variants["saveData"] = _saveData;
    variants["checkDigit"] = _checkDigit;
    return variants;
}

void DBSaveEntity::setSaveData(const string &saveData) {
    _saveData = saveData;
}
string DBSaveEntity::saveData() {
    return _saveData;
}

void DBSaveEntity::setCheckDigit(const string &checkDigit) {
    _checkDigit = checkDigit;
}
string DBSaveEntity::checkDigit() {
    return _checkDigit;
}
