//
//  SaveSendFetcher.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#ifndef SaveSendFetcher_h
#define SaveSendFetcher_h

#include "BaseFetcher.h"
#include "SaveSendRequestEntity.h"
#include "SaveSendResponseEntity.h"

/// セーブデータ送信フェッチャ
class SaveSendFetcher final: public BaseFetcher<SaveSendRequestEntity, SaveSendResponseEntity> {
public:

	/**
	 *  URL取得
	 *
	 *  @return URL
	 */
	string url();
	
private:
	
};

#endif /* SaveSendFetcher_h */
