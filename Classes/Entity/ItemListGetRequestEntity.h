//
//  ItemListGetRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef ItemListGetRequestEntity_h
#define ItemListGetRequestEntity_h

#include "BaseRequestEntity.h"

/// アイテムリスト取得パラメータリクエストEntity
class ItemListGetParamsRequestEntity final: public Ref {
public:
	
	/// 交換タイプ
	string exchangeType;
	/// アイテム種類
	int itemKindIndex;
	/// 希望アイテム種類
	int hopeItemKindIndex;
	/// 取得オフセット
	int offset;
	/// 取得数
	int count;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
	
	/**
	 *  コンストラクタ
	 */
	ItemListGetParamsRequestEntity();
	
	/**
	 *  デストラクタ
	 */
	~ItemListGetParamsRequestEntity();
};

/// マイアイテム情報取得リクエストEntity
class ItemListGetRequestEntity final: public BaseRequestEntity<ItemListGetParamsRequestEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	ItemListGetRequestEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~ItemListGetRequestEntity() {}
};

#endif /* ItemListGetRequestEntity_h */
