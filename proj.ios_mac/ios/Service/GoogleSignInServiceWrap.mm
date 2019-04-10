//
//  GoogleSignInServiceWrap.m
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/09.
//

#import "GoogleSignInServiceWrap.h"

#import "GoogleSignInService.h"

GoogleSignInServiceWrap::GoogleSignInServiceWrap() {
    _service = [GoogleSignInService new];
}

void GoogleSignInServiceWrap::signIn(const function<void(bool)> handler) {
    [_service signInWithCompletion:^(BOOL success) {
        handler(success);
    }];
}

void GoogleSignInServiceWrap::signOut() {
    [GoogleSignInService signOut];
}
