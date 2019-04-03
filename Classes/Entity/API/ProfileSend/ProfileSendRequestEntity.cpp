//
//  ProfileSendRequestEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "ProfileSendRequestEntity.h"

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void ProfileSendParamsRequestEntity::serialize(picojson::object &object) {
	object.insert(make_pair("profileData", picojson::value(profileData)));
}

/**
 *  プロフィールEntityより設定
 *
 *  @param profileEntity プロフィールEntity
 */
void ProfileSendParamsRequestEntity::fromPlayerProfileEntity(PlayerProfileEntity &profileEntity) {
	// JSONにシリアライズ
	picojson::object object;
	profileEntity.serialize(object);
	picojson::value val(object);
	// 設定
	profileData = val.serialize();
}

/**
 *  コンストラクタ
 */
ProfileSendParamsRequestEntity::ProfileSendParamsRequestEntity() {
	profileData = "";
}

/**
 *  デストラクタ
 */
ProfileSendParamsRequestEntity::~ProfileSendParamsRequestEntity() {
}

