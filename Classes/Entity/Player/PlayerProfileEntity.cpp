//
//  PlayerProfileEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/29.
//
//

#include "PlayerProfileEntity.h"

#include "LogConst.h"
#include "ProfileConst.h"

PlayerProfileEntity::PlayerProfileEntity() {
	_gender = 0;
	_age = 0;
	_address = 0;
	_blood = 0;
	_constellation = 0;
}

void PlayerProfileEntity::serialize(picojson::object &object) {
	object.insert(make_pair("gender", picojson::value(_gender)));
	object.insert(make_pair("age", picojson::value(_age)));
	object.insert(make_pair("address", picojson::value(_address)));
	object.insert(make_pair("blood", picojson::value(_blood)));
	object.insert(make_pair("constellation", picojson::value(_constellation)));
}

bool PlayerProfileEntity::mapping(picojson::object &object) {
	if (object["gender"].is<int>()) {
		setGender(object["gender"].get<int>());
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "gender");
		return false;
	}
	if (object["age"].is<int>()) {
		setAge(object["age"].get<int>());
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "age");
		return false;
	}
	if (object["address"].is<int>()) {
		setAddress(object["address"].get<int>());
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "address");
		return false;
	}
	if (object["blood"].is<int>()) {
		setBlood(object["blood"].get<int>());
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "blood");
		return false;
	}
	if (object["constellation"].is<int>()) {
		setConstellation(object["constellation"].get<int>());
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "constellation");
		return false;
	}
	return true;
}

void PlayerProfileEntity::setGender(const int gender) {
    if (gender < 0 || gender >= ProfileConst::sharedInstance()->genders.size()) {
        return;
    }
    _gender = gender;
}
int PlayerProfileEntity::gender() {
    return _gender;
}

void PlayerProfileEntity::setAge(const int age) {
    if (age < 0 || age >= ProfileConst::sharedInstance()->ages.size()) {
        return;
    }
    _age = age;
}
int PlayerProfileEntity::age() {
    return _age;
}

void PlayerProfileEntity::setAddress(const int address) {
    if (address < 0 || address >= ProfileConst::sharedInstance()->addresses.size()) {
        return;
    }
    _address = address;
}
int PlayerProfileEntity::address() {
    return _address;
}

void PlayerProfileEntity::setBlood(const int blood) {
    if (blood < 0 || blood >= ProfileConst::sharedInstance()->bloods.size()) {
        return;
    }
    _blood = blood;
}
int PlayerProfileEntity::blood() {
    return _blood;
}

void PlayerProfileEntity::setConstellation(const int constellation) {
    if (constellation < 0 || constellation >= ProfileConst::sharedInstance()->ages.size()) {
        return;
    }
    _constellation = constellation;
}
int PlayerProfileEntity::constellation() {
    return _constellation;
}
