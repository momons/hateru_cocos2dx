//
//  RemoteConfigLatestVersionsEntity.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/10.
//

#ifndef RemoteConfigLatestVersionsEntity_h
#define RemoteConfigLatestVersionsEntity_h

#include "../../../../Util/picojson.h"

using namespace std;

/// RemoteConfig
class RemoteConfigLatestVersionsEntity final {
public:
    
    /**
     *  コンストラクタ
     */
    RemoteConfigLatestVersionsEntity();
    
    /**
     *  デストラクタ
     */
    ~RemoteConfigLatestVersionsEntity() {}
    
    /**
     *  シリアライズ
     *
     *  @param object JSONオブジェクト
     */
    void serialize(picojson::object &object);
    
    /**
     *  マッピング
     *
     *  @param object JSONオブジェクト
     *
     *  @return マッピング可否
     */
    bool mapping(picojson::object &object);
    
    /**
     iOSビルドバージョン getter
     */
    int ios();
    
    /**
     Androidビルドバージョン getter
     */
    int android();
    
private:
    
    /// iOSビルドバージョン
    int _ios;
    /// Androidビルドバージョン
    int _android;

};

#endif /* RemoteConfigLatestVersionsEntity_h */
