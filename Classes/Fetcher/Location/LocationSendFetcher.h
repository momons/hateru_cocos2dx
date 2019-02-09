//
//  LocationSendFetcher.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#ifndef LocationSendFetcher_h
#define LocationSendFetcher_h

#include "BaseFetcher.h"
#include "LocationSendRequestEntity.h"
#include "LocationSendResponseEntity.h"

/// 位置情報 送信フェッチャ
class LocationSendFetcher final: public BaseFetcher<LocationSendRequestEntity, LocationSendResponseEntity> {
public:
	
	/**
	 *  URL取得
	 *
	 *  @return URL
	 */
	string url();
	
private:
	
};

#endif /* LocationSendFetcher_h */
