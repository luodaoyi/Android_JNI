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

发现这里乱码 原因是项目使用的是UTF-8编码，而CMD控制台默认使用的GBK编码!


解决上述问题就是修改CMD窗口的默认代码页为UTF-8编码即可，我们新建一个CMD窗口，输入命令`chcp 65001`，意思是修改CMD的代码页为65001,65001就是UTF-8编码


