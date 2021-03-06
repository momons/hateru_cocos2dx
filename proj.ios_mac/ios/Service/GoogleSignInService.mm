//
//  GoogleSignInService.m
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/09.
//

#import "GoogleSignInService.h"

#import <Firebase.h>

@interface GoogleSignInService() {
    /// サインインハンドラー
    signInHandler _signInHandler;
}

@end

@implementation GoogleSignInService

- (instancetype)init {
    if (self = [super init]) {
        [self configure];
    }
    return self;
}

- (void)configure {
    [GIDSignIn sharedInstance].clientID = [FIRApp defaultApp].options.clientID;
    [GIDSignIn sharedInstance].delegate = self;
}

- (void)signInWithCompletion:(signInHandler)completion {
    _signInHandler = completion;
    [[GIDSignIn sharedInstance] signIn];
}

- (void)signIn:(GIDSignIn *)signIn didSignInForUser:(GIDGoogleUser *)user withError:(NSError *)error {
    if (error != nil) {
        LOG(@"ERROR: Google sign in. %@", error.description);
        _signInHandler(NO);
        return;
    }
    __weak GoogleSignInService *weakSelf = self;
    FIRAuthCredential *credential = [FIRGoogleAuthProvider credentialWithIDToken:user.authentication.idToken
                                                                     accessToken:user.authentication.accessToken];
    [[FIRAuth auth] signInAndRetrieveDataWithCredential:credential completion:^(FIRAuthDataResult * _Nullable authResult, NSError * _Nullable error) {
        GoogleSignInService *blocksSelf = weakSelf;
        if (error != nil) {
            LOG(@"ERROR: Google sign in. %@", error.description);
            if (blocksSelf != nil && blocksSelf->_signInHandler != nullptr) {
                blocksSelf->_signInHandler(NO);
            }
            return;
        }
        if (blocksSelf != nil && blocksSelf->_signInHandler != nullptr) {
            blocksSelf->_signInHandler(YES);
        }
    }];
}

- (void)signIn:(GIDSignIn *)signIn didDisconnectWithUser:(GIDGoogleUser *)user withError:(NSError *)error {

}

+ (BOOL)handleURL:(nonnull NSURL *)url options:(nonnull NSDictionary<NSString *, id> *)options {
    return [[GIDSignIn sharedInstance] handleURL:url
                               sourceApplication:options[UIApplicationOpenURLOptionsSourceApplicationKey]
                                      annotation:options[UIApplicationOpenURLOptionsAnnotationKey]];
}

@end
