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

