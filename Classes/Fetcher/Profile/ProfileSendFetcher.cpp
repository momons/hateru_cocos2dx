//
//  ProfileSendFetcher.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#include "ProfileSendFetcher.h"
#include "UrlConst.h"

/**
 *  URL取得
 *
 *  @return URL
 */
string ProfileSendFetcher::url() {
	return UrlConst::domainName + "/profile_send";
}

