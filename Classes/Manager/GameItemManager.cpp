//
//  GameItemManager.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameItemManager.h"

#include "cocos2d.h"
#include <iostream>
#include <iomanip>

#include "Const/FileConst.h"
#include "ProjectIniManager.h"

USING_NS_CC;

/**
 *  読み込み
 *
 *  @return 取得データ
 */
map<int, GameItemEntity> GameItemManager::load() {
	
	auto projectIniEntity = ProjectIniManager::load();
	auto items = map<int, GameItemEntity>();
	
	for (auto i = 0;i < projectIniEntity.counts[ProjectIniEntity::typeItem];i++) {
		// ファイルデータ取得
		ostringstream ostr;
		ostr << FileConst::resouceGamePath << "Item" << setfill('0') << setw(3) << i << ".nmp";
		auto fileData = FileUtils::getInstance()->getDataFromFile(ostr.str());
		
		auto entity = GameItemEntity::createEntity(fileData.getBytes());
		
		items[i] = entity;
	}
	
	return items;
}

/**
 *  ファイルパス取得
 *
 *  @param imageId 画像Id
 *
 *  @return ファイルパス
 */
string GameItemManager::getImageFilePath(int imageId) {
	ostringstream ostr;
	ostr << "Item" << setfill('0') << setw(3) << imageId << ".png";
	return ostr.str();
}
