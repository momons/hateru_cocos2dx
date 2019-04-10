//
//  RemoteConfigService.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/10.
//

#ifndef RemoteConfigService_h
#define RemoteConfigService_h

using namespace std;

/// RemoteConfigサービスクラス
class RemoteConfigService final {
public:
    
    /**
     *  インスタンスシェア
     *
     *  @return インスタンス
     */
    static RemoteConfigService *sharedInstance();
    
    /**
     *  デストラクタ
     */
    ~RemoteConfigService() {}
    
    /**
     最新のビルドバージョン取得

     @return 最新のビルドバージョン
     */
    int latestVersions();
    
private:
    
    /// インスタンス
    static RemoteConfigService *instance;
    
    /**
     *  インストラクタ
     */
    RemoteConfigService();
    
    /**
     *  インスタンス設定
     */
    static void setupInstance();
};

#endif /* RemoteConfigService_h */
