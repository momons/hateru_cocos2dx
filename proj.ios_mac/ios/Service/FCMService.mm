//
//  FCMService.m
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/17.
//

#import "FCMService.h"

@implementation FCMService

- (instancetype)init {
    if (self = [super init]) {
        [self configure];
    }
    return self;
}

- (void)configure {
    [FIRMessaging messaging].delegate = self;
}

+ (void)registerAPNSToken:(NSData *)token {
    [FIRMessaging messaging].APNSToken = token;
}

// MARK:- FIRMessagingDelegate

- (void)messaging:(FIRMessaging *)messaging didReceiveMessage:(FIRMessagingRemoteMessage *)remoteMessage {
    
}

- (void)messaging:(FIRMessaging *)messaging didReceiveRegistrationToken:(NSString *)fcmToken {
    NSLog(@"FCM registration token: %@", fcmToken);
}

@end
