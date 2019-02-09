//
//  GameCharaManager.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameCharaManager.h"

#include <iostream>
#include <iomanip>

#include "FileConst.h"
#include "ProjectIniManager.h"

/**
 *  読み込み
 *
 *  @return 取得データ
 */
map<int, GameCharaEntity> GameCharaManager::load() {
	
	auto projectIniEntity = ProjectIniManager::load();
	auto charas = map<int, GameCharaEntity>();
	
	for (auto i = 0;i < projectIniEntity.counts[ProjectIniEntity::typeUnit];i++) {
		// ファイルデータ取得
		ostringstream ostr;
		ostr << FileConst::resouceGamePath << "Chara" << setfill('0') << setw(3) << i << ".nmp";
		auto fileData = FileUtils::getInstance()->getDataFromFile(ostr.str());
		
		auto entity = GameCharaEntity::createEntity(fileData.getBytes());
		
		charas[i] = entity;
	}
	
	return charas;
}

/**
 *  ファイルパス取得
 *
 *  @param imageId 画像Id
 *
 *  @return ファイルパス
 */
string GameCharaManager::getImageFilePath(const int imageId) {
	ostringstream ostr;
	ostr << "Chara" << setfill('0') << setw(3) << imageId << ".png";
	return ostr.str();
}
