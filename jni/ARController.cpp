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
#include <QCAR/Trackable.h>
#include <QCAR/Tool.h>
#include <QCAR/Tracker.h>
#include <QCAR/TrackerManager.h>
#include <QCAR/ImageTracker.h>
#include <QCAR/CameraCalibration.h>
#include <QCAR/UpdateCallback.h>
#include <QCAR/DataSet.h>

// Log:
#define LOG_TAG    "AR_CONTROLLER"
#define LOG(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

extern "C" {

// Dimensões da tela:
unsigned int larguraDaTela = 0;
unsigned int alturaDaTela = 0;

// dataset
QCAR::DataSet* dataset = 0;

// Matriz de projeção usada para renderizar os objetos
QCAR::Matrix44F projectionMatrix;


JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARController_iniciaTracker(JNIEnv *, jobject)
{
	LOG("Java_com_aftersixapps_watcher_ARController_iniciaTracker");

	// Inicializa o image trackrer:
	QCAR::TrackerManager& trackerManager = QCAR::TrackerManager::getInstance();
	QCAR::Tracker* tracker = trackerManager.initTracker(QCAR::Tracker::IMAGE_TRACKER);
}

}
