//
//  TwitterSignInServiceWrap.m
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/10.
//

#import "TwitterSignInServiceWrap.h"

#import "TwitterSignInService.h"

TwitterSignInServiceWrap::TwitterSignInServiceWrap() {
    _service = [[TwitterSignInService new] autorelease];
}

void TwitterSignInServiceWrap::signIn(const function<void(bool)> handler) {
    [_service signInWithCompletion:^(BOOL success) {
        handler(success);
    }];
}
