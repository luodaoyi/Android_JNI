LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_ARM_MODE := arm
LOCAL_MODULE    := hello        #ģ������
LOCAL_SRC_FILES := com_example_jnidemo_MainActivity.cpp    #Դ�ļ���
include $(BUILD_SHARED_LIBRARY)         #����ΪSo���ļ�