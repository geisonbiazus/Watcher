package com.aftersixapps.watcher;

import java.io.BufferedOutputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;

public class FileDownloader {

	private String endereco;
	private String caminho;

	public FileDownloader(String endereco, String caminho) {
		this.endereco = endereco;
		this.caminho = caminho;
	}

	public void download() {

		try {
			URL url = new URL(endereco);
			byte[] buffer = new byte[1024];
			int byteLido = 0;

			OutputStream outputStream = new BufferedOutputStream(
					new FileOutputStream(caminho));
			URLConnection conexao = url.openConnection();
			
			InputStream inputStream = conexao.getInputStream();
			
			while ((byteLido = inputStream.read(buffer)) != -1) {
				outputStream.write(buffer, 0, byteLido);
			}
			
			inputStream.close();
			outputStream.close();
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
