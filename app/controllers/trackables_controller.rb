class TrackablesController < ApplicationController
  active_scaffold :trackable do |config|
    config.columns = [:descricao, :observacao, :imagem, :url_video]
    config.create.columns.exclude :descricao
    config.update.columns.exclude :descricao
  end
end 