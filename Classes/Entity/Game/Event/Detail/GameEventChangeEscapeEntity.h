//
//  GameEventChangeEscapeEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventChangeEscapeEntity_h
#define GameEventChangeEscapeEntity_h

#include "GameEventBaseEntity.h"

/// イベント エスケープ禁止変更Entity
class GameEventChangeEscapeEntity final: public GameEventBaseEntity {
public:
	
	/// 有効/無効
	bool isValid;
	
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

#endif /* GameEventChangeEscapeEntity_h */
