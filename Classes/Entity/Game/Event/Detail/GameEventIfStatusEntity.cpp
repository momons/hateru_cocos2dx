//
//  GameEventIfStatusEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventIfStatusEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventIfStatusEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	/// 参照キャラ
	unitId = (int)data[dataIndex];
	dataIndex += 1;
	/// 参照ステータス
	statusType = static_cast<UnitStatusType>(data[dataIndex]);
	dataIndex += 1;
	/// 式
	formulaType = static_cast<IfFormulaType>(data[dataIndex]);
	dataIndex += 1;
	/// 値
	value = (int)data[dataIndex] * 0x100 + (int)data[dataIndex + 1];
	dataIndex += 2;
	
	return dataIndex;
}
