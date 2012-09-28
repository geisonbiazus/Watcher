class AddUrlVideoToTrackable < ActiveRecord::Migration
  def change
    add_column :trackables, :url_video, :string
  end
end
