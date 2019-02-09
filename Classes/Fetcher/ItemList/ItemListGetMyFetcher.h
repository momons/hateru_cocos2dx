//
//  ItemListGetMyFetcher.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#ifndef ItemListGetMyFetcher_h
#define ItemListGetMyFetcher_h

#include "BaseFetcher.h"
#include "ItemListGetMyRequestEntity.h"
#include "ItemListGetMyResponseEntity.h"

/// アイテム交換 アイテムリスト取得フェッチャ
class ItemListGetMyFetcher final: public BaseFetcher<ItemListGetMyRequestEntity, ItemListGetMyResponseEntity> {
public:
	
	/**
	 *  URL取得
	 *
	 *  @return URL
	 */
	string url();
	
private:
	
};

#endif /* ItemListGetMyFetcher_h */
