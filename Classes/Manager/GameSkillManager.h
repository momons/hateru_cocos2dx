//
//  GameSkillManager.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameSkillManager_h
#define GameSkillManager_h

#include "BaseManager.h"
#include "GameSkillEntity.h"

/// ゲームスキルマネージャ
class GameSkillManager final: BaseManager {
public:
	
	/**
	 *  読み込み
	 *
	 *  @return 取得データ
	 */
	static map<int, GameSkillEntity> load();
	
private:
	
	/**
	 *  コンストラクタ
	 */
	GameSkillManager() {}
	
	/**
	 *  デストラクタ
	 */
	~GameSkillManager() {}
};

#endif /* GameSkillManager_h */
