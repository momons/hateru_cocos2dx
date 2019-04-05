//
//  RealtimeDatabaseService.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/04.
//

#include "RealtimeDatabaseService.h"

#include "AuthService.h"

RealtimeDatabaseService *RealtimeDatabaseService::instance;

const string RealtimeDatabaseService::topFieldName = "hateru";

RealtimeDatabaseService::RealtimeDatabaseService() {
    
#if defined(__ANDROID__)
    app = App::Create(firebase::AppOptions(), my_jni_env, my_activity);
#else
    app = App::Create(firebase::AppOptions());
#endif
    
    database = database::Database::GetInstance(app);
}

RealtimeDatabaseService *RealtimeDatabaseService::sharedInstance() {
    static once_flag flag;
    call_once(flag, setupInstance);
    return instance;
}

void RealtimeDatabaseService::setupInstance() {
    instance = new RealtimeDatabaseService();
}

// MARK:- 位置情報

database::DatabaseReference RealtimeDatabaseService::locationsRef() {
    return database->GetReference().Child(RealtimeDatabaseService::topFieldName.c_str()).Child("locations");
}

database::DatabaseReference RealtimeDatabaseService::myLocationsRef() {
    auto userId = AuthService::sharedInstance()->userId();
    return locationsRef().Child(userId);
}

void RealtimeDatabaseService::readLocation(const int mapType, const int x, const int y) {
    
    auto dbref = myLocationsRef();
    
    auto result = dbref.GetValue();
    result.OnCompletion([](const Future<database::DataSnapshot> &result) {
        if (result.error() != kFutureStatusComplete) {
            printf("ERROR: GetValue() returned an invalid result.");
            return;
        }
        if (result.error() != database::kErrorNone) {
            printf("ERROR: GetValue() returned error %d: %s", result.error(), result.error_message());
            return;
        }
        
        auto snapshot = result.result();
        auto data = snapshot->Child("message");
        data.value();
    });
}

void RealtimeDatabaseService::writeMyLocation(const string username, const int mapType, const int x, const int y, const string message, const string otherInfos) {
    
    auto dbref = myLocationsRef();
    
    map<string, Variant> childUpdates;
    childUpdates["username"] = username;
    childUpdates["mapType"] = mapType;
    childUpdates["x"] = x;
    childUpdates["y"] = y;
    childUpdates["message"] = message;
    childUpdates["otherInfos"] = otherInfos;

    dbref.UpdateChildren(childUpdates);
}

void RealtimeDatabaseService::deleteMyLocation() {
    auto dbref = myLocationsRef();
    dbref.RemoveValue();
}

// MARK:- プロフィール

database::DatabaseReference RealtimeDatabaseService::profilesRef() {
    return database->GetReference().Child(RealtimeDatabaseService::topFieldName.c_str()).Child("profiles");
}

database::DatabaseReference RealtimeDatabaseService::myProfilesRef() {
    auto userId = AuthService::sharedInstance()->userId();
    return profilesRef().Child(userId);
}

void RealtimeDatabaseService::readProfile(const string userId, const function<void(const bool, const PlayerProfileEntity)> handler) {

    auto dbref = profilesRef().Child(userId);
    auto result = dbref.GetValue();
    result.OnCompletion([handler](const Future<database::DataSnapshot> &result) {
        if (result.error() != kFutureStatusComplete) {
            printf("ERROR: GetValue() returned an invalid result.");
            handler(false, PlayerProfileEntity());
            return;
        }
        if (result.error() != database::kErrorNone) {
            printf("ERROR: GetValue() returned error %d: %s", result.error(), result.error_message());
            handler(false, PlayerProfileEntity());
            return;
        }
        
        auto snapshot = result.result();
        if (!snapshot->exists()) {
            handler(false, PlayerProfileEntity());
            return;
        }
        
        PlayerProfileEntity entity;
//        entity.gender = static_cast<int>(snapshot->Child("gender").value());
//        entity.age = static_cast<int>(snapshot->Child("age").value());
//        entity.address = static_cast<int>(snapshot->Child("address").value());
//        entity.blood = static_cast<int>(snapshot->Child("blood").value());
//        entity.constellation = static_cast<int>(snapshot->Child("constellation").value());
        
        handler(true, entity);
    });
}

void RealtimeDatabaseService::writeMyPrpfole(const string username, PlayerProfileEntity *profile) {
    
    auto dbref = myProfilesRef();
    
    map<string, Variant> childUpdates;
    childUpdates["username"] = username;
    childUpdates["gender"] = profile->gender();
    childUpdates["age"] = profile->age();
    childUpdates["address"] = profile->address();
    childUpdates["blood"] = profile->blood();
    childUpdates["constellation"] = profile->constellation();
    
    dbref.UpdateChildren(childUpdates);
}

void RealtimeDatabaseService::deleteMyPrpfole() {
    auto dbref = myProfilesRef();
    dbref.RemoveValue();
}

// MARK:- キャラクター

