//
//  JsonUtil.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/18.
//
//

#include "JsonUtil.h"

/**
 *  JSONパース
 *
 *  @param jsonValue JSON値
 *  @param error     エラー
 *  @param response  HTTPレスポンス
 */
void JsonUtil::jsonParse(picojson::value *jsonValue, string *error, network::HttpResponse *response) {

	// データ取得
	vector<char> *buff = response->getResponseData();
	string::size_type jsonSize = buff->size();
	char *jsonBuff = (char*)malloc(jsonSize + 1);
	memset(jsonBuff,0x00,jsonSize + 1);
	for(int i = 0;i < jsonSize;i++){
		jsonBuff[i] = buff->at(i);
	}
	
	// JSON
	picojson::parse(*jsonValue, jsonBuff, jsonBuff + jsonSize, error);
	
	// 解放
	free(jsonBuff);
}

/**
 *  JSONパース
 *
 *  @param jsonValue  JSON値
 *  @param error      エラー
 *  @param jsonString JSON文字列
 */
void JsonUtil::jsonParse(picojson::value *jsonValue, string *error, string *jsonString) {
	
	// データ取得
	string::size_type jsonSize = strlen(jsonString->c_str());
	char *jsonBuff = (char*)malloc(jsonSize + 1);
	memset(jsonBuff,0x00,jsonSize + 1);
	memcpy(jsonBuff,jsonString->c_str(),jsonSize);
	
	// JSON
	picojson::parse(*jsonValue, jsonBuff, jsonBuff + jsonSize, error);
	
	// 解放
	free(jsonBuff);

}