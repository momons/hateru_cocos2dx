//
//  SaveSendRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef SaveSendRequestEntity_h
#define SaveSendRequestEntity_h

#include "BaseRequestEntity.h"

/// セーブデータ送信パラメータリクエストEntity
class SaveSendParamsRequestEntity final: public Ref {
public:
	
	/// セーブデータ
	string saveData;
	/// チェックデジット
	string checkDigit;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
	
	/**
	 *  セーブデータを読み込んで設定する
	 *
	 *  @return 読み込み可否
	 */
	bool loadAndSetting();
	
	/**
	 *  コンストラクタ
	 */
	SaveSendParamsRequestEntity();
	
	/**
	 *  デストラクタ
	 */
	~SaveSendParamsRequestEntity();
};

/// セーブデータ送信リクエストEntity
class SaveSendRequestEntity final: public BaseRequestEntity<SaveSendParamsRequestEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	SaveSendRequestEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~SaveSendRequestEntity() {}
};

#endif /* SaveSendRequestEntity_h */
