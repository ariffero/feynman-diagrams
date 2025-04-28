// draw the Feynman diagram for photon-nuclear inclusive process in UPCs

void diffractiveExclusive(bool coh = true, bool directions = true){

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
    if(!coh) t.DrawLatex(65,17,"A'");
    if(coh) t.DrawLatex(65,17,"A");

    // photon
    gamma = new TCurlyLine(30, 70, 37, 47);
    gamma->SetWavy();
    gamma->Draw();
    t.DrawLatex(27,62,"#gamma");


    //pomeron
    TLine *pomeron = new TLine(39.5, 29.8, 37, 40);
    pomeron->SetLineStyle(2);
    pomeron->Draw();
    pomeron = new TLine(40.5, 29.8, 38, 40);
    pomeron->SetLineStyle(2);
    pomeron->Draw();
    t.DrawLatex(34,34,"#Rho");
    
    //final state x
    //final = new TArrow(37, 42., 60, 38., arrowSize, "-->");
    //final->Draw();
    //final = new TArrow(37, 43.5, 61, 43., arrowSize, "-->");
    //final->Draw();
    //final = new TArrow(37, 45., 57, 47., arrowSize, "-->");
    //final->Draw();
    final = new TArrow(37, 44, 55, 44., arrowSize, "-->");
    final->Draw();

    t.DrawLatex(61,44.,"VM");

    //interaction
    TEllipse *interaction = new TEllipse(37.5, 44, 3, 5);
    interaction->SetNoEdges();
    interaction->SetFillColor(kGray);
    interaction->SetLineWidth(0);
    interaction->Draw();

    // if the interaction is incoh draw a neutron of the nucleus-going side
    TArrow *neutron;
    neutron = new TArrow(40, 30, 49, 30, arrowSize, "-->");
    if(!coh) neutron->Draw();
    if(!coh) t.DrawLatex(51.5,30,"n");

    //TLatex gaps;
    //gaps.SetTextAlign(22);
    //gaps.SetTextSize(0.18);
    //gaps.SetTextFont(152);
    //gaps.DrawLatex(50,34,"}");
    //gaps.SetTextSize(0.3);
    //gaps.DrawLatex(50,60,"}");
    //TLatex rap;
    //t.DrawLatex(58,34,"gap");

    //mark the rapidity gap
    TArrow *rap = new TArrow(50,36,60,36,arrowSize,"<-|");
    rap->Draw();
    t.DrawLatex(66, 36, "gap");
    rap = new TArrow(50, 60, 60, 60,arrowSize,"<-|");
    rap->Draw();
    t.DrawLatex(66, 60, "gap");

    //save the image
    gSystem->mkdir("images");
    if(coh){
        c->SaveAs("images/diffractiveExclusive.pdf");
        c->SaveAs("images/diffractiveExclusive.png");
    }
    if(!coh){
        c->SaveAs("images/diffractiveExclusiveIncoh.pdf");
        c->SaveAs("images/diffractiveExclusiveIncoh.png");
    }
        
}