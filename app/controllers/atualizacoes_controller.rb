class AtualizacoesController < ApplicationController

  def ultima_versao
    render :xml => "<versao>#{Versao.get_instance.numero}</versao>"
  end

  def trackables
    render :json => Trackable.all.to_json(:only => [:descricao, :url_video])
  end
end
