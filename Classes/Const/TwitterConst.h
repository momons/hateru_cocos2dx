//
//  TwitterConst.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/10.
//

#ifndef TwitterConst_h
#define TwitterConst_h

#include <stdio.h>

using namespace std;

/// Twitter定数定義クラス
class TwitterConst final {
public:
    
    /// コンシューマキー
    static const string consumerKey;
    /// コンシューマサークレット
    static const string consumerSecret;

private:
    
    /**
     *  コンストラクタ
     */
    TwitterConst() {}
    
    /**
     *  デストラクタ
     */
    ~TwitterConst() {}
};

#endif /* TwitterConst_h */
