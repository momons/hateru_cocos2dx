//
//  ProfileSendResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef ProfileSendResponseEntity_h
#define ProfileSendResponseEntity_h

#include "BaseResponseEntity.h"

/// マイアイテム情報取得メタレスポンスEntity
class ProfileSendMetaResponseEntity final: public Ref {
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
	ProfileSendMetaResponseEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~ProfileSendMetaResponseEntity() {}
};

/// プロフィール送信レスポンスEntity
class ProfileSendResponseEntity final: public BaseResponseEntity<ProfileSendMetaResponseEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	ProfileSendResponseEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~ProfileSendResponseEntity() {}
};

#endif /* ProfileSendResponseEntity_h */
