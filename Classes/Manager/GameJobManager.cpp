//
//  GameJobManager.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameJobManager.h"

#include <iostream>
#include <iomanip>

#include "FileConst.h"
#include "ProjectIniManager.h"

/**
 *  読み込み
 *
 *  @return 取得データ
 */
map<int, GameJobEntity> GameJobManager::load() {

	auto projectIniEntity = ProjectIniManager::load();
	auto jobs = map<int, GameJobEntity>();
	
	for (auto i = 0;i < projectIniEntity.counts[ProjectIniEntity::typeJob];i++) {
		// ファイルデータ取得
		ostringstream ostr;
		ostr << FileConst::resouceGamePath << "Job" << setfill('0') << setw(3) << i << ".nmp";
		auto fileData = FileUtils::getInstance()->getDataFromFile(ostr.str());
		
		auto entity = GameJobEntity::createEntity(fileData.getBytes());
		
		jobs[i] = entity;
	}
	
	return jobs;
}
