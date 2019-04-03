//
//  GameJobSkillEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameJobSkillEntity_h
#define GameJobSkillEntity_h

#include "BaseGameEntity.h"

/// 職業スキルEntity
class GameJobSkillEntity final: public BaseGameEntity {
public:
	
	/// 会得レベル
	int level;
	/// 特殊技能名
	int skillId;
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 */
	void convertData(const unsigned char *data);
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *
	 *  @return Entity
	 */
	static GameJobSkillEntity createEntity(const unsigned char *data);
	
private:
};

#endif /* GameJobSkillEntity_h */
