//
//  CharaGetFetcher.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#ifndef CharaGetFetcher_h
#define CharaGetFetcher_h

#include "BaseFetcher.h"
#include "CharaGetRequestEntity.h"
#include "CharaGetResponseEntity.h"

/// キャラ取得フェッチャ
class CharaGetFetcher final: public BaseFetcher<CharaGetRequestEntity, CharaGetResponseEntity> {
public:
	
	/**
	 *  URL取得
	 *
	 *  @return URL
	 */
	string url();
	
private:
	
};

#endif /* CharaGetFetcher_h */
