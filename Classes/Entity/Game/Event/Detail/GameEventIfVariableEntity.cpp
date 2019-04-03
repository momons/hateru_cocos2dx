//
//  GameEventIfVariableEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventIfVariableEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventIfVariableEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 変数ID
	variableId = (int)data[dataIndex] * 0x100 + (int)data[dataIndex + 1];
	dataIndex += 2;
	// X座標
	formulaType = static_cast<IfFormulaType>(data[dataIndex]);
	dataIndex += 1;
	// Y座標
	value = (int)data[dataIndex];
	dataIndex += 1;
	
	return dataIndex;
}
