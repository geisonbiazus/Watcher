class CreateTrackables < ActiveRecord::Migration
  def change
    create_table :trackables do |t|
      t.string :descricao
      t.text :observacao

      t.timestamps
    end
  end
end
