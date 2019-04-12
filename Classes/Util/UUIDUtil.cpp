//
//  UUIDUtil.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/31.
//
//

#include "UUIDUtil.h"

#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)
#include <uuid/uuid.h>
#endif

/**
 *  UUID生成
 *
 *  @return UUID
 */
string UUIDUtil::create() {

#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)
	uuid_t value;
	uuid_string_t string;
	
	uuid_generate(value);
	uuid_unparse_upper(value, string);
	
	return string;
#else
    // TODO: Androidは考える
    return "";
#endif
}
