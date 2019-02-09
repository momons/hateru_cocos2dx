//
//  ProjectIniEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/18.
//
//

#ifndef ProjectIniEntity_h
#define ProjectIniEntity_h

#include "BaseGameEntity.h"

/// Project.ini Entity
class ProjectIniEntity final: public BaseGameEntity {
public:
	
	/// チップグループ
	static const string typeChipGroup;
	/// マップ
	static const string typeMap;
	/// ユニット
	static const string typeUnit;
	/// 職業
	static const string typeJob;
	/// 敵
	static const string typeEnemy;
	/// スキル
	static const string typeSkill;
	/// アイテム
	static const string typeItem;
	/// 変数
	static const string typeVariable;
	/// サウンド
	static const string typeSound;
	
	/// カウント
	map<string, int> counts;
	
	/**
	 *  コンストラクタ
	 */
	ProjectIniEntity();
	
	/**
	 *  デストラクタ
	 */
	~ProjectIniEntity();
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *  @param len  データ長
	 */
	void convertData(const unsigned char *data, size_t len);
	
private:
};


#endif /* ProjectIniEntity_h */
