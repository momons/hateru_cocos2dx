//
//  GameEventService.cpp
//  hateru
//
//  Created by HaraKazunari on 2017/01/17.
//
//

#include "GameEventService.h"

#include "GameDataService.h"
#include "GameEventStatusService.h"
#include "GameEventVariableService.h"
#include "UUIDUtil.h"
#include "PlayerEntity.h"
#include "PlayerUnitEntity.h"
#include "GameEventEntity.h"
#include "GameEventMessageEntity.h"
#include "GameEventFluctuateHPEntity.h"
#include "GameEventFluctuateMPEntity.h"
#include "GameEventFluctuateGoldEntity.h"
#include "GameEventFluctuateItemEntity.h"
#include "GameEventOperateVariableEntity.h"

#pragma mark - 初期化

/**
 *  コンストラクタ
 *
 *  @param playerEntity プレイヤーデータ
 *  @param mapEntity    マップ
 *  @param events       イベント群
 */
GameEventService::GameEventService(PlayerEntity *playerEntity, GameMapEntity *mapEntity, map<int, GameEventEntity> &events) {
	// 退避
	this->playerEntity = playerEntity;
	this->mapEntity = mapEntity;
	this->events = events;
	// 初期化
	executeEventIndex = -1;
	waitingEventIndexs.clear();
	// サブサービス
	statusService = new GameEventStatusService(this);
	variableService = new GameEventVariableService(this);
}

/**
 *  デストラクタ
 */
GameEventService::~GameEventService() {
	// 解放
	statusService = nullptr;
	variableService = nullptr;
}

/**
 *  イベント初期化 SubInitEvent
 */
void GameEventService::initEvents() {
	for (int y = 0;y < mapEntity->height;y++) {
		for (int x = 0;x < mapEntity->width;x++) {
			int index = x + y * mapEntity->width;
			if (mapEntity->mapChips[index].eventId <= 0) {
				continue;
			}
			int eventId = mapEntity->mapChips[index].eventId - 1;
			events[eventId].workStatus = EventWorkStatus::Invalid;
			events[eventId].mapX = x;
			events[eventId].mapY = y;
			if (events[eventId].isIgnitionVariable) {
				if (!variableService->compareVariable(
													  playerEntity->variables[events[eventId].variableId],
													  events[eventId].value, events[eventId].formulaType)
					) {
					continue;
				}
			}
			// ステータス設定
			events[eventId].initEventStatus();
		}
	}
}


#pragma mark - 実行

/**
 *  イベント実行
 */
void GameEventService::executeEvents() {
	
	bool isLoopEnd = false;
	
	GameEventEntity *eventEntity = &events[executeEventIndex];
	while(true) {

		switch(eventEntity->eventTypes[executeEventDetailIndex]) {
			case EventType::Message: {
				// 文章表示
				GameEventMessageEntity *entity = (GameEventMessageEntity *)eventEntity->details[executeEventDetailIndex];
				showMessage(entity->message);
				isLoopEnd = true;
				break;
			}
			case EventType::FluctuateHP: {
				// ＨＰ増減
				statusService->fluctuateHP(eventEntity->details[executeEventDetailIndex]);
				break;
			}
			case EventType::FluctuateMP: {
				// ＭＰ増減
				statusService->fluctuateMP(eventEntity->details[executeEventDetailIndex]);
				break;
			}
			case EventType::FluctuateGold: {
				// 所持金増減
				isLoopEnd = statusService->fluctuateGold(eventEntity->details[executeEventDetailIndex]);
				break;
			}
			case EventType::FluctuateEXP:
				// 経験値増減
				break;
			case EventType::FluctuateItem:
				// アイテム増減
				isLoopEnd = statusService->fluctuateItem(eventEntity->details[executeEventDetailIndex]);
				break;
			case EventType::OperateVariable:
				// 変数操作
				variableService->operateVariable(eventEntity->details[executeEventDetailIndex]);
				break;
			case EventType::ChangeBGM:
				break;
			case EventType::ChangeChip:
				break;
			case EventType::ChangeUnit:
				break;
			case EventType::MoveLocation:
				break;
			case EventType::IfVariable:
				break;
			case EventType::Save:
				break;
			case EventType::ItemShop:
				break;
			case EventType::INN:
				break;
			case EventType::Cloakroom:
				break;
			case EventType::Church:
				break;
			case EventType::Battle:
				break;
			case EventType::FluctuateTeleport:
				break;
			case EventType::ChangeTeleport:
				break;
			case EventType::ChangeEscape:
				break;
			case EventType::Wipe:
				break;
			case EventType::ExchangeUnit:
				break;
			case EventType::EndIf:
				break;
			case EventType::ShowImage:
				break;
			case EventType::ChangeJob:
				break;
			case EventType::IfStatus:
				break;
			case EventType::IfItem:
				break;
			case EventType::IfSkill:
				break;
			case EventType::EncountRate:
				break;
			case EventType::SaveEscapeLocation:
				break;
			case EventType::SettingShip:
				break;
			case EventType::Exit:
				break;
			case EventType::SelectYesNo:
				break;
			case EventType::MoveMobUnit:
				break;
			case EventType::MoveUnit:
				break;
			case EventType::GettingOnOff:
				break;
			case EventType::MixShop:
				break;
			case EventType::IfTime:
				break;
			case EventType::Bar:
				break;
			case EventType::ItemBazaar:
				break;
			case EventType::BBS:
				break;
			case EventType::IfTerminal:
				break;
			case EventType::Jingle:
				break;
			case EventType::Random:
				break;
			default:
				break;
		}
		
		
	}
	
}

/**
 *  イベント指定実行
 *  @param eventIndex イベントインデックス
 */
void GameEventService::executeEvent(int eventIndex) {
	
	if (events.find(eventIndex) == events.end()){
		// 存在しない
		return;
	}
	
	GameEventEntity eventEntity = events[eventIndex];
	if (eventEntity.isExecute) {
		// すでに終了済み
		return;
	}
	runEvent(eventIndex);
}

/**
 *  イベント指定開始
 *  @param eventIndex イベントインデックス
 */
void GameEventService::runEvent(int eventIndex) {
	// 現在実行中
	if (executeEventIndex >= 0) {
		waitingEventIndexs.push_back(eventIndex);
		return;
	}
	
	// 即実行
	executeEventIndex = eventIndex;
	executeEventDetailIndex = 0;
	executeEventCount1 = 0;
	executeEventCount2 = 0;
	
	// 自動ならば実行フラグをONにする
	if (events[eventIndex].initConditionType == EventInitConditionType::Auto) {
		events[eventIndex].isExecute = true;
	}
}

#pragma mark - メッセージ

/**
 *  メッセージ表示
 *
 *  @param message メッセージ
 */
void GameEventService::showMessage(string message) {
	
	
}

/**
 *  乱数と内容を比較 SubSubIfRand
 *
 *  @param value 値
 *
 *  @return 比較可否
 */
bool GameEventService::compareRandom(int value) {
	random_device rnd;
	return (rnd() % 100) < value;
}


