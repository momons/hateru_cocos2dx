//
//  BbsGetResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef BbsGetResponseEntity_h
#define BbsGetResponseEntity_h

#include "BaseResponseEntity.h"

/// 掲示板取得詳細レスポンスEntity
class BbsGetDetailResponseEntity final: public Ref {
public:
	
	/// ユーザコード
	string userCode;
	/// ユーザ名
	string userName;
	/// メッセージコード
	string messageCode;
	/// メッセージタイプ
	string messageType;
	/// メッセージデータ
	string messageData;
	/// 追加日時
	string createAt;
	
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
	BbsGetDetailResponseEntity();
	
	/**
	 *  デストラクタ
	 */
	~BbsGetDetailResponseEntity();
};

/// 掲示板取得メタレスポンスEntity
class BbsGetMetaResponseEntity final: public Ref {
public:
	
	/// 掲示板コード
	string bbsCode;
	/// メッセージ
	vector<BbsGetDetailResponseEntity> messages;
	
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
	BbsGetMetaResponseEntity();
	
	/**
	 *  デストラクタ
	 */
	~BbsGetMetaResponseEntity();
};

/// 掲示板取得レスポンスEntity
class BbsGetResponseEntity final: public BaseResponseEntity<BbsGetMetaResponseEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	BbsGetResponseEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~BbsGetResponseEntity() {}
};

#endif /* BbsGetResponseEntity_h */
