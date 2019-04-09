//
//  DBCharacterEntity.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/08.
//

#ifndef DBCharacterEntity_h
#define DBCharacterEntity_h

#include "firebase/database.h"

using namespace std;
using namespace firebase;

/// キャラクターデータベースエンティティ
class DBCharacterEntity final {
public:
    
    /**
     * コンストラクタ
     */
    DBCharacterEntity();
    
    /**
     * コンストラクタ
     *
     *  @param snapshot スナップショット
     */
    DBCharacterEntity(const database::DataSnapshot *snapshot);
    
    /**
     * コンストラクタ
     *
     *  @param saveData   セーブデータ
     *  @param checkDigit チェックデジット
     */
    DBCharacterEntity(const string &saveData, const string &checkDigit);
    
    /**
     * デストラクタ
     */
    ~DBCharacterEntity() {};
    
    /**
     * map<string, Variant>に変換
     *
     *  @return map<string, Variant>
     */
    map<string, Variant> toVariants();
    
    /**
     *  ステータスデータ setter/getter
     */
    void setStatusData(const string &statusData);
    string statusData();
    
    /**
     *  チェックデジット setter/getter
     */
    void setCheckDigit(const string &checkDigit);
    string checkDigit();

private:
    
    /// ステータスデータ
    string _statusData;
    /// チェックデジット
    string _checkDigit;
    
};

#endif /* DBCharacterEntity_h */
