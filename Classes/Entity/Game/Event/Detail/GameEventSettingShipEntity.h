//
//  GameEventSettingShipEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventSettingShipEntity_h
#define GameEventSettingShipEntity_h

#include "GameEventBaseEntity.h"

/// イベント 船設定Entity
class GameEventSettingShipEntity final: public GameEventBaseEntity {
public:
	
	/// 乗り物タイプ
	VehicleType vehicleType;
	/// 表示/非表示
	bool isShow;
	/// マップId
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

#endif /* GameEventSettingShipEntity_h */
