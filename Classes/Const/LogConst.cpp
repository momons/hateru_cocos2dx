//
//  LogConst.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/18.
//
//

#include "LogConst.h"

/// JSON変換エラー
const string LogConst::jsonParseError = "Json parse error `%s`.";
/// JSONマッピングエラー
const string LogConst::jsonBadMappingError = "Json bad mapping `%s`.";

/// 暗号化エラー
const string LogConst::encryptError = "Encrypt error `%s`.";
/// 復号化エラー
const string LogConst::decryptError = "Decrypt error `%s`.";
/// チェックデジットエラー
const string LogConst::checkDigitError = "Check digit error `%s`.";
