require "spec_helper"

describe TrackablesController do
  describe "routing" do

    it "routes to #index" do
      get("/trackables").should route_to("trackables#index")
    end

    it "routes to #new" do
      get("/trackables/new").should route_to("trackables#new")
    end

    it "routes to #show" do
      get("/trackables/1").should route_to("trackables#show", :id => "1")
    end

    it "routes to #edit" do
      get("/trackables/1/edit").should route_to("trackables#edit", :id => "1")
    end

    it "routes to #create" do
      post("/trackables").should route_to("trackables#create")
    end

    it "routes to #update" do
      put("/trackables/1").should route_to("trackables#update", :id => "1")
    end

    it "routes to #destroy" do
      delete("/trackables/1").should route_to("trackables#destroy", :id => "1")
    end

  end
end
