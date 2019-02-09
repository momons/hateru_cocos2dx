//
//  GameEventMessageEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventMessageEntity.h"

#include "SJISUtil.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventMessageEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// メッセージ
	message = SJISUtil::convertUTF8(data, messageLen);
	dataIndex += messageLen;
	
	return dataIndex;
}
