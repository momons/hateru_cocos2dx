//
//  CharaSendFetcher.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#ifndef CharaSendFetcher_h
#define CharaSendFetcher_h

#include "BaseFetcher.h"
#include "CharaSendRequestEntity.h"
#include "CharaSendResponseEntity.h"

/// キャラ送信フェッチャ
class CharaSendFetcher final: public BaseFetcher<CharaSendRequestEntity, CharaSendResponseEntity> {
public:
	
	/**
	 *  URL取得
	 *
	 *  @return URL
	 */
	string url();
	
private:
	
};

#endif /* CharaSendFetcher_h */
