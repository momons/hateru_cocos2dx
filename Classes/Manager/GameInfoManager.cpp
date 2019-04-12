//
//  GameInfoManager.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameInfoManager.h"

#include "cocos2d.h"
#include <sstream>

#include "Const/FileConst.h"

USING_NS_CC;

/**
 *  読み込み
 *
 *  @return 取得データ
 */
GameInfoEntity GameInfoManager::load() {
	
	// ファイルデータ取得
	ostringstream ostr;
	ostr << FileConst::resouceGamePath << "Game.nmp";
	auto fileData = FileUtils::getInstance()->getDataFromFile(ostr.str());
	
	auto entity = GameInfoEntity::createEntity(fileData.getBytes());
	
	return entity;
}
