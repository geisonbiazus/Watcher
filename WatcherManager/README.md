para executar o projeto siga os seguintes passos:
obs: Os passos a seguir servem para o projeto ser executado no sistema operacional linux(Ubuntu).

Execute o seguinte comando no diretório do projeto para instalar as gems necessárias

$ bundle install

Instale o redis-server e o postgresql

$ sudo apt-get install redis-server postgresql

Configure apropriadamente o arquivo config/database.yml

obs.: normalmente são configurado apenas os atributos username e password

Configure o arquivo config/config.yml.
Neste arquivo informe seu usuário e senha do sistema do Vuforia SDK.
O Usuário pode ser criado no seguinte endereço:

https://developer.vuforia.com/target-manager

Depois de criar o usuário, crie um Database para ser usado pelo projeto
este database é onde serão adicionadas as imagens.

O arquivo de configuração deve ficar da seguinte forma:

tms:
  usuario: seu@email.com
  senha: suasenha
  database: Watcher

Depois do projeto configurado, execute os seguintes comandos em um terminal para criar o banco de dados

$ rake db:create
$ rake db:migrate


O projeto utiliza o Google Chrome para acessar o sistema do vuforia, portanto ele necessita estar instalado;
Além do Chrome é necessário o aplicativo chromedriver para o projeto poder manipular o browser.
o chromedriver pode ser encontrado do seguinte endereço: https://code.google.com/p/chromedriver/downloads/list

Após obtido, o executavel deve ser adicionado ao PATH. O seguinte comando adiciona ele ao PATH temporariamente,
caso deseje adicionar permanentemente adicione este comando ao arquivo ~/.bashrc.

export PATH=/diretorio/onde/esta/seu/choromedriver:$PATH

Para executar a aplicação rails digite o seguinte comando no terminal no diretório do projeto:

$ rails s

Feito isso abra outra janela do terminal no mesmo diretório e execute o seguinte comando:

$ rake resque:work QUEUE='*'

Isso irá iniciar o gerenciador de filas. Estas filas são responsáveis por adicionar a imagem ao sistema do Vuforia,
assim como, realizar o download do dataset.

Para finalizar execute em um terceiro terminal no mesmo diretório o comando a seguir:

$ rake resque:scheduler

Este comando inicia o agendador do sistema, que a cada 30 minutos verifica se houve mudança nas imagens cadastradas e
gera um novo dataset no sistema do Vuforia SDK.

