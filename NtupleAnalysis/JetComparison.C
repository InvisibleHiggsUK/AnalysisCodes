#include "TString.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TH1.h"

#include <iostream>
#include <fstream>

ofstream myfile;
//myfile.open("example.txt");


int JetComparison(){ 
  myfile.open("example.txt");
  myfile << "Writing this"; 
  myfile.close();

  gROOT->Reset();
  
  gStyle->SetOptStat(0);
  gStyle->SetTitleFontSize(0.03);

  TString dirname = ".";
  TString rootname = "VBF_ntuple_125_weightedTEST.root";
  
  TCanvas *c1 = new TCanvas("JetEtaComp","JetEtaComp", 600, 600);
  TCanvas *c2 = new TCanvas("JetEtComp","JetEtComp",600, 600);

  TLegend *leg = new TLegend(0.5, 0.7,0.75, 0.88);
  TLegend *leg2 = new TLegend(0.5, 0.7,0.75, 0.88);  

  rootname = dirname + "/" + rootname;
  
  std::cout << "Rootname: " << rootname << std::endl;
  
  delete gROOT->GetListOfFiles()->FindObject(rootname);
    
  TFile *rootfile = new TFile(rootname);
  
  Float_t weight = 0.308;
  
  c1->cd();
  TH1D* hJet3Eta = (TH1D*)rootfile->Get("JetEtaexcess");
  Double_t entries3 = hJet3Eta->GetEntries();
  hJet3Eta->Scale(1/entries3);
  hJet3Eta->Draw("hist");
  hJet3Eta->SetLineColor(kRed);
  hJet3Eta->SetTitle("Jet #eta comparison");
  hJet3Eta->GetXaxis()->SetTitle("#eta");
  hJet3Eta->GetYaxis()->SetTitle("Entries (normalised)");
  hJet3Eta->Draw("hist");
  leg->AddEntry(hJet3Eta,"3^{rd} Jet #eta","l");

  TH1D* hJet2Eta = (TH1D*)rootfile->Get("Jet2Eta");
  Double_t entries1 = hJet2Eta->GetEntries();
  hJet2Eta->Scale(1/entries1);
  hJet2Eta->Draw("SAME hist");
  hJet2Eta->SetLineColor(kBlue);
  hJet2Eta->Draw("SAME hist");
  

  TH1D* hJet1Eta = (TH1D*)rootfile->Get("Jet1Eta");
  Double_t entries2 = hJet1Eta->GetEntries();
  hJet1Eta->Scale(1/entries2);
  hJet1Eta->Draw("SAME hist");
  hJet1Eta->SetLineColor(kYellow);
  hJet1Eta->Draw("SAME hist");
  leg->AddEntry(hJet2Eta,"2^{nd} Jet #eta","l");
  leg->AddEntry(hJet1Eta,"1^{st} Jet #eta","l");


  TH1D* hcenJetEta = (TH1D*)rootfile->Get("cenJetEta");
  Double_t entries4 = hcenJetEta->GetEntries();
  hcenJetEta->Draw("SAME hist");
  hcenJetEta->SetLineColor(kBlack);
  hcenJetEta->Scale(1/entries4);
  hcenJetEta->Draw("SAME hist");
  leg->AddEntry(hcenJetEta,"Central Jet #eta","l");
  leg->AddEntry((TObject*)0,"Normalised to unity","");
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->Draw();
  
  c1->Draw();
  c1->SaveAs("JetComparison.pdf(");



  c2->cd();
  TH1D* hJet3PT = (TH1D*)rootfile->Get("JetPTexcess");
  hJet3PT->Draw("hist");
  hJet3PT->Scale(1/entries3);
  hJet3PT->SetLineColor(kRed);
  hJet3PT->SetTitle("Jet E_{T} comparison");
  hJet3PT->GetYaxis()->SetTitle("Entries (normalised)");
  hJet3PT->GetXaxis()->SetTitle("E_{T} [GeV]");
  hJet3PT->Draw("hist");
  
  TH1D* hJet1PT = (TH1D*)rootfile->Get("Jet1Pt");
  Double_t entries2_1 = hJet1PT->GetEntries();
  hJet1PT->Draw("SAME hist");
  hJet1PT->SetLineColor(kYellow);
  hJet1PT->Scale(1/entries2_1);
  hJet1PT->Draw("SAME hist");
  
  TH1D* hJet2PT = (TH1D*)rootfile->Get("Jet2Pt");
  Double_t entries1_1 = hJet2PT->GetEntries();
  hJet2PT->Draw("SAME hist");
  hJet2PT->SetLineColor(kBlue);
  hJet2PT->Scale(1/entries1_1);
  hJet2PT->Draw("SAME hist");
  

  
  TH1D* hcenJetEt = (TH1D*)rootfile->Get("cenJetEt");
  hcenJetEt->Draw("SAME hist");
  hcenJetEt->SetLineColor(kBlack);
  hcenJetEt->Scale(1/entries4);
  hcenJetEt->Draw("SAME hist");
  

  leg2->AddEntry(hJet3PT,"3^{rd} Jet P_{T}","l");
  leg2->AddEntry(hJet2PT,"2^{nd} Jet P_{T}","l");
  leg2->AddEntry(hJet1PT,"1^{st} Jet P_{T}","l");
  leg2->AddEntry(hcenJetEt,"Cen Jet E_{T}","l");
  leg2->SetBorderSize(0);
  leg2->SetFillStyle(0);
  leg2->Draw();
  
  


  c2->Draw();
  c2->SaveAs("JetComparison.pdf)");

}  
  
  
