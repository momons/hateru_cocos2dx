//
//  BbsWriteFetcher.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#ifndef BbsWriteFetcher_h
#define BbsWriteFetcher_h

#include "BaseFetcher.h"
#include "BbsWriteRequestEntity.h"
#include "BbsWriteResponseEntity.h"

/// 掲示板 書き込みフェッチャ
class BbsWriteFetcher final: public BaseFetcher<BbsWriteRequestEntity, BbsWriteResponseEntity> {
public:

	/**
	 *  URL取得
	 *
	 *  @return URL
	 */
	string url();
	
private:
	
};

#endif /* BbsWriteFetcher_h */
