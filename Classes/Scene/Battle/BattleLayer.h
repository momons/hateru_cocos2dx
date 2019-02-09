//
//  BattleLayer.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/10.
//
//

#ifndef BattleLayer_h
#define BattleLayer_h

#include "BaseLayer.h"

/// バトルレイヤー
class BattleLayer final: public BaseLayer {
public:
	
	/**
	 *  コンストラクタ
	 */
	BattleLayer();
	
	/**
	 *  デストラクタ
	 */
	~BattleLayer();
	
	
private:
	
	/**
	 *  クラス作成
	 *
	 *  @return クラス
	 */
	static BattleLayer *create();
	
	/**
	 *  レイヤー初期化
	 */
	virtual void initLayer() override;
	
	/**
	 *  レイヤーメイン処理
	 */
	virtual void layerMain() override;
	
};

#endif /* BattleLayer_h */
