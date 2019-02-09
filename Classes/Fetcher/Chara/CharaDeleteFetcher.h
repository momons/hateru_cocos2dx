//
//  CharaDeleteFetcher.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#ifndef CharaDeleteFetcher_h
#define CharaDeleteFetcher_h

#include "BaseFetcher.h"
#include "CharaDeleteRequestEntity.h"
#include "CharaDeleteResponseEntity.h"

/// キャラ削除フェッチャ
class CharaDeleteFetcher final: public BaseFetcher<CharaDeleteRequestEntity, CharaDeleteResponseEntity> {
public:
	
	/**
	 *  URL取得
	 *
	 *  @return URL
	 */
	string url();
	
private:
	
};

#endif /* CharaDeleteFetcher_h */
