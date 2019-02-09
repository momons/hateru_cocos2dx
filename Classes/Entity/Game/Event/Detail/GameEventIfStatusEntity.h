//
//  GameEventIfStatusEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventIfStatusEntity_h
#define GameEventIfStatusEntity_h

#include "GameEventBaseEntity.h"

/// イベント ステータス分岐Entity
class GameEventIfStatusEntity final: public GameEventBaseEntity {
public:
	
	/// 参照キャラ
	int unitId;
	/// 参照ステータス
	UnitStatusType statusType;
	/// 式
	IfFormulaType formulaType;
	/// 値
	int value;
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *
	 *  @return 使用サイズ
	 */
	int convertData(const unsigned char *data);
	
private:
};

#endif /* GameEventIfStatusEntity_h */
