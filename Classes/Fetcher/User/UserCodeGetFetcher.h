//
//  UserCodeGetFetcher.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/01.
//
//

#ifndef UserCodeGetFetcher_h
#define UserCodeGetFetcher_h

#include "BaseFetcher.h"
#include "UserCodeGetRequestEntity.h"
#include "UserCodeGetResponseEntity.h"

/// ユーザコード取得フェッチャ
class UserCodeGetFetcher final: public BaseFetcher<UserCodeGetRequestEntity, UserCodeGetResponseEntity> {
public:
	
	/**
	 *  URL取得
	 *
	 *  @return URL
	 */
	string url();
	
private:
	
};

#endif /* UserCodeGetFetcher_h */
