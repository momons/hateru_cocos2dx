//
//  GameEtcManager.cpp
//  hateru_cocos2dx-mobile
//
//  Created by Kazunari Hara on 2019/02/25.
//

#include "GameEtcManager.h"

#include <iostream>
#include <iomanip>
#include <sstream>

/**
 *  ファイルパス取得
 *
 *  @param imageId 画像Id
 *
 *  @return ファイルパス
 */
string GameEtcManager::getImageFilePath(const int imageId) {
    ostringstream ostr;
    ostr << "game/Etc/" << setfill('0') << setw(3) << imageId << ".png";
    return ostr.str();
}
