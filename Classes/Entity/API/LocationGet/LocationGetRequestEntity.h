//
//  LocationGetRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef LocationGetRequestEntity_h
#define LocationGetRequestEntity_h

#include "BaseRequestEntity.h"

/// 位置情報取得パラメータリクエストEntity
class LocationGetParamsRequestEntity final: public Ref {
public:
	
	/// マップインデックス
	int mapIndex;
	/// X座標
	int x;
	/// Y座標
	int y;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
	
	/**
	 *  コンストラクタ
	 */
	LocationGetParamsRequestEntity();
	
	/**
	 *  デストラクタ
	 */
	~LocationGetParamsRequestEntity();
};

/// 位置情報取得リクエストEntity
class LocationGetRequestEntity final: public BaseRequestEntity<LocationGetParamsRequestEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	LocationGetRequestEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~LocationGetRequestEntity() {}
};

#endif /* LocationGetRequestEntity_h */
