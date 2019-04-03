//
//  SaveGetResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "SaveGetResponseEntity.h"

#include "LogConst.h"
#include "PlayerEncryptEntity.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool SaveGetMetaResponseEntity::mapping(picojson::object &object) {
	if (object["saveData"].is<string>()) {
		saveData = object["saveData"].get<string>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "saveData");
		return false;
	}
	if (object["checkDigit"].is<string>()) {
		checkDigit = object["checkDigit"].get<string>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "checkDigit");
		return false;
	}
	return true;
}

/**
 *  プレイヤーEntityに変換
 *
 *  @return プレイヤーEntity
 */
PlayerEntity SaveGetMetaResponseEntity::toPlayerEntity() {

	PlayerEncryptEntity encryptEntity;
	encryptEntity.data = saveData;
	encryptEntity.checkDigit = saveData;

	return encryptEntity.toPlayerEntity();
}

/**
 *  コンストラクタ
 */
SaveGetMetaResponseEntity::SaveGetMetaResponseEntity() {
	saveData = "";
	checkDigit = "";
}

/**
 *  デストラクタ
 */
SaveGetMetaResponseEntity::~SaveGetMetaResponseEntity() {
}

