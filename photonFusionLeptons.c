//draw Feynman diagram for photon-photon fusion in ll

void photonFusionLeptons(bool directions = true){
    
    TCanvas *c = new TCanvas("c", "c", 10,10, 600, 400);
    c->Range(0, 0, 100, 80);
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

    //line for leptons
    TArrow *lep;
    float arrowSize = 0.02;
    if(!directions) arrowSize = 0;

    //upper lead
    lead = new TLine(10, 70, 25, 60); 
    lead->Draw();
    lead = new TLine(25, 60, 90, 70); 
    lead->Draw();

    t.DrawLatex(15,74,"A");
    t.DrawLatex(85,74,"A");

    //lower lead
    // draw lower particle
    lead = new TLine(10, 10, 50, 20); 
    lead->Draw();
    lead = new TLine(50, 20, 90, 10); 
    lead->Draw();

    t.DrawLatex(15,6,"A");
    t.DrawLatex(85,6,"A");    

    //upper photon
    gamma = new TCurlyLine(25, 60, 40, 47.5);
    gamma->Draw();
    t.DrawLatex(27,52,"#gamma");

    //lower photon
    gamma = new TCurlyLine(50, 20, 40, 32.5);
    gamma->Draw();
    t.DrawLatex(51,25,"#gamma");

    //exchanged lepton
    lep = new TArrow(40, 32.5, 40, 47.5, arrowSize, "->-");
    lep->SetFillStyle(1001);
    lep->SetFillColor(0);
    lep->Draw();
    
    //electron
    lep = new TArrow(40, 47.5, 55, 47.5, arrowSize, "->-");
    lep->Draw();
    t.DrawLatex(57,47.5,"#it{l}^{-}");

    //positron
    lep = new TArrow(40, 32.5, 55, 32.5, arrowSize, "-<-");
    lep->Draw();
    t.DrawLatex(57,32.5,"#it{l}^{+}");

}