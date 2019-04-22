//
//  ConfigManager.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/22.
//

#ifndef ConfigManager_h
#define ConfigManager_h

#include <string>

using namespace std;

/// コンフィグを読み込み/書き込みするためのマネージャ
class ConfigManager final {
public:
    
    /**
     *  インスタンスシェア
     *
     *  @return インスタンス
     */
    static ConfigManager *sharedInstance();
    
    /**
     *  デストラクタ
     */
    ~ConfigManager() {}

    /**
     *  Firebaseレジスタートークン setter/getter
     */
    void setFirebaseRegisterToken(const string &token);
    string firebaseRegisterToken();
    
private:
    
    /// インスタンス
    static ConfigManager *instance;
    
    /**
     *  インストラクタ
     */
    ConfigManager() {}
    
    /**
     *  インスタンス設定
     */
    static void setupInstance();
};

#endif /* ConfigManager_h */
