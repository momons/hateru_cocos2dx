//
//  SplashLayer.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/16.
//
//

#ifndef SplashLayer_h
#define SplashLayer_h

#include "Scene/Base/BaseLayer.h"

/// スプラッシュレイヤー
class SplashLayer final: public BaseLayer {
public:

	/**
	 *  コンストラクタ
	 */
	SplashLayer();
	
	/**
	 *  デストラクタ
	 */
	~SplashLayer();
	
	/**
	 *  クラス作成
	 *
	 *  @return クラス
	 */
	static SplashLayer *create();
	
private:
	
	/// カウント
	int count;
	
	/**
	 *  レイヤー初期化
	 */
	virtual void initLayer() override;
	
	/**
	 *  レイヤーメイン処理
	 */
	virtual void layerMain() override;
	
};

#endif /* SplashLayer_h */
