//
//  LocationGetResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef LocationGetResponseEntity_h
#define LocationGetResponseEntity_h

#include "BaseResponseEntity.h"

/// 位置情報取得メタ詳細レスポンスEntity
class LocationGetMetaDetailResponseEntity final: public Ref {
public:
	
	/// 位置情報群
	string userCode;
	/// 位置情報群
	string userName;
	/// 位置情報群
	string message;
	/// 位置情報群
	int mapIndex;
	/// 位置情報群
	int x;
	/// 位置情報群
	int y;
	/// 位置情報群
	string otherInfos;
	
	/**
	 *  マッピング
	 *
	 *  @param object JSONオブジェクト
	 *
	 *  @return マッピング可否
	 */
	bool mapping(picojson::object &object);
	
	/**
	 *  コンストラクタ
	 */
	LocationGetMetaDetailResponseEntity();
	
	/**
	 *  デストラクタ
	 */
	~LocationGetMetaDetailResponseEntity();
};

/// 位置情報取得メタレスポンスEntity
class LocationGetMetaResponseEntity final: public Ref {
public:
	
	/// 位置情報群
	vector<LocationGetMetaDetailResponseEntity> locations;
	
	/**
	 *  マッピング
	 *
	 *  @param object JSONオブジェクト
	 *
	 *  @return マッピング可否
	 */
	bool mapping(picojson::object &object);
	
	/**
	 *  コンストラクタ
	 */
	LocationGetMetaResponseEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~LocationGetMetaResponseEntity() {}
};

/// 位置情報取得レスポンスEntity
class LocationGetResponseEntity final: public BaseResponseEntity<LocationGetMetaResponseEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	LocationGetResponseEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~LocationGetResponseEntity() {}
};

#endif /* LocationGetResponseEntity_h */
