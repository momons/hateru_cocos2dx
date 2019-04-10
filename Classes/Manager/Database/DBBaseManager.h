//
//  DBBaseManager.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/05.
//

#ifndef DBBaseManager_h
#define DBBaseManager_h

#include "firebase/auth.h"
#include "firebase/database.h"

using namespace std;
using namespace firebase;

/// データベースマネージャ基底クラス
class DBBaseManager {
public:
    
    /**
     *  コンストラクタ
     */
    DBBaseManager();
    
    /**
     *  デストラクタ
     */
    ~DBBaseManager() {}

protected:

    /// 最上位フィールド名
    static const string topFieldName;
    
    /// DBインスタンス
    database::Database *database;
    
private:
};

#endif /* DBBaseManager_h */
