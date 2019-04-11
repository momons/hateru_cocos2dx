//
//  MapLayer.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/10.
//
//

#ifndef MapLayer_h
#define MapLayer_h

#include "../Base/BaseLayer.h"

class GameMapEntity;
class GameMapChipEntity;
class GameMapAutoEntity;

/// マップレイヤー
class MapLayer final: public BaseLayer {
public:
	
	/**
	 *  コンストラクタ
	 */
	MapLayer();
	
	/**
	 *  デストラクタ
	 */
	~MapLayer();
	
	/**
	 *  クラス作成
	 *
	 *  @return クラス
	 */
	static MapLayer *create();
	
	/**
	 *  セットアップ
	 *
	 *  @param mapEntity マップEntity
	 */
	void setupMapLayer(const GameMapEntity *mapEntity);
	
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

	/// ダウンチップ
	Sprite **downChips;
	/// アップチップ
	Sprite **upChips;
	
	/**
	 *  レイヤー初期化
	 */
	virtual void initLayer() override;
	
	/**
	 *  レイヤーメイン処理
	 */
	virtual void layerMain() override;
	
	/**
	 *  通常マップセットアップ
	 *
	 *  @param mapEntity マップEntity
	 */
	void setupNormalMap(const GameMapEntity *mapEntity);
	
	/**
	 *  自動マップセットアップ
	 *
	 *  @param mapEntity マップEntity
	 */
	void setupAutoMap(const GameMapEntity *mapEntity);
	
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

#endif /* MapLayer_h */
