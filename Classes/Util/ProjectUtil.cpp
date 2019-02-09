//
//  ProjectUtil.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/15.
//
//

#include "ProjectUtil.h"

#include <mutex>

/// インスタンス
ProjectUtil *ProjectUtil::instance;

/**
 *  コンストラクタ
 */
ProjectUtil::ProjectUtil() {
}

/**
 *  デストラクタ
 */
ProjectUtil::~ProjectUtil() {
	instance = nullptr;
}

/**
 *  インスタンスシェア
 *
 *  @return インスタンス
 */
ProjectUtil *ProjectUtil::sharedInstance() {
	static once_flag flag;
	call_once(flag, ProjectUtil::setupInstance);
	return instance;
}


/**
 *  インスタンスセットアップ
 */
void ProjectUtil::setupInstance() {
	instance = new ProjectUtil();
	if(instance){
		instance->Ref::autorelease();
	}else {
		delete instance;
		instance = nullptr;
	}
}
