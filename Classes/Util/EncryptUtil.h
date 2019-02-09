//
//  EncryptUtil.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/19.
//
//

#ifndef EncryptUtil_h
#define EncryptUtil_h

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

/// 暗号化ユーティリティ
class EncryptUtil final {
public:
	
	/**
	 *  ハッシュ化
	 *
	 *  @param inStr 入力文字列
	 *
	 *  @return ハッシュ値
	 */
	static string hash(const string &inStr);

	/**
	 *  暗号化
	 *
	 *  @param inStr 入力文字列
	 *
	 *  @return 暗号化文字列
	 */
	static string encrypt(const string &inStr);
	
	/**
	 *  復号化
	 *
	 *  @param inStr 入力文字列
	 *
	 *  @return 復号化文字列
	 */
	static string decrypt(const string &inStr);
	
private:
	
	/**
	 *  コンストラクタ
	 */
	EncryptUtil() {}
	
	/**
	 *  デストラクタ
	 */
	~EncryptUtil() {}

};

#endif /* EncryptUtil_h */
