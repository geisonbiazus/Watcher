class AdicionadorDeImagem
  @queue = :imagens_a_adicionar
  def self.perform(nome, imagem)
    profile = Selenium::WebDriver::Chrome::Profile.new
    profile['download.prompt_for_download'] = false
    profile['download.default_directory'] = '/home/geison/'

    d = Selenium::WebDriver.for :chrome, :profile => profile

    d.get "https://ar.qualcomm.at/user?destination=sdk"
    d.find_element(:id, "edit-name").send_keys "geisonbiazus@gmail.com"
    d.find_element(:id, "edit-pass").send_keys "0787gb"
    d.find_element(:id, "edit-submit-1").click

    d.get "https://ar.qualcomm.at/project/1137799"
    d.find_element(:link, "Create a trackable").click

    d.find_element(:id, "edit-target-id").send_keys nome
    d.find_element(:id, "edit-dimension-width").send_keys "100"
    d.find_element(:id, "edit-target-submit").click

    d.find_element(:link, "Upload").click

    d.find_element(:id, "edit-image").send_keys "#{Rails.root}/public/system/imagems/#{imagem}"
    d.find_element(:id, "edit-submit-1").click
    d.close
  end

end
