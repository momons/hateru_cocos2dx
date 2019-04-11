//
//  GameEventVariableService.cpp
//  hateru
//
//  Created by HaraKazunari on 2017/01/26.
//
//

#include "GameEventVariableService.h"

#include "GameEventService.h"
#include "../Entity/Player/PlayerEntity.h"
#include "../Entity/Game/Map/GameMapEntity.h"
#include "../Entity/Game/Event/Detail/GameEventBaseEntity.h"
#include "../Entity/Game/Event/Detail/GameEventOperateVariableEntity.h"

#pragma mark - 初期化

/**
 *  コンストラクタ
 *
 *  @param eventService イベントサービス
 */
GameEventVariableService::GameEventVariableService(GameEventService *eventService) {
	// 退避
	this->eventService = eventService;
}

/**
 *  デストラクタ
 */
GameEventVariableService::~GameEventVariableService() {
}


#pragma mark - 変数操作

/**
 *  変数操作 SubSetNum
 *
 *  @param entity イベント詳細Entity
 */
void GameEventVariableService::operateVariable(GameEventBaseEntity *entity) {
	GameEventOperateVariableEntity *detailEntity = (GameEventOperateVariableEntity *)entity;
	
	switch (detailEntity->operateType) {
		case VariableOperateType::Assignment:
			eventService->playerEntity->variables[detailEntity->variableId] = detailEntity->value;
			break;
		case VariableOperateType::Increase:
			eventService->playerEntity->variables[detailEntity->variableId] += detailEntity->value;
			break;
		case VariableOperateType::Decline:
			eventService->playerEntity->variables[detailEntity->variableId] -= detailEntity->value;
			break;
	}
	eventService->playerEntity->variables[detailEntity->variableId] &= 0xff;
	
	// イベント
	for (auto it = eventService->events.begin();it != eventService->events.end();it++) {
		// 有効ではない
		if (it->second.workStatus == EventWorkStatus::NoMap) {
			continue;
		}
		it->second.workStatus = EventWorkStatus::Invalid;
		// 変数チェック
		if (it->second.isIgnitionVariable) {
			if (!compareVariable(eventService->playerEntity->variables[it->second.variableId], it->second.value, it->second.formulaType)) {
				if (it->second.isUseUnit) {
					// ユニットを扱っている場合消す
					// TODO: SubDelShow
					continue;
				}
			}
		}
		// ステータス設定
		it->second.initEventStatus();
	}
}

/**
 *  変数の内容を比較 SubIf
 *
 *  @param valueSource      元値
 *  @param valueDestination 比較値
 *  @param formulaType      比較式
 *
 *  @return 比較可否
 */
bool GameEventVariableService::compareVariable(int valueSource, int valueDestination, IfFormulaType formulaType) {
	bool isValid = true;
	switch (formulaType) {
		case IfFormulaType::Equal:
			isValid = (valueSource == valueDestination);
			break;
		case IfFormulaType::NotEqual:
			isValid = (valueSource != valueDestination);
			break;
		case IfFormulaType::LessThan:
			isValid = (valueSource < valueDestination);
			break;
		case IfFormulaType::GreaterThan:
			isValid = (valueSource > valueDestination);
			break;
		case IfFormulaType::LessThanEqual:
			isValid = (valueSource <= valueDestination);
			break;
		case IfFormulaType::GreaterThanEqual:
			isValid = (valueSource >= valueDestination);
			break;
	}
	
	return isValid;
}
