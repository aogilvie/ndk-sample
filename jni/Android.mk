LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_LDLIBS := -llog

LOCAL_MODULE    := testLib
LOCAL_SRC_FILES := testApp.c

include $(BUILD_SHARED_LIBRARY)