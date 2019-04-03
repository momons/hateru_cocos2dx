//
//  ItemCombackRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/18.
//
//

#ifndef ItemCombackRequestEntity_h
#define ItemCombackRequestEntity_h

#include "BaseRequestEntity.h"

/// アイテム取り戻しパラメータリクエストEntity
class ItemCombackParamsRequestEntity final: public Ref {
public:
	
	/// 交換トークン
	string exchangeToken;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
	
	/**
	 *  コンストラクタ
	 */
	ItemCombackParamsRequestEntity();
	
	/**
	 *  デストラクタ
	 */
	~ItemCombackParamsRequestEntity();
};

/// アイテム削除リクエストEntity
class ItemCombackRequestEntity final: public BaseRequestEntity<ItemCombackParamsRequestEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	ItemCombackRequestEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~ItemCombackRequestEntity() {}
};

#endif /* ItemCombackRequestEntity_h */
