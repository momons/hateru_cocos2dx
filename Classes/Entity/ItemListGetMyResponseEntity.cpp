//
//  ItemListGetMyResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "ItemListGetMyResponseEntity.h"

#include "LogConst.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool ItemListGetMyMetaResponseEntity::mapping(picojson::object &object) {
	if (object["items"].is<picojson::array>()) {
		picojson::array array = object["items"].get<picojson::array>();
		for (picojson::array::iterator it = array.begin(); it != array.end(); it++) {
			ItemInfoGetMetaResponseEntity item;
			item.mapping(it->get<picojson::object>());
			items.push_back(item);
		}
	} else {
		log(LogConst::jsonBadMappingError.c_str(), "items");
		return false;
	}
	return true;
}
