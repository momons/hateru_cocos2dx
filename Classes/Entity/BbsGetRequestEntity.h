//
//  BbsGetRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef BbsGetRequestEntity_h
#define BbsGetRequestEntity_h

#include "BaseRequestEntity.h"

/// 掲示板取得パラメータリクエストEntity
class BbsGetParamsRequestEntity final: public Ref {
public:
	/// 掲示板コード
	string bbsCode;
	/// 取得オフセット
	int offset;
	/// 取得カウント
	int count;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
	
	/**
	 *  コンストラクタ
	 */
	BbsGetParamsRequestEntity();
	
	/**
	 *  デストラクタ
	 */
	~BbsGetParamsRequestEntity();
};

/// 掲示板取得リクエストEntity
class BbsGetRequestEntity final: public BaseRequestEntity<BbsGetParamsRequestEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	BbsGetRequestEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~BbsGetRequestEntity() {}
};

#endif /* BbsGetRequestEntity_h */
