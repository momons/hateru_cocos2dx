//
//  DBDeviceEntity.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/18.
//

#ifndef DBDeviceEntity_h
#define DBDeviceEntity_h

#include "firebase/database.h"

using namespace std;
using namespace firebase;

/// 端末情報データベースエンティティ
class DBDeviceEntity final {
public:
    
    /**
     * コンストラクタ
     */
    DBDeviceEntity();
    
    /**
     * コンストラクタ
     *
     *  @param token Firebaseレジスタートークン
     */
    DBDeviceEntity(const string &token);
    
    /**
     * デストラクタ
     */
    ~DBDeviceEntity() {};
    
    /**
     * map<string, Variant>に変換
     *
     *  @return map<string, Variant>
     */
    map<string, Variant> toVariants();
    
    /**
     *  Firebaseレジスタートークン setter/getter
     */
    void setToken(const string &token);
    string token();
    
private:
    
    /// Firebaseレジスタートークン
    string _token;
    
};

#endif /* DBDeviceEntity_h */
