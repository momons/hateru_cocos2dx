//
//  UserIdGetFetcher.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/01.
//
//

#include "UserIdGetFetcher.h"
#include "UrlConst.h"

/**
 *  URL取得
 *
 *  @return URL
 */
string UserIdGetFetcher::url() {
	return UrlConst::domainName + "/user/id";
}

/**
 *  メソッド取得
 *
 *  @return Method
 */
network::HttpRequest::Type UserIdGetFetcher::method() {
    return network::HttpRequest::Type::GET;
}
