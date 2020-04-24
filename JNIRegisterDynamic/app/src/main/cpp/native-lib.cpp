#include <jni.h>
#include <string>

#include <android/log.h>

#define LOG_TAG    "JniDebugLogger"
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGF(...)  __android_log_print(ANDROID_LOG_FATAL, LOG_TAG, __VA_ARGS__)

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_jniregisterdynamic_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

jint NativeAdd(JNIEnv *env, jobject obj, jint a, jint b) {
    return a + b;
}

jint NativeSub(JNIEnv *env, jobject obj, jint a, jint b) {
    return a - b;
}

jint NativeMul(JNIEnv *env, jobject obj, jint a, jint b) {
    return a * b;
}

jint NativeDiv(JNIEnv *env, jobject obj, jint a, jint b) {
    return a / b;
}

// JNI函数签名数组
JNINativeMethod jniNativeMethods[]
        {
                {"add", "(II)I", (void *) NativeAdd},
                {"sub", "(II)I", (void *) NativeSub},
                {"mul", "(II)I", (void *) NativeMul},
                {"div", "(II)I", (void *) NativeDiv}
        };

jint RegistNativeMethods(JNIEnv *env) {
    //获得class
    jclass clazz = env->FindClass("com/example/jniregisterdynamic/MainActivity");
    //执行动态注册
    if (env->RegisterNatives(clazz, jniNativeMethods,
                             sizeof(jniNativeMethods) / sizeof(jniNativeMethods[0])) == JNI_OK) {

        return JNI_OK;
    }
    return JNI_ERR;
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *jniEnv = nullptr;
    if (vm->GetEnv((void **) &jniEnv, JNI_VERSION_1_6) != JNI_OK) {
        LOGE("GetEnv ERROR");
        return JNI_ERR;
    }
    if (RegistNativeMethods(jniEnv) != JNI_OK) {
        LOGE("RegistNativeMethods FAILED");
        return JNI_ERR;
    }
    return JNI_VERSION_1_6;
}