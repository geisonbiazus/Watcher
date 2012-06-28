class TrackablesController < ApplicationController
  active_scaffold :trackable do |config|
    config.columns = [:descricao, :observacao, :imagem]
  end
end 