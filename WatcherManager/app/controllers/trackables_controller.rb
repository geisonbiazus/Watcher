# encoding : utf-8

class TrackablesController < ApplicationController
  active_scaffold :trackable do |config|
    config.columns = [:descricao, :imagem, :url_video]
    config.create.columns.exclude :descricao
    config.update.columns.exclude :descricao

    config.columns[:descricao].label = "Descrição"
    config.columns[:url_video].label = "URL Vídeo"

  end
end 