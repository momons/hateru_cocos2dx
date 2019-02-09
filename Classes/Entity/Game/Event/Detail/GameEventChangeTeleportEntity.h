//
//  GameEventChangeTeleportEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventChangeTeleportEntity_h
#define GameEventChangeTeleportEntity_h

#include "GameEventBaseEntity.h"

/// イベント テレポート禁止変更Entity
class GameEventChangeTeleportEntity final: public GameEventBaseEntity {
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

#endif /* GameEventChangeTeleportEntity_h */
