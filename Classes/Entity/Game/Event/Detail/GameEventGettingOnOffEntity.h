//
//  GameEventGettingOnOffEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventGettingOnOffEntity_h
#define GameEventGettingOnOffEntity_h

#include "GameEventBaseEntity.h"

/// イベント 船乗降りEntity
class GameEventGettingOnOffEntity final: public GameEventBaseEntity {
public:
	
	/// 乗り物タイプ
	VehicleType vehicleType;
	/// 乗り降り
	bool isGetOff;
	
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

#endif /* GameEventGettingOnOffEntity_h */
