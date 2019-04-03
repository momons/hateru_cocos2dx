//
//  CharaGetRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef CharaGetRequestEntity_h
#define CharaGetRequestEntity_h

#include "BaseRequestEntity.h"

/// キャラ取得パラメータリクエストEntity
class CharaGetParamsRequestEntity final: public Ref {
public:
	
	/// ユーザコード
	string userCode;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
	
	/**
	 *  コンストラクタ
	 */
	CharaGetParamsRequestEntity();
	
	/**
	 *  デストラクタ
	 */
	~CharaGetParamsRequestEntity();
};

/// キャラ取得リクエストEntity
class CharaGetRequestEntity final: public BaseRequestEntity<CharaGetParamsRequestEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	CharaGetRequestEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~CharaGetRequestEntity() {}
};

#endif /* CharaGetRequestEntity_h */
