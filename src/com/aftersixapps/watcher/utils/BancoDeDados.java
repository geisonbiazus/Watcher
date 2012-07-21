package com.aftersixapps.watcher.utils;

import com.aftersixapps.watcher.model.Configuracoes;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

public class BancoDeDados {

	private SQLiteDatabase bd;
	private Context context;

	public BancoDeDados(Context context) {
		this.context = context;
		inicializaBD();
	}

	public Long adicionaTrackable(String nome, String url) {
		ContentValues values = new ContentValues();
		values.put("nome", nome);
		values.put("url", url);
		return bd.insert("trackables", null, values);
	}

	public void limparTrackables() {
		bd.delete("trackables", null, null);
	}

	public Cursor buscaTrackablePorNome(String nome) {
		return bd.query("trackables", new String[] { "nome", "url" },
				"nome = ?", new String[] { nome }, null, null, null);
	}
	
	public int getVersao() {
		Cursor cursor = bd.query("versao", new String[] {"numero"}, null, null, null, null, null);
		int versao = 0;
		
		if (cursor.moveToNext()) {
			versao = cursor.getInt(0);
		}
		cursor.close();
		
		return versao;
	}
	
	public void setVersao(int versao) {
		ContentValues values = new ContentValues();
		values.put("numero", versao);
		
		if (getVersao() > 0) {
			bd.update("versao", values, null, null);
		} else {
			bd.insert("versao", null, values);
		}
	}
	
	public Configuracoes getConfiguracoes() {
		Cursor cursor = bd.query("configuracoes", new String[] {"url_servidor"}, null, null, null, null, null);
		Configuracoes configuracoes = new Configuracoes();
		
		if (cursor.moveToNext()) {
			configuracoes.setUrlServidor(cursor.getString(0));
		}
		
		return configuracoes;
	}
	
	
	public void setConfiguracoes(Configuracoes configuracoes) {
		Cursor cursor = bd.query("configuracoes", new String[] {"url_servidor"}, null, null, null, null, null);
		
		ContentValues values = new ContentValues();
		values.put("url_servidor", configuracoes.getUrlServidor());
		
		if (cursor.moveToNext()) {
			bd.update("configuracoes", values, null, null);
		} else {
			bd.insert("configuracoes", null, values);
		}
	}

	private void inicializaBD() {
		abrir();

		bd.execSQL("create table if not exists trackables "
				+ "(id integer primary key, nome text, url text);");
		
		bd.execSQL("create table if not exists versao "
				+ "(numero integer);");		
		
		bd.execSQL("create table if not exists configuracoes "
				+ "(url_servidor text);");
		
		limparTrackables();
		adicionaTrackable("avengers",
				"http://www.youtube.com/watch?v=Lj-DQOPHdPY");
		adicionaTrackable("avatar",
				"http://www.youtube.com/watch?v=5PSNL1qE6VY");
		adicionaTrackable("shawshankredemption",
				"http://www.youtube.com/watch?v=6hB3S9bIaco");
		adicionaTrackable("skyrim",
				"http://www.youtube.com/watch?v=MUNRNbEyh3o&feature=fvst");
		adicionaTrackable("terminator2",
				"http://www.youtube.com/watch?v=eajuMYNYtuY");
		adicionaTrackable("rocky",
				"http://www.youtube.com/watch?v=YgmK7110jYU");

	}

	public void abrir() {
		bd = context.openOrCreateDatabase("watcherdb", Context.MODE_PRIVATE,
				null);
	}

	public void fechar() {
		bd.close();
	}

}
