//
//  LocationGetFetcher.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#ifndef LocationGetFetcher_h
#define LocationGetFetcher_h

#include "BaseFetcher.h"
#include "LocationGetRequestEntity.h"
#include "LocationGetResponseEntity.h"

/// 位置情報 取得フェッチャ
class LocationGetFetcher final: public BaseFetcher<LocationGetRequestEntity, LocationGetResponseEntity> {
public:
	
	/**
	 *  URL取得
	 *
	 *  @return URL
	 */
	string url();
	
private:
	
};

#endif /* LocationGetFetcher_h */
