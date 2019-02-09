//
//  ProfileSendFetcher.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#ifndef ProfileSendFetcher_h
#define ProfileSendFetcher_h

#include "BaseFetcher.h"
#include "ProfileSendRequestEntity.h"
#include "ProfileSendResponseEntity.h"

/// プロフィール送信フェッチャ
class ProfileSendFetcher final: public BaseFetcher<ProfileSendRequestEntity, ProfileSendResponseEntity> {
public:
	
	/**
	 *  URL取得
	 *
	 *  @return URL
	 */
	string url();
	
private:
	
};

#endif /* ProfileSendFetcher_h */
