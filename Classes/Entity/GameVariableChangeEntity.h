//
//  GameVariableChangeEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameVariableChangeEntity_h
#define GameVariableChangeEntity_h

#include "BaseGameEntity.h"

/// 変数変化Entity
class GameVariableChangeEntity final: public BaseGameEntity {
public:
	
	/// 変数Id
	int variableId;
	/// 式
	VariableOperateType operateType;
	/// 値
	int value;

	/**
	 *  演算実行
	 */
	void calculation();
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data      バイナリデータ
	 */
	void convertData(const unsigned char *data);
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *
	 *  @return Entity
	 */
	static GameVariableChangeEntity createEntity(const unsigned char *data);
	
private:
};

#endif /* GameVariableChangeEntity_h */
