//
//  GameEventRandomEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventRandomEntity_h
#define GameEventRandomEntity_h

#include "GameEventBaseEntity.h"

/// イベント 乱数Entity
class GameEventRandomEntity final: public GameEventBaseEntity {
public:
	
	/// 退避変数
	int variableId;
	/// 範囲From
	int from;
	/// 範囲To
	int to;
	
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

#endif /* GameEventRandomEntity_h */
