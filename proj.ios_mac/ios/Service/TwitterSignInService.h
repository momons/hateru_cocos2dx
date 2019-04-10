//
//  TwitterSignInService.h
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^signInHandler)(BOOL);

@interface TwitterSignInService : NSObject

/**
 サインイン
 
 @param completion 完了通知
 */
- (void)signInWithCompletion:(nonnull signInHandler)completion;

/**
 URLハンドリング
 
 @param url         URL
 @param options     オプション
 @param application アプリケーション
 @return 処理可否
 */
+ (BOOL)handleURL:(nonnull NSURL *)url options:(nonnull NSDictionary<NSString *, id> *)options application:(nonnull UIApplication *)application;

@end

NS_ASSUME_NONNULL_END
