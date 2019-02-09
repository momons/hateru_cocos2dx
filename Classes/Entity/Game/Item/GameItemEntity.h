//
//  GameItemEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameItemEntity_h
#define GameItemEntity_h

#include "BaseGameEntity.h"
#include "GameItemMixEntity.h"
#include "GameItemStatusEntity.h"
#include "GameVariableChangeEntity.h"

/// アイテムEntity
class GameItemEntity final: public BaseGameEntity {
public:
	
	/// 名前
	string name;
	/// 種類
	ItemType type;
	/// 買値
	int purchasePrice;
	/// 売値
	int sellingPrice;
	/// 調合値
	int preparationPrice;
	/// 使用回数
	int useCount;
	/// 使用時、特殊技能と同一効果になる nilは無効
	int useSkillId;
	/// 状態治療
	ConditionType conditionTreatment;
	/// 変化ステータス
	vector<GameItemStatusEntity> changeStatus;
	/// 画像ID
	int imageId;
	/// 調合<GameItemMixEntity>
	vector<GameItemMixEntity> mixings;
	/// 装備可能
	bool isCanEquipped;
	/// 装備可能職業
	vector<bool> equipmentJobs;
	/// 変更職業
	int changeJobId;
	/// 表示コメント
	string comment;
	/// 出品可否
	bool isExhibit;
	/// 変数変化
	GameVariableChangeEntity changeVariable;
	
	/**
	 *  アイテム数が調合に規定数に達しているか？
	 *
	 *  @param itemCounts アイテムカウント
	 *
	 *  @return true: 達している、 false: 達してない
	 */
	bool isValidMixings(map<int, int> itemCounts);
	
	/**
	 *  ヒット回数取得
	 *
	 *  @return ヒット回数
	 */
	int hitCount();
	
	/**
	 *  コンストラクタ
	 */
	GameItemEntity();
	
	/**
	 *  デストラクタ
	 */
	~GameItemEntity();
	
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
	static GameItemEntity createEntity(const unsigned char *data);
	
private:
};

#endif /* GameItemEntity_h */
