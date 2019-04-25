//
//  FirebaseService.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/10.
//

#ifndef FirebaseService_h
#define FirebaseService_h

#include "firebase/app.h"

using namespace std;
using namespace firebase;

/// Firebaseサービスクラス
class FirebaseService final {
public:
    
    /**
     *  インスタンスシェア
     *
     *  @return インスタンス
     */
    static FirebaseService *sharedInstance();
    
    /**
     *  デストラクタ
     */
    ~FirebaseService() {}
    
    /**
     *  Firebaseアプリケーション取得
     *
     *  @return Firebaseアプリケーション
     */
    App *app();
    
private:
    
    /// インスタンス
    static FirebaseService *instance;
    
    /// Firebaseインスタンス
    App *_app;
    
    /**
     *  インストラクタ
     */
    FirebaseService();
    
    /**
     *  インスタンス設定
     */
    static void setupInstance();
};

#endif /* FirebaseService_h */
