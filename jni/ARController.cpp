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

void configureVideoBackground() {
	bool isActivityInPortraitMode = false;

	// Get the default video mode:
	QCAR::CameraDevice& cameraDevice = QCAR::CameraDevice::getInstance();
	QCAR::VideoMode videoMode = cameraDevice.getVideoMode(
			QCAR::CameraDevice::MODE_DEFAULT);

	// Configure the video background
	QCAR::VideoBackgroundConfig config;
	config.mEnabled = true;
	config.mSynchronous = true;
	config.mPosition.data[0] = 0.0f;
	config.mPosition.data[1] = 0.0f;

	if (isActivityInPortraitMode) {
		//LOG("configureVideoBackground PORTRAIT");
		config.mSize.data[0] = videoMode.mHeight
				* (alturaDaTela / (float) videoMode.mWidth);
		config.mSize.data[1] = alturaDaTela;

		if (config.mSize.data[0] < larguraDaTela) {
			LOG(
					"Correcting rendering background size to handle missmatch between screen and video aspect ratios.");
			config.mSize.data[0] = larguraDaTela;
			config.mSize.data[1] = larguraDaTela
					* (videoMode.mWidth / (float) videoMode.mHeight);
		}
	} else {
		//LOG("configureVideoBackground LANDSCAPE");
		config.mSize.data[0] = larguraDaTela;
		config.mSize.data[1] = videoMode.mHeight
				* (larguraDaTela / (float) videoMode.mWidth);

		if (config.mSize.data[1] < alturaDaTela) {
			LOG(
					"Correcting rendering background size to handle missmatch between screen and video aspect ratios.");
			config.mSize.data[0] = alturaDaTela
					* (videoMode.mWidth / (float) videoMode.mHeight);
			config.mSize.data[1] = alturaDaTela;
		}
	}

	LOG(
			"Configure Video Background : Video (%d,%d), Screen (%d,%d), mSize (%d,%d)", videoMode.mWidth, videoMode.mHeight, larguraDaTela, alturaDaTela, config.mSize.data[0], config.mSize.data[1]);

	// Set the config:
	QCAR::Renderer::getInstance().setVideoBackgroundConfig(config);
}

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARController_iniciaTracker(JNIEnv *, jobject)
{
	LOG("Java_com_aftersixapps_watcher_ARController_iniciaTracker");

	// Inicializa o image trackrer:
	QCAR::TrackerManager& trackerManager = QCAR::TrackerManager::getInstance();
	QCAR::Tracker* tracker = trackerManager.initTracker(QCAR::Tracker::IMAGE_TRACKER);
}

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARController_iniciaAplicacaoNative(
		JNIEnv* env, jobject obj, jint largura, jint altura)
{
	LOG("Java_com_aftersixapps_watcher_ARController_iniciaAplicacaoNative");

	larguraDaTela = largura;
	alturaDaTela = altura;
}

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARController_carregaDadosDoTracker(
		JNIEnv* env, jobject obj)
{
	LOG("Java_com_aftersixapps_watcher_ARController_carregaDadosDoTracker");

	// pega o image tracker
	QCAR::TrackerManager& trackerManager = QCAR::TrackerManager::getInstance();
	QCAR::ImageTracker* imageTracker = static_cast<QCAR::ImageTracker*>(
			trackerManager.getTracker(QCAR::Tracker::IMAGE_TRACKER));

	dataset = imageTracker->createDataSet();
	dataset->load("Watcher.xml", QCAR::DataSet::STORAGE_APPRESOURCE);
	imageTracker->activateDataSet(dataset);

}

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARController_iniciaCamera(
		JNIEnv* env, jobject obj)
{
	LOG("Java_com_aftersixapps_watcher_ARController_iniciaCamera");

	QCAR::CameraDevice::getInstance().init();

	configureVideoBackground();

	QCAR::CameraDevice::getInstance().selectVideoMode(QCAR::CameraDevice::MODE_DEFAULT);
	QCAR::CameraDevice::getInstance().start();

	QCAR::TrackerManager& trackerManager = QCAR::TrackerManager::getInstance();
	QCAR::Tracker* imageTracker = trackerManager.getTracker(QCAR::Tracker::IMAGE_TRACKER);
	imageTracker->start();
}

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARController_setProjectionMatrix(JNIEnv *, jobject)
{
	LOG("Java_com_aftersixapps_watcher_ARController_setProjectionMatrix");

	const QCAR::CameraCalibration& cameraCalibration =
	QCAR::CameraDevice::getInstance().getCameraCalibration();
	projectionMatrix = QCAR::Tool::getProjectionGL(cameraCalibration, 2.0f,
			2000.0f);
}

}
