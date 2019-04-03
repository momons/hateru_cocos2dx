//
//  GameEventShowImageEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventShowImageEntity_h
#define GameEventShowImageEntity_h

#include "GameEventBaseEntity.h"

/// イベント 画像表示Entity
class GameEventShowImageEntity final: public GameEventBaseEntity {
public:
	
	/// 表示/非表示
	bool isShow;
	/// 画像Id
	int imageId;
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *
	 *  @return 使用サイズ
	 */
	int convertData(const unsigned char *data);
	
private:
};

#endif /* GameEventShowImageEntity_h */
