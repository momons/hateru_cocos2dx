//
//  GameEventIfSkillEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventIfSkillEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventIfSkillEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	/// 参照キャラ
	unitId = (int)data[dataIndex];
	dataIndex += 1;
	/// 参照スキル
	skillId = (int)data[dataIndex];
	dataIndex += 1;
	/// 会得
	isLearning = data[dataIndex] != 0;
	dataIndex += 1;
	
	return dataIndex;
}
