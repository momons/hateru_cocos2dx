//
//  FCMService.h
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/17.
//

#import <Foundation/Foundation.h>
#import "Firebase.h"

NS_ASSUME_NONNULL_BEGIN

@interface FCMService : NSObject<FIRMessagingDelegate>

/**
 APNsデバイストークンをFirebaseに登録する

 @param token APNsデバイストークン
 */
+ (void)registerAPNSToken:(NSData *)token;

@end

NS_ASSUME_NONNULL_END
