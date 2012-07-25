package com.aftersixapps.watcher.utils;

import java.util.ArrayList;
import java.util.List;

import com.aftersixapps.watcher.model.Configuracoes;
import com.aftersixapps.watcher.model.Trackable;

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

	public Long adicionaTrackable(Trackable trackable) {
		ContentValues values = new ContentValues();
		values.put("descricao", trackable.getDescricao());
		values.put("url_video", trackable.getUrlVideo());
		values.put("observacao", trackable.getObservacao());
		return bd.insert("trackables", null, values);
	}
	
	public List<Trackable> getTrackables() {
		List<Trackable> trackables = new ArrayList<Trackable>();
		Trackable trackable;
		
		Cursor cursor = bd.query("trackables", new String[] { "descricao", "url_video", "observacao" },
				null, null, null, null, null);
		
		while (cursor.moveToNext()) {
			trackable = new Trackable();
			trackable.setDescricao(cursor.getString(0));
			trackable.setUrlVideo(cursor.getString(1));
			trackable.setObservacao(cursor.getString(2));
			trackables.add(trackable);			
		}
		
		cursor.close();
		
		return trackables;
	}

	public void limparTrackables() {
		bd.delete("trackables", null, null);
	}

	public Trackable buscaTrackablePorDescricao(String descricao) {
		Trackable trackable = null;
		
		Cursor cursor = bd.query("trackables", new String[] { "descricao", "url_video", "observacao" },
				"descricao = ?", new String[] { descricao }, null, null, null);
		
		if (cursor.moveToNext()) {
			trackable = new Trackable();
			trackable.setDescricao(cursor.getString(0));
			trackable.setUrlVideo(cursor.getString(1));
			trackable.setObservacao(cursor.getString(2));
		}
		
		cursor.close();
		
		return trackable;
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
		
		cursor.close();
		
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
		
		cursor.close();
	}

	private void inicializaBD() {
		abrir();

//		bd.execSQL("drop table trackables;");
		
		bd.execSQL("create table if not exists trackables "
				+ "(id integer primary key, descricao text, url_video text, observacao text);");
		
		bd.execSQL("create table if not exists versao "
				+ "(numero integer);");
		
		bd.execSQL("create table if not exists configuracoes "
				+ "(url_servidor text);");
		
//		limparTrackables();
//		adicionaTrackable("avengers",
//				"http://www.youtube.com/watch?v=Lj-DQOPHdPY");
//		adicionaTrackable("avatar",
//				"http://www.youtube.com/watch?v=5PSNL1qE6VY");
//		adicionaTrackable("shawshankredemption",
//				"http://www.youtube.com/watch?v=6hB3S9bIaco");
//		adicionaTrackable("skyrim",
//				"http://www.youtube.com/watch?v=MUNRNbEyh3o&feature=fvst");
//		adicionaTrackable("terminator2",
//				"http://www.youtube.com/watch?v=eajuMYNYtuY");
//		adicionaTrackable("rocky",
//				"http://www.youtube.com/watch?v=YgmK7110jYU");

	}

	public void abrir() {
		bd = context.openOrCreateDatabase("watcherdb", Context.MODE_PRIVATE,
				null);
	}

	public void fechar() {
		bd.close();
	}

}
