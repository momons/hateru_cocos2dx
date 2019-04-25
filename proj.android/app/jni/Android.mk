LOCAL_PATH := $(call my-dir)

# Firebase
FIREBASE_CPP_SDK_DIR := $(LOCAL_PATH)/../../../../../Firebase/firebase_cpp_sdk
APP_ABI := armeabi-v7a x86
STL := $(firstword $(subst _, ,$(APP_STL)))
FIREBASE_LIBRARY_PATH := $(FIREBASE_CPP_SDK_DIR)/libs/android/$(TARGET_ARCH_ABI)/$(STL)

# Firebase Application
include $(CLEAR_VARS)
LOCAL_MODULE := firebase_app
LOCAL_SRC_FILES := $(FIREBASE_LIBRARY_PATH)/libfirebase_app.a
LOCAL_EXPORT_C_INCLUDES := $(FIREBASE_CPP_SDK_DIR)/include
include $(PREBUILT_STATIC_LIBRARY)

# Firebase Authentication
include $(CLEAR_VARS)
LOCAL_MODULE := firebase_auth
LOCAL_SRC_FILES := $(FIREBASE_LIBRARY_PATH)/libfirebase_auth.a
LOCAL_EXPORT_C_INCLUDES := $(FIREBASE_CPP_SDK_DIR)/include
include $(PREBUILT_STATIC_LIBRARY)

# Firebase Realtime Database
include $(CLEAR_VARS)
LOCAL_MODULE := firebase_database
LOCAL_SRC_FILES := $(FIREBASE_LIBRARY_PATH)/libfirebase_database.a
LOCAL_EXPORT_C_INCLUDES := $(FIREBASE_CPP_SDK_DIR)/include
include $(PREBUILT_STATIC_LIBRARY)

# Firebase Remote Config
include $(CLEAR_VARS)
LOCAL_MODULE := firebase_remote_config
LOCAL_SRC_FILES := $(FIREBASE_LIBRARY_PATH)/libfirebase_remote_config.a
LOCAL_EXPORT_C_INCLUDES := $(FIREBASE_CPP_SDK_DIR)/include
include $(PREBUILT_STATIC_LIBRARY)

# Firebase Functions
include $(CLEAR_VARS)
LOCAL_MODULE := firebase_functions
LOCAL_SRC_FILES := $(FIREBASE_LIBRARY_PATH)/libfirebase_functions.a
LOCAL_EXPORT_C_INCLUDES := $(FIREBASE_CPP_SDK_DIR)/include
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE := MyGame_shared
LOCAL_MODULE_FILENAME := libMyGame

LOCAL_SRC_FILES_JNI_PREFIXED := \
    $(wildcard $(LOCAL_PATH)/../../../Classes/*.cpp) \
    $(wildcard $(LOCAL_PATH)/../../../Classes/**/*.cpp) \
    $(wildcard $(LOCAL_PATH)/../../../Classes/**/**/*.cpp) \
    $(wildcard $(LOCAL_PATH)/../../../Classes/**/**/**/*.cpp) \
    $(wildcard $(LOCAL_PATH)/../../../Classes/**/**/**/**/*.cpp)

LOCAL_SRC_FILES := \
	$(LOCAL_PATH)/hellocpp/main.cpp \
	$(LOCAL_SRC_FILES_JNI_PREFIXED)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END

LOCAL_STATIC_LIBRARIES := cc_static firebase_auth firebase_database firebase_remote_config firebase_functions firebase_app

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module, cocos)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
