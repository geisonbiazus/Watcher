package com.aftersixapps.watcher;

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

	// public Cursor todosOsProdutos() {
	// return bd.query("produtos", new String[] { "id as _id", "descricao",
	// "quantidade", "valor" }, null, null, null, null, null);
	// }
	//
	public Cursor buscaTrackablePorNome(String nome) {
		return bd.query("trackables", new String[] { "nome", "url" },
				"nome = ?", new String[] { nome }, null, null, null);
	}

	private void inicializaBD() {
		abrir();

		bd.execSQL("create table if not exists trackables "
				+ "(id integer primary key, nome text, url text);");
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
