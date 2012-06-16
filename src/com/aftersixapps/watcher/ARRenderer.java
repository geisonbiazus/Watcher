package com.aftersixapps.watcher;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import com.qualcomm.QCAR.QCAR;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.opengl.GLSurfaceView.Renderer;
import android.util.Log;

public class ARRenderer implements Renderer {

	private Activity activity;
	
	public ARRenderer(Activity activity) {
		this.activity = activity;
	}
	
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
	
	public void abrirVideo() {
		Log.i("JAVA", "Abrindo video........");
		
		Uri uri = Uri.parse("http://www.youtube.com/watch?v=Lj-DQOPHdPY");

		Intent it = new Intent(Intent.ACTION_VIEW, uri);
		activity.startActivity(it);
	}
	
	private native void iniciaRenderizacao();
	private native void atualizaRenderizacao(int width, int height);
	private native void renderizaFrame();

}
