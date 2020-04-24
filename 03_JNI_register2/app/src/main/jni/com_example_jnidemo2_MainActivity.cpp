//
// Created by asura on 2020/4/24.
//

#include "com_example_jnidemo2_MainActivity.h"

/*
 * Class:     com_example_jnidemo2_MainActivity
 * Method:    get_reflection_field
 * Signature: ()Ljava/lang/String;
 */
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_jnidemo2_MainActivity_get_1reflection_1field(JNIEnv *env, jobject obj) {
    auto clazz = env->FindClass("com/example/jnidemo2/MainActivity");
    auto fieldId = env->GetFieldID(clazz, "ReflectionField", "Ljava/lang/String;");
    auto pJstring = (jstring) env->GetObjectField(obj, fieldId);
    return pJstring;
}

/*
 * Class:     com_example_jnidemo2_MainActivity
 * Method:    get_static_reflection_field
 * Signature: ()Ljava/lang/String;
 */
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_jnidemo2_MainActivity_get_1static_1reflection_1field(JNIEnv *env, jobject obj) {
    auto clazz = env->FindClass("com/example/jnidemo2/MainActivity");
    auto fieldId = env->GetStaticFieldID(clazz, "StaticReflectionField", "Ljava/lang/String;");
    auto pJstring = (jstring) env->GetStaticObjectField(clazz, fieldId);
    return pJstring;
}

/*
 * Class:     com_example_jnidemo2_MainActivity
 * Method:    set_reflection_field
 * Signature: (Ljava/lang/String;)V
 */
extern "C" JNIEXPORT void JNICALL
Java_com_example_jnidemo2_MainActivity_set_1reflection_1field(JNIEnv *env, jobject obj,
                                                              jstring str) {
    auto clazz = env->FindClass("com/example/jnidemo2/MainActivity");
    auto fieldId = env->GetFieldID(clazz, "ReflectionField", "Ljava/lang/String;");
    env->SetObjectField(obj, fieldId, str);
}

/*
 * Class:     com_example_jnidemo2_MainActivity
 * Method:    set_static_reflection_field
 * Signature: (Ljava/lang/String;)V
 */
extern "C" JNIEXPORT void JNICALL
Java_com_example_jnidemo2_MainActivity_set_1static_1reflection_1field(JNIEnv *env, jobject obj,
                                                                      jstring str) {
    auto clazz = env->FindClass("com/example/jnidemo2/MainActivity");
    auto fieldId = env->GetStaticFieldID(clazz, "StaticReflectionField", "Ljava/lang/String;");
    env->SetStaticObjectField(clazz, fieldId, str);
}

extern "C" JNIEXPORT jstring JNICALL Java_com_example_jnidemo2_MainActivity_CallMethod
        (JNIEnv *env, jobject jobj, jstring watermark) {
    auto clazz = env->FindClass("com/example/jnidemo2/MainActivity");
    auto method_id = env->GetMethodID(clazz, "DemoMethod",
                                      "(Ljava/lang/String;)Ljava/lang/String;");
    auto method_return = (jstring) env->CallObjectMethod(jobj, method_id, watermark);

    return method_return;
}

extern "C" jstring JNICALL Java_com_example_jnidemo2_MainActivity_CallStaticMethod
        (JNIEnv *env, jobject jobj, jstring watermark) {
    auto clazz = env->FindClass("com/example/jnidemo2/MainActivity");
    auto static_method_id = env->GetStaticMethodID(clazz, "StaticDemoMethod",
                                                   "(Ljava/lang/String;)Ljava/lang/String;");
    auto static_method_return = (jstring) env->CallStaticObjectMethod(clazz, static_method_id,
                                                                      watermark);
    return static_method_return;
}