package com.aftersixapps.watcher;

import android.app.Activity;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.view.WindowManager;

import com.aftersixapps.watcher.model.Configuracoes;
import com.aftersixapps.watcher.model.Trackable;
import com.aftersixapps.watcher.tasks.AtualizadorTask;
import com.aftersixapps.watcher.utils.BancoDeDados;

public class MainActivity extends Activity {
	
	public static final int MENU_ATUALIZAR = 0;
	public static final int MENU_CONFIGURACOES = 1;
	
	private ARController controller;
	private BancoDeDados bancoDeDados;
	
	@Override
	public void onCreate(Bundle savedInstanceState) {
		
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);

		iniciaAplicacao();
		bancoDeDados = new BancoDeDados(this);
		
		Configuracoes configuracoes = bancoDeDados.getConfiguracoes();
		configuracoes.setUrlServidor("http://192.168.1.10:3000");
		bancoDeDados.setConfiguracoes(configuracoes);
		
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
	public boolean onMenuItemSelected(int featureId, MenuItem item) {

		switch (item.getItemId()) {
		case MENU_CONFIGURACOES:
			Intent intent = new Intent(this, ConfiguracoesActivity.class);
			startActivity(intent);
			
			break;
		case MENU_ATUALIZAR:
			AtualizadorTask task = new AtualizadorTask(this, bancoDeDados, controller);
			task.execute();
			
			break;
		}

		return super.onMenuItemSelected(featureId, item);
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