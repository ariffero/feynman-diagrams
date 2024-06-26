// draw the Feynman diagram for photon-nuclear diffractive process in UPCs
// with EMD interaction

void diffractiveEMD(bool directions = true, bool separate = true){

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

    //line for neutron from EMD
    TArrow *neutron;

    //upper lead
    lead = new TLine(10, 80, 30, 70); 
    lead->Draw();
    lead = new TLine(30, 70, 70, 80); 
    lead->Draw();
    t.DrawLatex(15,83,"A");
    t.DrawLatex(65,83,"A'");

    //lower lead
    lead = new TLine(10, 20, 40, 30); 
    lead->Draw();
    lead = new TLine(40, 30, 70, 20); 
    lead->Draw();
    t.DrawLatex(15,17,"A");
    t.DrawLatex(65,17,"A");

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

    //final state x
    final = new TArrow(37, 44, 50, 44., arrowSize, "-->");
    final->Draw();

    t.DrawLatex(49,48.,"x");

    //interaction
    TEllipse *interaction = new TEllipse(37.5, 44, 3, 5);
    interaction->SetNoEdges();
    interaction->SetFillColor(kGray);
    interaction->SetLineWidth(0);
    interaction->Draw();

    t.DrawLatex(34,34,"#Rho");

    //EMD
    gamma = new TCurlyLine(59, 77.3, 62, 22.7);
    gamma->SetWavy();
    gamma->Draw();
    t.DrawLatex(64,57,"#gamma");

    //neutron
    neutron = new TArrow(59, 77.2, 68, 77.2, arrowSize, "-->");
    neutron->Draw();
    t.DrawLatex(67,74.5,"n");

    //separe EMD processes
    TLine *sep = new TLine(55, 15, 55, 85);
    sep->SetLineStyle(3);
    if(separate) sep->Draw();

    //save the image
    gSystem->mkdir("images");
    if(!separate) c->SaveAs("images/diffractiveEMD.pdf");
    if(separate)  c->SaveAs("images/diffractiveEMD-sep.pdf");

        
}