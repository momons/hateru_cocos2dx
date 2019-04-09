//
//  DBProfileEntity.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/05.
//

#include "DBProfileEntity.h"

#include "ProfileConst.h"

DBProfileEntity::DBProfileEntity() {
    _username = "";
    _gender = 0;
    _age = 0;
    _address = 0;
    _blood = 0;
    _constellation = 0;
}

DBProfileEntity::DBProfileEntity(const database::DataSnapshot *snapshot) {

    DBProfileEntity();
    
    if (!snapshot->exists()) {
        // データなし
        return;
    }
    
    auto username = snapshot->Child("username").value();
    if (username.is_mutable_string()) {
        setUsername(username.mutable_string());
    }
    auto gender = snapshot->Child("gender").value();
    if (gender.is_int64()) {
        setGender(static_cast<int>(gender.int64_value()));
    }
    auto age = snapshot->Child("age").value();
    if (age.is_int64()) {
        setAge(static_cast<int>(age.int64_value()));
    }
    auto address = snapshot->Child("address").value();
    if (address.is_int64()) {
        setAddress(static_cast<int>(address.int64_value()));
    }
    auto blood = snapshot->Child("blood").value();
    if (blood.is_int64()) {
        setBlood(static_cast<int>(blood.int64_value()));
    }
    auto constellation = snapshot->Child("constellation").value();
    if (constellation.is_int64()) {
        setConstellation(static_cast<int>(constellation.int64_value()));
    }
}

DBProfileEntity::DBProfileEntity(const string &username, PlayerProfileEntity *profile) {
    DBProfileEntity();
    setUsername(username);
    setGender(profile->gender());
    setAge(profile->age());
    setAddress(profile->address());
    setBlood(profile->blood());
    setConstellation(profile->constellation());
}

map<string, Variant> DBProfileEntity::toVariants() {
    map<string, Variant> variants;
    variants["username"] = _username;
    variants["gender"] = _gender;
    variants["age"] = _age;
    variants["address"] = _address;
    variants["blood"] = _blood;
    variants["constellation"] = _constellation;
    return variants;
}

void DBProfileEntity::setUsername(const string &username) {
    _username = username;
}
string DBProfileEntity::username() {
    return _username;
}

void DBProfileEntity::setGender(const int gender) {
    if (gender < 0 || gender >= ProfileConst::sharedInstance()->genders.size()) {
        return;
    }
    _gender = gender;
}
int DBProfileEntity::gender() {
    return _gender;
}

void DBProfileEntity::setAge(const int age) {
    if (age < 0 || age >= ProfileConst::sharedInstance()->ages.size()) {
        return;
    }
    _age = age;
}
int DBProfileEntity::age() {
    return _age;
}

void DBProfileEntity::setAddress(const int address) {
    if (address < 0 || address >= ProfileConst::sharedInstance()->addresses.size()) {
        return;
    }
    _address = address;
}
int DBProfileEntity::address() {
    return _address;
}

void DBProfileEntity::setBlood(const int blood) {
    if (blood < 0 || blood >= ProfileConst::sharedInstance()->bloods.size()) {
        return;
    }
    _blood = blood;
}
int DBProfileEntity::blood() {
    return _blood;
}

void DBProfileEntity::setConstellation(const int constellation) {
    if (constellation < 0 || constellation >= ProfileConst::sharedInstance()->ages.size()) {
        return;
    }
    _constellation = constellation;
}
int DBProfileEntity::constellation() {
    return _constellation;
}
