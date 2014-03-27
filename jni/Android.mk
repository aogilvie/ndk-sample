LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_LDLIBS := -llog -landroid

LOCAL_MODULE    := testLib
LOCAL_SRC_FILES := testApp.cpp

include $(BUILD_SHARED_LIBRARY)