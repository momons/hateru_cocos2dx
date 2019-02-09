//
//  GameVariableEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameVariableEntity_h
#define GameVariableEntity_h

#include "BaseGameEntity.h"

/// 変数Entity
class GameVariableEntity final: public BaseGameEntity {
public:
	
	/// ID
	int id;
	/// 名前
	string name;
	/// 初期値
	int initValue;
	/// 説明
	string guide;

	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *  @param name 名前
	 *
	 *  @return Entity
	 */
	static GameVariableEntity convertData(const unsigned char *data, const string &name);
	
private:
};

#endif /* GameVariableEntity_h */
