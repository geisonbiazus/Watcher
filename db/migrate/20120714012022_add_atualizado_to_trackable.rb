class AddAtualizadoToTrackable < ActiveRecord::Migration
  def change
    add_column :trackables, :atualizado, :boolean
  end
end
