//
//  LocationSendFetcher.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#include "LocationSendFetcher.h"
#include "UrlConst.h"

/**
 *  URL取得
 *
 *  @return URL
 */
string LocationSendFetcher::url() {
	return UrlConst::domainName + "/location_send";
}

