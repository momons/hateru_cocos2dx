//
//  DBCharactersManager.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/09.
//

#ifndef DBCharactersManager_h
#define DBCharactersManager_h

#include "DBBaseManager.h"

#include "Entity/Database/DBCharacterEntity.h"

using namespace std;

/// キャラクターデータベースマネージャ
class DBCharactersManager final: DBBaseManager {
public:
    
    /**
     *  コンストラクタ
     */
    DBCharactersManager() {}
    
    /**
     *  デストラクタ
     */
    ~DBCharactersManager() {}
    
    /**
     *  キャラクター読み込み
     *
     *  @param userId  ユーザーID
     *  @param handler 完了ハンドラ (データ有無、キャラクター)
     */
    void read(const string &userId, const function<void(const bool, const DBCharacterEntity)> handler);
    
    /**
     *  自分のキャラクター保存
     *
     *  @param statusData ステータスデータ
     *  @param checkDigit チェックデジット
     */
    void writeMy(const string &statusData, const string &checkDigit);
    
    /**
     *  自分のキャラクター削除
     */
    void deleteMy();
    
private:
    
    /**
     *  キャラクター情報のリファレンス取得
     *
     *  @return キャラクター情報のリファレンス
     */
    database::DatabaseReference ref();
    
    /**
     *  自分のキャラクター情報のリファレンス取得
     *
     *  @return 自分のキャラクター情報のリファレンス
     */
    database::DatabaseReference myRef();
    
};

#endif /* DBCharactersManager_h */
