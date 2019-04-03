//
//  PlayerEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/16.
//
//

#ifndef PlayerEntity_h
#define PlayerEntity_h

#include "cocos2d.h"

#include "picojson.h"

#include "PlayerUnitEntity.h"
#include "PlayerTeleportEntity.h"
#include "PlayerMapEntity.h"
#include "PlayerProfileEntity.h"

class GameDataService;

USING_NS_CC;
using namespace std;

/// プレイヤーEntity
class PlayerEntity: public Ref {
public:
	
	/// 有効フラグ
	bool isValid;
	
	/// ユーザID
	string id;
	/// ユーザ名
	string name;
	
	/// セーブトークン
	string saveToken;
	
	/// プロフィールEntity
	PlayerProfileEntity profile;
	
	/// 所持金
	int money;
	
	/// ユニット
	vector<PlayerUnitEntity>units;
	
	/// 現在位置
	PlayerMapEntity location;
	
	/// 移動タイプ
	MoveType moveType;
	
	/// テレポート情報
	vector<PlayerTeleportEntity> teleports;
	
	/// エスケープ
	PlayerMapEntity escapeLocation;
	
	/// 預かり所
	vector<PlayerItemEntity> cloakrooms;
	
	/// 変数群
	map<int, int> variables;
	
	/**
	 *  初期化
	 */
	void initialize();
	
#pragma mark - ユニット
	
	/**
	 *  ユニット追加
	 *
	 *  @param unitId ユニットID
	 */
	void addUnit(const int unitId);
	
#pragma mark - アイテム
	
	/**
	 *  持ちアイテムがフルか？
	 *
	 *  @return true: フル、false: まだまだ
	 */
	bool isFullItem();
	
	/**
	 *  アイテム追加
	 *
	 *  @param id       追加アイテムID
	 *  @param useCount 使用回数
	 *  @param itemId   アイテムID
	 *
	 *  @return true: フル、false: まだまだ
	 */
	bool addItem(const int id, const int useCount, const string itemId);
	
	/**
	 *  アイテム削除
	 *
	 *  @param id 削除アイテムID
	 *
	 *  @return true: あった、false: なかった
	 */
	bool removeItem(const int id);
	
#pragma mark - アイテム調合
	
	/**
	 *  現在のアイテムで調合できる一覧を取得する
	 *
	 *  @return アイテムIDリスト
	 */
	vector<int> validMixings();
	
#pragma mark - 預かり所
	
	/**
	 *  預かり所追加
	 *
	 *  @param id       追加アイテムID
	 *  @param useCount 使用回数
	 *  @param itemId   アイテムID
	 */
	void addCloakrooms(const int id, const int useCount, const string itemId);
	
	/**
	 *  預かり所削除
	 *
	 *  @param id 削除アイテムID
	 *
	 *  @return true: あった、false: なかった
	 */
	bool removeCloakrooms(const int id);
	
	/**
	 *  預かり所をソート
	 */
	void sortCloakrooms();
	
#pragma mark - 初期化

	/**
	 *  コンストラクタ
	 */
	PlayerEntity();
	
	/**
	 *  デストラクタ
	 */
	~PlayerEntity();
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
	
	/**
	 *  マッピング
	 *
	 *  @param object JSONオブジェクト
	 *
	 *  @return マッピング可否
	 */
	bool mapping(picojson::object &object);
	
private:
	
	/// ゲームサービス
	GameDataService *service;
	
};

#endif /* PlayerEntity_h */
