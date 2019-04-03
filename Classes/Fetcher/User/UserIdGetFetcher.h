//
//  UserIdGetFetcher.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/01.
//
//

#ifndef UserIdGetFetcher_h
#define UserIdGetFetcher_h

#include "BaseFetcher.h"
#include "UserIdGetRequestEntity.h"
#include "UserIdGetResponseEntity.h"

/// ユーザID取得フェッチャ
class UserIdGetFetcher final: public BaseFetcher<UserIdGetRequestEntity, UserIdGetResponseEntity> {
public:
	
	/**
	 *  URL取得
	 *
	 *  @return URL
	 */
	string url();
	
    /**
     *  メソッド取得
     *
     *  @return Method
     */
    network::HttpRequest::Type method();

private:
	
};

#endif /* UserIdGetFetcher_h */
