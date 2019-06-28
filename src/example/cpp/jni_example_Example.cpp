#include "jni_example_Example.h"

static jclass JC_DoubleArray;

static jclass JC_Pair;
static jmethodID JMID_Pair_init;
static jmethodID JMID_Pair_getLeft;
static jmethodID JMID_Pair_getRight;

static jint JNI_VERSION = JNI_VERSION_1_8;

jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv* env;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION) != JNI_OK) {
        return JNI_ERR;
    }
    jclass tempLocalClassRef;
    tempLocalClassRef = env->FindClass("jni/example/Pair");
    JC_Pair = (jclass) env->NewGlobalRef(tempLocalClassRef);
    env->DeleteLocalRef(tempLocalClassRef);
    JMID_Pair_init = env->GetMethodID(JC_Pair, "<init>", "(DD)V");
    JMID_Pair_getLeft = env->GetMethodID(JC_Pair, "getLeft", "()D");
    JMID_Pair_getRight = env->GetMethodID(JC_Pair, "getRight", "()D");

    tempLocalClassRef = env->FindClass("[D");
    JC_DoubleArray = (jclass) env->NewGlobalRef(tempLocalClassRef);
    env->DeleteLocalRef(tempLocalClassRef);
    return JNI_VERSION;
}

void JNI_OnUnload(JavaVM* vm, void* reserved) {
    JNIEnv* env;
    vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION);
    env->DeleteGlobalRef(JC_Pair);
    env->DeleteGlobalRef(JC_DoubleArray);
}

JNIEXPORT void JNICALL Java_jni_example_Example_sq(JNIEnv* env, jclass thiz, jdoubleArray array) {
    jsize size = env->GetArrayLength(array);
    jdouble* arr = env->GetDoubleArrayElements(array, 0);
    for (int i = 0; i < size; ++i) {
        arr[i] *= arr[i];
    }
    env->ReleaseDoubleArrayElements(array, arr, 0);
}


JNIEXPORT jdoubleArray JNICALL Java_jni_example_Example_newArray(JNIEnv* env, jclass thiz, jint size, jdouble fill) {
    jdoubleArray result = env->NewDoubleArray(size);
    jdouble temp[size];
    for (int i = 0; i < size; ++i) {
        temp[i] = fill;
    }
    env->SetDoubleArrayRegion(result, 0, size, temp);
    return result;
}


JNIEXPORT jobjectArray JNICALL Java_jni_example_Example_new2DArray(JNIEnv* env, jclass thiz, jint size1, jint size2, jdouble fill) {
    jobjectArray result = env->NewObjectArray(size1, JC_DoubleArray, NULL);
    for (int i = 0; i < size1; ++i) {
        jdoubleArray doubleArray = env->NewDoubleArray(size2);
        jdouble temp[size2];
        for (int j = 0; j < size2; ++j) {
            temp[j] = fill;
        }
        env->SetDoubleArrayRegion(doubleArray, 0, size2, temp);
        env->SetObjectArrayElement(result, i, doubleArray);
        env->DeleteLocalRef(doubleArray);
    }
    return result;
}

JNIEXPORT jobject JNICALL Java_jni_example_Example_copy(JNIEnv* env, jclass clazz, jobject pair) {
    jdouble left = env->CallDoubleMethod(pair, JMID_Pair_getLeft);
    jdouble right = env->CallDoubleMethod(pair, JMID_Pair_getRight);
    return env->NewObject(JC_Pair, JMID_Pair_init, left, right);
}