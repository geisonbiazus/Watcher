package com.aftersixapps.watcher;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.util.DisplayMetrics;
import android.view.View;
import android.view.ViewGroup.LayoutParams;

import com.qualcomm.QCAR.QCAR;

public class ARController {

	static {
		System.loadLibrary("QCAR");
		System.loadLibrary("Watcher");
	}

	private Activity activity;
	private GLSurfaceView glView;
	private ARRenderer renderer;
	private BancoDeDados bancoDeDados;

	public ARController(Activity activity, BancoDeDados bancoDeDados) {
		this.activity = activity;
		this.bancoDeDados = bancoDeDados;
	}

	public void onCreate() {
		iniciaQCAR();
		iniciaTracker();
		iniciaAplicacaoAR();
		carregaDadosDoTracker();
		addGLView();
	}

	public void onResume() {
		resumeGLView();
		iniciaCamera();
		setProjectionMatrix();
		QCAR.onResume();
	}

	public void onPause() {
		pouseGLView();
		pararCamera();
		QCAR.onPause();
	}

	public void onDestroy() {
		finalizaTracker();
		QCAR.deinit();
	}

	private void iniciaQCAR() {
		QCAR.setInitParameters(activity, QCAR.GL_11);
		QCAR.init();
	}

	private void iniciaAplicacaoAR() {
		DisplayMetrics metrics = new DisplayMetrics();
		activity.getWindowManager().getDefaultDisplay().getMetrics(metrics);

		iniciaAplicacaoNative(metrics.widthPixels, metrics.heightPixels);

		glView = new GLSurfaceView(activity);
		renderer = new ARRenderer(activity, bancoDeDados);

		glView.setRenderer(renderer);
	}

	private void addGLView() {
		activity.addContentView(glView, new LayoutParams(
				LayoutParams.FILL_PARENT, LayoutParams.FILL_PARENT));
	}

	private void resumeGLView() {
		glView.setVisibility(View.VISIBLE);
		glView.onResume();
	}

	private void pouseGLView() {
		glView.setVisibility(View.INVISIBLE);
		glView.onPause();
	}

	private native void iniciaTracker();

	private native void iniciaAplicacaoNative(int largura, int altura);

	private native void carregaDadosDoTracker();

	private native void iniciaCamera();

	private native void setProjectionMatrix();

	private native void pararCamera();

	private native void finalizaTracker();

}
