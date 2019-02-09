//
//  ItemCombackFetcher.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#include "ItemCombackFetcher.h"
#include "UrlConst.h"

/**
 *  URL取得
 *
 *  @return URL
 */
string ItemCombackFetcher::url() {
	return UrlConst::domainName + "/item_comeback";
}

