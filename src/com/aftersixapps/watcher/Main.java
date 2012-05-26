package com.aftersixapps.watcher;

import android.app.Activity;
import android.content.pm.ActivityInfo;
import android.os.Bundle;
import android.view.WindowManager;

public class Main extends Activity {
	
	private ARController controller;
	
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);

		iniciaAplicacao();
		
		controller = new ARController(this);		
		controller.init();
	}

	private void iniciaAplicacao() {
		// deixa a tela com a orientação paisagem
		setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE);

		// deixa a tela sempre ligada
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON,
				WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
	}
}