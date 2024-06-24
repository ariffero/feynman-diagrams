//draw Feynman diagram for photon-photon fusion in ll

void photonFusionLeptons2(bool directions = true){
    
    TCanvas *c = new TCanvas("c", "c", 10,10, 400, 600);
    c->Range(0, 0, 80, 100);
    Int_t linsav = gStyle->GetLineWidth();
    gStyle->SetLineWidth(2);
    TLatex t;
    t.SetTextAlign(22);
    t.SetTextSize(0.07);
    t.SetTextFont(22);

    //line for lead
    TLine *lead;

    //wave for photon
    TCurlyLine *gamma = new TCurlyLine(); 
    gamma->SetWavy();
    gamma->Draw();

    //line for final state x
    TArrow *final;

    //line for leptons
    TArrow *lep;
    float arrowSize = 0.02;
    if(!directions) arrowSize = 0;

    //upper lead
    lead = new TLine(10, 80, 30, 70); 
    lead->Draw();
    lead = new TLine(30, 70, 70, 80); 
    lead->Draw();
    t.DrawLatex(15,83,"A");
    t.DrawLatex(65,83,"A");

    //lower lead
    lead = new TLine(10, 20, 40, 30); 
    lead->Draw();
    lead = new TLine(40, 30, 70, 20); 
    lead->Draw();
    t.DrawLatex(15,17,"A");
    t.DrawLatex(65,17,"A");

    //upper photon
    gamma = new TCurlyLine(30, 70, 35, 55);
    gamma->SetWavy();
    gamma->Draw();
    t.DrawLatex(27,62,"#gamma");

    //lower photon
    gamma = new TCurlyLine(40, 30, 35, 45);
    gamma->SetWavy();
    gamma->Draw();
    t.DrawLatex(43,37,"#gamma");

    //exchanged lepton
    lep = new TArrow(35, 45, 35, 55, arrowSize, "->-");
    lep->SetFillStyle(1001);
    lep->SetFillColor(0);
    lep->Draw();

    //electron
    lep = new TArrow(35, 55, 45, 55, arrowSize, "->-");
    lep->Draw();
    t.DrawLatex(48,55,"#it{l}^{-}");

    //positron
    lep = new TArrow(35, 45, 45, 45, arrowSize, "-<-");
    lep->Draw();
    t.DrawLatex(48,45,"#it{l}^{+}");

    //save the image
    gSystem->mkdir("images");
    c->SaveAs("images/photonFusionLeptons2.pdf");

}