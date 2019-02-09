//
//  EncryptUtil.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/19.
//
//

#include "EncryptUtil.h"

#include <iostream>
#include <iomanip>
#include <openssl/md5.h>
#include <openssl/evp.h>

#include "EncryptConst.h"
#include "Base64Util.h"

/**
 *  ハッシュ化
 *
 *  @param inStr 入力文字列
 *
 *  @return ハッシュ値
 */
string EncryptUtil::hash(const string &inStr) {
	unsigned char md5[MD5_DIGEST_LENGTH];
	MD5((unsigned char*)(inStr.c_str()), inStr.length(), md5);
	string result = "";
	ostringstream ostr;
	for (auto i = 0; i < MD5_DIGEST_LENGTH; i++) {
		result += StringUtils::format("%02x", md5[i]);
	}
	return result;
}

/**
 *  暗号化
 *
 *  @param inStr 入力文字列
 *
 *  @return 暗号化文字列
 */
string EncryptUtil::encrypt(const string &inStr) {
	
	// AES128で暗号化 (AES256はAndoridで難があるらしい)
	int encryptLen = 0;
	int paddingLen = 0;
	vector<unsigned char> encrypt(inStr.length() + EVP_MAX_BLOCK_LENGTH);
    // TODO: 後で考える
//    EVP_CIPHER_CTX context;
//    EVP_EncryptInit(&context, EVP_aes_128_ecb(), (unsigned char*)EncryptConst::saveDataEncryptKey.c_str(), nullptr);
//    EVP_EncryptUpdate(&context, encrypt.data(), &encryptLen, (unsigned char*)inStr.c_str(), (int)inStr.length());
//    EVP_EncryptFinal(&context, encrypt.data() + encryptLen, &paddingLen);
//    EVP_CIPHER_CTX_cleanup(&context);

	// Base64エンコード
	auto retStr = Base64Util::encode(encrypt.data(), encryptLen + paddingLen);
	
	// メモリ解放
	EVP_cleanup();
	
	return retStr;
}

/**
 *  復号化
 *
 *  @param inStr 入力文字列
 *
 *  @return 復号化文字列
 */
string EncryptUtil::decrypt(const string &inStr) {
	
	// Base64デコード
	vector<unsigned char> buff;
	auto isSuccess = Base64Util::decode(inStr, buff);
	if (!isSuccess) {
		return "";
	}
	
	// 復号化
	int decryptLen = 0;
	int paddingLen = 0;
	vector<unsigned char> decrypt(buff.size());
    // TODO: 後で考える
//    EVP_CIPHER_CTX context;
//    EVP_DecryptInit(&context, EVP_aes_128_ecb(), (unsigned char*)EncryptConst::saveDataEncryptKey.c_str(), nullptr);
//    EVP_DecryptUpdate(&context, decrypt.data(), &decryptLen, buff.data(), (int)buff.size());
//    EVP_DecryptFinal(&context, decrypt.data() + decryptLen, &paddingLen);
//    EVP_CIPHER_CTX_cleanup(&context);

	// 復号化したデータを文字列に変換
	string retStr((char *)decrypt.data(), decryptLen + paddingLen);
	
	// メモリ解放
	EVP_cleanup();
	
	return retStr;
}
