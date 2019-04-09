//
//  GoogleSignInService.h
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/09.
//

#import <Foundation/Foundation.h>

#import <GoogleSignIn/GoogleSignIn.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^signInHandler)(BOOL);

/**
 Googleサインインサービス
 */
@interface GoogleSignInService : NSObject<GIDSignInDelegate>

/**
 サインイン

 @param completion 完了通知
 */
- (void)signInWithCompletion:(signInHandler)completion;

/**
 サインアウト
 */
+ (void)signOut;

/**
 URLハンドリング

 @param url     URL
 @param options オプション
 @return 処理可否
 */
+ (BOOL)handleURL:(nonnull NSURL *)url options:(nonnull NSDictionary<NSString *, id> *)options;


@end

NS_ASSUME_NONNULL_END
