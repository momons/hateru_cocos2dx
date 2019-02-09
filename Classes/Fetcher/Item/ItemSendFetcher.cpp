//
//  ItemSendFetcher.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#include "ItemSendFetcher.h"
#include "UrlConst.h"

/**
 *  URL取得
 *
 *  @return URL
 */
string ItemSendFetcher::url() {
	return UrlConst::domainName + "/item_send";
}

