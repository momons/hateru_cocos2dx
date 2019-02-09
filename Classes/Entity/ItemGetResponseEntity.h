//
//  ItemGetResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef ItemGetResponseEntity_h
#define ItemGetResponseEntity_h

#include "BaseResponseEntity.h"

/// アイテム取得メタレスポンスEntity
class ItemGetMetaResponseEntity final: public Ref {
public:
	
	/// アイテム種類
	int itemKindIndex;
	/// 所持アイテムコード
	string itemCode;
	
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
	ItemGetMetaResponseEntity();
	
	/**
	 *  デストラクタ
	 */
	~ItemGetMetaResponseEntity();
};

/// アイテム取得レスポンスEntity
class ItemGetResponseEntity final: public BaseResponseEntity<ItemGetMetaResponseEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	ItemGetResponseEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~ItemGetResponseEntity() {}
};

#endif /* ItemGetResponseEntity_h */
