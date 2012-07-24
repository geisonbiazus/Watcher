package com.aftersixapps.watcher.tasks;

import java.io.IOException;

import android.app.ProgressDialog;
import android.content.Context;
import android.os.AsyncTask;

import com.aftersixapps.watcher.utils.BancoDeDados;
import com.aftersixapps.watcher.utils.FileDownloader;
import com.aftersixapps.watcher.utils.WebUtils;

public class AtualizadorTask extends AsyncTask<String, Void, Void> {

	private Context context;
	private BancoDeDados bancoDeDados;
	private ProgressDialog dialog;
	
	public AtualizadorTask(Context context, BancoDeDados bancoDeDados) {
		this.context = context;
		this.bancoDeDados = bancoDeDados;		
	}
	
	@Override
	protected void onPreExecute() {
		dialog = ProgressDialog.show(context, "Atualizando", "Aguarde, atualização em andamento...");
	}
	
	@Override
	protected Void doInBackground(String... params) {
		String url = params[0];
		String urlVersao = url + "/atualizacoes/ultima_versao";
		
		try {
			int ultimaVersao = Integer.parseInt(WebUtils.getTextFromUrl(urlVersao));
			
			if (ultimaVersao > bancoDeDados.getVersao()) {
				
				downloadDataset(url);
				
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
		dialog.dismiss();
	}

	
	private void downloadDataset(String url) {
		String urlXml = url + "/dataset/Watcher.xml";
		String urlDat = url + "/dataset/Watcher.dat";
		
		FileDownloader downloader = new FileDownloader(urlXml, "/data/data/com.aftersixapps.watcher/Watcher.xml");
		downloader.download();
		
		downloader = new FileDownloader(urlDat, "/data/data/com.aftersixapps.watcher/Watcher.dat");
		downloader.download();		
	}
	

}
