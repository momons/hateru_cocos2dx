//
//  UserCodeGetResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/01.
//
//

#ifndef UserCodeGetResponseEntity_h
#define UserCodeGetResponseEntity_h

#include <time.h>
#include "BaseResponseEntity.h"

/// ユーザコード取得メタレスポンスEntity
class UserCodeGetMetaResponseEntity final: public Ref {
public:
	
	/// ユーザコード
	string userCode;
	
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
	UserCodeGetMetaResponseEntity();
	
	/**
	 *  デストラクタ
	 */
	~UserCodeGetMetaResponseEntity();
};

/// トークン取得レスポンスEntity
class UserCodeGetResponseEntity final: public BaseResponseEntity<UserCodeGetMetaResponseEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	UserCodeGetResponseEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~UserCodeGetResponseEntity() {}
};

#endif /* UserCodeGetResponseEntity_h */
