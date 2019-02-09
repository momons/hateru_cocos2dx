//
//  ItemInfoGetFetcher.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#ifndef ItemInfoGetFetcher_h
#define ItemInfoGetFetcher_h

#include "BaseFetcher.h"
#include "ItemInfoGetRequestEntity.h"
#include "ItemInfoGetResponseEntity.h"

/// アイテム交換 アイテム情報取得フェッチャ
class ItemInfoGetFetcher final: public BaseFetcher<ItemInfoGetRequestEntity, ItemInfoGetResponseEntity> {
public:
	
	/**
	 *  URL取得
	 *
	 *  @return URL
	 */
	string url();
	
private:
	
};

#endif /* ItemInfoGetFetcher_h */
