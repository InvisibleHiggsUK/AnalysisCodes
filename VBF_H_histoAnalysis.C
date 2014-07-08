// Author: Dominic Smith 
//         June 2014
// 
// 
// Description: 
// ROOT script to plot several histograms on a single and multiple pdfs/ps.
// Requires a ROOT TFile with the correct histo titles.
// User can choose what style to plot histos with


void VBF_H_histoAnalysis()
{

  gROOT->Reset();
  gStyle->SetOptStat(0);

  
  TString dirname = ".";
  TString rootname = "VBF_invH_8000_outputNEW.root";
  
  rootname = dirname + "/" + rootname;
  
  TFile *rootfile = new TFile(rootname);
  std::cout << "Rootfile : " << rootname << std::endl;

  // For TH2D histograms
  TString plots2 = "DeltaR1,DeltaR2,DeltaR3,DeltaR4";
  TObjArray* tokens1 = plots2.Tokenize(",");
  int n1 = tokens1->GetEntries();
  
  // For TH1D histograms
  TString plots = "InvJetMass,DeltaEtaJJ,DeltaPhiJJ,Jet1PT,Jet2PT,JetEta1,JetEta2,EtaDP,MET,CJVCut,Njets30,CJEta";
  TObjArray* tokens = plots.Tokenize(",");
  int n = tokens->GetEntries();

  // Canvas initialising 
  TCanvas c1("c1","draw plots",0,0,1000, 800);
  TCanvas ci_1("ci_1","draw separately",0,0,1000, 800);
  TCanvas c2("c2","draw together", 0, 0, 1000, 800);
  c1.Divide( 4, TMath::Nint(n/3.));

  // Legend initialising
  TLegend *leg = new TLegend(0.5,0.8,0.9,0.88);
  TLegend *leg2 = new TLegend(0.5,0.8,0.9,0.88);

  // Histo style initialising 
  TString styles = "hist,E,l,CONTZ";
  TObjArray* styletokens = styles.Tokenize(",");
  int m = styletokens->GetEntries();


  // Plot TH2D histos
  /*
  for(int i=0; i<n1; i++)
    {
      TString style = ((TObjString*) styletokens->At(3))->String();
      TString plot1 = ((TObjString*) tokens1->At(i))->String();

      std::cout << "Plot " << plot1 << std::endl;
      TH2F *h2i = (TH2F*)rootfile->Get(plot1);

      ci_1.cd();
      gStyle->SetOptStat(0);
      h2i->Draw(style);
      h2i->SetLineColor(kRed);
      //      h2i->GetXaxis()->SetTitle((const Char_t*) (plot1));
      h2i->GetXaxis()->SetTitle("");
      h2i->GetYaxis()->SetTitle("");
      h2i->GetYaxis()->SetRangeUser(0,4);
      h2i->SetTitle("");
      //      leg->AddEntry(h2i,"M3","l");
      leg->SetBorderSize(0);
      leg->SetFillStyle(0);
      //      leg->Draw();
      ci_1.SaveAs((const Char_t*) (plot1 + ".pdf"));

      c1.cd(i+1);
      h2i->Draw(style);
      
      c2.cd();
      h2i->Draw(style);
      c2.Print("histos.pdf(");

    }
  */

  c1.cd();
  c1.SaveAs("VBF_invH_8TeV_Nminus1HistoBoard_newest.pdf");

  // Plot TH1D histos

  for(int i=0; i<n; i++)
    {

      TString style = ((TObjString*) styletokens->At(0))->String();
      TString plot = ((TObjString*) tokens->At(i))->String();

      std::cout << "Plot " << plot << std::endl;
      TH1F *hi = (TH1F*)rootfile->Get(plot);

      ci_1.cd();
      hi->Draw(style);
      gPad->SetLogy();
      //      hi->Scale(1/hi->GetEntries());
      hi->GetXaxis()->SetTitle((const Char_t*) (plot));
      hi->GetYaxis()->SetTitle("Entries");
      ci_1.SaveAs((const Char_t*) (plot + ".pdf"));

      c1.cd(i+1);
      hi->Draw(style);
      gPad->SetLogy();

      c2.cd();
      hi->Draw(style);
      gPad->SetLogy();
      c2.Print("VBF_invH_8TeV_Histos.pdf(");

    }	   
  

  c2.Print("VBF_invH_8TeV_Histos.pdf)");
  c1.cd();
  c1.SaveAs("VBF_invH_8TeV_Nminus1HistoBoard_newest.pdf");

}
