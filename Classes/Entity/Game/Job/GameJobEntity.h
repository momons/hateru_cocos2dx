//
//  GameJobEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameJobEntity_h
#define GameJobEntity_h

#include <string>
#include <vector>

#include "Const/GameConst.h"
#include "GameJobSkillEntity.h"

using namespace std;

/// 職業Entity
class GameJobEntity final {
public:
	
	/// 名前
	string name;
	/// 会心率
	int criticalRate;
	/// 命中率
	int hitRate;
	/// レベルアップ時のステータス
	int statuses[ENUM_INT(AddStatusType::EXP) + 1][GameConst::maxLevel];
	/// 会得スキル情報
	vector<GameJobSkillEntity> skills;
	
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
	static GameJobEntity createEntity(const unsigned char *data);
	
private:
};

#endif /* GameJobEntity_h */
