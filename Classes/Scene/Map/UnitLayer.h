//
//  UnitLayer.h
//  hateru
//
//  Created by HaraKazunari on 2017/08/22.
//
//

#ifndef UnitLayer_h
#define UnitLayer_h

#include "../Base/BaseLayer.h"

class UnitSprite;
class PlayerEntity;
class GameMapEntity;

/// ユニットレイヤー
class UnitLayer final: public BaseLayer {
public:
	
	/**
	 *  コンストラクタ
	 */
	UnitLayer();
	
	/**
	 *  デストラクタ
	 */
	~UnitLayer();
	
	/**
	 *  クラス作成
	 *
	 *  @return クラス
	 */
	static UnitLayer *create();
	
	/**
	 *  セットアップ
	 *
	 *  @param playerEntity プレイヤーEntity
	 *  @param mapEntity    マップEntity
	 */
	void setupUnitLayer(PlayerEntity *playerEntity, GameMapEntity *mapEntity);
	
	/**
	 *  ユニットのポジション設定
	 *
	 *  @param position ポジション
	 */
	void setUnitPosition(Point position);
	
private:
	
	/// ユニットスプライト
	UnitSprite **units;
	/// ユニット数
	int unitCount;
	
	/**
	 *  レイヤー初期化
	 */
	virtual void initLayer() override;
	
	/**
	 *  レイヤーメイン処理
	 */
	virtual void layerMain() override;
	
	/**
	 *  SpriteFrame取得
	 *
	 *  @param imageId 画像ID
	 *
	 *  @return SpriteFrame
	 */
	SpriteFrame *getSpriteFrame(const int imageId);
	
	/**
	 *  スプライト情報解放
	 */
	void freeSprites();
};

#endif /* UnitLayer_h */
