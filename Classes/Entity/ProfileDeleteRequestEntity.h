//
//  ProfileDeleteRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef ProfileDeleteRequestEntity_h
#define ProfileDeleteRequestEntity_h

#include "BaseRequestEntity.h"

/// プロフィール削除パラメータリクエストEntity
class ProfileDeleteParamsRequestEntity final: public Ref {
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
	ProfileDeleteParamsRequestEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~ProfileDeleteParamsRequestEntity() {}
};

/// プロフィール削除リクエストEntity
class ProfileDeleteRequestEntity final: public BaseRequestEntity<ProfileDeleteParamsRequestEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	ProfileDeleteRequestEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~ProfileDeleteRequestEntity() {}
};

#endif /* ProfileDeleteRequestEntity_h */
