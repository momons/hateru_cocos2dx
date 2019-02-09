//
//  CharaSendRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef CharaSendRequestEntity_h
#define CharaSendRequestEntity_h

#include "BaseRequestEntity.h"

/// キャラ送信パラメータリクエストEntity
class CharaSendParamsRequestEntity final: public Ref {
public:
	
	/// ステータスデータ
	string statusData;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
	
	/**
	 *  コンストラクタ
	 */
	CharaSendParamsRequestEntity();
	
	/**
	 *  デストラクタ
	 */
	~CharaSendParamsRequestEntity();
};

/// キャラ送信リクエストEntity
class CharaSendRequestEntity final: public BaseRequestEntity<CharaSendParamsRequestEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	CharaSendRequestEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~CharaSendRequestEntity() {}
};

#endif /* CharaSendRequestEntity_h */
