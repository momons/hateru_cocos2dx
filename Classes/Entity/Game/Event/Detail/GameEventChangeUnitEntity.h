//
//  GameEventChangeUnitEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventChangeUnitEntity_h
#define GameEventChangeUnitEntity_h

#include "GameEventBaseEntity.h"

/// イベント キャラ変更Entity
class GameEventChangeUnitEntity final: public GameEventBaseEntity {
public:
	
	/// 画像使用
	bool isUseImage;
	/// キャラID
	int charaId;
	
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

#endif /* GameEventChangeUnitEntity_h */
