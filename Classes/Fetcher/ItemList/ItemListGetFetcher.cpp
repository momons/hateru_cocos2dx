//
//  ItemListGetFetcher.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#include "ItemListGetFetcher.h"
#include "UrlConst.h"

/**
 *  URL取得
 *
 *  @return URL
 */
string ItemListGetFetcher::url() {
	return UrlConst::domainName + "/item_list_get";
}

/**
 *  メソッド取得
 *
 *  @return Method
 */
network::HttpRequest::Type ItemListGetFetcher::method() {
    return network::HttpRequest::Type::GET;
}
