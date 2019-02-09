//
//  ItemGetFetcher.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#ifndef ItemGetFetcher_h
#define ItemGetFetcher_h

#include "BaseFetcher.h"
#include "ItemGetRequestEntity.h"
#include "ItemGetResponseEntity.h"

/// アイテム交換 アイテム取得フェッチャ
class ItemGetFetcher final: public BaseFetcher<ItemGetRequestEntity, ItemGetResponseEntity> {
public:
	
	/**
	 *  URL取得
	 *
	 *  @return URL
	 */
	string url();
	
private:
	
};

#endif /* ItemGetFetcher_h */
