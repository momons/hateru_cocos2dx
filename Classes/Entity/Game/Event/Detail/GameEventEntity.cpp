//
//  GameEventEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameEventEntity.h"

#include "GameEventMessageEntity.h"
#include "GameEventFluctuateHPEntity.h"
#include "GameEventFluctuateMPEntity.h"
#include "GameEventFluctuateGoldEntity.h"
#include "GameEventFluctuateEXPEntity.h"
#include "GameEventFluctuateItemEntity.h"
#include "GameEventOperateVariableEntity.h"
#include "GameEventChangeBGMEntity.h"
#include "GameEventChangeChipEntity.h"
#include "GameEventChangeUnitEntity.h"
#include "GameEventMoveLocationEntity.h"
#include "GameEventIfVariableEntity.h"
#include "GameEventSaveEntity.h"
#include "GameEventItemShopEntity.h"
#include "GameEventINNEntity.h"
#include "GameEventCloakroomEntity.h"
#include "GameEventChurchEntity.h"
#include "GameEventBattleEntity.h"
#include "GameEventFluctuateTeleportEntity.h"
#include "GameEventChangeTeleportEntity.h"
#include "GameEventChangeEscapeEntity.h"
#include "GameEventWipeEntity.h"
#include "GameEventExchangeUnitEntity.h"
#include "GameEventEndIfEntity.h"
#include "GameEventShowImageEntity.h"
#include "GameEventChangeJobEntity.h"
#include "GameEventIfStatusEntity.h"
#include "GameEventIfItemEntity.h"
#include "GameEventIfSkillEntity.h"
#include "GameEventEncountRateEntity.h"
#include "GameEventSaveEscapeLocationEntity.h"
#include "GameEventSettingShipEntity.h"
#include "GameEventExitEntity.h"
#include "GameEventSelectYesNoEntity.h"
#include "GameEventMoveMobUnitEntity.h"
#include "GameEventMoveUnitEntity.h"
#include "GameEventGettingOnOffEntity.h"
#include "GameEventMixShopEntity.h"
#include "GameEventIfTimeEntity.h"
#include "GameEventBarEntity.h"
#include "GameEventItemBazaarEntity.h"
#include "GameEventBBSEntity.h"
#include "GameEventIfTerminalEntity.h"
#include "GameEventJingleEntity.h"
#include "GameEventRandomEntity.h"
#include "UnitSprite.h"

#pragma mark - 初期化

/**
 *  イベントステータス初期化
 */
void GameEventEntity::initEventStatus() {
	workStatus = initConditionType == EventInitConditionType::Auto && !isExecute ? EventWorkStatus::Execute : EventWorkStatus::Valid;
	// TODO: ステータス設定 SubSetEvtSts
}

/**
 *  コンストラクタ
 */
GameEventEntity::GameEventEntity() {
	name = "";
	isIgnitionVariable = false;
	variableId = 0;
	formulaType = IfFormulaType::Equal;
	value = 0;
	initConditionType = EventInitConditionType::Key;
	moveType = EventDetailMoveType::NoMove;
	detailMoveTypes.clear();
	isUseUnit = false;
	charaId = 0;
	eventTypes.clear();
	details.clear();
	isExecute = false;
	workStatus = EventWorkStatus::NoMap;
	x = 0;
	y = 0;
	mapX = 0;
	mapY = 0;
	unitSprite = nullptr;
}

/**
 *  デストラクタ
 */
GameEventEntity::~GameEventEntity() {
	
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *  @param name 名前
 *
 *  @return 使用したオフセット数
 */
int GameEventEntity::convertData(const unsigned char *data, const string &name) {
	
	auto dataIndex = 0;
	
	// 名前
	this->name = name;
	
	// 変数による発生
	isIgnitionVariable = data[dataIndex] != 0;
	dataIndex += 1;
	// 変数Id
	variableId = (int)data[dataIndex] * 0x100 + (int)data[dataIndex + 1];
	dataIndex += 2;
	// 式
	formulaType = static_cast<IfFormulaType>(data[dataIndex]);
	dataIndex += 1;
	// 値
	value = (int)data[dataIndex];
	dataIndex += 1;
	// 開始条件
	initConditionType = static_cast<EventInitConditionType>(data[dataIndex]);
	dataIndex += 1;
	// 移動タイプ
	moveType = static_cast<EventDetailMoveType>(data[dataIndex]);
	dataIndex += 1;
	detailMoveTypes.clear();
	if (moveType == EventDetailMoveType::Set) {
		// 詳細移動数
		int moveCount = (int)data[dataIndex];
		dataIndex += 1;
		// 詳細移動
		for (auto i = 0;i < moveCount;i++) {
			detailMoveTypes.push_back(static_cast<EventMoveType>(data[dataIndex]));
			dataIndex += 1;
		}
	}
	// キャラ使用
	isUseUnit = (int)data[dataIndex] != 0;
	dataIndex += 1;
	// キャラId
	charaId = (int)data[dataIndex];
	dataIndex += 1;
	// 詳細数
	int detailCount = (int)data[dataIndex];
	dataIndex += 1;
	// イベント詳細ヘッダ
	eventTypes.clear();
	vector<int> detailSizes;
	for (auto i = 0;i < detailCount;i++) {
		// タイプ
		eventTypes.push_back(static_cast<EventType>(data[dataIndex]));
		dataIndex += 1;
		// 使用サイズ (不正確)
		detailSizes.push_back((int)data[dataIndex]);
		dataIndex += 1;
	}
	// イベント詳細
	details.clear();
	for (auto i = 0;i < detailCount;i++) {
		switch (eventTypes[i]) {
			case EventType::Message: {
				auto eventEntity = GameEventMessageEntity();
				eventEntity.messageLen = detailSizes[i];
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::FluctuateHP: {
				auto eventEntity = GameEventFluctuateHPEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::FluctuateMP: {
				auto eventEntity = GameEventFluctuateMPEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::FluctuateGold: {
				auto eventEntity = GameEventFluctuateGoldEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::FluctuateEXP: {
				auto eventEntity = GameEventFluctuateEXPEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::FluctuateItem: {
				auto eventEntity = GameEventFluctuateItemEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::OperateVariable: {
				auto eventEntity = GameEventOperateVariableEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::ChangeBGM: {
				auto eventEntity = GameEventChangeBGMEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::ChangeChip: {
				auto eventEntity = GameEventChangeChipEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::ChangeUnit: {
				auto eventEntity = GameEventChangeUnitEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::MoveLocation: {
				auto eventEntity = GameEventMoveLocationEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::IfVariable: {
				auto eventEntity = GameEventIfVariableEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::Save: {
				auto eventEntity = GameEventSaveEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::ItemShop: {
				auto eventEntity = GameEventItemShopEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::INN: {
				auto eventEntity = GameEventINNEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::Cloakroom: {
				auto eventEntity = GameEventCloakroomEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::Church: {
				auto eventEntity = GameEventChurchEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::Battle: {
				auto eventEntity = GameEventBattleEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::FluctuateTeleport: {
				auto eventEntity = GameEventFluctuateTeleportEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::ChangeTeleport: {
				auto eventEntity = GameEventChangeTeleportEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::ChangeEscape: {
				auto eventEntity = GameEventChangeEscapeEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::Wipe: {
				auto eventEntity = GameEventWipeEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::ExchangeUnit: {
				auto eventEntity = GameEventExchangeUnitEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::EndIf: {
				auto eventEntity = GameEventEndIfEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::ShowImage: {
				auto eventEntity = GameEventShowImageEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::ChangeJob: {
				auto eventEntity = GameEventChangeJobEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::IfStatus: {
				auto eventEntity = GameEventIfStatusEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::IfItem: {
				auto eventEntity = GameEventIfItemEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::IfSkill: {
				auto eventEntity = GameEventIfSkillEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::EncountRate: {
				auto eventEntity = GameEventEncountRateEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::SaveEscapeLocation: {
				auto eventEntity = GameEventSaveEscapeLocationEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::SettingShip: {
				auto eventEntity = GameEventSettingShipEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::Exit: {
				auto eventEntity = GameEventExitEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::SelectYesNo: {
				auto eventEntity = GameEventSelectYesNoEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::MoveMobUnit: {
				auto eventEntity = GameEventMoveMobUnitEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::MoveUnit: {
				auto eventEntity = GameEventMoveUnitEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::GettingOnOff: {
				auto eventEntity = GameEventGettingOnOffEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::MixShop: {
				auto eventEntity = GameEventMixShopEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::IfTime: {
				auto eventEntity = GameEventIfTimeEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::Bar: {
				auto eventEntity = GameEventBarEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::ItemBazaar: {
				auto eventEntity = GameEventItemBazaarEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::BBS: {
				auto eventEntity = GameEventBBSEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::IfTerminal: {
				auto eventEntity = GameEventIfTerminalEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::Jingle: {
				auto eventEntity = GameEventJingleEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventType::Random: {
				auto eventEntity = GameEventRandomEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
		}
	}
	
	return dataIndex;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *  @param name 名前
 *
 *  @return Entity
 */
GameEventEntity GameEventEntity::createEntity(const unsigned char *data, const string &name) {
	auto entity = GameEventEntity();
	entity.convertData(data, name);
	return entity;
}
