//
//  BaseResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/18.
//
//

#ifndef BaseResponseEntity_h
#define BaseResponseEntity_h

#include "cocos2d.h"
#include "picojson.h"

USING_NS_CC;
using namespace std;

/// ベースステータスレスポンスEntity
class BaseStatusResponseEntity final: public Ref {
public:
	
	/// コード
	int code;
	/// メッセージ
	string message;
	
	/**
	 *  マッピング
	 *
	 *  @param object JSONオブジェクト
	 *
	 *  @return マッピング可否
	 */
	bool mapping(picojson::object &object);
	
	/**
	 *  コンストラクタ
	 */
	BaseStatusResponseEntity();
	
	/**
	 *  デストラクタ
	 */
	~BaseStatusResponseEntity();
};

/// ベースレスポンスEntity
template<class T_META>
class BaseResponseEntity: public Ref {
public:
	
	/// ステータス
	BaseStatusResponseEntity status;
	/// メタ
	T_META meta;
	
	/**
	 *  マッピング
	 *
	 *  @param object JSONオブジェクト
	 *
	 *  @return マッピング可否
	 */
	virtual bool mapping(picojson::object &object);
};

#endif /* BaseResponseEntity_h */
