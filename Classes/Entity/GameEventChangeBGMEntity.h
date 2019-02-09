//
//  GameEventChangeBGMEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventChangeBGMEntity_h
#define GameEventChangeBGMEntity_h

#include "GameEventBaseEntity.h"

/// イベント BGM変更Entity
class GameEventChangeBGMEntity final: public GameEventBaseEntity {
public:
	
	/// 再生
	bool play;
	/// サウンドID
	int soundId;
	/// マップ/戦闘
	SoundFieldType fieldType;
	
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

#endif /* GameEventChangeBGMEntity_h */
