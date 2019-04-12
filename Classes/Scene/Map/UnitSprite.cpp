//
//  UnitSpite.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/15.
//
//

#include "UnitSprite.h"

#include <iostream>
#include <iomanip>

#include "Manager/GameCharaManager.h"
#include "Const/GameConst.h"

/**
 *  クラス作成
 *
 *  @param entity キャラEntity
 *
 *  @return クラス
 */
UnitSprite *UnitSprite::create(const GameCharaEntity &entity) {
	auto sprite = new UnitSprite();
	if(sprite && sprite->init()){
		sprite->Node::autorelease();
		sprite->setup(entity);
		return sprite;
	}else {
		delete sprite;
		sprite = nullptr;
		return nullptr;
	}
}

/**
 *  コンストラクタ
 */
UnitSprite::UnitSprite() {
}

/**
 *  デストラクタ
 */
UnitSprite::~UnitSprite() {
	
}

/**
 *  セットアップ
 *
 *  @param entity キャラEntity
 */
void UnitSprite::setup(const GameCharaEntity &entity) {

	// 退避
	this->entity = entity;
	
	// 初期設定
	x = 0;
	y = 0;
	mapX = 0;
	mapY = 0;
	directionType = DirectionType::Down;
	isStopWalk = false;
	walkCount = 0;
	scheduleCount = 0;
	
	// 画像を変更
	setSpriteFrame(getSpriteFrame());
	
	// スケジュール設定
	scheduleUpdate();
}

/**
 *  スケジュール更新
 *
 *  @param delta delta
 */
void UnitSprite::update(float delta) {

	// カウントアップ
	scheduleCount = (scheduleCount + 1) % GameConst::frameRate;
	
	// 歩くカウント設定
	if (scheduleCount == 0 && !isStopWalk) {
		walkCount = (walkCount + 1) % 2;
		// 画像を変更
		setSpriteFrame(getSpriteFrame());
	}
}

/**
 *  画像Id取得
 *
 *  @param directionType 向き
 *
 *  @return 画像インデックス
 */
int UnitSprite::getImageId(DirectionType directionType) {
	return entity.imageIds[ENUM_INT(directionType) * 2 + walkCount];
}

/**
 *  SpriteFrame取得
 *
 *  @return SpriteFrame
 */
SpriteFrame *UnitSprite::getSpriteFrame() {
	auto filePath = GameCharaManager::getImageFilePath(getImageId(directionType));
	auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(filePath);
	return frame;
}

#pragma mark - getter setter

/**
 *  向きを設定
 *
 *  @param direction 向きタイプ
 */
void UnitSprite::setDirectionType(DirectionType directionType) {
	// 向きが一緒
	if (this->directionType == directionType) {
		return;
	}
	// 画像が一緒
	if (getImageId(this->directionType) == getImageId(directionType)) {
		return;
	}
	
	// 退避
	this->directionType = directionType;
	
	// 画像を変更
	setSpriteFrame(getSpriteFrame());
}

/**
 *  マップ座標を設定する
 *
 *  @param mapX マップX座標
 *  @param mapY マップY座標
 */
void UnitSprite::setMapLocation(int mapX, int mapY) {
	this->mapX = mapX;
	this->mapY = mapY;
	x = mapX * GameConst::mapOnePanelDot;
	y = mapY * GameConst::mapOnePanelDot;
}

/**
 *  向きを取得
 *
 *  @return 向きタイプ
 */
DirectionType UnitSprite::getDirectionType() {
	return directionType;
}

/**
 *  歩きストップ設定
 *
 *  @param isStopWalk 歩きストップフラグ
 */
void UnitSprite::setStopWalk(bool isStopWalk) {
	this->isStopWalk = isStopWalk;
}
