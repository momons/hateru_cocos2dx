//
//  BbsGetFetcher.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#ifndef BbsGetFetcher_h
#define BbsGetFetcher_h

#include "BaseFetcher.h"
#include "BbsGetRequestEntity.h"
#include "BbsGetResponseEntity.h"

/// 掲示板 取得フェッチャ
class BbsGetFetcher final: public BaseFetcher<BbsGetRequestEntity, BbsGetResponseEntity> {
public:
	
	/**
	 *  URL取得
	 *
	 *  @return URL
	 */
	string url();
	
private:
	
};

#endif /* BbsGetFetcher_h */
