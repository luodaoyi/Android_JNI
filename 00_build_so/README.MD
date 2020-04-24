# 使用NDK编译c语言可执行程序

# 构建命令
```cmd
ndk-build NDK_PROJECT_PATH=. APP_BUILD_SCRIPT=./Android.mk
```

# 调用命令
```cmd
adb push libs/armeabi/hello /data/local/tmp
adb shell
su
cd /data/local/tmp
chmod 777 /data/local/tmp/hello
./hello
```

# 问题

如果代码中有中文输入输出,编译后cmd中执行发现是乱码的话 则需要在执行钱将cmd窗口字符集改为UTF-8


```shell
chcp 65001
```