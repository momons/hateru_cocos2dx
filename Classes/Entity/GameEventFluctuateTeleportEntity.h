//
//  GameEventFluctuateTeleportEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventFluctuateTeleportEntity_h
#define GameEventFluctuateTeleportEntity_h

#include "GameEventBaseEntity.h"

/// イベント テレポート位置増減Entity
class GameEventFluctuateTeleportEntity final: public GameEventBaseEntity {
public:
	
	/// 削除フラグ
	bool isRemove;
	/// 表示名
	string name;
	/// 対象マップId
	int mapId;
	/// マップId 歩行/船/飛行船
	vector<int> jumpMapIds;
	/// X座標 歩行/船/飛行船
	vector<int> jumpXs;
	/// Y座標 歩行/船/飛行船
	vector<int> jumpYs;
	
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

#endif /* GameEventFluctuateTeleportEntity_h */
