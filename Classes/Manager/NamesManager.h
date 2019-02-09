//
//  NamesManager.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/18.
//
//

#ifndef NamesManager_h
#define NamesManager_h

#include "BaseManager.h"
#include "NamesEntity.h"

/// 名前リストマネージャ
class NamesManager final: BaseManager {
public:
	
	/// マップチップ
	static const string typeChipGroup;
	/// マップ
	static const string typeMap;
	/// サウンド
	static const string typeSound;
	/// 変数
	static const string typeVariable;
	
	/**
	 *  読み込み
	 *
	 *  @param fileName ファイル名
	 *
	 *  @return 取得データ
	 */
	static NamesEntity load(const string &fileName);
	
	/**
	 *  イベントリストファイル名を取得する
	 *
	 *  @param id イベントID
	 *
	 *  @return イベントリストファイル名
	 */
	static string eventListName(const int id);
	
private:
	
	/**
	 *  コンストラクタ
	 */
	NamesManager() {}
	
	/**
	 *  デストラクタ
	 */
	~NamesManager() {}
};

#endif /* NamesManager_h */
