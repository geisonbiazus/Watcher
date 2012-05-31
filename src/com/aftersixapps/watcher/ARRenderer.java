package com.aftersixapps.watcher;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import com.qualcomm.QCAR.QCAR;

import android.opengl.GLSurfaceView.Renderer;

public class ARRenderer implements Renderer {

	@Override
	public void onDrawFrame(GL10 gl) {
		renderizaFrame();
	}

	@Override
	public void onSurfaceChanged(GL10 gl, int width, int height) {
		atualizaRenderizacao(width, height);
		QCAR.onSurfaceChanged(width, height);
	}

	@Override
	public void onSurfaceCreated(GL10 gl, EGLConfig config) {
		iniciaRenderizacao();
		QCAR.onSurfaceCreated();
	}
	
	private native void iniciaRenderizacao();
	private native void atualizaRenderizacao(int width, int height);
	private native void renderizaFrame();

}
