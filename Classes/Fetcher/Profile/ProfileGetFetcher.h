//
//  ProfileGetFetcher.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#ifndef ProfileGetFetcher_h
#define ProfileGetFetcher_h

#include "BaseFetcher.h"
#include "ProfileGetRequestEntity.h"
#include "ProfileGetResponseEntity.h"

/// プロフィール取得フェッチャ
class ProfileGetFetcher final: public BaseFetcher<ProfileGetRequestEntity, ProfileGetResponseEntity> {
public:
	
	/**
	 *  URL取得
	 *
	 *  @return URL
	 */
	string url();
	
private:
	
};

#endif /* ProfileGetFetcher_h */
