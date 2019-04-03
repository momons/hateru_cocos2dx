//
//  UserIdGetResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/01.
//
//

#ifndef UserIdGetResponseEntity_h
#define UserIdGetResponseEntity_h

#include <time.h>
#include "BaseResponseEntity.h"

/// ユーザID取得メタレスポンスEntity
class UserIdGetMetaResponseEntity final: public Ref {
public:
	
	/// ユーザID
	string userId;
	
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
	UserIdGetMetaResponseEntity();
	
	/**
	 *  デストラクタ
	 */
	~UserIdGetMetaResponseEntity();
};

/// トークン取得レスポンスEntity
class UserIdGetResponseEntity final: public BaseResponseEntity<UserIdGetMetaResponseEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	UserIdGetResponseEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~UserIdGetResponseEntity() {}
};

#endif /* UserIdGetResponseEntity_h */
