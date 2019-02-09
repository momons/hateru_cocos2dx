//
//  SaveSendResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef SaveSendResponseEntity_h
#define SaveSendResponseEntity_h

#include "BaseResponseEntity.h"

/// マイアイテム情報取得メタレスポンスEntity
class SaveSendMetaResponseEntity final: public Ref {
public:
	
	/// セーブトークン
	string saveToken;
	
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
	SaveSendMetaResponseEntity();
	
	/**
	 *  デストラクタ
	 */
	~SaveSendMetaResponseEntity();
};

/// セーブデータ送信レスポンスEntity
class SaveSendResponseEntity final: public BaseResponseEntity<SaveSendMetaResponseEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	SaveSendResponseEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~SaveSendResponseEntity() {}
};

#endif /* SaveSendResponseEntity_h */
