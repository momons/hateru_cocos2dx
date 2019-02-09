//
//  CharaDeleteFetcher.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#include "CharaDeleteFetcher.h"
#include "UrlConst.h"

/**
 *  URL取得
 *
 *  @return URL
 */
string CharaDeleteFetcher::url() {
	return UrlConst::domainName + "/chara_delete";
}

