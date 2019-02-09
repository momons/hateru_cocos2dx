//
//  TokenGetFetcher.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/17.
//
//

#ifndef TokenGetFetcher_h
#define TokenGetFetcher_h

#include "BaseFetcher.h"
#include "TokenGetRequestEntity.h"
#include "TokenGetResponseEntity.h"

/// トークン取得フェッチャ
class TokenGetFetcher final: public BaseFetcher<TokenGetRequestEntity, TokenGetResponseEntity> {
public:
	
	/**
	 *  URL取得
	 *
	 *  @return URL
	 */
	string url();
	
private:

};


#endif /* TokenGetFetcher_hpp */
