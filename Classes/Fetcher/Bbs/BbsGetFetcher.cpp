//
//  BbsGetFetcher.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#include "BbsGetFetcher.h"
#include "UrlConst.h"

/**
 *  URL取得
 *
 *  @return URL
 */
string BbsGetFetcher::url() {
	return UrlConst::domainName + "/bbs_get";
}

/**
 *  メソッド取得
 *
 *  @return Method
 */
network::HttpRequest::Type BbsGetFetcher::method() {
    return network::HttpRequest::Type::GET;
}

