//
// Created by Kazunari Hara on 2019/04/15.
//

#ifndef PROJ_ANDROID_JNICALLBACK_H
#define PROJ_ANDROID_JNICALLBACK_H

#include "../Firebase/Auth/AuthDelegate.h"

/// JNI用のコールバッククラス
class JniCallback final {
public:

    /// 認証用JNIコールバック
    static AuthDelegate *delegate;

};

#endif //PROJ_ANDROID_JNICALLBACK_H
