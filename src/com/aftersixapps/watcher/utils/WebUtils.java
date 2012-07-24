package com.aftersixapps.watcher.utils;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;

import android.util.Log;

public class WebUtils {

	public static String getTextFromUrl(String endereco) throws IOException {

		String retorno = null;

		try {
			URL url = new URL(endereco);

			HttpURLConnection urlConnection = (HttpURLConnection) url
					.openConnection();
			BufferedReader in = new BufferedReader(new InputStreamReader(
					urlConnection.getInputStream()));

			String linha = null;

			while ((linha = in.readLine()) != null) {
				if (retorno == null) {
					retorno = "";
				}

				retorno += linha;
			}

			in.close();
			urlConnection.disconnect();

		} catch (MalformedURLException e) {
			Log.e("ERRO", "Formato da url incorreto.");
		}

		return retorno;
	}

}
