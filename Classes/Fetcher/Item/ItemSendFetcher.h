//
//  ItemSendFetcher.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#ifndef ItemSendFetcher_h
#define ItemSendFetcher_h

#include "BaseFetcher.h"
#include "ItemSendRequestEntity.h"
#include "ItemSendResponseEntity.h"

/// アイテム交換 送信フェッチャ
class ItemSendFetcher final: public BaseFetcher<ItemSendRequestEntity, ItemSendResponseEntity> {
public:
	
	/**
	 *  URL取得
	 *
	 *  @return URL
	 */
	string url();
	
private:
	
};

#endif /* ItemSendFetcher_h */
