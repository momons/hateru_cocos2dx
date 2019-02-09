//
//  UrlConst.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/17.
//
//

#include "UrlConst.h"

#if COCOS2D_DEBUG

const string UrlConst::domainName = "https://nikuqx.com/hateru";

#elif LOCALHOST

const string UrlConst::domainName = "http://localhost";

#else

const string UrlConst::domainName = "http://nikuqx.com/hateru";

#endif
