LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_ARM_MODE := arm
LOCAL_MODULE    := hello        #模块名称
LOCAL_SRC_FILES := com_example_jnidemo_MainActivity.cpp    #源文件名
include $(BUILD_SHARED_LIBRARY)         #编译为So库文件