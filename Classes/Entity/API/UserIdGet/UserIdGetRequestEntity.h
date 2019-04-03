//
//  UserIdGetRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/01.
//
//

#ifndef UserIdGetRequestEntity_h
#define UserIdGetRequestEntity_h

#include "BaseRequestEntity.h"

/// ユーザID取得パラメータリクエストEntity
class UserIdGetParamsRequestEntity final: public Ref {
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
	UserIdGetParamsRequestEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~UserIdGetParamsRequestEntity() {}
};

/// ユーザコード取得リクエストEntity
class UserIdGetRequestEntity final: public BaseRequestEntity<UserIdGetParamsRequestEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	UserIdGetRequestEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~UserIdGetRequestEntity() {}
};

#endif /* UserIdGetRequestEntity_h */
