//
//  LogConst.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/18.
//
//

#ifndef LogConst_h
#define LogConst_h

#include <stdio.h>

using namespace std;

/// ログ定数
class LogConst final {
public:

	/// JSON変換エラー
	static const string jsonParseError;
	/// JSONマッピングエラー
	static const string jsonBadMappingError;

	/// 暗号化エラー
	static const string encryptError;
	/// 復号化エラー
	static const string decryptError;
	/// チェックデジットエラー
	static const string checkDigitError;

private:
	
	/**
	 *  コンストラクタ
	 */
	LogConst() {}
	
	/**
	 *  デストラクタ
	 */
	~LogConst() {}
	
};

#endif /* LogConst_h */
