//
//  SaveGetFetcher.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#include "SaveGetFetcher.h"
#include "UrlConst.h"

/**
 *  URL取得
 *
 *  @return URL
 */
string SaveGetFetcher::url() {
	return UrlConst::domainName + "/save_get";
}

