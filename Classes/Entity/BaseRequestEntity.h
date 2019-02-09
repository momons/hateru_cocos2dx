//
//  BaseRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef BaseRequestEntity_h
#define BaseRequestEntity_h

#include "cocos2d.h"
#include "picojson.h"

USING_NS_CC;
using namespace std;

/// ベースステータスリクエストEntity
class BaseStatusRequestEntity final: public Ref {
public:
	
	/// アプリトークン
	string appToken;
	/// アプリバージョン
	string appVersion;
	/// プラットフォーム
	string platform;
	/// ユーザコード
	string userCode;
	/// ユーザ名
	string userName;
	/// アクセストークン
	string accessToken;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);

	/**
	 *  コンストラクタ
	 */
	BaseStatusRequestEntity();
	
	/**
	 *  デストラクタ
	 */
	~BaseStatusRequestEntity();
};

/// ベースリクエストEntity
template<class T_PARAMS>
class BaseRequestEntity: public Ref {
public:
	
	/// ステータス
	BaseStatusRequestEntity status;
	
	// パラメータ
	T_PARAMS params;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
};

#endif /* BaseRequestEntity_h */
