//
//  TitleMapLayer.h
//  hateru
//
//  Created by HaraKazunari on 2017/09/07.
//
//

#ifndef TitleMapLayer_h
#define TitleMapLayer_h

#include "Scene/Base/BaseLayer.h"

/// タイトルマップレイヤー
class TitleMapLayer final: public BaseLayer {
public:
	
	/**
	 *  コンストラクタ
	 */
	TitleMapLayer();
	
	/**
	 *  デストラクタ
	 */
	~TitleMapLayer();
	
	/**
	 *  クラス作成
	 *
	 *  @return クラス
	 */
	static TitleMapLayer *create();
	
private:
	
	/// チップ
	Sprite **chips;
	
	/// マップサイズ幅
    int mapSizeWidth;
    /// マップサイズ高さ
    int mapSizeHeight;
    /// ワールドサイズ
    Size worldSize;

    /**
	 *  レイヤー初期化
	 */
	virtual void initLayer() override;
	
	/**
	 *  レイヤーメイン処理
	 */
	virtual void layerMain() override;
	
};

#endif /* TitleMapLayer_h */
