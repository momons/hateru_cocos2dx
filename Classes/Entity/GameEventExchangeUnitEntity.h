//
//  GameEventExchangeUnitEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventExchangeUnitEntity_h
#define GameEventExchangeUnitEntity_h

#include "GameEventBaseEntity.h"

/// イベント メンバー入替Entity
class GameEventExchangeUnitEntity final: public GameEventBaseEntity {
public:
	
	/// 入替タイプ
	ExchangeUnitType exchangeType;
	/// 外すキャラId
	int removeCharaId;
	/// 追加キャラId
	int addCharaId;
	
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

#endif /* GameEventExchangeUnitEntity_h */
