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
 * Method:    openDb
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_ldbjni_natives_NativeDB_openDb
  (JNIEnv *, jclass, jstring);

/*
 * Class:     net_daporkchop_ldbjni_natives_NativeDB
 * Method:    closeDb
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_ldbjni_natives_NativeDB_closeDb
  (JNIEnv *, jclass, jlong);

#ifdef __cplusplus
}
#endif

#endif //_Included_net_daporkchop_ldbjni_natives_NativeDB
