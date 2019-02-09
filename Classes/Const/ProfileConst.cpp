//
//  ProfileConst.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/29.
//
//

#include "ProfileConst.h"

/// インスタンス
ProfileConst *ProfileConst::instance;

#pragma mark - 初期化

/**
 *  コンストラクタ
 */
ProfileConst::ProfileConst() {
}

/**
 *  デストラクタ
 */
ProfileConst::~ProfileConst() {
	instance = nullptr;
}

/**
 *  インスタンス取得
 *
 *  @return インスタンス
 */
ProfileConst *ProfileConst::sharedInstance() {
	static once_flag flag;
	call_once(flag, ProfileConst::setupInstance);
	return instance;
}

/**
 *  インスタンスセットアップ
 */
void ProfileConst::setupInstance() {
	instance = new ProfileConst();
	if (instance == nullptr) {
		delete instance;
		instance = nullptr;
		return;
	}
	
	instance->Ref::autorelease();
}
