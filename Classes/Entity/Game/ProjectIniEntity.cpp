//
//  ProjectIniEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/18.
//
//

#include "ProjectIniEntity.h"

#include "StringUtil.h"

/// チップグループ
const string ProjectIniEntity::typeChipGroup = "[ChipGp]";
/// マップ
const string ProjectIniEntity::typeMap = "[MapList]";
/// ユニット
const string ProjectIniEntity::typeUnit = "[Chara]";
/// 職業
const string ProjectIniEntity::typeJob = "[Job]";
/// 敵
const string ProjectIniEntity::typeEnemy = "[Enemy]";
/// スキル
const string ProjectIniEntity::typeSkill = "[Waza]";
/// アイテム
const string ProjectIniEntity::typeItem = "[Item]";
/// 変数
const string ProjectIniEntity::typeVariable = "[NumList]";
/// サウンド
const string ProjectIniEntity::typeSound = "[SoundList]";


/**
 *  コンストラクタ
 */
ProjectIniEntity::ProjectIniEntity() {
	counts.clear();
}

/**
 *  デストラクタ
 */
ProjectIniEntity::~ProjectIniEntity() {
	
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *  @param len  データ長
 */
void ProjectIniEntity::convertData(const unsigned char *data, size_t len) {

	// 文字に変換
	string inStr = StringUtil::copyBuff(data, len);
	
	// 分割
	counts.clear();
	string paramName = "";
	vector<string> line;
	StringUtil::split(line, inStr, "\r\n");
	for (auto it = line.begin(); it != line.end(); it++) {
		vector<string> params;
		StringUtil::split(params, *it, "=");
		if (params.size() == 2) {
			counts[paramName] = atoi(params[1].c_str());
		} else {
			paramName = *it;
			counts[paramName] = 0;
		}
	}
}