//
//  GameEtcManager.h
//  hateru_cocos2dx
//
//  Created by Kazunari Hara on 2019/02/25.
//

#ifndef GameEtcManager_h
#define GameEtcManager_h

#include <string>

using namespace std;

/// ゲームその他マネージャ
class GameEtcManager final {
public:
    
    /**
     *  ファイルパス取得
     *
     *  @param imageId 画像Id
     *
     *  @return ファイルパス
     */
    static string getImageFilePath(const int imageId);
    
private:
    
    /**
     *  コンストラクタ
     */
    GameEtcManager() {}
    
    /**
     *  デストラクタ
     */
    ~GameEtcManager() {}
};

#endif /* GameEtcManager_h */
