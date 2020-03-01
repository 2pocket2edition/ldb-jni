#!/bin/bash

#i use this script simply so that i can add the natives compilation as a run configuration in intellij

#export LDB_NATIVES_DEBUG="true"

#make clean && \
#make -j$( nproc ) || exit 1

#[ -f build/native/debug/x86_64-linux-gnu/lib-leveldb/libleveldb.a ] && rm -v build/native/debug/x86_64-linux-gnu/lib-leveldb/libleveldb.a
[ -f src/main/resources/x86_64-linux-gnu/libldb-jni.so ] && (rm -v src/main/resources/x86_64-linux-gnu/libldb-jni.so || exit 1)

make -j$( nproc ) build.x86_64-linux-gnu || exit 1

[ -d test_out2 ] && (rm -rfv test_out2 || exit 1)
cp -rv test_out test_out2 || exit 1
