//
//  ProfileSendRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef ProfileSendRequestEntity_h
#define ProfileSendRequestEntity_h

#include "BaseRequestEntity.h"

#include "PlayerProfileEntity.h"

/// プロフィール送信パラメータリクエストEntity
class ProfileSendParamsRequestEntity final: public Ref {
public:
	
	/// プロフィールデータ
	string profileData;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
	
	/**
	 *  プロフィールEntityより設定
	 *
	 *  @param profileEntity プロフィールEntity
	 */
	void fromPlayerProfileEntity(PlayerProfileEntity &profileEntity);
	
	/**
	 *  コンストラクタ
	 */
	ProfileSendParamsRequestEntity();
	
	/**
	 *  デストラクタ
	 */
	~ProfileSendParamsRequestEntity();
};

/// プロフィール送信リクエストEntity
class ProfileSendRequestEntity final: public BaseRequestEntity<ProfileSendParamsRequestEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	ProfileSendRequestEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~ProfileSendRequestEntity() {}
};

#endif /* ProfileSendRequestEntity_h */
