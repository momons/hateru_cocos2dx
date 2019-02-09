//
//  ProfileConst.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/29.
//
//

#ifndef ProfileConst_h
#define ProfileConst_h

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

/// プロフィール定数
class ProfileConst final: Ref {
public:
	
	/// 性別
	const vector<string> genders {
		"ひみつ",
		"男",
		"女",
		"ネカマ",
		"ネナベ",
		"両性",
		"ツキモチ",
	};
	
	/// 年齢
	const vector<string> ages {
		"ひみつ",
		"9歳以下",
		"10代",
		"20代",
		"30代",
		"40代",
		"50代",
		"60代",
		"70代",
		"80代",
		"90代",
		"100歳以上",
	};
	
	/// 住所
	const vector<string> addresses {
		"ひみつ", "北海道", "青森県", "岩手県", "宮城県", "秋田県", "山形県", "福島県", "茨城県", "栃木県",
		"群馬県", "埼玉県", "千葉県", "東京都", "神奈川県", "新潟県", "富山県", "石川県", "福井県", "山梨県",
		"長野県", "岐阜県", "静岡県", "愛知県",	"三重県", "滋賀県", "京都府", "大阪府", "兵庫県", "奈良県",
		"和歌山県", "鳥取県", "島根県", "岡山県", "広島県", "山口県", "徳島県", "香川県", "愛媛県", "高知県",
		"福岡県", "佐賀県", "長崎県", "熊本県", "大分県", "宮崎県", "鹿児島県", "沖縄県", "海外", "地球外", "宇宙外",
	};
	
	/// 血液型
	const vector<string> bloods {
		"ひみつ",	"A型",	"B型",	"O型",	"AB型",
	};
	
	/// 星座
	const vector<string> constellations {
		"ひみつ",	 "おひつじ座", "おうし座", "ふたご座", "かに座", "しし座",	 "おとめ座",
		"てんびん座", "さそり座", "いて座", "やぎ座", "みずがめ座", "うお座",
	};
	
	/**
	 *  デストラクタ
	 */
	~ProfileConst();
	
	/**
	 *  インスタンスシェア
	 *
	 *  @return インスタンス
	 */
	static ProfileConst *sharedInstance();
	
private:
	
	/// インスタンス
	static ProfileConst *instance;
	
	/**
	 *  コンストラクタ
	 */
	ProfileConst();
	
	/**
	 *  インスタンスセットアップ
	 */
	static void setupInstance();
};


#endif /* ProfileConst_h */
