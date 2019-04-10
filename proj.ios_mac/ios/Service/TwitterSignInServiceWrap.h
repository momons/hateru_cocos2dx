//
//  TwitterSignInServiceWrap.h
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/04/10.
//

using namespace std;

#ifdef __OBJC__
@class TwitterSignInService;
#else
class TwitterSignInService;
#endif

/// Twitterサインインサービスをラップするクラス
class TwitterSignInServiceWrap final {
public:
    
    /**
     *  コンストラクタ
     */
    TwitterSignInServiceWrap();
    
    /**
     *  デストラクタ
     */
    ~TwitterSignInServiceWrap() {}
    
    /**
     *  サインイン
     *
     *  @param handler 完了ハンドラ true:成功、false:失敗
     */
    void signIn(const function<void(bool)> handler);
    
private:
    
    /// Twitterサインインサービス
    TwitterSignInService *_service;
};
