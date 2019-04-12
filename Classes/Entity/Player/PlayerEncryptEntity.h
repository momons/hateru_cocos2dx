//
//  PlayerEncryptionEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/19.
//
//

#ifndef PlayerEncryptionEntity_h
#define PlayerEncryptionEntity_h

#include <string>

#include "Util/picojson.h"

class PlayerEntity;

using namespace std;

/// プレイヤー暗号化Entity
class PlayerEncryptEntity {
public:
	
	/// 有効フラグ
	bool isValid;
	
	/// データ
	string data;
	
	/// チェックデジット
	string checkDigit;
	
	/**
	 *  コンストラクタ
	 */
	PlayerEncryptEntity();
	
	/**
	 *  デストラクタ
	 */
	~PlayerEncryptEntity();

	/**
	 *  PlayerEntityを暗号化し設定する
	 *
	 *  @param playerEntity PlayerEntity
	 */
	void setPlayerEntity(PlayerEntity &playerEntity);
	
	/**
	 *  複合かしPlayerEntityにする
	 *
	 *  @return PlayerEntity
	 */
	PlayerEntity toPlayerEntity();
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
	
	/**
	 *  マッピング
	 *
	 *  @param object JSONオブジェクト
	 *
	 *  @return マッピング可否
	 */
	bool mapping(picojson::object &object);
	
private:
	
};


#endif /* PlayerEncryptionEntity_h */
