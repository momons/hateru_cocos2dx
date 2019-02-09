//
//  GameEventIfSkillEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventIfSkillEntity_h
#define GameEventIfSkillEntity_h

#include "GameEventBaseEntity.h"

/// イベント 特殊技能分岐Entity
class GameEventIfSkillEntity final: public GameEventBaseEntity {
public:
	
	/// 参照キャラ
	int unitId;
	/// 参照スキル
	int skillId;
	/// 会得
	bool isLearning;
	
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

#endif /* GameEventIfSkillEntity_h */
