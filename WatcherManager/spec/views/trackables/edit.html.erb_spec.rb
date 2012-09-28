require 'spec_helper'

describe "trackables/edit" do
  before(:each) do
    @trackable = assign(:trackable, stub_model(Trackable,
      :descricao => "MyString",
      :observacao => "MyText"
    ))
  end

  it "renders the edit trackable form" do
    render

    # Run the generator again with the --webrat flag if you want to use webrat matchers
    assert_select "form", :action => trackables_path(@trackable), :method => "post" do
      assert_select "input#trackable_descricao", :name => "trackable[descricao]"
      assert_select "textarea#trackable_observacao", :name => "trackable[observacao]"
    end
  end
end
