//
//  ItemSendRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/18.
//
//

#ifndef ItemSendRequestEntity_h
#define ItemSendRequestEntity_h

#include "BaseRequestEntity.h"

/// アイテム送信パラメータリクエストEntity
class ItemSendParamsRequestEntity final: public Ref {
public:
	
	/// アイテム種類
	int itemKindIndex;
	/// 所持アイテムコード
	string itemCode;
	/// 交換希望アイテム種別
	int hopeItemKindIndex;
	/// 交換相手ユーザコード
	string partnerUserCode;
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
	ItemSendParamsRequestEntity();
	
	/**
	 *  デストラクタ
	 */
	~ItemSendParamsRequestEntity();
};

/// アイテム送信リクエストEntity
class ItemSendRequestEntity final: public BaseRequestEntity<ItemSendParamsRequestEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	ItemSendRequestEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~ItemSendRequestEntity() {}
};

#endif /* ItemSendRequestEntity_h */
