//
//  GameEventFluctuateEXPEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventFluctuateEXPEntity_h
#define GameEventFluctuateEXPEntity_h

#include "GameEventBaseEntity.h"

/// イベント 経験値増減Entity
class GameEventFluctuateEXPEntity final: public GameEventBaseEntity {
public:
	
	/// 対象
	int target;
	/// 増減タイプ
	FluctuateType fluctuateType;
	/// 値
	int value;
	
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

#endif /* GameEventFluctuateEXPEntity_h */
