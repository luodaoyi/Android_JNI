LOCAL_PATH	:= $(call my-dir)		# 获取jni文件路径
include $(CLEAR_VARS)				# 因为是全局变量 所以要清理设置
LOCAL_CFLAGS += -std=c99            #使用c语言c99规范
LOCAL_CFLAGS += -pie -fPIE          #相当于在源文件中增加宏定义，安卓5.0以上需要添加,否则编译出来无法使用
LOCAL_LDFLAGS += -pie -fPIE         #相当于在源文件中增加宏定义，安卓5.0以上需要添加,否则编译出来无法使用
LOCAL_ARM_MODE	:= arm				# 编译后的指令集
LOCAL_MODULE	:= hello			# 编译后的名字 唯一且不可以包含空格 不是so就不会加.so so模块=> libbuild.so
LOCAL_SRC_FILES	:= hello.c			# 指定源文件
include $(BUILD_EXECUTABLE)			# 指定为构建可执行文件 
									# 如果是SO库为:    $(shared library) 
									# 如果是静态库为:   $(static library)