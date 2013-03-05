class AdicionadorDeImagem
  @queue = :imagens_a_adicionar
  def self.perform(nome, imagem)
    profile = Selenium::WebDriver::Chrome::Profile.new
    profile['download.prompt_for_download'] = false
    profile['download.default_directory'] = '/home/geison/'

    d = Selenium::WebDriver.for :chrome, :profile => profile

    d.get "https://developer.vuforia.com/target-manager"
    d.find_element(:id, "edit-popup-user-name-login").send_keys $config["tms"]["usuario"]
    d.find_element(:id, "edit-popup-user-pass-login").send_keys $config["tms"]["senha"]
    d.find_element(:id, "edit-submit").click

    d.find_element(:xpath, "//div[text()=\"#{$config["tms"]["database"]}\"]").click

    d.find_element(:id, 'addDeviceTargetUserView').click

    d.find_element(:id, "targetName").send_keys nome
    d.find_element(:id, "targetDimension").send_keys "100"
    d.find_element(:id, "targetImgFile").send_keys "#{Rails.root}/public/system/imagens/#{imagem}"

    d.find_element(:id, "AddDeviceTargetBtn").click

    d.close
  end

end
