//
//  FacebookSignInServiceWrap.m
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/10.
//

#import "FacebookSignInServiceWrap.h"

#import "FacebookSignInService.h"

FacebookSignInServiceWrap::FacebookSignInServiceWrap() {
    _service = [FacebookSignInService new];
}

void FacebookSignInServiceWrap::signIn(const function<void(bool)> handler) {
    [_service signInWithCompletion:^(BOOL success) {
        handler(success);
    }];
}

void FacebookSignInServiceWrap::signOut() {
    [_service signOut];
}
