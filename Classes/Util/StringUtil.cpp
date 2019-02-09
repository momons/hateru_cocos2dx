//
//  StringUtil.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/18.
//
//

#include "StringUtil.h"

/**
 *  文字分割
 *
 *  @param result    分割文字
 *  @param inStr     入力文字列
 *  @param delimiter デリミタ
 */
void StringUtil::split(vector<string> &result, const string &inStr, const string &delim) {
	
	result.clear();
	
	using string = std::string;
	string::size_type pos = 0;
	
	while (pos != string::npos) {
		string::size_type p = inStr.find(delim, pos);
		
		if (p == string::npos) {
			result.push_back(inStr.substr(pos));
			break;
		} else {
			result.push_back(inStr.substr(pos, p - pos));
		}
		pos = p + delim.size();
	}
}

/**
 *  バッファから文字列作成
 *
 *  @param data データ
 *  @param len  データ長
 *
 *  @return コピー後文字列
 */
string StringUtil::copyBuff(const unsigned char *data, size_t len) {
	char *buff = (char*)malloc(len + 1);
	memset(buff, 0x00, len + 1);
	memcpy(buff, data, len);
	string inStr = buff;
	free(buff);
	return inStr;
}

/**
 *  余白削除
 *
 *  @param string            文字
 *  @param trimCharacterList 削除対象リスト
 *
 *  @return 変換後文字
 */
string StringUtil::trim(const string& string, const char* trimCharacterList) {
	
	std::string result;
 
	// 左側からトリムする文字以外が見つかる位置を検索します。
	string::size_type left = string.find_first_not_of(trimCharacterList);
 
	if (left != string::npos) {
		// 左側からトリムする文字以外が見つかった場合は、同じように右側からも検索します。
		string::size_type right = string.find_last_not_of(trimCharacterList);
		
		// 戻り値を決定します。ここでは右側から検索しても、トリムする文字以外が必ず存在するので判定不要です。
		result = string.substr(left, right - left + 1);
	}
 
	return result;
}