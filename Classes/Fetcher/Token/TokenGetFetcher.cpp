//
//  TokenGetFetcher.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/17.
//
//

#include "TokenGetFetcher.h"
#include "UrlConst.h"

/**
 *  URL取得
 *
 *  @return URL
 */
string TokenGetFetcher::url() {
	return UrlConst::domainName + "/token_get";
}

