require 'spec_helper'

describe "trackables/show" do
  before(:each) do
    @trackable = assign(:trackable, stub_model(Trackable,
      :descricao => "Descricao",
      :observacao => "MyText"
    ))
  end

  it "renders attributes in <p>" do
    render
    # Run the generator again with the --webrat flag if you want to use webrat matchers
    rendered.should match(/Descricao/)
    rendered.should match(/MyText/)
  end
end
