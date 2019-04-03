//
//  GameEventBattleEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventBattleEntity_h
#define GameEventBattleEntity_h

#include "GameEventBaseEntity.h"

/// イベント 戦闘Entity
class GameEventBattleEntity final: public GameEventBaseEntity {
public:
	
	/// 結果退避変数Id
	int variableId;
	/// 敵Id
	vector<int> enemyIds;
	
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

#endif /* GameEventBattleEntity_h */
