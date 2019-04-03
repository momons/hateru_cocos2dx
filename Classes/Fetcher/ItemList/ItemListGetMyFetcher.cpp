//
//  ItemListGetMyFetcher.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#include "ItemListGetMyFetcher.h"
#include "UrlConst.h"

/**
 *  URL取得
 *
 *  @return URL
 */
string ItemListGetMyFetcher::url() {
	return UrlConst::domainName + "/item_list_get_my";
}

/**
 *  メソッド取得
 *
 *  @return Method
 */
network::HttpRequest::Type ItemListGetMyFetcher::method() {
    return network::HttpRequest::Type::GET;
}
