#include <jni.h>
#include <android/log.h>
#include <stdio.h>
#include <string.h>

#include <GLES/gl.h>
#include <GLES/glext.h>

#include <QCAR/QCAR.h>
#include <QCAR/CameraDevice.h>
#include <QCAR/Renderer.h>
#include <QCAR/VideoBackgroundConfig.h>
#include <QCAR/TrackableResult.h>
#include <QCAR/ImageTargetResult.h>
#include <QCAR/VirtualButtonResult.h>
#include <QCAR/Trackable.h>
#include <QCAR/Tool.h>
#include <QCAR/Tracker.h>
#include <QCAR/TrackerManager.h>
#include <QCAR/ImageTracker.h>
#include <QCAR/CameraCalibration.h>
#include <QCAR/UpdateCallback.h>
#include <QCAR/DataSet.h>
#include <QCAR/Rectangle.h>
#include <QCAR/VirtualButton.h>
#include <QCAR/ImageTarget.h>

#include "cube.h"

// Log:
#define LOG_TAG    "AR_CONTROLLER"
#define LOG(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

extern "C" {

unsigned int larguraDaTela = 0;
unsigned int alturaDaTela = 0;
bool criarBotao = true;
QCAR::DataSet* dataset = 0;
QCAR::Matrix44F projectionMatrix; // Matriz de projeção usada para renderizar os objetos

void configureVideoBackground();
void iniciaTracker();
void iniciaAplicacao(JNIEnv* env, jobject obj, jint largura, jint altura);
void carregaDadosDoTracker();
void iniciaCamera();
void setProjectionMatrix();
void pararCamera();
void finalizaTracker();
void desativaDataset();
void iniciaRenderizacao();
void atualizaRenderizacao(jint largura, jint altura);
void renderizaFrame(JNIEnv* env, jobject obj);

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARController_iniciaTracker(JNIEnv *, jobject);

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARController_iniciaAplicacaoNative(JNIEnv* env, jobject obj, jint largura, jint altura);

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARController_carregaDadosDoTracker(JNIEnv* env, jobject obj);

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARController_iniciaCamera(JNIEnv* env, jobject obj);

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARController_setProjectionMatrix(JNIEnv *, jobject);

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARController_pararCamera(JNIEnv *, jobject);

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARController_finalizaTracker(JNIEnv *, jobject);

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARController_desativaDataset(JNIEnv *, jobject);

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARRenderer_iniciaRenderizacao(JNIEnv *, jobject);

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARRenderer_atualizaRenderizacao(JNIEnv* env, jobject obj, jint largura, jint altura);

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARRenderer_renderizaFrame(JNIEnv* env, jobject obj);

}
