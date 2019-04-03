//
//  NamesEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/18.
//
//

#ifndef NamesEntity_h
#define NamesEntity_h

#include "BaseGameEntity.h"

/// 名前リストEntity
class NamesEntity final: public BaseGameEntity {
public:
	
	/// 名前リスト
	vector<string> names;

	/**
	 *  コンストラクタ
	 */
	NamesEntity();
	
	/**
	 *  デストラクタ
	 */
	~NamesEntity();
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *  @param len  データ長
	 */
	void convertData(const unsigned char *data, size_t len);

	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *  @param len  データ長
	 *
	 *  @return Entity
	 */
	static NamesEntity createEntity(const unsigned char *data, size_t len);
	
private:
};

#endif /* NamesEntity_h */
