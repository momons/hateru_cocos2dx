//
//  FCMService.m
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/17.
//

#import "FCMService.h"

#import "ConfigManager.h"

@interface FCMService() {
}
@end

@implementation FCMService

- (instancetype)init {
    if (self = [super init]) {
        [self configure];
    }
    return self;
}

- (void)dealloc {
    [super dealloc];
}

- (void)configure {
    [FIRMessaging messaging].delegate = self;
}

// MARK:- FIRMessagingDelegate

- (void)messaging:(FIRMessaging *)messaging didReceiveMessage:(FIRMessagingRemoteMessage *)remoteMessage {
    
}

- (void)messaging:(FIRMessaging *)messaging didReceiveRegistrationToken:(NSString *)fcmToken {
    LOG(@"FCM registration token: %@", fcmToken);
    ConfigManager::sharedInstance()->setFirebaseRegisterToken([fcmToken UTF8String]);
}

@end
