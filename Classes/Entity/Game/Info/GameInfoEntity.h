//
//  GameInfoEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameInfoEntity_h
#define GameInfoEntity_h

#include "BaseGameEntity.h"

#include "PlayerEntity.h"

/// ゲームEntity
class GameInfoEntity final: public BaseGameEntity {
public:
	
	/// 初期所持金
	int initMoney;
	/// 初期所持金
	string moneyUnit;
	/// 初期マップID
	int initMapId;
	/// 初期X座標
	int initX;
	/// 初期Y座標
	int initY;
	/// 初期メンバーID
	vector<int> initMemberIds;
	/// 船キャラID
	int shipUnitId;
	/// 飛行船キャラID
	int flyShipUnitId;
	/// 船サウンドID
	int shipSoundId;
	/// 飛行船サウンドID
	int flyShipSoundId;
	/// 宿屋サウンドID
	int innSoundId;
	/// レベルアップサウンドID
	int levelUpSoundId;
	/// 戦闘終了サウンドID
	int battleEndSoundId;
	
	/**
	 *  コンストラクタ
	 */
	GameInfoEntity();
	
	/**
	 *  デストラクタ
	 */
	~GameInfoEntity();
	
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
	static GameInfoEntity createEntity(const unsigned char *data);
	
private:
};

#endif /* GameInfoEntity_h */
