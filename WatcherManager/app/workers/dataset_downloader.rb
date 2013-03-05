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

      d.get "https://developer.vuforia.com/target-manager"
      d.find_element(:id, "edit-popup-user-name-login").send_keys $config["tms"]["usuario"]
      d.find_element(:id, "edit-popup-user-pass-login").send_keys $config["tms"]["senha"]
      d.find_element(:id, "edit-submit").click

      d.find_element(:xpath, "//div[text()=\"#{$config["tms"]["database"]}\"]").click

      sleep 2

      d.find_element(:link, 'Select All').click

      d.find_element(:id, 'buttonsCreate').click

      d.find_element(:id, 'createlDownloadDatabaseBtn').click

      while not File.exists?(FILE_URL)
        sleep 1
      end

      d.close
    
      File.delete("#{DOWNLOAD_DIR}/Watcher.dat") rescue nil
      File.delete("#{DOWNLOAD_DIR}/Watcher.xml") rescue nil
    

      system("unzip #{FILE_URL} -d #{DOWNLOAD_DIR}") 

      sleep 2

      File.delete(FILE_URL)

      xml = XmlSimple.xml_in("#{Rails.root}/public/dataset/Watcher.xml")

      xml['Tracking'].first["ImageTarget"].each do |item|
        if trackable = Trackable.find_by_descricao(item["name"])
          trackable.atualizado = true
          trackable.save
        end
      end

      Versao.get_instance.incrementa!      
    end
  end
end
