class Trackable < ActiveRecord::Base

  CAMINHO_IMAGEM = "system/imagems/:filename"

  attr_accessible :descricao, :observacao, :imagem
  has_attached_file :imagem, :path => ":rails_root/public/#{CAMINHO_IMAGEM}", :url => CAMINHO_IMAGEM

  validates :descricao, :presence => true, :uniqueness => true  
end
