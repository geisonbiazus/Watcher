class AtualizacoesController < ApplicationController

  def ultima_versao
    render :text => Versao.get_instance.numero
  end

  def trackables
    render :json => Trackable.all.to_json(:only => [:descricao, :url_video, :observacao])
  end
end
