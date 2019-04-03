//
//  SaveSendRequestEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "SaveSendRequestEntity.h"

#include "PlayerManager.h"

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void SaveSendParamsRequestEntity::serialize(picojson::object &object) {
	object.insert(make_pair("saveData", picojson::value(saveData)));
	object.insert(make_pair("checkDigit", picojson::value(checkDigit)));
}

/**
 *  セーブデータを読み込んで設定する
 *
 *  @return 読み込み可否
 */
bool SaveSendParamsRequestEntity::loadAndSetting() {
	// 暗号化データ読み込み
	auto entity = PlayerManager::loadEncrypt();
	if (!entity.isValid) {
		return false;
	}

	saveData = entity.data;
	checkDigit = entity.checkDigit;
	
	return true;
}

/**
 *  コンストラクタ
 */
SaveSendParamsRequestEntity::SaveSendParamsRequestEntity() {
	saveData = "";
	checkDigit = "";
}

/**
 *  デストラクタ
 */
SaveSendParamsRequestEntity::~SaveSendParamsRequestEntity() {
}

