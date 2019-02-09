//
//  GameEventSelectYesNoEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventSelectYesNoEntity_h
#define GameEventSelectYesNoEntity_h

#include "GameEventBaseEntity.h"

/// イベント YESNO選択Entity
class GameEventSelectYesNoEntity final: public GameEventBaseEntity {
public:
	
	/// 返却変数Id
	int variableId;
	
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

#endif /* GameEventSelectYesNoEntity_h */
