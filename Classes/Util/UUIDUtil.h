//
//  UUIDUtil.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/31.
//
//

#ifndef UUIDUtil_h
#define UUIDUtil_h

#include <string>

using namespace std;

/// UUIDユーティリティ
class UUIDUtil final {
public:
	
	/**
	 *  UUID生成
	 *
	 *  @return UUID
	 */
	static string create();
	
private:
	
	/**
	 *  コンストラクタ
	 */
	UUIDUtil() {}
	
	/**
	 *  デストラクタ
	 */
	~UUIDUtil() {}
	
};
#endif /* UUIDUtil_h */
