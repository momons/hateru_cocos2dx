//
//  GameItemEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameItemEntity.h"

#include "Manager/ProjectIniManager.h"
#include "Util/SJISUtil.h"
#include "Util/StringUtil.h"

/**
 *  アイテム数が調合に規定数に達しているか？
 *
 *  @param itemCounts アイテムカウント
 *
 *  @return true: 達している、 false: 達してない
 */
bool GameItemEntity::isValidMixings(map<int, int> itemCounts) {

	for (auto it = mixings.begin();it != mixings.end();it++) {
		if (itemCounts[it->itemId] < it->value) {
			// 数が達していない
			return false;
		}
	}

	return true;
}

/**
 *  ヒット回数取得
 *
 *  @return ヒット回数
 */
int GameItemEntity::hitCount() {
	int hitCount = 0;
	for (auto it = changeStatus.begin();it != changeStatus.end();it++) {
		if (it->status == ItemStatusType::HitCount && hitCount < it->value) {
			hitCount = it->value;
		}
	}
	return hitCount;
}

/**
 *  コンストラクタ
 */
GameItemEntity::GameItemEntity() {
	name = "";
	type = ItemType::Normal;
	purchasePrice = 0;
	sellingPrice = 0;
	preparationPrice = 0;
	useCount = 0;
	useSkillId = 0;
	conditionTreatment = ConditionType::None;
	changeStatus.clear();
	imageId = 0;
	mixings.clear();
	isCanEquipped = false;
	equipmentJobs.clear();
	changeJobId = 0;
	comment = "";
	isExhibit = false;
}

/**
 *  デストラクタ
 */
GameItemEntity::~GameItemEntity() {
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameItemEntity::convertData(const unsigned char *data) {
	
	auto dataIndex = 0;
	auto projectIniEntity = ProjectIniManager::load();
	
	// 名前
	name = StringUtil::trim(SJISUtil::convertUTF8(&data[dataIndex], 16));
	dataIndex += 16;
	// 種別
	type = (ItemType)data[dataIndex];
	dataIndex += 1;
	// 買値
	purchasePrice = (int)data[dataIndex] * 0x100 + (int)data[dataIndex + 1];
	dataIndex += 2;
	// 売値
	sellingPrice = (int)data[dataIndex] * 0x100 + (int)data[dataIndex + 1];
	dataIndex += 2;
	// 調合値
	preparationPrice = (int)data[dataIndex] * 0x100 + (int)data[dataIndex + 1];
	dataIndex += 2;
	// 使用回数
	useCount = (int)data[dataIndex];
	dataIndex += 1;
	// 特殊技能
	useSkillId = (int)data[dataIndex];
	dataIndex += 1;
	// 状態治療
	conditionTreatment = static_cast<ConditionType>(data[dataIndex]);
	dataIndex += 1;
	// ステータス
	changeStatus.clear();
	for (auto i = 0;i < 5;i++) {
		changeStatus.push_back(GameItemStatusEntity::createEntity(&data[dataIndex]));
		dataIndex += 3;
	}
	// 変数変化
	changeVariable.convertData(&data[dataIndex]);
	dataIndex += 4;
	// 画像
	imageId = (int)data[dataIndex];
	dataIndex += 1;
	// 調合
	mixings.clear();
	for (auto i = 0;i < 5;i++) {
		auto itemMixEntity = GameItemMixEntity::createEntity(&data[dataIndex]);
		if (itemMixEntity.itemId != 0) {
			mixings.push_back(itemMixEntity);
		}
		dataIndex += 2;
	}
	// 装備可能
	isCanEquipped = (data[dataIndex] == 1);
	dataIndex += 1;
	// 装備可能職業指定
	equipmentJobs.clear();
	for (auto i = 0;i < projectIniEntity.counts[ProjectIniEntity::typeJob];i++) {
		equipmentJobs.push_back(data[dataIndex] == 1);
		dataIndex += 1;
	}
	// 変更職業
	changeJobId = (int)data[dataIndex];
	dataIndex += 1;
	// 出品可否
	isExhibit = data[dataIndex] == 1;
	dataIndex += 1;
	// コメント
	comment = StringUtil::trim(SJISUtil::convertUTF8(&data[dataIndex], 40));
	dataIndex += 40;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return Entity
 */
GameItemEntity GameItemEntity::createEntity(const unsigned char *data) {
	auto entity = GameItemEntity();
	entity.convertData(data);
	return entity;
}
