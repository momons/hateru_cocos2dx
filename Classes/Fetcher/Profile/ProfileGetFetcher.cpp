//
//  ProfileGetFetcher.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#include "ProfileGetFetcher.h"
#include "UrlConst.h"

/**
 *  URL取得
 *
 *  @return URL
 */
string ProfileGetFetcher::url() {
	return UrlConst::domainName + "/profile_get";
}

/**
 *  メソッド取得
 *
 *  @return Method
 */
network::HttpRequest::Type ProfileGetFetcher::method() {
    return network::HttpRequest::Type::GET;
}
