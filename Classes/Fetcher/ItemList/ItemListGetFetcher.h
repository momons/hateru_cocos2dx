//
//  ItemListGetFetcher.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#ifndef ItemListGetFetcher_h
#define ItemListGetFetcher_h

#include "BaseFetcher.h"
#include "ItemListGetRequestEntity.h"
#include "ItemListGetResponseEntity.h"

/// アイテム交換 アイテムリスト取得フェッチャ
class ItemListGetFetcher final: public BaseFetcher<ItemListGetRequestEntity, ItemListGetResponseEntity> {
public:
	
	/**
	 *  URL取得
	 *
	 *  @return URL
	 */
	string url();
	
private:

};

#endif /* ItemListGetFetcher_h */
