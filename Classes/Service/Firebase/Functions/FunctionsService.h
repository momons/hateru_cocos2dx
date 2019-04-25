//
//  FunctionsService.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/24.
//

#ifndef FunctionsService_h
#define FunctionsService_h

#include "firebase/functions.h"

using namespace std;
using namespace firebase;

/// 関数コールサービスクラス
class FunctionsService final {
public:
    
    /**
     *  インスタンスシェア
     *
     *  @return インスタンス
     */
    static FunctionsService *sharedInstance();
    
    /**
     *  デストラクタ
     */
    ~FunctionsService() {}
    
    /**
     *  掲示板にメッセージ追加
     *
     *  @param bbsId    掲示板ID
     *  @param username ユーザー名
     *  @param message  メッセージ
     *  @param handler  完了ハンドラ (正常可否)
     */
    void bbsAddMessage(const string &bbsId, const string &username, const string &message, const function<void(const bool)> handler);
    
    /**
     *  掲示板のメッセージ更新
     *
     *  @param bbsId     掲示板ID
     *  @param messageId メッセージID
     *  @param username  ユーザー名
     *  @param message   メッセージ
     *  @param handler   完了ハンドラ (正常可否)
     */
    void bbsUpdateMessage(const string &bbsId, const string &messageId, const string &username, const string &message, const function<void(const bool)> handler);
    
    /**
     *  掲示板のメッセージ削除
     *
     *  @param bbsId     掲示板ID
     *  @param messageId メッセージID
     *  @param handler   完了ハンドラ (正常可否)
     */
    void bbsRemoveMessage(const string &bbsId, const string &messageId, const function<void(const bool)> handler);

private:
    
    /// インスタンス
    static FunctionsService *instance;
    
    /// 関数インスタンス
    functions::Functions *_functions;
    
    /**
     *  インストラクタ
     */
    FunctionsService();
    
    /**
     *  インスタンス設定
     */
    static void setupInstance();
};

#endif /* FunctionsService_h */
