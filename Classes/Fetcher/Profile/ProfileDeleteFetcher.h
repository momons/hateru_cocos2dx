//
//  ProfileDeleteFetcher.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#ifndef ProfileDeleteFetcher_h
#define ProfileDeleteFetcher_h

#include "BaseFetcher.h"
#include "ProfileDeleteRequestEntity.h"
#include "ProfileDeleteResponseEntity.h"

/// プロフィール削除フェッチャ
class ProfileDeleteFetcher final: public BaseFetcher<ProfileDeleteRequestEntity, ProfileDeleteResponseEntity> {
public:
	
	/**
	 *  URL取得
	 *
	 *  @return URL
	 */
	string url();
	
private:
	
};

#endif /* ProfileDeleteFetcher_h */
