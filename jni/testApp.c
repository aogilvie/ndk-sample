#include <jni.h>
#include <android/log.h>
#include <string.h>

#define  LOG_TAG "testApp"
#define  Log(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)


void Java_com_example_testapp_MainActivity_nativeMyFunction(JNIEnv *env, jobject thiz, jstring message)
{
	const char *messageAsChar = (*env)->GetStringUTFChars(env, message, 0);
	Log("Message is in C: %s", messageAsChar);
}
