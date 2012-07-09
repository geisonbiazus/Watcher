a = Mechanize.new

a.get "https://ar.qualcomm.at/user?destination=sdk"
a.page.forms.first["name"] = "geisonbiazus@gmail.com"
a.page.forms.first["pass"] = "0787gb"
a.page.forms.first.submit

a.get "https://ar.qualcomm.at/projects"
a.get "https://ar.qualcomm.at/project/1137799"
a.get "https://ar.qualcomm.at/image_upload/1137799"

a.page.forms.first["target_id"] = "piratasdocaribe"
a.page.forms.first["dimension_width"] = "100"
a.page.forms.first.submit

a.page.link_with(:class => "uploadTargetInSingletarget").click()

a.page.forms.first.file_uploads.first.file_name = "/home/geison/workspace/Watcher/media/piratasdocaribe.jpg"
a.page.forms.first.submit

a.get "https://ar.qualcomm.at/project/1137799"

a.page.forms.first.checkboxes.each {|c| c.check}




require 'selenium-webdriver'

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

d.find_element(:id, "edit-target-id").send_keys "piratasdocaribe"
d.find_element(:id, "edit-dimension-width").send_keys "100"
d.find_element(:id, "edit-target-submit").click

d.find_element(:link, "Upload").click

d.find_element(:id, "edit-image").send_keys "/home/geison/workspace/Watcher/media/piratasdocaribe.jpg"
d.find_element(:id, "edit-submit-1").click
#
#require 'selenium-webdriver'
#
#profile = Selenium::WebDriver::Chrome::Profile.new
#profile['download.prompt_for_download'] = false
#profile['download.default_directory'] = '/home/geison/'
#
#d = Selenium::WebDriver.for :chrome, :profile => profile
#
#d.get "https://ar.qualcomm.at/user?destination=sdk"
#d.find_element(:id, "edit-name").send_keys "geisonbiazus@gmail.com"
#d.find_element(:id, "edit-pass").send_keys "0787gb"
#d.find_element(:id, "edit-submit-1").click

d.get "https://ar.qualcomm.at/project/1137799"

d.find_element(:link, "All").click

d.find_element(:link, "download selected trackables").click

d.find_element(:id, "edit-submit-1").click
