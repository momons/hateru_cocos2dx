//
//  FunctionsService.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/24.
//

#include "FunctionsService.h"

#include "cocos2d.h"
#include <mutex>
#include "Service/Firebase/FirebaseService.h"
#include "Service/Firebase/Auth/AuthService.h"

USING_NS_CC;

#define FUNCTIONS_REGION "asia-northeast1"

FunctionsService *FunctionsService::instance;

FunctionsService::FunctionsService() {
    _functions = functions::Functions::GetInstance(FirebaseService::sharedInstance()->app(), FUNCTIONS_REGION);
}

FunctionsService *FunctionsService::sharedInstance() {
    static once_flag flag;
    call_once(flag, setupInstance);
    return instance;
}

void FunctionsService::setupInstance() {
    instance = new FunctionsService();
}

void FunctionsService::bbsAddMessage(const string &userId, const string &username, const string &message, const function<void(const bool)> handler) {
    // データ作成
    auto data = Variant::EmptyMap();
    data.map()["userId"] = Variant(userId);
    data.map()["username"] = Variant(username);
    data.map()["message"] = Variant(message);
    
    auto method = _functions->GetHttpsCallable("bbsPutMessage");
    auto retValue = method.Call(data);
    retValue.OnCompletion([handler](const Future<functions::HttpsCallableResult> &future){
        if (future.error() != functions::kErrorNone) {
            log("%s", future.error_message());
            handler(false);
            return;
        }
        log("%s", future.result()->data().string_value());
        handler(true);
    });
}
