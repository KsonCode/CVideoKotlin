#include <jni.h>
#include <string>
#include <stdio.h>

//宏定义
#define JNI_CLASS_PATH "com/cvideokotlin/CActivity"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_cvideokotlin_CActivity_stringFromc(JNIEnv *env, jobject instance) {

    // TODO



    return env->NewStringUTF("hhhihihihihi");
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_cvideokotlin_CActivity_stringFromC(JNIEnv *env, jobject instance, jstring msg_) {
    const char *msg = env->GetStringUTFChars(msg_, 0);

    // TODO

    env->ReleaseStringUTFChars(msg_, msg);


    return env->NewStringUTF("xxxxxxxx");
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_cvideokotlin_CActivity_stringFromJNI(JNIEnv *env, jobject instance) {

    std::string hello = "Hello from C++";

    return env->NewStringUTF(hello.c_str());
}

class st;

/**
 * c 调用java
 */
extern "C"
JNIEXPORT jstring JNICALL
my_test_register(JNIEnv *env, jobject instance) {

    //step 1 得到类类型
    jclass jclass1 = env->FindClass("com/cvideokotlin/Student");

    //step 2 获取方法id
    jmethodID method_init_id = env->GetMethodID(jclass1, "<init>", "()V");//构造方法
    jmethodID method_set_id = env->GetMethodID(jclass1, "setYear", "(I)V");
    jmethodID method_get_id = env->GetMethodID(jclass1, "getYear", "()I");
    //STEP 3 创建对象
    jobject obj = env->NewObject(jclass1, method_init_id);
    //step 4 调用方法
    env->CallVoidMethod(obj, method_set_id, 18);
    int year = env->CallIntMethod(obj, method_get_id);

//
    char temp[] = {0,};
    sprintf(temp, "%d", year);//转字符串


    std::string hello = "hello from c++ ,year=";
    hello.append(temp);


    return env->NewStringUTF(hello.c_str());

}

/**
 * 方法映射表
 */
static JNINativeMethod g_methods[] = {
        "_test",
        "()Ljava/lang/String;", (void *) my_test_register,
};

jint JNI_OnLoad(JavaVM *vm, void *reserved) {

    JNIEnv *env = NULL;
    vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
    jclass clazz = env->FindClass(JNI_CLASS_PATH);
    env->RegisterNatives(clazz, g_methods, sizeof(g_methods) / sizeof(g_methods[0]));

    return JNI_VERSION_1_6;
}
