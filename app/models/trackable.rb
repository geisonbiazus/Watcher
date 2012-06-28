class Trackable < ActiveRecord::Base
  attr_accessible :descricao, :observacao, :imagem
  has_attached_file :imagem

  validates :descricao, :presence => true, :uniqueness => true  
end
