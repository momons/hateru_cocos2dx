//
//  TitleScene.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/15.
//
//

#ifndef TitleScene_h
#define TitleScene_h

#include "BaseScene.h"

/// タイトルシーン
class TitleScene final: public BaseScene {
public:
	
	/**
	 *  インスタンスシェア
	 *
	 *  @return インスタンス
	 */
	static TitleScene *sharedInstance();
	
	/**
	 *  デストラクタ
	 */
	~TitleScene();
	
private:
	
	/// インスタンス
	static TitleScene *instance;
	
	/**
	 *  インストラクタ
	 */
	TitleScene();
	
	/**
	 *  クラス作成(autorelease)
	 */
	CREATE_FUNC(TitleScene);
	
	/**
	 *  インスタンス設定
	 */
	static void setupInstance();
	
	/**
	 *  更新処理
	 *
	 *  @param delta デルタ
	 */
	void update(float delta) override;
};


#endif /* TitleScene_h */
