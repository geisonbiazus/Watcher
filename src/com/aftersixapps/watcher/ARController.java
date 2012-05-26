package com.aftersixapps.watcher;

import android.app.Activity;

import com.qualcomm.QCAR.QCAR;

public class ARController {
	
	static {
		System.loadLibrary("QCAR");
		System.loadLibrary("Watcher");
	}
	
	private Activity activity;
	
	public ARController(Activity activity) {
		this.activity = activity;
	}
	
	public void init() {
		iniciaQCAR();
		iniciaTracker();
	}
	
	private void iniciaQCAR() {
		QCAR.setInitParameters(activity, QCAR.GL_11);
		QCAR.init();
	}
	
	private native void iniciaTracker();

}
