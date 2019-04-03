//
//  GameEventFluctuateMPEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventFluctuateMPEntity_h
#define GameEventFluctuateMPEntity_h

#include "GameEventBaseEntity.h"

/// イベント MP増減Entity
class GameEventFluctuateMPEntity final: public GameEventBaseEntity {
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

#endif /* GameEventFluctuateMPEntity_h */
