//
//  ProfileGetRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef ProfileGetRequestEntity_h
#define ProfileGetRequestEntity_h

#include "BaseRequestEntity.h"

/// プロフィール取得パラメータリクエストEntity
class ProfileGetParamsRequestEntity final: public Ref {
public:
	
	/// ユーザコード
	string userCode;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
	
	/**
	 *  コンストラクタ
	 */
	ProfileGetParamsRequestEntity();
	
	/**
	 *  デストラクタ
	 */
	~ProfileGetParamsRequestEntity();
};

/// プロフィール取得リクエストEntity
class ProfileGetRequestEntity final: public BaseRequestEntity<ProfileGetParamsRequestEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	ProfileGetRequestEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~ProfileGetRequestEntity() {}
};

#endif /* ProfileGetRequestEntity_h */
