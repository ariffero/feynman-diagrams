// draw the Feynman diagram for photon-nuclear diffractive process in UPCs

void diffractive(bool directions = true){

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
    t.DrawLatex(65,17,"A");

    // photon
    gamma = new TCurlyLine(30, 70, 40, 30);
    gamma->SetWavy();
    gamma->Draw();
    t.DrawLatex(27,62,"#gamma");

    //final state x
    final = new TArrow(40, 33., 55, 33., arrowSize, "-->");
    final->Draw();
    t.DrawLatex(59,33.,"x");
    
    //interaction
    TEllipse *interaction = new TEllipse(40, 32, 3, 5);
    interaction->SetNoEdges();
    interaction->SetFillColor(kGray);
    interaction->SetLineWidth(0);
    interaction->Draw();

    //save the image
    gSystem->mkdir("images");
    c->SaveAs("images/diffractive.pdf");

        
}