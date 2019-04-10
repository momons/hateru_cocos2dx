//
//  RemoteConfigService.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/10.
//

#include "RemoteConfigService.h"

#include "picojson.h"
#include "firebase/remote_config.h"

#include "LogConst.h"
#include "FirebaseService.h"
#include "JsonUtil.h"
#include "RemoteConfigLatestVersionsEntity.h"

using namespace firebase;

RemoteConfigService *RemoteConfigService::instance;

RemoteConfigService::RemoteConfigService() {
    const App *app = FirebaseService::sharedInstance()->app();
    remote_config::Initialize(*app);
#ifdef COCOS2D_DEBUG
    // デバッグモードで即時反映
    remote_config::SetConfigSetting(remote_config::kConfigSettingDeveloperMode, "1");
#endif
    auto result = remote_config::Fetch();
    result.OnCompletion([](const Future<void> &result) {
        remote_config::ActivateFetched();
    });
}

RemoteConfigService *RemoteConfigService::sharedInstance() {
    static once_flag flag;
    call_once(flag, setupInstance);
    return instance;
}

void RemoteConfigService::setupInstance() {
    instance = new RemoteConfigService();
}

int RemoteConfigService::latestVersions() {
    auto latestVersions = remote_config::GetString("latestVersions");
    if (latestVersions.empty()) {
        return -1;
    }
    
    string error;
    picojson::value jsonValue;
    JsonUtil::jsonParse(&jsonValue, &error, &latestVersions);
    if(!error.empty()){
        log(LogConst::jsonParseError.c_str(), error.c_str());
        return -1;
    }

    RemoteConfigLatestVersionsEntity entity;
    auto isSuccess = entity.mapping(jsonValue.get<picojson::object>());
    if (!isSuccess) {
        return -1;
    }

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    return entity.ios();
#else
    return entity.android();
#endif
}
