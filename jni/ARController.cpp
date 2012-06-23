#include "ARController.h"

class VirtualButton_UpdateCallback: public QCAR::UpdateCallback {
	virtual void QCAR_onUpdate(QCAR::State& /*state*/) {

		if (criarBotao) {

			LOG("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
			LOG("Criando botão virtual");
			LOG("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");

			QCAR::TrackerManager& trackerManager = QCAR::TrackerManager::getInstance();
			QCAR::ImageTracker* imageTracker = static_cast<QCAR::ImageTracker*>(
					trackerManager.getTracker(QCAR::Tracker::IMAGE_TRACKER));


			imageTracker->deactivateDataSet(dataset);

			for(int tIdx = 0; tIdx < dataset->getNumTrackables(); tIdx++) {

				QCAR::Trackable* trackable = dataset->getTrackable(tIdx);

				QCAR::ImageTarget* imageTarget = static_cast<QCAR::ImageTarget*>(trackable);
				QCAR::Rectangle vbRectangle(-5.0,  5.0, 5.0, -5.0);
				QCAR::VirtualButton* virtualButton = imageTarget->createVirtualButton("botao", vbRectangle);

				virtualButton->setEnabled(true);
				virtualButton->setSensitivity(QCAR::VirtualButton::MEDIUM);
			}

			imageTracker->activateDataSet(dataset);
			criarBotao = false;
		}
	}
} qcarUpdate;

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

void iniciaTracker() {
	// Inicializa o image trackrer:
	QCAR::TrackerManager& trackerManager = QCAR::TrackerManager::getInstance();
	QCAR::Tracker* tracker = trackerManager.initTracker(QCAR::Tracker::IMAGE_TRACKER);
}

void iniciaAplicacao(jint largura, jint altura) {
	larguraDaTela = largura;
	alturaDaTela = altura;

	QCAR::registerCallback(&qcarUpdate);
}

void carregaDadosDoTracker() {
	// pega o image tracker
	QCAR::TrackerManager& trackerManager = QCAR::TrackerManager::getInstance();
	QCAR::ImageTracker* imageTracker = static_cast<QCAR::ImageTracker*>(
			trackerManager.getTracker(QCAR::Tracker::IMAGE_TRACKER));

	dataset = imageTracker->createDataSet();
	dataset->load("Watcher.xml", QCAR::DataSet::STORAGE_APPRESOURCE);
	imageTracker->activateDataSet(dataset);
}

void iniciaCamera() {
	QCAR::CameraDevice::getInstance().init();

	configureVideoBackground();

	QCAR::CameraDevice::getInstance().selectVideoMode(QCAR::CameraDevice::MODE_DEFAULT);
	QCAR::CameraDevice::getInstance().start();

	QCAR::TrackerManager& trackerManager = QCAR::TrackerManager::getInstance();
	QCAR::Tracker* imageTracker = trackerManager.getTracker(QCAR::Tracker::IMAGE_TRACKER);
	imageTracker->start();
}

void setProjectionMatrix() {
	const QCAR::CameraCalibration& cameraCalibration =
	QCAR::CameraDevice::getInstance().getCameraCalibration();
	projectionMatrix = QCAR::Tool::getProjectionGL(cameraCalibration, 2.0f,
			2000.0f);
}

void pararCamera() {
	QCAR::TrackerManager& trackerManager = QCAR::TrackerManager::getInstance();
	QCAR::Tracker* imageTracker = trackerManager.getTracker(QCAR::Tracker::IMAGE_TRACKER);
	imageTracker->stop();

	QCAR::CameraDevice::getInstance().stop();
	QCAR::CameraDevice::getInstance().deinit();
}

void finalizaTracker() {
	QCAR::TrackerManager& trackerManager = QCAR::TrackerManager::getInstance();
	QCAR::ImageTracker* imageTracker = static_cast<QCAR::ImageTracker*>(
			trackerManager.getTracker(QCAR::Tracker::IMAGE_TRACKER));

	imageTracker->deactivateDataSet(dataset);
	trackerManager.deinitTracker(QCAR::Tracker::IMAGE_TRACKER);
}

void iniciaRenderizacao() {
	// Define clear color
	glClearColor(0.0f, 0.0f, 0.0f, QCAR::requiresAlpha() ? 0.0f : 1.0f);}

void atualizaRenderizacao(jint largura, jint altura) {
	larguraDaTela = largura;
	alturaDaTela = altura;

	configureVideoBackground();
}

void renderizaFrame(JNIEnv* env, jobject obj) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	QCAR::State state = QCAR::Renderer::getInstance().begin();

	QCAR::Renderer::getInstance().drawVideoBackground();

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	for(int tIdx = 0; tIdx < state.getNumActiveTrackables(); tIdx++)
	{

		const QCAR::Trackable* trackable = state.getActiveTrackable(tIdx);
		QCAR::Matrix44F modelViewMatrix = QCAR::Tool::convertPose2GLMatrix(trackable->getPose());

		const QCAR::ImageTarget* target = static_cast<const QCAR::ImageTarget*>(trackable);


		if (strcmp(trackable->getName(), "avengers") == 0) {
			LOG("Imagem detectada");
		}

		if (target->getNumVirtualButtons() == 0) {
			criarBotao = true;
		}

		for (int i = 0; i < target->getNumVirtualButtons(); ++i)
		{
			LOG("Botão detectado");

			QCAR::TrackerManager& trackerManager = QCAR::TrackerManager::getInstance();
			QCAR::Tracker* tracker = trackerManager.initTracker(QCAR::Tracker::IMAGE_TRACKER);
			const QCAR::VirtualButton* button = target->getVirtualButton(i);

			// If the button is pressed, than use this texture:
			if (button->isPressed())
			{
				 // Handle to the activity class:
				jclass cls = env->GetObjectClass(obj);

				jstring name = env->NewStringUTF(trackable->getName());

				jmethodID abrirVideoMethodID = env->GetMethodID(cls, "abrirVideo", "(Ljava/lang/String;)V");

				if (abrirVideoMethodID == 0) {
					LOG("METODO NAO ENCONTRADO");
				}

				env->CallIntMethod(obj, abrirVideoMethodID, name);
			}

		}


		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf(projectionMatrix.data);

		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(modelViewMatrix.data);

		float kObjectScale = 3.f;

		glTranslatef(0.f, 0.f, kObjectScale);
		glScalef(kObjectScale, kObjectScale, kObjectScale);

		glFrontFace(GL_CW);


		glVertexPointer(3, GL_FLOAT, 0, (const GLvoid*) &cubeVertices[0]);
		glColorPointer(4, GL_FLOAT, 0, (const GLvoid*) &cubeColors[0]);

		glDrawElements(GL_TRIANGLES, NUM_CUBE_OBJECT_INDEX, GL_UNSIGNED_SHORT,
				(const GLvoid*) &cubeIndices[0]);
	}
	glDisable(GL_DEPTH_TEST);

	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	QCAR::Renderer::getInstance().end();
}

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARController_iniciaTracker(JNIEnv *, jobject)
{
	LOG("Java_com_aftersixapps_watcher_ARController_iniciaTracker");
	iniciaTracker();
}

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARController_iniciaAplicacaoNative(
		JNIEnv* env, jobject obj, jint largura, jint altura)
{
	LOG("Java_com_aftersixapps_watcher_ARController_iniciaAplicacaoNative");
	iniciaAplicacao(largura, altura);
}

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARController_carregaDadosDoTracker(
		JNIEnv* env, jobject obj)
{
	LOG("Java_com_aftersixapps_watcher_ARController_carregaDadosDoTracker");
	carregaDadosDoTracker();
}

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARController_iniciaCamera(
		JNIEnv* env, jobject obj)
{
	LOG("Java_com_aftersixapps_watcher_ARController_iniciaCamera");
	iniciaCamera();
}

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARController_setProjectionMatrix(JNIEnv *, jobject)
{
	LOG("Java_com_aftersixapps_watcher_ARController_setProjectionMatrix");
	setProjectionMatrix();
}

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARController_pararCamera(JNIEnv *, jobject)
{
	LOG("Java_com_aftersixapps_watcher_ARController_pararCamera");
	pararCamera();
}

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARController_finalizaTracker(JNIEnv *, jobject)
{
	LOG("Java_com_aftersixapps_watcher_ARController_finalizaTracker");
	finalizaTracker();
}

//////////////////////////////////////////
// Métodos dativos da classe ARRenderer //
//////////////////////////////////////////

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARRenderer_iniciaRenderizacao(JNIEnv *, jobject)
{
	LOG("Java_com_aftersixapps_watcher_ARRenderer_iniciaRenderizacao");
	iniciaRenderizacao();
}

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARRenderer_atualizaRenderizacao(
		JNIEnv* env, jobject obj, jint largura, jint altura)
{
	LOG("JJava_com_aftersixapps_watcher_ARRenderer_atualizaRenderizacao");
	atualizaRenderizacao(largura, altura);
}

JNIEXPORT void JNICALL
Java_com_aftersixapps_watcher_ARRenderer_renderizaFrame(JNIEnv* env, jobject obj)
{
//	LOG("Java_com_aftersixapps_watcher_ARRenderer_renderizaFrame");
	renderizaFrame(env, obj);
}

