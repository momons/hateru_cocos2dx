//
//  BaseFetcher.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/17.
//
//

#ifndef BaseFetcher_h
#define BaseFetcher_h

#include "cocos2d.h"
#include "network/HttpClient.h"
#include "picojson.h"
#include "BaseRequestEntity.h"
#include "BaseResponseEntity.h"

USING_NS_CC;
using namespace std;

/// ベースフェッチャ
template <class T_REQUEST, class T_RESPONSE>
class BaseFetcher: public Ref {
public:

	/// 成功ハンドラ
	template <class T_RESPONSE_U>
	using successHandler = function<void(T_RESPONSE_U responseEntity)>;
	/// 失敗ハンドラ
	using failureHandler = function<void(void)>;

	/**
	 *  リクエストスタート
	 *
	 *  @param requestEntity リクエストEntity
	 *  @param success       成功ハンドラ
	 *  @param failure       失敗ハンドラ
	 */
	void startRequest(T_REQUEST requestEntity, successHandler<T_RESPONSE> success, failureHandler failure);
	
	/**
	 *  HTTP通信完了
	 *
	 *  @param client   クライアント情報
	 *  @param response レスポンス
	 */
	void onHttpRequestCompleted(network::HttpClient* client, network::HttpResponse* response);
	
	/**
	 *  URL取得
	 *
	 *  @return URL
	 */
	virtual string url() = 0;
	
	/**
	 *  エラーチェック
	 *
	 *  @param response レスポンス
	 *
	 *  @return エラー可否
	 */
	bool isValid(network::HttpResponse *response);
	
	/**
	 *  JSONパース
	 *
	 *  @param jsonValue 出力JSON
	 *  @param response  レスポンス
	 *
	 *  @return エラー可否
	 */
	bool jsonParse(picojson::value *jsonValue, network::HttpResponse *response);
	
private:
	
	/// リクエストEntity
	T_REQUEST requestEntity;
	
	/// 成功ハンドラ退避
	successHandler<T_RESPONSE> success;
	/// 失敗ハンドラ退避
	failureHandler failure;

	
};

#endif /* BaseFetcher_h */
