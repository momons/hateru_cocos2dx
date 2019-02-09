//
//  GameVariableManager.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameVariableManager.h"

#include "FileConst.h"
#include "ProjectIniManager.h"
#include "NamesManager.h"

/**
 *  読み込み
 *
 *  @return 取得データ
 */
map<int, GameVariableEntity> GameVariableManager::load() {
	
	// 数を取得
	auto projectIniEntity = ProjectIniManager::load();
	// 名前リスト取得
	auto namesEntity = NamesManager::load(NamesManager::typeVariable);
	
	auto variables = map<int, GameVariableEntity>();

	// ファイルデータ取得
	ostringstream ostr;
	ostr << FileConst::resouceGamePath << "NumData.nmp";
	auto fileData = FileUtils::getInstance()->getDataFromFile(ostr.str());
	unsigned char *data = fileData.getBytes();

	for (auto i = 0;i < projectIniEntity.counts[ProjectIniEntity::typeVariable];i++) {
		
		auto entity = GameVariableEntity::convertData(&data[i], namesEntity.names[i]);
		
		variables[i] = entity;
	}
	
	return variables;
}
