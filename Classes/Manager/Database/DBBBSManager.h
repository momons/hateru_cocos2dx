//
//  DBBBSManager.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/08.
//

#ifndef DBBBSManager_h
#define DBBBSManager_h

#include "DBBaseManager.h"
#include "../../Entity/Database/DBBBSEntity.h"

using namespace std;

/// 掲示板データベースマネージャ
class DBBBSManager final: DBBaseManager {
public:
    
    /**
     *  コンストラクタ
     */
    DBBBSManager() {}
    
    /**
     *  デストラクタ
     */
    ~DBBBSManager() {}
    
    /**
     *  自分のセーブデータ読み込み
     *
     *  @param handler 完了ハンドラ (データ有無、セーブデータ)
     */
    void readMy(const function<void(const bool, const DBBBSEntity)> handler);
    
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
     *  @return 位置情報のリファレンス
     */
    database::DatabaseReference ref();
    
    /**
     *  自分のセーブデータのリファレンス取得
     *
     *  @return 自分のセーブデータのリファレンス
     */
    database::DatabaseReference myRef();
    
};

#endif /* DBBBSManager_h */
