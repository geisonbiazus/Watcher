package com.aftersixapps.watcher;

import com.aftersixapps.watcher.R;
import com.aftersixapps.watcher.R.layout;
import com.aftersixapps.watcher.utils.BancoDeDados;
import com.aftersixapps.watcher.utils.WebUtils;

import android.app.Activity;
import android.content.pm.ActivityInfo;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MotionEvent;
import android.view.WindowManager;

public class Main extends Activity {
	
	public static final int MENU_ATUALIZAR = 0;
	public static final int MENU_CONFIGURACOES = 1;
	
	private ARController controller;
	private BancoDeDados bancoDeDados;
	
	@Override
	public void onCreate(Bundle savedInstanceState) {
//		FileDownloader downloader = new FileDownloader("http://192.168.1.106:3000/Watcher.xml", "/data/data/com.aftersixapps.watcher/Watcher.xml");
//		downloader.download();
//		
//		downloader = new FileDownloader("http://192.168.1.106:3000/Watcher.dat", "/data/data/com.aftersixapps.watcher/Watcher.dat");
//		downloader.download();
		
		
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);

		iniciaAplicacao();
		bancoDeDados = new BancoDeDados(this);
		
		controller = new ARController(this, bancoDeDados);		
		controller.onCreate();
	}

	
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		
		menu.add(0, MENU_ATUALIZAR, 0, "Atualizar");
		menu.add(0, MENU_CONFIGURACOES, 0, "Configurações");
		return super.onCreateOptionsMenu(menu);
	}

	@Override
	protected void onResume() {
		super.onResume();
		controller.onResume();
	}
	
	@Override
	protected void onDestroy() {
		super.onDestroy();
		controller.onDestroy();
		bancoDeDados.fechar();
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