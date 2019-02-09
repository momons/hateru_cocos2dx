//
//  CharaGetResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef CharaGetResponseEntity_h
#define CharaGetResponseEntity_h

#include "BaseResponseEntity.h"

/// マイアイテム情報取得メタレスポンスEntity
class CharaGetMetaResponseEntity final: public Ref {
public:
	
	/// ユーザコード
	string userCode;
	/// ユーザ名
	string userName;
	/// ステータスデータ
	string statusData;
	
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
	CharaGetMetaResponseEntity();
	
	/**
	 *  デストラクタ
	 */
	~CharaGetMetaResponseEntity();
};

/// キャラ取得レスポンスEntity
class CharaGetResponseEntity final: public BaseResponseEntity<CharaGetMetaResponseEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	CharaGetResponseEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~CharaGetResponseEntity() {}
};

#endif /* CharaGetResponseEntity_h */
