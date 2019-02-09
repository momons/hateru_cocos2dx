//
//  ItemGetFetcher.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#include "ItemGetFetcher.h"
#include "UrlConst.h"

/**
 *  URL取得
 *
 *  @return URL
 */
string ItemGetFetcher::url() {
	return UrlConst::domainName + "/item_get";
}

