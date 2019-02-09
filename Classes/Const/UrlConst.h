//
//  UrlConst.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/17.
//
//

#ifndef UrlConst_h
#define UrlConst_h

#include <stdio.h>

using namespace std;

/// URL定数定義クラス
class UrlConst final {
public:

	/// ドメイン名
	static const string domainName;
	
private:

	/**
	 *  コンストラクタ
	 */
	UrlConst() {}
	
	/**
	 *  デストラクタ
	 */
	~UrlConst() {}
};

#endif /* UrlConst_h */
