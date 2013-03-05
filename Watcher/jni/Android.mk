
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := QCAR-prebuilt
LOCAL_SRC_FILES = ../qcar/lib/$(TARGET_ARCH_ABI)/libQCAR.so
LOCAL_EXPORT_C_INCLUDES := /home/geison/Projetos/Watcher/Watcher/qcar/include
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE := Watcher

TARGET_PLATFORM := android-8

OPENGLES_LIB  := -lGLESv1_CM
OPENGLES_DEF  := -DUSE_OPENGL_ES_1_1

LOCAL_CFLAGS := -Wno-write-strings $(OPENGLES_DEF)

LOCAL_LDLIBS := \
    -llog $(OPENGLES_LIB)
     
LOCAL_SHARED_LIBRARIES := QCAR-prebuilt

LOCAL_SRC_FILES := ARController.cpp

LOCAL_ARM_MODE := arm

include $(BUILD_SHARED_LIBRARY)
