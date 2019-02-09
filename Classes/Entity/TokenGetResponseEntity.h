//
//  TokenGetResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/18.
//
//

#ifndef TokenGetResponseEntity_h
#define TokenGetResponseEntity_h

#include <time.h>
#include "BaseResponseEntity.h"

/// トークン取得メタレスポンスEntity
class TokenGetMetaResponseEntity final: public Ref {
public:
	
	/// トークン
	string accessToken;
	
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
	TokenGetMetaResponseEntity();
	
	/**
	 *  デストラクタ
	 */
	~TokenGetMetaResponseEntity();
};

/// トークン取得レスポンスEntity
class TokenGetResponseEntity final: public BaseResponseEntity<TokenGetMetaResponseEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	TokenGetResponseEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~TokenGetResponseEntity() {}
};

#endif /* TokenGetResponseEntity_h */
