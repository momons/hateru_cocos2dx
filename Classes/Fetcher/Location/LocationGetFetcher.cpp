//
//  LocationGetFetcher.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#include "LocationGetFetcher.h"
#include "UrlConst.h"

/**
 *  URL取得
 *
 *  @return URL
 */
string LocationGetFetcher::url() {
	return UrlConst::domainName + "/location_get";
}

