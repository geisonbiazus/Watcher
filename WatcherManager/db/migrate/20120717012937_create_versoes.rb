class CreateVersoes < ActiveRecord::Migration
  def change
    create_table :versoes do |t|
      t.integer :numero

      t.timestamps
    end
  end
end
