#include "com_example_jnidemo_MainActivity.h"

JNIEXPORT jstring JNICALL Java_com_example_jnidemo_MainActivity_Hello
  (JNIEnv * env, jobject obj)
{
	return env->NewStringUTF("Hello JNI");
}
