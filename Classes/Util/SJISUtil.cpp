//
//  SJISUtil.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/17.
//
//

#include "SJISUtil.h"

#include <iconv.h>

/**
 *  SJISをUTF8に変換
 *
 *  @param buff     入力バッファ
 *  @param buffLen  入力長
 *
 *  @return 変換後文字
 */
string SJISUtil::convertUTF8(const unsigned char *buff, const size_t buffLen) {

	string outputStr = "";

	size_t inputLen = buffLen;
	char *inputBuff = (char *)malloc(inputLen + 1);
	memset(inputBuff, 0x00, inputLen + 1);
	memcpy(inputBuff, buff, inputLen);
	char *inputBuffPoint = inputBuff;
	
	size_t outputLen = buffLen * 3;
	char *outputBuff = (char *)malloc(outputLen + 1);
	memset(outputBuff, 0x00, outputLen + 1);
	char *outputBuffPoint = outputBuff;
	
	auto iConv = iconv_open("UTF-8", "cp932");
	auto ret = iconv(iConv, &inputBuffPoint, &inputLen, &outputBuffPoint, &outputLen);
	if (ret != (size_t)-1) {
		if (outputLen == 0) {
			return outputStr;
		}
		*outputBuffPoint = '\0';
		outputStr = outputBuff;
	}
	iconv_close(iConv);
	
	free(inputBuff);
	free(outputBuff);
	
	return outputStr;
}
