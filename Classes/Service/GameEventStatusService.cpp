//
//  GameEventStatusService.cpp
//  hateru
//
//  Created by HaraKazunari on 2017/01/26.
//
//

#include "GameEventStatusService.h"

#include "GameDataService.h"
#include "GameEventService.h"

#include "PlayerEntity.h"
#include "GameMapEntity.h"
#include "GameEventBaseEntity.h"
#include "GameEventFluctuateHPEntity.h"
#include "GameEventFluctuateMPEntity.h"
#include "GameEventFluctuateGoldEntity.h"
#include "GameEventFluctuateItemEntity.h"
#include "GameItemEntity.h"

#pragma mark - 初期化

/**
 *  コンストラクタ
 *
 *  @param eventService イベントサービス
 */
GameEventStatusService::GameEventStatusService(GameEventService *eventService) {
	// 退避
	this->eventService = eventService;
}

/**
 *  デストラクタ
 */
GameEventStatusService::~GameEventStatusService() {
}

#pragma mark - ステータス増減

/**
 *  ステータス増減
 *
 *  @param target           ターゲット
 *  @param maxStatusType    最大ステータスタイプ
 *  @param changeStatusType 変化ステータスタイプ
 *  @param value            値
 */
void GameEventStatusService::fluctuateStatus(int target, int maxStatusType, int changeStatusType, int value) {
	if (target == GameConst::eventTargetTypeAll) {
		for (auto it = eventService->playerEntity->units.begin();it != eventService->playerEntity->units.end();it++) {
			it->fluctuateStatus(maxStatusType, changeStatusType, value);
		}
	} else {
		target -= 1;
		if (target < eventService->playerEntity->units.size()) {
			eventService->playerEntity->units[target].fluctuateStatus(maxStatusType, changeStatusType, value);
		}
	}
}

/**
 *  HP増減
 *
 *  @param entity イベント詳細Entity
 */
void GameEventStatusService::fluctuateHP(GameEventBaseEntity *entity) {
	GameEventFluctuateHPEntity *detailEntity = (GameEventFluctuateHPEntity *)entity;
	int value = detailEntity->value * (detailEntity->fluctuateType == FluctuateType::Increase ? 1 : -1);
	fluctuateStatus(detailEntity->target, ENUM_INT(UnitStatusType::MaxHP), ENUM_INT(UnitStatusType::HP), value);
}

/**
 *  MP増減
 *
 *  @param entity イベント詳細Entity
 */
void GameEventStatusService::fluctuateMP(GameEventBaseEntity *entity) {
	GameEventFluctuateMPEntity *detailEntity = (GameEventFluctuateMPEntity *)entity;
	int value = detailEntity->value * (detailEntity->fluctuateType == FluctuateType::Increase ? 1 : -1);
	fluctuateStatus(detailEntity->target, ENUM_INT(UnitStatusType::MaxMP), ENUM_INT(UnitStatusType::MP), value);
}

/**
 *  所持金増減
 *
 *  @param entity イベント詳細Entity
 *
 *  @return 終了フラグ
 */
bool GameEventStatusService::fluctuateGold(GameEventBaseEntity *entity) {
	GameEventFluctuateGoldEntity *detailEntity = (GameEventFluctuateGoldEntity *)entity;
	int value = detailEntity->value * (detailEntity->fluctuateType == FluctuateType::Increase ? 1 : -1);
	eventService->playerEntity->money += value;
	if (eventService->playerEntity->money <= 0) {
		eventService->playerEntity->money = 0;
	}
	if (value > 0) {
		// +の場合はメッセージを表示
		eventService->showMessage(StringUtils::format("%d%sを手に入れた！", value, GameDataService::sharedInstance()->gameInfo.moneyUnit.c_str()));
		return true;
	}
	return false;
}

/**
 *  アイテム増減
 *
 *  @param entity イベント詳細Entity
 *
 *  @return 終了フラグ
 */
bool GameEventStatusService::fluctuateItem(GameEventBaseEntity *entity) {
	GameEventFluctuateItemEntity *detailEntity = (GameEventFluctuateItemEntity *)entity;
	GameItemEntity itemEntity = GameDataService::sharedInstance()->items[detailEntity->itemId];
	
	if (detailEntity->fluctuateType == FluctuateType::Increase) {
		// アイテム増イベント
		switch (eventService->executeEventCount1) {
			case 0: {
				// メッセージのみ
				eventService->showMessage(StringUtils::format("%sを手に入れた！", itemEntity.name.c_str()));
				eventService->executeEventCount1 += 1;
				break;
			}
			case 1: {
				// 実際アイテムを追加する
				auto isFull = eventService->playerEntity->addItem(detailEntity->itemId, itemEntity.useCount, "");
				if (isFull) {
					eventService->showMessage("荷物がいっぱいです\nどれを捨てますか？");
					eventService->executeEventCount1 += 1;
				} else {
					// 次のイベントへ
					eventService->executeEventDetailIndex += 1;
				}
				break;
			}
			case 2: {
				// TODO:キャラ選択メニュー表示
				
				eventService->executeEventCount1 += 1;
				break;
			}
			case 3: {
				// TODO:キャラ選択
				
				break;
			}
			case 4: {
				// TODO:捨てるアイテムを選択
				
				break;
			}
			case 5: {
				// TODO:捨てる確認
				
				break;
			}
		}
		
		// イベントを前に戻す
		eventService->executeEventDetailIndex -= 1;
		
		return true;
	}
	
	// アイテム減イベント
	auto isExist = eventService->playerEntity->removeItem(detailEntity->itemId);
	if (isExist) {
		eventService->showMessage(StringUtils::format("%sを手渡した", itemEntity.name.c_str()));
		return true;
	}
	return false;
}
