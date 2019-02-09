//
//  MapUpLayer.h
//  hateru
//
//  Created by HaraKazunari on 2017/01/09.
//
//

#ifndef MapUpLayer_h
#define MapUpLayer_h

#include "BaseLayer.h"

class GameMapEntity;
class GameMapChipEntity;
class GameMapAutoEntity;

/// マップ上レイヤー
class MapUpLayer final: public BaseLayer {
public:
	
	/**
	 *  コンストラクタ
	 */
	MapUpLayer();
	
	/**
	 *  デストラクタ
	 */
	~MapUpLayer();
	
	/**
	 *  クラス作成
	 *
	 *  @return クラス
	 */
	static MapUpLayer *create();
	
	/**
	 *  セットアップ
	 *
	 *  @param mapEntity マップEntity
	 */
	void setupMapUpLayer(const GameMapEntity *mapEntity);
	
	/**
	 *  ユニットのポジション設定
	 *
	 *  @param position ポジション
	 */
	void setUnitPosition(Point position);
	
private:
	
	/// 幅
	int width;
	/// 高さ
	int height;
	
	/// チップ
	Sprite **chips;
	
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

#endif /* MapUpLayer_h */
