//
//  UUIDUtil.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/31.
//
//

#include "UUIDUtil.h"

#include <uuid/uuid.h>

/**
 *  UUID生成
 *
 *  @return UUID
 */
string UUIDUtil::create() {

	uuid_t value;
	uuid_string_t string;
	
	uuid_generate(value);
	uuid_unparse_upper(value, string);
	
	return string;
}
