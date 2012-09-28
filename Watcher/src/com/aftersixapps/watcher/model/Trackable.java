package com.aftersixapps.watcher.model;

import java.io.Serializable;

import com.google.gson.annotations.SerializedName;

public class Trackable implements Serializable {

	private static final long serialVersionUID = 8184593837922716702L;

	private Integer id;
	@SerializedName("descricao")
	private String descricao;
	@SerializedName("url_video")
	private String urlVideo;
	@SerializedName("observacao")
	private String observacao;

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public String getDescricao() {
		return descricao;
	}

	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}

	public String getUrlVideo() {
		return urlVideo;
	}

	public void setUrlVideo(String urlVideo) {
		this.urlVideo = urlVideo;
	}

	public String getObservacao() {
		return observacao;
	}

	public void setObservacao(String observacao) {
		this.observacao = observacao;
	}
}
