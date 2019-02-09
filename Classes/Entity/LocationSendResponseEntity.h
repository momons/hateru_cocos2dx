//
//  LocationSendResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef LocationSendResponseEntity_h
#define LocationSendResponseEntity_h

#include "BaseResponseEntity.h"

/// マイアイテム情報取得メタレスポンスEntity
class LocationSendMetaResponseEntity final: public Ref {
public:
	
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
	LocationSendMetaResponseEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~LocationSendMetaResponseEntity() {}
};

/// 位置情報送信レスポンスEntity
class LocationSendResponseEntity final: public BaseResponseEntity<LocationSendMetaResponseEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	LocationSendResponseEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~LocationSendResponseEntity() {}
};

#endif /* LocationSendResponseEntity_h */
