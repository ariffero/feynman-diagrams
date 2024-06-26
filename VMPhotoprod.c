// draw the Feynman diagram for photon-nuclear diffractive process in UPCs
// with one EMD interaction (Xn0n). Landscape orientation.

void VMPhotoprod(string EMD = "Xn0n", bool directions = true, bool separate = true){

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

    //line for final state x
    TArrow *final;
    float arrowSize = 0.02;
    if(!directions) arrowSize = 0;

    //line for neutron from EMD
    TArrow *neutron;

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

    // photon
    gamma = new TCurlyLine(25, 60, 47, 33);
    gamma->SetWavy();
    gamma->Draw();
    t.DrawLatex(26,50,"#gamma");

    //pomeron
    TLine *pomeron = new TLine(49.5, 20, 55, 29);
    pomeron->SetLineStyle(2);
    pomeron->Draw();
    pomeron = new TLine(50.5, 20, 56, 29);
    pomeron->SetLineStyle(2);
    pomeron->Draw();
    t.DrawLatex(51,26,"#Rho");

    //final state x
    final = new TArrow(63, 33., 73, 33., arrowSize, "-->");
    final->Draw();
    t.SetTextFont(42);
    t.DrawLatex(84, 33.5,"#rho^{0}, J/#psi, ...");

    //interaction
    TEllipse *interaction;
    
    interaction = new TEllipse(55, 33, 8, 3);
    interaction->SetLineWidth(2);
    interaction->SetFillColor(0);
    //interaction->SetLineStyle(7);
    interaction->Draw();

    interaction = new TEllipse(55, 33, 3, 6);
    interaction->SetNoEdges();
    interaction->SetFillColor(kGray);
    interaction->SetLineWidth(0);
    interaction->Draw();

    

/*
    //EMD
    gamma = new TCurlyLine(60, 65.4, 66, 16.);
    if(separate) gamma = new TCurlyLine(70, 14.9, 66.3, 66.3);
    gamma->SetWavy();
    gamma->Draw();
    if(!separate) t.DrawLatex(58., 51.5,"#gamma");
    if(separate)  t.DrawLatex(71, 51.5,"#gamma");

    neutron = new TArrow(66, 16., 74, 16, arrowSize, "-->");
    if(separate) neutron = new TArrow(70, 15, 79, 15, arrowSize, "-->");
    neutron->Draw();
    if(!separate) t.DrawLatex(73,19.5,"n");
    if(separate)  t.DrawLatex(77,19,"n");

    if(EMD == "XnXn"){
        gamma = new TCurlyLine(78, 12.8, 73, 67.2);
        if(separate) gamma = new TCurlyLine(81.5, 12, 77.6, 68);
        gamma->SetWavy();
        gamma->Draw();
        if(!separate) t.DrawLatex(71, 51.5,"#gamma");
        if(separate)  t.DrawLatex(82, 53,"#gamma");

        neutron = new TArrow(73, 67.2, 84, 67.2, arrowSize, "-->");
        if(separate) neutron = new TArrow(77.6, 68, 88, 68, arrowSize, "-->");
        neutron->Draw();
        if(!separate) t.DrawLatex(83, 64,"n");
        if(separate)  t.DrawLatex(87, 64,"n");
    }
    
    //separate EMD interactions to make it clear that they are factorizable
    TLine *sep = new TLine(62.9, 5, 62.9, 75);
    sep->SetLineStyle(3);
    if(separate) sep->Draw();
*/

    //save the image
    gSystem->mkdir("images");
    c->SaveAs(Form("images/VMPhotoprod.pdf"));
}