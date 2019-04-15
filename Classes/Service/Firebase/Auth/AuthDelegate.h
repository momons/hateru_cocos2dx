//
// Created by Kazunari Hara on 2019/04/15.
//

#ifndef PROJ_ANDROID_AUTHDELEGATE_H
#define PROJ_ANDROID_AUTHDELEGATE_H

/// 認証コールバックデリゲート
class AuthDelegate {
public:
    /**
     *  Facebook認証完了通知
     *
     *  @param success true:認証OK、false:認証NG
     */
    virtual void onCompletionFacebookAuth(const bool success) = 0;

};

#endif //PROJ_ANDROID_AUTHDELEGATE_H
