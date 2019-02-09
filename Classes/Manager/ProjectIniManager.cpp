//
//  ProjectIniManager.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/18.
//
//

#include "ProjectIniManager.h"

#include <mutex>
#include "FileConst.h"

/**
 *  Project.ini読み込み
 *
 *  @param ProjectIniEntity 設定Entity
 */
void ProjectIniManager::loadProjectIni(ProjectIniEntity &entity) {
	// ファイルデータ取得
	ostringstream ostr;
	ostr << FileConst::resouceGamePath << "Project.ini";
	auto fileData = FileUtils::getInstance()->getDataFromFile(ostr.str());
	
	entity.convertData(fileData.getBytes(), (size_t)fileData.getSize());
}

/**
 *  読み込み
 *
 *  @return 取得データ
 */
ProjectIniEntity ProjectIniManager::load() {
	
	static once_flag flag;
	static ProjectIniEntity entity;

	call_once(flag, ProjectIniManager::loadProjectIni, ref(entity));
	
	return entity;
}

