//
//  GameEventINNEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventINNEntity_h
#define GameEventINNEntity_h

#include "GameEventBaseEntity.h"

/// イベント 宿屋Entity
class GameEventINNEntity final: public GameEventBaseEntity {
public:
	
	/// 値段
	int price;
	/// 変数退避Id
	int variableId;

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

#endif /* GameEventINNEntity_h */
