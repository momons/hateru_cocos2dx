//
//  EncryptConst.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/19.
//
//

#ifndef EncryptConst_h
#define EncryptConst_h

#include <string>

using namespace std;

/// 暗号化定数定義クラス
class EncryptConst final {
public:
	
	/// 暗号化キー
	static const string saveDataEncryptKey;
	
private:
	
	/**
	 *  コンストラクタ
	 */
	EncryptConst() {}
	
	/**
	 *  デストラクタ
	 */
	~EncryptConst() {}
};

#endif /* EncryptConst_h */
