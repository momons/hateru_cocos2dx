//
//  CharaSendFetcher.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#include "CharaSendFetcher.h"
#include "UrlConst.h"

/**
 *  URL取得
 *
 *  @return URL
 */
string CharaSendFetcher::url() {
	return UrlConst::domainName + "/chara_send";
}

/**
 *  メソッド取得
 *
 *  @return Method
 */
network::HttpRequest::Type CharaSendFetcher::method() {
    return network::HttpRequest::Type::GET;
}

