LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)                   #会清理除了LOCAL_PATH歪的其他LOCAL文件路径
LOCAL_ARM_MODE := arm                   #模块指令集
LOCAL_MODULE    := hello        #模块名称
LOCAL_SRC_FILES := com_example_jnidemo2_MainActivity.cpp    #源文件名
include $(BUILD_SHARED_LIBRARY)         #编译为So库文件