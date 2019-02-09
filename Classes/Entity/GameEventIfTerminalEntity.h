//
//  GameEventIfTerminalEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventIfTerminalEntity_h
#define GameEventIfTerminalEntity_h

#include "GameEventBaseEntity.h"

/// イベント 機種判別Entity
class GameEventIfTerminalEntity final: public GameEventBaseEntity {
public:
	
	/// キャリアタイプ
	int careerType;
	
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

#endif /* GameEventIfTerminalEntity_h */
