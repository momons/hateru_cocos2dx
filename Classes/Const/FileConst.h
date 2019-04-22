//
//  FileConst.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/18.
//
//

#ifndef FileConst_h
#define FileConst_h

#include <string>

using namespace std;

/// ファイル定数定義クラス
class FileConst final {
public:
	
	/// リソースゲームパス
	static const string resouceGamePath;
	
	/// データ保存ファイル名
	static const string saveFileName;
	
	/// 画像ファイル名
	static const string gameImagesFileName;
    
private:
	
	/**
	 *  コンストラクタ
	 */
	FileConst() {}
	
	/**
	 *  デストラクタ
	 */
	~FileConst() {}
};

#endif /* FileConst_h */
