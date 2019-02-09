//
//  GameConst.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameConst_h
#define GameConst_h

/// enum→数値変換用マクロ
#define ENUM_INT(value) static_cast<int>(value)

#pragma mark - ユニット

/// ステータスタイプ
enum class UnitStatusType {
	/// LV
	Lv,
	/// 職業
	Job,
	/// HP
	HP,
	/// MP
	MP,
	/// 最大HP
	MaxHP,
	/// 最大MP
	MaxMP,
	/// 攻撃力
	Attack,
	/// 精神力
	Mental,
	/// 防御力
	Defence,
	/// 機敏さ
	Speed,
	/// 経験値
	EXP,
	/// 名声
	Fame,
	/// 道徳心
	Moral,
	/// 装備後HP
	HPEq,
	/// 装備後MP
	MPEq,
	/// 装備後攻撃力
	AttackEq,
	/// 装備後精神力
	MentalEq,
	/// 装備後防御力
	DefenceEq,
	/// 装備後機敏さ
	SpeedEq,
	/// 装備後炎耐性
	FireEq,
	/// 装備後氷耐性
	IceEq,
	/// 装備後雷耐性
	ThunderEq,
	/// 装備後毒耐性
	PoisonEq,
	/// 次のレベルまでの経験値
	NextEXP,
	/// 装備後名声
	FameEq,
	/// 装備後道徳心
	MoralEq,
	/// 命中率
	HitRate,
	/// 必殺率
	CriticalRate,
	/// 所持金(ステータス分岐用)
	Money,
	/// 方向(ステータス分岐用)
	Direction,
};

/// 装備タイプ
enum class EquipmentType {
	/// 武器
	Weapon,
	/// 防具
	Armar,
	/// 盾
	Shield,
	/// 兜
	Helm,
	/// 装飾品
	Accessory,
};

/// 状態治療
enum class ConditionType {
	/// なし
	None,
	/// 戦闘不能
	Die,
	/// 毒
	Poison,
	/// 暗闇
	Darkness,
	/// 沈黙
	Silence,
	/// 混乱
	Confusion,
	/// 睡眠
	Sleep,
	/// 麻痺
	Parray,
};

/// 攻撃属性
enum class AttackAttributeType {
	/// なし
	None,
	/// 打撃
	Blow,
	/// 炎
	Fire,
	/// 氷
	Ice,
	/// 雷
	Thunder,
	/// 毒
	Poison,
};

#pragma mark - マップ

/// マップタイプ
enum class MapType {
	/// 通常
	Normal,
	/// 自動
	Auto
};

/// 地図端制御タイプ
enum class MapLoopType {
	/// 制御なし
	None,
	/// 固定
	Fixtation,
	/// ループ
	Loop,
};

/// 移動タイプ
enum class MoveType {
	/// 歩行
	Walk,
	/// 船
	Ship,
	/// 飛行船
	FlyShip,
};

/// 乗り物タイプ
enum class VehicleType {
	/// 船
	Ship,
	/// 飛行船
	FlyShip,
};

#pragma mark - 自動マップ

/// 下チップタイプ
enum class AutoMapDownChipType {
	/// 床
	Floor = 1,
	/// 壁(影有)
	WallShadow,
	/// 壁(影無)
	Wall,
};

/// 上チップタイプ
enum class AutoMapUpChipType {
	/// 下階段
	BelowStairs = 1,
	/// 上階段
	AboveStairs,
	/// 宝箱
	Chest,
};

/// イベントタイプ
enum class AutoMapEventType {
	/// 下階段
	BelowStairs = 1,
	/// 上階段
	AboveStairs,
	/// 宝箱
	Chest,
};

#pragma mark - イベント

/// イベントタイプ
enum class EventType {
	///	メッセージ表示
	Message,
	///	HP増減
	FluctuateHP	,
	///	MP増減
	FluctuateMP	,
	///	所持金増減
	FluctuateGold	,
	///	経験値増減
	FluctuateEXP	,
	///	アイテム増減
	FluctuateItem	,
	///	変数操作
	OperateVariable,
	///	BGM変更
	ChangeBGM		,
	///	マップチップ変更
	ChangeChip		,
	///	キャラ変更
	ChangeUnit		,
	///	場所移動
	MoveLocation	,
	///	変数分岐
	IfVariable		,
	///	セーブ
	Save			,
	///	道具屋
	ItemShop		,
	///	宿屋
	INN			,
	///	預り所
	Cloakroom		,
	///	教会
	Church			,
	///	戦闘
	Battle			,
	///	テレポート位置増減
	FluctuateTeleport,
	///	テレポート禁止変更
	ChangeTeleport	,
	///	エスケープ禁止変更
	ChangeEscape	,
	///	ワイプ
	Wipe			,
	///	メンバー入替
	ExchangeUnit	,
	///	変数分岐終了
	EndIf			,
	///	画像表示
	ShowImage		,
	///	職業変更
	ChangeJob		,
	///	ステータス分岐
	IfStatus		,
	///	アイテム分岐
	IfItem			,
	///	特殊技能分岐
	IfSkill		,
	///	敵出現率
	EncountRate	,
	///	エスケープで戻る位置を保存
	SaveEscapeLocation,
	///	船設定
	SettingShip	,
	///	イベント終了
	Exit			,
	///	YESNO選択
	SelectYesNo	,
	///	キャラ移動
	MoveMobUnit	,
	///	主人公移動
	MoveUnit		,
	///	船乗降り
	GettingOnOff	,
	///	調合屋
	MixShop		,
	///	リアルタイム分岐
	IfTime			,
	///	酒場
	Bar			,
	///	バザー
	ItemBazaar		,
	///	掲示板
	BBS			,
	///	機種判別
	IfTerminal		,
	///	ジングル
	Jingle			,
	///	乱数
	Random			,
};

/// 増減タイプ
enum class FluctuateType {
	/// 増
	Increase,
	/// 減
	Decline
};

/// サウンドフィールドタイプ
enum class SoundFieldType {
	/// マップ
	Map,
	/// 戦闘
	Battle,
};

/// 分岐式
enum class IfFormulaType {
	/// ＝
	Equal,
	/// ≠
	NotEqual,
	/// ＜
	LessThan,
	/// ＞
	GreaterThan,
	/// ≦
	LessThanEqual,
	/// ≧
	GreaterThanEqual,
};

/// メンバーチェンジタイプ
enum class ExchangeUnitType {
	/// 外す
	Remove,
	/// 追加
	Add,
	/// 入替
	Shift,
};

/// キャラの方向
enum class DirectionType {
	/// 上向き
	Up,
	/// 右向き
	Right,
	/// 下向き
	Down,
	/// 左向き */
	Left,
};

/// イベント移動タイプ
enum class EventMoveType {
	/// 上移動
	MoveUp,
	/// 右移動
	MoveRight,
	/// 下移動
	MoveDown,
	/// 左移動
	MoveLeft,
	/// 上向き
	FaceUp,
	/// 右向き
	FaceRight,
	/// 下向き
	FaceDown,
	/// 左向き
	FaceLeft,
	/// ループ
	Loop,
	/// 移動頻度
	MoveCount,
};

/// 日時タイプ
enum class DateTimeType {
	/// 月
	Month,
	/// 日
	Day,
	/// 時
	Hour,
	/// 分
	Minute,
	/// 秒
	Second,
	/// 週
	Week,
};

/// イベント開始タイプ
enum class EventInitConditionType {
	/// キー
	Key,
	/// 離れたら
	Leave,
	/// 触れたら
	Touch,
	/// 自動
	Auto,			
};

/// イベント詳細移動タイプ
enum class EventDetailMoveType {
	/// 動かない
	NoMove,
	/// ランダム
	Random,
	/// 主人公に近づく
	Near,
	/// 主人公から離れる
	Far,
	/// 詳細設定
	Set,
};

/// イベント作業ステータスタイプ
enum class EventWorkStatus {
	// マップ上に存在しない
	NoMap,
	// 無効
	Invalid,
	// 有効
	Valid,
	// 実行
	Execute,
};

#pragma mark - 敵

/// 敵ステータスタイプ
enum class EnemyStatusType {
	/// 最大HP
	MaxHP,
	/// 最大MP
	MaxMP,
	/// 攻撃力
	Attack,
	/// 精神力
	Mental,
	/// 防御力
	Defence,
	/// 機敏さ
	Speed,
	/// 装備後炎耐性
	Fire,
	/// 装備後氷耐性
	Ice,
	/// 装備後雷耐性
	Thunder,
	/// 装備後毒耐性
	Poison,
	/// 所持金
	Money,
	/// 経験値
	EXP,
	/// 命中率
	HitRate,
	/// 必殺率
	CriticalRate,
};

#pragma mark - 職業

/// レベルアップ時のステータスタイプ
enum class AddStatusType {
	/// 最大HP
	MaxHP,
	/// 最大MP
	MaxMP,
	/// 攻撃力
	Attack,
	/// 精神力
	Mental,
	/// 防御力
	Defence,
	/// スピード
	Speed,
	/// レベルアップ経験値
	EXP,
};

#pragma mark - アイテム

/// アイテム種別
enum class ItemType {
	/// 通常
	Normal,
	/// 武器
	Weapon,
	/// 鎧
	Armar,
	/// 盾
	Shield,
	/// 兜
	Helm,
	/// 装飾品
	Access,
	/// 回復
	Recovery,
	/// 種
	Seed,
	/// 地図
	Map,
	/// 職業変更
	Job,
	/// 特技追加
	Skill,
};

/// アイテムステータス種別
enum class ItemStatusType {
	/// 影響なし
	Nothing,
	/// 最大HPに影響
	HP,
	/// 最大MPに影響
	MP,
	/// 攻撃力に影響
	Attack,
	/// 精神力に影響
	Mental,
	/// 防御力に影響
	Defence,
	/// 機敏性に影響
	Speed,
	/// 炎耐性に影響
	Fire,
	/// 氷耐性に影響
	Ice,
	/// 雷耐性に影響
	Thunder,
	/// 毒耐性に影響
	Poison,
	/// ヒット回数
	HitCount,
	/// 名声
	Fame,
	/// 道徳心
	Moral,
	/// 命中率
	HitRate,
	/// 必殺率
	CriticalRate,
};

#pragma mark - スキル

/// 特殊技能種別
enum class SkillType {
	/// 攻撃
	Attack,
	/// 回復
	Recvary,
	/// テレポート
	Teleport,
	/// エスケープ
	Escape,
	/// 地図
	Map,
};

/// 効果範囲
enum class EffectRangeType {
	/// 使用者
	User,
	/// 単体
	Single,
	/// 全員
	All,
};

#pragma mark - 変数

/// 変数変化増減タイプ
enum class VariableOperateType {
	///	代入
	Assignment,
	///	増
	Increase,
	///	減
	Decline,
};

#pragma mark - バトル

/// バトル
enum class BattleStatusType {
	/// 最大HP
	MaxHP,
	/// 最大MP
	MaxMP,
	/// 移動中の攻撃力
	MaxAttack,
	/// 移動中の精神力
	MaxMental,
	/// 移動中の防御力
	MaxDefence,
	/// 移動中の機敏さ
	MaxSpeed,
	/// HP
	HP,
	/// MP
	MP,
	/// 攻撃力
	Attack,
	/// 精神力
	Mental,
	/// 防御力
	Defence,
	/// 機敏さ
	Speed,
	/// 炎耐性
	Fire,
	/// 氷耐性
	Ice,
	/// 雷耐性
	Thunder,
	/// 毒耐性
	Poison,
	/// 金
	Money,
	/// 経験値
	EXP,
	/// 命中率
	HitRate,
	/// 必殺率
	CriticalRate,
	/// 状態
	Condition,
	/// ヒット
	Hit,
	/// バトルステータスMAX
	Max,
};

/// ゲーム定数定義クラス
class GameConst final {
public:
	
	/// フレームレート
	static const int frameRate = 60;
	
	/// 最大レベル
	static const int maxLevel = 99;
	
	/// イベントターゲットタイプ　全て
	static const int eventTargetTypeAll = 0;
	
	/// 初期メンバーカウント
	static const int initMemberCount = 3;
	
	/// マップチップ最大数
	static const int mapChipValueMax = 63;
	
	/// 1マスのドット数
	static const int mapOnePanelDot = 28;
	
	/// パーティ数
	static const int maxParty = 3;
	/// 最大スキル数
	static const int maxUnitSkill = 24;
	/// 最大アイテム数
	static const int maxUnitItem = 16;
	
	/// スプライト倍率
	static constexpr float spriteScale = 4.0;

	/// 下チップZインデックス
	static const int zSortDownMapChip = 1;
	/// 上チップZインデックス(投下なし)
	static const int zSortUpMapChip = 2;
	/// ユニットZインデックス + Y座標
	static const int zSortUnit = 100;
	/// 上チップZインデックス(投下あり) + Y座標
	static const int zSortUpMapChipTrans = 100;
	
private:
	
	/**
	 *  コンストラクタ
	 */
	GameConst() {}
	
	/**
	 *  デストラクタ
	 */
	~GameConst() {}
};


#endif /* GameConst_h */
