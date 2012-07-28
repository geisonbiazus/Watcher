package com.aftersixapps.watcher.tasks;

import java.io.IOException;
import java.lang.reflect.Type;
import java.util.List;

import android.app.ProgressDialog;
import android.content.Context;
import android.os.AsyncTask;
import android.widget.Toast;

import com.aftersixapps.watcher.ARController;
import com.aftersixapps.watcher.model.Trackable;
import com.aftersixapps.watcher.utils.BancoDeDados;
import com.aftersixapps.watcher.utils.FileDownloader;
import com.aftersixapps.watcher.utils.WebUtils;
import com.google.gson.Gson;
import com.google.gson.JsonSyntaxException;
import com.google.gson.reflect.TypeToken;

public class AtualizadorTask extends AsyncTask<String, Void, Void> {

	private Context context;
	private BancoDeDados bancoDeDados;
	private ProgressDialog dialog;
	private String url;
	private ARController controller;

	public AtualizadorTask(Context context, BancoDeDados bancoDeDados, ARController controller) {
		this.context = context;
		this.bancoDeDados = bancoDeDados;
		this.url = bancoDeDados.getConfiguracoes().getUrlServidor();
		this.controller = controller;
	}

	@Override
	protected void onPreExecute() {
		dialog = ProgressDialog.show(context, "Atualizando",
				"Aguarde, atualização em andamento...");
		controller.desativaDataset();
	}

	@Override
	protected Void doInBackground(String... params) {
		String urlVersao = url + "/atualizacoes/ultima_versao";

		try {
			int ultimaVersao = Integer.parseInt(WebUtils
					.getTextFromUrl(urlVersao));

			if (ultimaVersao > bancoDeDados.getVersao()) {

				downloadDataset();
				atualizaTrackables();
				
				bancoDeDados.setVersao(ultimaVersao);
				
				Toast.makeText(context, "Trackables atualizados com sucesso.", Toast.LENGTH_SHORT).show();
			}

		} catch (NumberFormatException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

		return null;
	}

	@Override
	protected void onPostExecute(Void result) {
		controller.carregaDadosDoTracker();
		dialog.dismiss();
	}

	private void downloadDataset() {
		String urlXml = url + "/dataset/Watcher.xml";
		String urlDat = url + "/dataset/Watcher.dat";

		FileDownloader downloader = new FileDownloader(urlXml, context
				.getFilesDir().getAbsolutePath() + "/Watcher.xml");
		downloader.download();

		downloader = new FileDownloader(urlDat, context.getFilesDir()
				.getAbsolutePath() + "/Watcher.dat");
		downloader.download();
	}

	private void atualizaTrackables() throws JsonSyntaxException, IOException {
		String urlTrackables = url + "/atualizacoes/trackables";
		
		Gson gson = new Gson();
		Type type = new TypeToken<List<Trackable>>() {
		}.getType();
		List<Trackable> trackables = gson.fromJson(
				WebUtils.getTextFromUrl(urlTrackables), type);
		
		for (Trackable trackable : trackables) {
			if (bancoDeDados.buscaTrackablePorDescricao(trackable.getDescricao()) == null) {
				bancoDeDados.adicionaTrackable(trackable);
			}
		}
	}

}
