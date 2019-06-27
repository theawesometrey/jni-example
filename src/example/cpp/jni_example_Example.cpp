#include "jni_example_Example.h"

//static jclass JC_Example;
//static jmethodID JMID_Example_pow;
//
//static jint JNI_VERSION = JNI_VERSION_1_8;
//
//jint JNI_OnLoad(JavaVM* vm, void* reserved) {
//    JNIEnv* env;
//    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION) != JNI_OK) {
//        return JNI_ERR;
//    }
//    jclass tempLocalClassRef;
//    tempLocalClassRef = env->FindClass("jni/example/Example");
//    JC_Example = (jclass) env->NewGlobalRef(tempLocalClassRef);
//    env->DeleteLocalRef(tempLocalClassRef);
//    JMID_Example_pow = env->GetStaticMethodID(JC_Example, "pow", "([D)V");
//    return JNI_VERSION;
//}
//
//void JNI_OnUnload(JavaVM* vm, void* reserved) {
//    JNIEnv* env;
//    vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION);
//    env->DeleteGlobalRef(JC_Example);
//}

JNIEXPORT void JNICALL Java_jni_example_Example_sq(JNIEnv* env, jclass thiz, jdoubleArray array) {
    jsize size = env->GetArrayLength(array);
    jdouble* arr = env->GetDoubleArrayElements(array, 0);
    for (int i = 0; i < size; ++i) {
        arr[i] *= arr[i];
    }
    env->ReleaseDoubleArrayElements(array, arr, 0);
}
