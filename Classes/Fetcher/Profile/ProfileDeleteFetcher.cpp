//
//  ProfileDeleteFetcher.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#include "ProfileDeleteFetcher.h"
#include "UrlConst.h"

/**
 *  URL取得
 *
 *  @return URL
 */
string ProfileDeleteFetcher::url() {
	return UrlConst::domainName + "/profile_delete";
}

/**
 *  メソッド取得
 *
 *  @return Method
 */
network::HttpRequest::Type ProfileDeleteFetcher::method() {
    return network::HttpRequest::Type::GET;
}
