package com.aftersixapps.watcher;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.opengl.GLSurfaceView.Renderer;
import android.util.Log;

import com.aftersixapps.watcher.model.Trackable;
import com.aftersixapps.watcher.utils.BancoDeDados;
import com.qualcomm.QCAR.QCAR;

public class ARRenderer implements Renderer {

	private Activity activity;
	private BancoDeDados bancoDeDados;

	public ARRenderer(Activity activity, BancoDeDados bancoDeDados) {
		this.activity = activity;
		this.bancoDeDados = bancoDeDados;
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

	public void abrirVideo(String nome) {
		Log.i("JAVA", "Abrindo video........");

		Trackable trackable = bancoDeDados.buscaTrackablePorDescricao(nome);

		if (trackable != null) {
			Uri uri = Uri.parse(trackable.getUrlVideo());

			Intent it = new Intent(Intent.ACTION_VIEW, uri);
			activity.startActivity(it);
		}
	}

	private native void iniciaRenderizacao();

	private native void atualizaRenderizacao(int width, int height);

	private native void renderizaFrame();

}
