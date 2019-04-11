//
//  GameMapEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameMapEntity_h
#define GameMapEntity_h

#include "GameMapChipEntity.h"
#include "GameMapAutoEntity.h"
#include "../Event/GameEventEntity.h"

/// マップEntity
class GameMapEntity final {
public:
	
	/// マップ名
	string name;
	/// マップタイプ
	MapType mapType;
	/// 幅
	int width;
	/// 高さ
	int height;
	/// 背景画像
	int backgroundImageId;
	/// 画面制御
	MapLoopType mapEndType;
	/// 上マップチップグループID
	int upMapChips[GameConst::mapChipValueMax];
	int upMapChipGpId;
	/// 下マップチップグループID
	int downMapChips[GameConst::mapChipValueMax];
	int downMapChipGpId;
	/// 背景色
	int backgroundColor;
	/// 出現率
	int enemyEncountRate;
	/// テレポート可不可
	bool isUseTeleport;
	/// エスケープ可不可
	bool isUseEscape;
	/// サウンド
	int soundId;
	/// 戦闘音楽
	int battleSoundId;
	/// 戦闘背景
	int battleBackgroundImageId;
	/// マップチップ情報
	vector<GameMapChipEntity> mapChips;
	/// 自動マップ情報
	GameMapAutoEntity autoMap;
	/// イベント情報
	map<int, GameEventEntity> events;

	/**
	 *  コンストラクタ
	 */
	GameMapEntity();
	
	/**
	 *  デストラクタ
	 */
	~GameMapEntity();
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *  @param name 名前
	 */
	void convertData(const unsigned char *data, const string &name);
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *  @param name 名前
	 *
	 *  @return Entity
	 */
	static GameMapEntity createEntity(const unsigned char *data, const string &name);
	
	/**
	 *  バイナリデータよりイベントEntity作成
	 *
	 *  @param data  バイナリデータ
	 *  @param names 名前
	 */
	void convertEventData(const unsigned char *data, const vector<string> names);
	
private:
};

#endif /* GameMapEntity_h */
