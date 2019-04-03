//
//  GameEventOperateVariableEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventOperateVariableEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventOperateVariableEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 変数ID
	variableId = (int)data[dataIndex] * 0x100 + (int)data[dataIndex + 1];
	dataIndex += 2;
	// 値
	value = (int)data[dataIndex];
	dataIndex += 1;
	// 操作タイプ
	operateType = static_cast<VariableOperateType>(data[dataIndex]);
	dataIndex += 1;
	
	return dataIndex;
}
