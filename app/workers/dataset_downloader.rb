require 'xmlsimple'

class DatasetDownloader
  DOWNLOAD_DIR = "#{Rails.root}/public/dataset"
  FILE_URL = "#{DOWNLOAD_DIR}/Watcher.zip"
  @queue = :baixar_datasets

  def self.perform

    unless Trackable.a_atualizar.empty?
      
      profile = Selenium::WebDriver::Chrome::Profile.new
      profile['download.prompt_for_download'] = false

      Dir.mkdir(DOWNLOAD_DIR) rescue nil

      profile['download.default_directory'] = DOWNLOAD_DIR

      d = Selenium::WebDriver.for :chrome, :profile => profile

      d.get "https://ar.qualcomm.at/user?destination=sdk"
      d.find_element(:id, "edit-name").send_keys "geisonbiazus@gmail.com"
      d.find_element(:id, "edit-pass").send_keys "0787gb"
      d.find_element(:id, "edit-submit-1").click

      d.get "https://ar.qualcomm.at/project/1137799"

      d.find_element(:link, "All").click

      d.find_element(:link, "download selected trackables").click

      d.find_element(:id, "edit-submit-1").click

      while not File.exists?(FILE_URL)
        sleep 1
      end

      d.close
    
      File.delete("#{DOWNLOAD_DIR}/Watcher.dat")
      File.delete("#{DOWNLOAD_DIR}/Watcher.xml")
    

      system("unzip #{FILE_URL} -d #{DOWNLOAD_DIR}")

      File.delete(FILE_URL)

      xml = XmlSimple.xml_in('/home/geison/projetos/WatcherManager/public/dataset/Watcher.xml')

      xml['Tracking'].first["ImageTarget"].each do |item|
        if trackable = Trackable.find_by_descricao(item["name"])
          trackable.atualizado = true
          trackable.save
        end
      end
      
    end
  end
end
