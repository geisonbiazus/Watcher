class Trackable < ActiveRecord::Base

  scope :a_atualizar, :conditions => "not atualizado or atualizado is null"

  CAMINHO_IMAGEM = "system/imagems/:filename"

  attr_accessible :descricao, :observacao, :imagem, :url_video
  has_attached_file :imagem, :path => ":rails_root/public/#{CAMINHO_IMAGEM}", :url => CAMINHO_IMAGEM

  validates :descricao, :presence => true, :uniqueness => true
  validates :imagem, :attachment_presence => true

  before_validation do |trackable|
    i = trackable.imagem_file_name
    trackable.descricao = (i.reverse[i.reverse.index(".")+1..-1].reverse rescue nil)
  end

  after_create do |trackable|
    TargetManagementSystem.adicionar_imagem(trackable)
  end


end
