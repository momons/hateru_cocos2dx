//
//  CharaGetFetcher.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#include "CharaGetFetcher.h"
#include "UrlConst.h"

/**
 *  URL取得
 *
 *  @return URL
 */
string CharaGetFetcher::url() {
	return UrlConst::domainName + "/chara_get";
}

