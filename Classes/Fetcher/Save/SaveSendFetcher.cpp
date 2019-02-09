//
//  SaveSendFetcher.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#include "SaveSendFetcher.h"
#include "UrlConst.h"

/**
 *  URL取得
 *
 *  @return URL
 */
string SaveSendFetcher::url() {
	return UrlConst::domainName + "/save_send";
}

