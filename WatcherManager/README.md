bundle install
database.yml
rake db:create
rake db:migrate

chrome driver https://code.google.com/p/chromedriver/downloads/list
colocar no path
export PATH=/home/geison/Programas/bin:$PATH

rake resque:work QUEUE='*'

rails s

