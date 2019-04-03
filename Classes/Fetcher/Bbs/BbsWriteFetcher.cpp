//
//  BbsWriteFetcher.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#include "BbsWriteFetcher.h"
#include "UrlConst.h"

/**
 *  URL取得
 *
 *  @return URL
 */
string BbsWriteFetcher::url() {
	return UrlConst::domainName + "/bbs_write";
}

/**
 *  メソッド取得
 *
 *  @return Method
 */
network::HttpRequest::Type BbsWriteFetcher::method() {
    return network::HttpRequest::Type::GET;
}

