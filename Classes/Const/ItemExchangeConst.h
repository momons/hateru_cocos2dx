//
//  ItemExchangeConst.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/29.
//
//

#ifndef ItemExchangeConst_h
#define ItemExchangeConst_h

#include <stdio.h>

using namespace std;

/// アイテム交換定数
class ItemExchangeConst final {
public:
	
	/// 交換タイプ 交換
	static const string exchangeTypeExchange;
	/// 交換タイプ 譲渡
	static const string exchangeTypeTransfer;
	
private:
	
	/**
	 *  コンストラクタ
	 */
	ItemExchangeConst() {}
	
	/**
	 *  デストラクタ
	 */
	~ItemExchangeConst() {}

};

#endif /* ItemExchangeConst_h */
