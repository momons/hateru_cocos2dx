//
//  GameEventFluctuateItemEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventFluctuateItemEntity_h
#define GameEventFluctuateItemEntity_h

#include "GameEventBaseEntity.h"

/// イベント アイテム増減Entity
class GameEventFluctuateItemEntity final: public GameEventBaseEntity {
public:
	
	/// 増減タイプ
	FluctuateType fluctuateType;
	/// アイテムID
	int itemId;
	
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

#endif /* GameEventFluctuateItemEntity_h */
