#include "ldb-jni_common.h"
#include "NativeWriteBatch.h"

JNIEXPORT void JNICALL Java_net_daporkchop_ldbjni_natives_NativeWriteBatch_put0
  (JNIEnv* env, jobject obj, jlong ptr, jbyteArray key, jbyteArray value)  {
    auto writeBatch = (leveldb::WriteBatch*) ptr;

    if (writeBatch == nullptr)  {
        throwISE(env, "NativeWriteBatch has already been closed!");
        return;
    }

    int keyLength = env->GetArrayLength(key);
    char* keyRaw = new char[keyLength];
    env->GetByteArrayRegion(key, 0, keyLength, (jbyte*) keyRaw);
    leveldb::Slice keySlice(keyRaw, keyLength);

    int valueLength = env->GetArrayLength(value);
    char* valueRaw = new char[valueLength];
    env->GetByteArrayRegion(value, 0, valueLength, (jbyte*) valueRaw);
    leveldb::Slice valueSlice(valueRaw, valueLength);

    writeBatch->Put(keySlice, valueSlice);
    delete keyRaw;
    delete valueRaw;
}

JNIEXPORT void JNICALL Java_net_daporkchop_ldbjni_natives_NativeWriteBatch_delete0
  (JNIEnv* env, jobject obj, jlong ptr, jbyteArray key)  {
    auto writeBatch = (leveldb::WriteBatch*) ptr;

    if (writeBatch == nullptr)  {
        throwISE(env, "NativeWriteBatch has already been closed!");
        return;
    }

    int keyLength = env->GetArrayLength(key);
    char* keyRaw = new char[keyLength];
    env->GetByteArrayRegion(key, 0, keyLength, (jbyte*) keyRaw);
    leveldb::Slice keySlice(keyRaw, keyLength);

    writeBatch->Delete(keySlice);
    delete keyRaw;
}
