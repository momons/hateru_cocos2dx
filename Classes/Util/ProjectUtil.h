//
//  ProjectUtil.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/15.
//
//

#ifndef ProjectUtil_h
#define ProjectUtil_h

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

/// プロジェクト共通ユーティリティ
class ProjectUtil final: public Ref {
public:
	
	/**
	 *  デストラクタ
	 */
	~ProjectUtil();

	/**
	 *  インスタンスシェア
	 *
	 *  @return インスタンス
	 */
	static ProjectUtil *sharedInstance();
	
private:
	
	/// インスタンス
	static ProjectUtil *instance;
	
	/**
	 *  コンストラクタ
	 */
	ProjectUtil();
	

	/**
	 *  インスタンスセットアップ
	 */
	static void setupInstance();
};


#endif /* ProjectUtil_h */
