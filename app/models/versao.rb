class Versao < ActiveRecord::Base
  attr_accessible :numero

  def self.get_instance
    Versao.first || Versao.new(:numero => 0)
  end

  def incrementa!
    self.numero += 1
    self.save
  end

end
