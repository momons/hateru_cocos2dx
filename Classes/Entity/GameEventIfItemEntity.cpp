//
//  GameEventIfItemEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventIfItemEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventIfItemEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	/// 参照キャラ
	unitId = (int)data[dataIndex];
	dataIndex += 1;
	/// 参照ステータス
	itemId = (int)data[dataIndex];
	dataIndex += 1;
	/// 式
	formulaType = static_cast<IfFormulaType>(data[dataIndex]);
	dataIndex += 1;
	/// 値
	value = (int)data[dataIndex];
	dataIndex += 1;
	
	return dataIndex;
}
