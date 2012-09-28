class TargetManagementSystem
  class << self

    def adicionar_imagem(trackable)
      Resque.enqueue(AdicionadorDeImagem, trackable.descricao, trackable.imagem_file_name)
    end

    def remover_imagem(imagem)

    end

    def baixar_dataset

    end
  end

end
