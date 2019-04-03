//
//  BbsWriteResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef BbsWriteResponseEntity_h
#define BbsWriteResponseEntity_h

#include "BaseResponseEntity.h"

/// マイアイテム情報取得メタレスポンスEntity
class BbsWriteMetaResponseEntity final: public Ref {
public:
	
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
	BbsWriteMetaResponseEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~BbsWriteMetaResponseEntity() {}
};

/// 掲示板書き込みレスポンスEntity
class BbsWriteResponseEntity final: public BaseResponseEntity<BbsWriteMetaResponseEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	BbsWriteResponseEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~BbsWriteResponseEntity() {}
};

#endif /* BbsWriteResponseEntity_h */
