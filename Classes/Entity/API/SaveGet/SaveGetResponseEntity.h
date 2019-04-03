//
//  SaveGetResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef SaveGetResponseEntity_h
#define SaveGetResponseEntity_h

#include "BaseResponseEntity.h"

#include "PlayerEntity.h"

/// マイアイテム情報取得メタレスポンスEntity
class SaveGetMetaResponseEntity final: public Ref {
public:
	
	/// セーブデータ
	string saveData;
	/// チェックデジット
	string checkDigit;
	
	/**
	 *  マッピング
	 *
	 *  @param object JSONオブジェクト
	 *
	 *  @return マッピング可否
	 */
	bool mapping(picojson::object &object);
	
	/**
	 *  プレイヤーEntityに変換
	 *
	 *  @return プレイヤーEntity
	 */
	PlayerEntity toPlayerEntity();
	
	/**
	 *  コンストラクタ
	 */
	SaveGetMetaResponseEntity();
	
	/**
	 *  デストラクタ
	 */
	~SaveGetMetaResponseEntity();
};

/// セーブデータ取得レスポンスEntity
class SaveGetResponseEntity final: public BaseResponseEntity<SaveGetMetaResponseEntity> {
public:
	/**
	 *  コンストラクタ
	 */
	SaveGetResponseEntity() {}
	
	/**
	 *  デストラクタ
	 */
	~SaveGetResponseEntity() {}
};

#endif /* SaveGetResponseEntity_h */
