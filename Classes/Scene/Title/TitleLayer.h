//
//  TitleLayer.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/16.
//
//

#ifndef TitleLayer_h
#define TitleLayer_h

#include "../Base/BaseLayer.h"

/// タイトルレイヤー
class TitleLayer final: public BaseLayer {
public:
	
	/**
	 *  コンストラクタ
	 */
	TitleLayer();
	
	/**
	 *  デストラクタ
	 */
	~TitleLayer();
	
	/**
	 *  クラス作成
	 *
	 *  @return クラス
	 */
	static TitleLayer *create();
	
private:
	
    /// タイトル
    Sprite *_titleSprite;
    /// 気球
    Sprite *_balloonSprite;
    /// 気球の影
    DrawNode *_balloonShadow;

    /// 気球の速度
    Point _balloonSpeed;
    
	/**
	 *  レイヤー初期化
	 */
	virtual void initLayer() override;
	
	/**
	 *  レイヤーメイン処理
	 */
	virtual void layerMain() override;
	
};

#endif /* TitleLayer_h */
