//
//  Base64Util.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/21.
//
//

#ifndef Base64Util_h
#define Base64Util_h

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

/// Base64ユーティリティ
class Base64Util final {
public:
	
	/**
	 *  変換
	 *
	 *  @param src    入力バッファ
	 *  @param length 入力バッファ長
	 *
	 *  @return 変換後文字列
	 */
	static string encode(const unsigned char* src, const size_t length);
	
	/**
	 *  復号
	 *
	 *  @param src src 入力文字列
	 *  @param dst dst 出力バッファ
	 *
	 *  @return 変換可否
	 */
	static bool decode(const string &src, vector<unsigned char>& dst);
	
private:
	
	/**
	 *  コンストラクタ
	 */
	Base64Util() {}
	
	/**
	 *  デストラクタ
	 */
	~Base64Util() {}
	
};

#endif /* Base64Util_h */
