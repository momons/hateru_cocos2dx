//
//  BaseLayer.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/16.
//
//

#ifndef BaseLayer_h
#define BaseLayer_h

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

/// レイヤーの基底クラス
class BaseLayer: public Layer, public EventListener {
public:

	/**
	 *  初期化
	 * 
	 *  @return 作成可否
	 */
	virtual bool init() override;

	/**
	 *  コンストラクタ
	 */
	BaseLayer();
	
	/**
	 *  デストラクタ
	 */
	virtual ~BaseLayer();

	/**
	 *  レイヤー破棄
	 */
	virtual void deallocLayer();
	
	/**
	 *  レイヤー初期化
	 */
	virtual void initLayer() = 0;
	
	/**
	 *  レイヤーメイン処理
	 */
	virtual void layerMain() = 0;
	
	/**
	 *  更新処理
	 *
	 *  @param delta デルタ
	 */
	virtual void update(float delta) override;
	
	/**
	 *  タッチ削除
	 */
	void unregisterWithTouchDispatcher();
	
	/**
	 *  キープレス
	 *
	 *  @param keyCode キーコード
	 *  @param event   イベント情報
	 */
	virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) override;
	
	/**
	 *  キーリリース
	 *
	 *  @param keyCode キーコード
	 *  @param event   イベント情報
	 */
	virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event) override;

	/**
	 *  タッチダウンイベント
	 *
	 *  @param pTouch タッチ情報
	 *  @param pEvent イベント情報
	 *
	 *  @return 処理可否
	 */
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent) override;

	/**
	 *  タッチ移動イベント
	 *
	 *  @param pTouch タッチ情報
	 *  @param pEvent イベント情報
	 */
	virtual void onTouchMoved(Touch *pTouch, Event *pEvent) override;
	
	/**
	 *  タッチアップイベント
	 *
	 *  @param pTouch タッチ情報
	 *  @param pEvent イベント情報
	 */
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent) override;
	
	/**
	 *  リスナーが使用可能かどうかをチェックします。
	 *
	 *  @return 使用可否
	 */
	virtual bool checkAvailable() override;
	
	/**
	 *  クローンリスナーは、そのサブクラスではこのメソッドをオーバーライドする必要があります。
	 *
	 *  @return イベントリスナー
	 */
	virtual EventListener* clone() override;
	
	/**
	 *  背景色設定
	 *
	 *  @param color カラー情報
	 */
	void setBackgroundColor(const Color4B color);
	
private:
	
	/// 背景用
	LayerColor *backgroundColor;
};

#endif /* BaseLayer_h */
