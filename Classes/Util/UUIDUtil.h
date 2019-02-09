//
//  UUIDUtil.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/31.
//
//

#ifndef UUIDUtil_h
#define UUIDUtil_h

#include "cocos2d.h"

USING_NS_CC;
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
