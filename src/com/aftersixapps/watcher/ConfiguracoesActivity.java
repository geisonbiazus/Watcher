package com.aftersixapps.watcher;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import com.aftersixapps.watcher.model.Configuracoes;
import com.aftersixapps.watcher.utils.BancoDeDados;

public class ConfiguracoesActivity extends Activity {

	private BancoDeDados bancoDeDados;
	private Configuracoes configuracoes;
	
	private EditText urlServidor;
	private Button botaoGravar;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.configuracoes);

		bancoDeDados = new BancoDeDados(this);
		configuracoes = bancoDeDados.getConfiguracoes();
		
		urlServidor = (EditText) findViewById(R.id.url_servidor);
		botaoGravar = (Button) findViewById(R.id.botao_gravar);
		
		urlServidor.setText(configuracoes.getUrlServidor());

		botaoGravar.setOnClickListener(new View.OnClickListener() {

			@Override
			public void onClick(View v) {
				botaoGravarOnCLick();
			}
		});

	}

	private void botaoGravarOnCLick() {
		configuracoes.setUrlServidor(urlServidor.getText().toString());
		bancoDeDados.setConfiguracoes(configuracoes);
		finish();
	}

}
