/* DO NOT EDIT THIS FILE - it is machine generated */
//actually it's not, it was initially though
//easier to make this by hand lol
#include <jni.h>

#ifndef _Included_net_daporkchop_ldbjni_natives_NativeDB
#define _Included_net_daporkchop_ldbjni_natives_NativeDB

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Class:     net_daporkchop_ldbjni_natives_NativeDB
 * Method:    init
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_net_daporkchop_ldbjni_natives_NativeDB_init
  (JNIEnv *, jclass);

/*
 * Class:     net_daporkchop_ldbjni_natives_NativeDB
 * Method:    openDb
 * Signature: (Ljava/lang/String;ZZZIIIIIIJ)J
 */
JNIEXPORT jlong JNICALL Java_net_daporkchop_ldbjni_natives_NativeDB_openDb
  (JNIEnv *, jclass, jstring, jboolean, jboolean, jboolean, jint, jint, jint, jint, jint, jint, jlong);

/*
 * Class:     net_daporkchop_ldbjni_natives_NativeDB
 * Method:    createDecompressAllocator
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_net_daporkchop_ldbjni_natives_NativeDB_createDecompressAllocator
  (JNIEnv *, jclass);

/*
 * Class:     net_daporkchop_ldbjni_natives_NativeDB
 * Method:    closeDb
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_net_daporkchop_ldbjni_natives_NativeDB_closeDb
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     net_daporkchop_ldbjni_natives_NativeDB
 * Method:    get0
 * Signature: ([BZZL)[B
 */
JNIEXPORT jbyteArray JNICALL Java_net_daporkchop_ldbjni_natives_NativeDB_get0
  (JNIEnv *, jobject, jbyteArray, jboolean, jboolean, jlong);

/*
 * Class:     net_daporkchop_ldbjni_natives_NativeDB
 * Method:    put0
 * Signature: ([B[BZ)V
 */
JNIEXPORT void JNICALL Java_net_daporkchop_ldbjni_natives_NativeDB_put0
  (JNIEnv *, jobject, jbyteArray, jbyteArray, jboolean);

/*
 * Class:     net_daporkchop_ldbjni_natives_NativeDB
 * Method:    delete0
 * Signature: ([BZ)V
 */
JNIEXPORT void JNICALL Java_net_daporkchop_ldbjni_natives_NativeDB_delete0
  (JNIEnv *, jobject, jbyteArray, jboolean);

/*
 * Class:     net_daporkchop_ldbjni_natives_NativeDB
 * Method:    createWriteBatch0
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_net_daporkchop_ldbjni_natives_NativeDB_createWriteBatch0
  (JNIEnv *, jobject);

/*
 * Class:     net_daporkchop_ldbjni_natives_NativeDB
 * Method:    releaseWriteBatch0
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_net_daporkchop_ldbjni_natives_NativeDB_releaseWriteBatch0
  (JNIEnv *, jobject, jlong);

/*
 * Class:     net_daporkchop_ldbjni_natives_NativeDB
 * Method:    writeBatch0
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_net_daporkchop_ldbjni_natives_NativeDB_writeBatch0
  (JNIEnv *, jobject, jlong, jboolean);

/*
 * Class:     net_daporkchop_ldbjni_natives_NativeDB
 * Method:    compactRange0
 * Signature: ([B[B)V
 */
JNIEXPORT void JNICALL Java_net_daporkchop_ldbjni_natives_NativeDB_compactRange0
  (JNIEnv *, jobject, jbyteArray, jbyteArray);

#ifdef __cplusplus
}
#endif

#endif //_Included_net_daporkchop_ldbjni_natives_NativeDB
