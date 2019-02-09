//
//  ItemCombackFetcher.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#ifndef ItemCombackFetcher_h
#define ItemCombackFetcher_h

#include "BaseFetcher.h"
#include "ItemCombackRequestEntity.h"
#include "ItemCombackResponseEntity.h"

/// アイテム交換 取り戻しフェッチャ
class ItemCombackFetcher final: public BaseFetcher<ItemCombackRequestEntity, ItemCombackResponseEntity> {
public:
	
	/**
	 *  URL取得
	 *
	 *  @return URL
	 */
	string url();
	
private:
	
};

#endif /* ItemCombackFetcher_h */
