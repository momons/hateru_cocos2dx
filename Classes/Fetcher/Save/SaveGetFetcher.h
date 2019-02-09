//
//  SaveGetFetcher.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#ifndef SaveGetFetcher_h
#define SaveGetFetcher_h

#include "BaseFetcher.h"
#include "SaveGetRequestEntity.h"
#include "SaveGetResponseEntity.h"

/// セーブデータ取得フェッチャ
class SaveGetFetcher final: public BaseFetcher<SaveGetRequestEntity, SaveGetResponseEntity>  {
public:
	
	/**
	 *  URL取得
	 *
	 *  @return URL
	 */
	string url();
	
private:
	
};

#endif /* SaveGetFetcher_h */
