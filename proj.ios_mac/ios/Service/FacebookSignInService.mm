//
//  FacebookSignInService.m
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/09.
//

#import "FacebookSignInService.h"

#import <Firebase.h>

#import "AppController.h"

#import "FBSDKApplicationDelegate.h"
#import "FBSDKAccessToken.h"
#import "FBSDKLoginManagerLoginResult.h"
#import "FBSDKLoginManager.h"

@interface FacebookSignInService() {
    /// Facebookログインマネージャ
    FBSDKLoginManager *_loginManager;
}

@end

@implementation FacebookSignInService

- (instancetype)init {
    if (self = [super init]) {
        [self setupFacebookSignIn];
    }
    return self;
}

- (void)setupFacebookSignIn {
    _loginManager = [FBSDKLoginManager new];
}

- (void)signInWithCompletion:(signInHandler)completion {
    AppController* appController = (AppController *)[UIApplication sharedApplication].delegate;
    UIViewController* viewController = (UIViewController *)appController.viewController;
    [_loginManager logInWithReadPermissions:@[@"email"] fromViewController:viewController handler:^(FBSDKLoginManagerLoginResult *result, NSError *error) {
        if (error != nil) {
            LOG("ERROR: Facebook sign in. %@", error.description);
            completion(NO);
            return;
        }
        if (result.isCancelled) {
            completion(NO);
            return;
        }
        FIRAuthCredential *credential = [FIRFacebookAuthProvider credentialWithAccessToken:[FBSDKAccessToken currentAccessToken].tokenString];
        [[FIRAuth auth] signInAndRetrieveDataWithCredential:credential completion:^(FIRAuthDataResult * _Nullable authResult, NSError * _Nullable error) {
            if (error != nil) {
                LOG("ERROR: Facebook sign in. %@", error.description);
                // 失敗
                completion(NO);
                return;
            }
            // 成功
            completion(YES);
        }];
    }];
}

- (void)signOut {
    [_loginManager logOut];
}

+ (BOOL)handleURL:(nonnull NSURL *)url options:(nonnull NSDictionary<NSString *, id> *)options application:(UIApplication *)application {
    return [[FBSDKApplicationDelegate sharedInstance] application:application
                                                          openURL:url
                                                sourceApplication:options[UIApplicationOpenURLOptionsSourceApplicationKey]
                                                       annotation:options[UIApplicationOpenURLOptionsAnnotationKey]];
}

@end
