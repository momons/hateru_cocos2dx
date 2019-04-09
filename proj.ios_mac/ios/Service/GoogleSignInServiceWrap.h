//
//  GoogleSignInServiceWrap.h
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/09.
//

using namespace std;

#ifdef __OBJC__
@class GoogleSignInService;
#else
class GoogleSignInService;
#endif

/// Googleサインインサービスをラップするクラス
class GoogleSignInServiceWrap final {
public:
    
    /**
     *  コンストラクタ
     */
    GoogleSignInServiceWrap();
    
    /**
     *  デストラクタ
     */
    ~GoogleSignInServiceWrap() {}
    
    /**
     *  サインイン
     *
     *  @param handler 完了ハンドラ true:成功、false:失敗
     */
    void signIn(const function<void(bool)> handler);
    
    /**
     *  サインアウト
     */
    void signOut();
    
private:
    
    // Googleサインインサービス
    GoogleSignInService *_service;
};
