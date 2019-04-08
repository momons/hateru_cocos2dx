//
//  DBSaveEntity.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/04/08.
//

#ifndef DBSaveEntity_h
#define DBSaveEntity_h

#include "firebase/database.h"

using namespace std;
using namespace firebase;

/// セーブデータベースエンティティ
class DBSaveEntity final {
public:
    
    /**
     * コンストラクタ
     */
    DBSaveEntity();
    
    /**
     * コンストラクタ
     *
     *  @param snapshot スナップショット
     */
    DBSaveEntity(const database::DataSnapshot *snapshot);
    
    /**
     * コンストラクタ
     *
     *  @param saveData   セーブデータ
     *  @param checkDigit チェックデジット
     */
    DBSaveEntity(const string &saveData, const string &checkDigit);

    /**
     * デストラクタ
     */
    ~DBSaveEntity() {};
    
    /**
     * map<string, Variant>に変換
     *
     *  @return map<string, Variant>
     */
    map<string, Variant> toVariants();
    
    /**
     *  セーブデータ setter/getter
     */
    void setSaveData(const string &saveData);
    string saveData();
    
    /**
     *  チェックデジット setter/getter
     */
    void setCheckDigit(const string &checkDigit);
    string checkDigit();
    
private:
    
    // セーブデータ
    string _saveData;
    /// チェックデジット
    string _checkDigit;
    
};

#endif /* DBSaveEntity_h */
