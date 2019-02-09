//
//  GameEventMoveLocationEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventMoveLocationEntity_h
#define GameEventMoveLocationEntity_h

#include "GameEventBaseEntity.h"

/// イベント 場所移動Entity
class GameEventMoveLocationEntity final: public GameEventBaseEntity {
public:
	
	/// マップID
	int mapId;
	/// X座標
	int x;
	/// Y座標
	int y;
	
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

#endif /* GameEventMoveLocationEntity_h */
