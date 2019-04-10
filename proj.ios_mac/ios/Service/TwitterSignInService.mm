//
//  TwitterSignInService.m
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/10.
//

#import "TwitterSignInService.h"

#import <TwitterKit/TWTRKit.h>
#import <Firebase.h>

#import "AppController.h"
#import "TwitterConst.h"

@interface TwitterSignInService() {
}

@end

@implementation TwitterSignInService

+ (void)configure {
    [[Twitter sharedInstance] startWithConsumerKey:[NSString stringWithUTF8String:TwitterConst::consumerKey.c_str()]
                                    consumerSecret:[NSString stringWithUTF8String:TwitterConst::consumerSecret.c_str()]];
}

- (void)signInWithCompletion:(signInHandler)completion {
    AppController* appController = (AppController *)[UIApplication sharedApplication].delegate;
    UIViewController* viewController = (UIViewController *)appController.viewController;
    [[Twitter sharedInstance] logInWithViewController:viewController completion:^(TWTRSession * _Nullable session, NSError * _Nullable error) {
        if (error != nil) {
            LOG(@"ERROR: Twitter sign in. %@", error.description);
            completion(NO);
            return;
        }
        FIRAuthCredential *credential = [FIRTwitterAuthProvider credentialWithToken:session.authToken secret:session.authTokenSecret];
        [[FIRAuth auth] signInAndRetrieveDataWithCredential:credential completion:^(FIRAuthDataResult * _Nullable authResult, NSError * _Nullable error) {
            if (error != nil) {
                LOG(@"ERROR: Twitter sign in. %@", error.description);
                completion(NO);
                return;
            }
            completion(YES);
        }];
    }];
}

+ (BOOL)handleURL:(nonnull NSURL *)url options:(nonnull NSDictionary<NSString *, id> *)options application:(nonnull UIApplication *)application {
    return [[Twitter sharedInstance] application:application
                                         openURL:url
                                         options:options];
}

@end
