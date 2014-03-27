#include <jni.h>
#include <android/log.h>
#include <string.h>

#include <stdlib.h>
#include <stdio.h>

#include <android/asset_manager_jni.h>
#include <android/asset_manager.h>

#define  LOG_TAG "testApp"
#define  Log(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

extern "C" {

	JNIEXPORT void JNICALL Java_com_example_testapp_MainActivity_nativeMyFunction(JNIEnv *env, jobject thiz, jstring message, jobject assetManager)
	{
		AAssetManager *aassetManager = AAssetManager_fromJava(env, assetManager);

		const char *filename = "dir/textfile.txt";

		const char *messageAsChar = (env)->GetStringUTFChars(message, 0);
		Log("Message is in C++: %s", messageAsChar);

		// Open file
		AAsset *asset = AAssetManager_open(aassetManager, filename, AASSET_MODE_UNKNOWN);
		if (NULL == asset) {
			Log("Error: Cannot find file %s", filename);
			return;
		} else {
			long size = AAsset_getLength(asset);
			unsigned char *buffer = (unsigned char *) malloc(sizeof(char) *size);
			int result = AAsset_read(asset, buffer, size);
			if (result < 0) {
				Log("Error reading file %s", filename);
				AAsset_close(asset);
				free(buffer);
				return;
			}

			if (buffer != NULL)
			{
				char* pStr = (char*)malloc(size+1);
				if (pStr != NULL)
				{
					pStr[size] = '\0';
					if (size > 0)
					{
						memcpy(pStr, buffer, size);
					}

					Log("****** OUTPUT: %s", pStr);
					free(pStr);
				}
			}

			AAsset_close(asset);
			free(buffer);
		}
	}
}
