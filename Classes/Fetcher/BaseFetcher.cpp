//
//  BaseFetcher.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/17.
//
//

#include "BaseFetcher.h"
#include "JsonUtil.h"

/**
 *  リクエストスタート
 *
 *  @param requestEntity リクエストEntity
 *  @param success       成功ハンドラ
 *  @param failure       失敗ハンドラ
 */
template <class T_REQUEST, class T_RESPONSE>
void BaseFetcher<T_REQUEST, T_RESPONSE>::startRequest(T_REQUEST requestEntity, successHandler<T_RESPONSE> success, failureHandler failure) {
	
	// 退避
	this->requestEntity = requestEntity;
	this->success = success;
	this->failure = failure;
	
	// 通信設定
	auto request = new network::HttpRequest();
	request->setUrl(url().c_str());
	request->setRequestType(network::HttpRequest::Type::POST);
	request->setResponseCallback(this, httpresponse_selector(BaseFetcher::onHttpRequestCompleted));

	// POSTデータ作成
	picojson::object object;
	requestEntity.serialize(&object);
	picojson::value val(object);
	string postData = val.serialize();
	request->setRequestData(postData.c_str(), postData.length());
	
	// 通信開始
	network::HttpClient::getInstance()->send(request);
}

/**
 *  HTTP通信完了
 *
 *  @param client   クライアント情報
 *  @param response レスポンス
 */
template <class T_REQUEST, class T_RESPONSE>
void BaseFetcher<T_REQUEST, T_RESPONSE>::onHttpRequestCompleted(network::HttpClient* client, network::HttpResponse* response) {
	
	// エラーチェック
	if (!BaseFetcher::isValid(response)) {
		this->failure();
		return;
	}
	
	// JSON変換
	picojson::value jsonValue;
	if (!BaseFetcher::jsonParse(&jsonValue, response)) {
		this->failure();
		return;
	}
	
	// オブジェクトに変換
	T_RESPONSE responseEntity;
	auto isSuccess = responseEntity.mapping(jsonValue.get<picojson::object>());
	if (responseEntity.status.code != 200 || !isSuccess) {
		this->failure();
		return;
	}
	
	// 成功
	this->success(responseEntity);
}

/**
 *  エラーチェック
 *
 *  @param response レスポンス
 *
 *  @return エラー可否
 */
template <class T_REQUEST, class T_RESPONSE>
bool BaseFetcher<T_REQUEST, T_RESPONSE>::isValid(network::HttpResponse *response) {
	// エラー
	if(!response->isSucceed() || response->getResponseCode() != 200){
		return false;
	}
	return true;
}

/**
 *  JSONパース
 *
 *  @param jsonValue 出力JSON
 *  @param response  レスポンス
 *
 *  @return エラー可否
 */
template <class T_REQUEST, class T_RESPONSE>
bool BaseFetcher<T_REQUEST, T_RESPONSE>::jsonParse(picojson::value *jsonValue, network::HttpResponse *response) {
	// JSON変換
	string error;
	JsonUtil::jsonParse(jsonValue, &error, response);
	if(!error.empty()){
		cout << error;
		return false;
	}
	return true;
}
