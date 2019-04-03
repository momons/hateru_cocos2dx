//
//  ItemInfoGetFetcher.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#include "ItemInfoGetFetcher.h"
#include "UrlConst.h"

/**
 *  URL取得
 *
 *  @return URL
 */
string ItemInfoGetFetcher::url() {
	return UrlConst::domainName + "/item_info_get";
}

/**
 *  メソッド取得
 *
 *  @return Method
 */
network::HttpRequest::Type ItemInfoGetFetcher::method() {
    return network::HttpRequest::Type::GET;
}
