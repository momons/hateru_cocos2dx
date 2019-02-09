//
//  Base64Util.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/21.
//
//

#include "Base64Util.h"


/**
 *  変換
 *
 *  @param src    入力バッファ
 *  @param length 入力バッファ長
 *
 *  @return 変換後文字列
 */
string Base64Util::encode(const unsigned char* src, const size_t length) {

	const string table("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");
	string cdst;
	
	for (size_t i = 0; i < length; i++) {
		switch (i % 3) {
			case 0:
				cdst.push_back(table[(src[i] & 0xFC) >> 2]);
				if (i + 1 == length) {
					cdst.push_back(table[(src[i] & 0x03) << 4]);
					cdst.push_back('=');
					cdst.push_back('=');
				}
				break;
			case 1:
				cdst.push_back(table[((src[i - 1] & 0x03) << 4) | ((src[i + 0] & 0xF0) >> 4)]);
				if (i + 1 == length) {
					cdst.push_back(table[(src[i] & 0x0F) << 2]);
					cdst.push_back('=');
				}
				break;
			case 2:
				cdst.push_back(table[((src[i - 1] & 0x0F) << 2) | ((src[i + 0] & 0xC0) >> 6)]);
				cdst.push_back(table[src[i] & 0x3F]);
				break;
		}
	}
	
	return cdst;
}

/**
 *  復号
 *
 *  @param src src 入力文字列
 *  @param dst dst 出力バッファ
 *
 *  @return 変換可否
 */
bool Base64Util::decode(const string &src, vector<unsigned char>& dst) {
	
	if (src.size() & 0x00000003) {
		return false;
	}
	
	const string table("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");
	vector<unsigned char> cdst;
	
	for (std::size_t i = 0; i < src.size(); i += 4) {
		if (src[i + 0] == '=') {
			return false;
		} else if (src[i + 1] == '=') {
			return false;
		} else if (src[i + 2] == '=') {
			const std::string::size_type s1 = table.find(src[i + 0]);
			const std::string::size_type s2 = table.find(src[i + 1]);
			
			if (s1 == std::string::npos || s2 == std::string::npos) {
				return false;
			}
			
			cdst.push_back(static_cast<unsigned char>(((s1 & 0x3F) << 2) | ((s2 & 0x30) >> 4)));
			
			break;
		} else if (src[i + 3] == '=') {
			const std::string::size_type s1 = table.find(src[i + 0]);
			const std::string::size_type s2 = table.find(src[i + 1]);
			const std::string::size_type s3 = table.find(src[i + 2]);
			
			if (s1 == std::string::npos || s2 == std::string::npos || s3 == std::string::npos) {
				return false;
			}
			
			cdst.push_back(static_cast<unsigned char>(((s1 & 0x3F) << 2) | ((s2 & 0x30) >> 4)));
			cdst.push_back(static_cast<unsigned char>(((s2 & 0x0F) << 4) | ((s3 & 0x3C) >> 2)));
			
			break;
		} else {
			const std::string::size_type s1 = table.find(src[i + 0]);
			const std::string::size_type s2 = table.find(src[i + 1]);
			const std::string::size_type s3 = table.find(src[i + 2]);
			const std::string::size_type s4 = table.find(src[i + 3]);
			
			if (s1 == std::string::npos || s2 == std::string::npos || s3 == std::string::npos || s4 == std::string::npos) {
				return false;
			}
			
			cdst.push_back(static_cast<unsigned char>(((s1 & 0x3F) << 2) | ((s2 & 0x30) >> 4)));
			cdst.push_back(static_cast<unsigned char>(((s2 & 0x0F) << 4) | ((s3 & 0x3C) >> 2)));
			cdst.push_back(static_cast<unsigned char>(((s3 & 0x03) << 6) | ((s4 & 0x3F) >> 0)));
		}
	}
	
	dst.swap(cdst);
	
	return true;
}