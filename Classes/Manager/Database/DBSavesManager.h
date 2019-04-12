//
//  DBSavesManager.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/08.
//

#ifndef DBSavesManager_h
#define DBSavesManager_h

#include "DBBaseManager.h"
#include "Entity/Database/DBSaveEntity.h"

using namespace std;

/// セーブデータデータベースマネージャ
class DBSavesManager final: DBBaseManager {
public:
    
    /**
     *  コンストラクタ
     */
    DBSavesManager() {}
    
    /**
     *  デストラクタ
     */
    ~DBSavesManager() {}
    
    /**
     *  自分のセーブデータ読み込み
     *
     *  @param handler 完了ハンドラ (データ有無、セーブデータ)
     */
    void readMy(const function<void(const bool, const DBSaveEntity)> handler);
    
    /**
     *  自分のセーブデータ保存
     *
     *  @param saveData   セーブデータ
     *  @param checkDigit チェックデジット
     */
    void writeMy(const string &saveData, const string &checkDigit);
    
    /**
     *  自分のセーブデータ削除
     */
    void deleteMy();
    
private:
    
    /**
     *  セーブデータのリファレンス取得
     *
     *  @return セーブデータのリファレンス
     */
    database::DatabaseReference ref();
    
    /**
     *  自分のセーブデータのリファレンス取得
     *
     *  @return 自分のセーブデータのリファレンス
     */
    database::DatabaseReference myRef();
    
};

#endif /* DBSavesManager_h */
