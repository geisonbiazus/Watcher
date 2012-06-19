package com.aftersixapps.watcher;

import android.app.Activity;
import android.content.pm.ActivityInfo;
import android.os.Bundle;
import android.util.Log;
import android.view.MotionEvent;
import android.view.WindowManager;

public class Main extends Activity {
	
	private ARController controller;
	
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);

		iniciaAplicacao();
		
		controller = new ARController(this);		
		controller.onCreate();
	}
	
	protected void onResume() {
		super.onResume();
		controller.onResume();
	}
	
	@Override
	protected void onDestroy() {
		super.onDestroy();
		controller.onDestroy();
	}

	@Override
	protected void onPause() {
		super.onPause();
		controller.onPause();
	}
	
	@Override
	public boolean onTouchEvent(MotionEvent event) {	
		super.onTouchEvent(event);
		
		if (event.getActionMasked() == MotionEvent.ACTION_UP) {
			Log.i("MAIN", "X = " + event.getX());
			Log.i("MAIN", "Y = " + event.getY());
		}
		
		
		return true;
	}

	private void iniciaAplicacao() {
		// deixa a tela com a orientação paisagem
		setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE);

		// deixa a tela sempre ligada
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON,
				WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
	}
}