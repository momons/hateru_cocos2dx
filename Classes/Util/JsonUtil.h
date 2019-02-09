//
//  JsonUtil.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/18.
//
//

#ifndef JsonUtil_h
#define JsonUtil_h

#include "cocos2d.h"
#include "picojson.h"
#include "network/HttpClient.h"

USING_NS_CC;
using namespace std;

/// JSONユーティリティ
class JsonUtil final {
public:
	
	/**
	 *  JSONパース
	 *
	 *  @param jsonValue JSON値
	 *  @param error     エラー
	 *  @param response  HTTPレスポンス
	 */
	static void jsonParse(picojson::value *jsonValue, string *error, network::HttpResponse *response);
	
	/**
	 *  JSONパース
	 *
	 *  @param jsonValue  JSON値
	 *  @param error      エラー
	 *  @param jsonString JSON文字列
	 */
	static void jsonParse(picojson::value *jsonValue, string *error, string *jsonString);
	
private:
	
	/**
	 *  コンストラクタ
	 */
	JsonUtil() {}
	
	/**
	 *  デストラクタ
	 */
	~JsonUtil() {}
};

#endif /* JsonUtil_h */
