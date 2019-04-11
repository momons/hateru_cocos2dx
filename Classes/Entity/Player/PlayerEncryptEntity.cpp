//
//  PlayerEncryptionEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/19.
//
//

#include "PlayerEncryptEntity.h"

#include "../../Const/LogConst.h"
#include "../../Util/JsonUtil.h"
#include "../../Util/EncryptUtil.h"
#include "../../Entity/Player/PlayerEntity.h"

/**
 *  コンストラクタ
 */
PlayerEncryptEntity::PlayerEncryptEntity() {
	isValid = false;
	data = "";
	checkDigit = "";
}

/**
 *  デストラクタ
 */
PlayerEncryptEntity::~PlayerEncryptEntity() {
}

/**
 *  PlayerEntityを暗号化し設定する
 *
 *  @param playerEntity PlayerEntity
 */
void PlayerEncryptEntity::setPlayerEntity(PlayerEntity &playerEntity) {
	
	// JSONにシリアライズ
	picojson::object object;
	playerEntity.serialize(object);
	picojson::value val(object);

	// チェックデジット取得
	checkDigit = EncryptUtil::hash(val.serialize());
	
	// 暗号化
	data = EncryptUtil::encrypt(val.serialize());
}

/**
 *  復号化しPlayerEntityにする
 *
 *  @return PlayerEntity
 */
PlayerEntity PlayerEncryptEntity::toPlayerEntity() {
	
	// 復号化
	auto decryptStr = EncryptUtil::decrypt(data);
	if (decryptStr.empty()) {
		log(LogConst::decryptError.c_str(), data.c_str());
		return PlayerEntity();
	}
	
	// チェックデジットチェック
	if (checkDigit.compare(EncryptUtil::hash(decryptStr)) != 0) {
		log(LogConst::checkDigitError.c_str(), checkDigit.c_str());
		return PlayerEntity();
	}
	
	// JSON変換
	string error;
	picojson::value jsonValue;
	JsonUtil::jsonParse(&jsonValue, &error, decryptStr);
	if(!error.empty()){
		log(LogConst::jsonParseError.c_str(), error.c_str());
		return PlayerEntity();
	}

	// マッピング
	PlayerEntity entity;
	auto isSuccess = entity.mapping(jsonValue.get<picojson::object>());
	if (!isSuccess) {
		return PlayerEntity();
	}
	
	// 有効フラグON
	entity.isValid = true;

	return entity;
}

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void PlayerEncryptEntity::serialize(picojson::object &object) {
	object.insert(make_pair("data", picojson::value(data)));
	object.insert(make_pair("checkDigit", picojson::value(checkDigit)));
}

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool PlayerEncryptEntity::mapping(picojson::object &object) {
	if (object["data"].is<string>()) {
		data = object["data"].get<string>();
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "data");
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
