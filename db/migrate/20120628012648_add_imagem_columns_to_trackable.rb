class AddImagemColumnsToTrackable < ActiveRecord::Migration
  def self.up
    add_attachment :trackables, :imagem
  end

  def self.down
    remove_attachment :trackables, :imagem
  end
end
