//
//  UserCodeGetRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/01.
//
//

#ifndef UserCodeGetRequestEntity_h
#define UserCodeGetRequestEntity_h

#include "BaseRequestEntity.h"

/// ユーザコード取得パラメータリクエストEntity
class UserCodeGetParamsRequestEntity final: public Ref {
public:
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
	
	/**
	 *  コンストラクタ
	 */
	UserCodeGetParamsRequestEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~UserCodeGetParamsRequestEntity() {}
};

/// ユーザコード取得リクエストEntity
class UserCodeGetRequestEntity final: public BaseRequestEntity<UserCodeGetParamsRequestEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	UserCodeGetRequestEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~UserCodeGetRequestEntity() {}
};

#endif /* UserCodeGetRequestEntity_h */
