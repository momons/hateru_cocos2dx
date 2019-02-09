//
//  GameCharaEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameCharaEntity_h
#define GameCharaEntity_h

#include "BaseGameEntity.h"

/// キャラEntity
class GameCharaEntity final: public BaseGameEntity {
public:
	
	/// 名前
	string name;
	/// 初期職業ID
	int initJobId;
	/// 画像
	vector<int> imageIds;
	/// 初期アイテム
	vector<int> initItemIds;
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 */
	void convertData(const unsigned char *data);
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *
	 *  @return Entity
	 */
	static GameCharaEntity createEntity(const unsigned char *data);
	
private:
};

#endif /* GameCharaEntity_h */
