//
//  ItemListGetMyRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef ItemListGetMyRequestEntity_h
#define ItemListGetMyRequestEntity_h

#include "BaseRequestEntity.h"

/// 自分向けアイテムリスト取得パラメータリクエストEntity
class ItemListGetMyParamsRequestEntity final: public Ref {
public:
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
	
	/**
	 *  コンストラクタ
	 */
	ItemListGetMyParamsRequestEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~ItemListGetMyParamsRequestEntity() {}
};

/// 自分向けアイテムリスト取得リクエストEntity
class ItemListGetMyRequestEntity final: public BaseRequestEntity<ItemListGetMyParamsRequestEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	ItemListGetMyRequestEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~ItemListGetMyRequestEntity() {}
};

#endif /* ItemListGetMyRequestEntity_h */
