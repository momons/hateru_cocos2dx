//
//  FacebookSignInService.h
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/09.
//

#import <Foundation/Foundation.h>

#import "FBSDKLoginButton.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^signInHandler)(BOOL);

/**
 Facebookサインインサービス
 */
@interface FacebookSignInService : NSObject

/**
 サインイン
 
 @param completion 完了通知
 */
- (void)signInWithCompletion:(nonnull signInHandler)completion;

/**
 サインアウト
 */
- (void)signOut;

/**
 URLハンドリング
 
 @param url         URL
 @param options     オプション
 @param application アプリケーション
 @return 処理可否
 */
+ (BOOL)handleURL:(nonnull NSURL *)url options:(nonnull NSDictionary<NSString *, id> *)options application:(UIApplication *)application;

@end

NS_ASSUME_NONNULL_END
