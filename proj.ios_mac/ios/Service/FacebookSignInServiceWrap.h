//
//  FacebookSignInServiceWrap.h
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/10.
//

using namespace std;

#ifdef __OBJC__
@class FacebookSignInService;
#else
class FacebookSignInService;
#endif

/// Facebookサインインサービスをラップするクラス
class FacebookSignInServiceWrap final {
public:
    
    /**
     *  コンストラクタ
     */
    FacebookSignInServiceWrap();
    
    /**
     *  デストラクタ
     */
    ~FacebookSignInServiceWrap() {}
    
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
    
    /// Facebookサインインサービス
    FacebookSignInService *_service;
};
