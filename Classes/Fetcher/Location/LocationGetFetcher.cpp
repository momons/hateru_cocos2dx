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

/**
 *  メソッド取得
 *
 *  @return Method
 */
network::HttpRequest::Type LocationGetFetcher::method() {
    return network::HttpRequest::Type::GET;
}
