//
//  GameEventEncountRateEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventEncountRateEntity_h
#define GameEventEncountRateEntity_h

#include "GameEventBaseEntity.h"

/// イベント 敵出現率Entity
class GameEventEncountRateEntity final: public GameEventBaseEntity {
public:
	
	/// 敵出現率
	int encoundRate;
	
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

#endif /* GameEventEncountRateEntity_h */
