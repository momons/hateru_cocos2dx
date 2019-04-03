//
//  ItemGetRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef ItemGetRequestEntity_h
#define ItemGetRequestEntity_h

#include "BaseRequestEntity.h"

/// アイテム取得パラメータリクエストEntity
class ItemGetParamsRequestEntity final: public Ref {
public:
	
	/// 交換相手ユーザコード
	string userCode;
	/// 交換トークン
	string exchangeToken;
	/// 交換パスワード
	string password;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
	
	/**
	 *  コンストラクタ
	 */
	ItemGetParamsRequestEntity();
	
	/**
	 *  デストラクタ
	 */
	~ItemGetParamsRequestEntity();
};

/// マイアイテム情報取得リクエストEntity
class ItemGetRequestEntity final: public BaseRequestEntity<ItemGetParamsRequestEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	ItemGetRequestEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~ItemGetRequestEntity() {}
};

#endif /* ItemGetRequestEntity_h */
