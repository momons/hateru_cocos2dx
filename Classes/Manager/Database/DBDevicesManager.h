//
//  DBDevicesManager.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/18.
//

#ifndef DBDevicesManager_h
#define DBDevicesManager_h

#include "DBBaseManager.h"
#include "Entity/Database/DBDeviceEntity.h"

using namespace std;

/// 端末情報データベースマネージャ
class DBDevicesManager final: DBBaseManager {
public:
    
    /**
     *  コンストラクタ
     */
    DBDevicesManager() {}
    
    /**
     *  デストラクタ
     */
    ~DBDevicesManager() {}
    
    /**
     *  端末情報を追加する
     *
     *  @param token Firebaseレジスタートークン
     */
    void writeMy(const string &token);
    
private:
    
    /**
     *  端末情報のリファレンス取得
     *
     *  @return 端末情報のリファレンス
     */
    database::DatabaseReference ref();
    
    /**
     *  自分の端末情報のリファレンス取得
     *
     *  @return 自分の端末情報のリファレンス
     */
    database::DatabaseReference myRef();
    
};

#endif /* DBDevicesManager_h */
