require 'spec_helper'

describe "trackables/new" do
  before(:each) do
    assign(:trackable, stub_model(Trackable,
      :descricao => "MyString",
      :observacao => "MyText"
    ).as_new_record)
  end

  it "renders new trackable form" do
    render

    # Run the generator again with the --webrat flag if you want to use webrat matchers
    assert_select "form", :action => trackables_path, :method => "post" do
      assert_select "input#trackable_descricao", :name => "trackable[descricao]"
      assert_select "textarea#trackable_observacao", :name => "trackable[observacao]"
    end
  end
end
