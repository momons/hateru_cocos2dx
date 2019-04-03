//
//  GameEventFluctuateGoldEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventFluctuateGoldEntity_h
#define GameEventFluctuateGoldEntity_h

#include "GameEventBaseEntity.h"

/// イベント 所持金増減Entity
class GameEventFluctuateGoldEntity final: public GameEventBaseEntity {
public:
	
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

#endif /* GameEventFluctuateGoldEntity_h */
