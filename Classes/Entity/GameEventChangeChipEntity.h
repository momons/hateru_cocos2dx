//
//  GameEventChangeChipEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventChangeChipEntity_h
#define GameEventChangeChipEntity_h

#include "GameEventBaseEntity.h"

/// イベント マップチップ変更Entity
class GameEventChangeChipEntity final: public GameEventBaseEntity {
public:

	/// 通行禁止
	bool isNotPassWalk;
	/// 上チップ/下チップ
	bool isUpChip;
	/// チップID
	int chipId;
	/// X座標
	int x;
	/// Y座標
	int y;
	/// 船通行禁止
	bool isNotPassShip;
	/// 飛行通行禁止
	bool isNotPassFlyShip;
	
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

#endif /* GameEventChangeChipEntity_h */
