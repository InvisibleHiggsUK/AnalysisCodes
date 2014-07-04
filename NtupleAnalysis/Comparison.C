#ifndef COMPARISON_H
#define COMPARISON_H
// Comparison between DELPHES and Fullsim ntuples before any baseline-cuts are applied

// The histograms in both DELPHES samples are labelled: 
// InvMass, DeltaEta, DeltaPhi EtaDP, CJEt, MET, Jet1PT JetEta1t, Jet2PT, JetEta2
//
// They have either no weight and no baseline cuts, no weight and baseline cuts applied, 
// or weighted to 19.5 1/fb with baseline cuts applied
//
// The histograms in the Fullsim ntuples are labelled:
// vbfM, vbfDEta, vbfDPhi, cenJetEt, MET, Jet1Pt, Jet1Eta, Jet2Pt, Jet2Eta
// They are taken from 19.5 1/fb of data at 8 TeV
#include <iostream>
#include <TH1.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TPad.h>

#include "Dataset.h"    // Includes the dataset declaration 

void Comparison(unsigned int id){

  gROOT->Reset();

  std::cout << "Running comparison for the '" << Dataset::toTString(id) << "' sample" << std::endl;
  
  std::cout << "\nDataset is : " << Dataset::fullDatasetName(id) << "\n" << std::endl;

  gStyle->SetOptStat(0);
  gStyle->SetTitleFontSize(0.03);
  
  TCanvas *c1 = new TCanvas("JetMassComp","InvJetMass Comparison", 600, 600);
  TPad *c1_0 = new TPad("pad1","pad1",0., 0.15, 1., 1.);
  c1_0->SetTopMargin(0.05);
  c1_0->SetBottomMargin(0.26);
  c1_0->Draw();

  TPad *c1_1 = new TPad("pad1_1","pad1_1",0., 0.02, 1., 0.3);
  c1_1->SetTopMargin(0.05);
  c1_1->SetBottomMargin(0.26);
  c1_1->SetRightMargin(0.05);
  c1_1->SetGridx(1);
  c1_1->SetGridy(1);
  c1_1->Draw();

  TCanvas *c2 = new TCanvas("DeltaEtaComp","DeltaEta Comparison", 600, 600);
  TPad *c2_0 = new TPad("pad2","pad2",0., 0.15, 1., 1.);
  c2_0->SetTopMargin(0.05);
  c2_0->SetBottomMargin(0.26);
  c2_0->Draw();

  TPad *c2_1 = new TPad("pad2_1","pad2_1",0., 0.02, 1., 0.3);
  c2_1->SetTopMargin(0.05);
  c2_1->SetBottomMargin(0.26);
  c2_1->SetRightMargin(0.05);
  c2_1->SetGridx(1);
  c2_1->SetGridy(1);
  c2_1->Draw();

  TCanvas *c3 = new TCanvas("DeltaPhiComp","DeltaPhi Comparison", 600, 600);
  TPad *c3_0 = new TPad("pad3","pad3",0., 0.15, 1., 1.);
  c3_0->SetTopMargin(0.05);
  c3_0->SetBottomMargin(0.26);
  c3_0->Draw();

  TPad *c3_1 = new TPad("pad3_1","pad3_1",0., 0.02, 1., 0.3);
  c3_1->SetTopMargin(0.05);
  c3_1->SetBottomMargin(0.26);
  c3_1->SetRightMargin(0.05);
  c3_1->SetGridx(1);
  c3_1->SetGridy(1);
  c3_1->Draw();
  
  TCanvas *c4 = new TCanvas("cenjetEt","cenjetEt Comparison", 600, 600);
  TPad *c4_0 = new TPad("pad4","pad4",0., 0.15, 1., 1.);
  c4_0->SetTopMargin(0.05);
  c4_0->SetBottomMargin(0.26);
  c4_0->Draw();

  TPad *c4_1 = new TPad("pad4_1","pad4_1",0., 0.02, 1., 0.3);
  c4_1->SetTopMargin(0.05);
  c4_1->SetBottomMargin(0.26);
  c4_1->SetRightMargin(0.05);
  c4_1->SetGridx(1);
  c4_1->SetGridy(1);
  c4_1->Draw();

  TCanvas *c5 = new TCanvas("MET","MET Comparison", 600, 600);
  TPad *c5_0 = new TPad("pad5","pad5",0., 0.15, 1., 1.);
  c5_0->SetTopMargin(0.05);
  c5_0->SetBottomMargin(0.26);
  c5_0->Draw();

  TPad *c5_1 = new TPad("pad5_1","pad5_1",0., 0.02, 1., 0.3);
  c5_1->SetTopMargin(0.05);
  c5_1->SetBottomMargin(0.26);
  c5_1->SetRightMargin(0.05);
  c5_1->SetGridx(1);
  c5_1->SetGridy(1);
  c5_1->Draw();

  TCanvas *c6 = new TCanvas("Jet1PT","Jet1PT Comparison", 600, 600);
  TPad *c6_0 = new TPad("pad6","pad6",0., 0.15, 1., 1.);
  c6_0->SetTopMargin(0.05);
  c6_0->SetBottomMargin(0.26);
  c6_0->Draw();

  TPad *c6_1 = new TPad("pad6_1","pad6_1",0., 0.02, 1., 0.3);
  c6_1->SetTopMargin(0.05);
  c6_1->SetBottomMargin(0.26);
  c6_1->SetRightMargin(0.05);
  c6_1->SetGridx(1);
  c6_1->SetGridy(1);
  c6_1->Draw();

  TCanvas *c7 = new TCanvas("Jet2PT","Jet2PT Comparison", 600, 600);
  TPad *c7_0 = new TPad("pad7","pad7",0., 0.15, 1., 1.);
  c7_0->SetTopMargin(0.05);
  c7_0->SetBottomMargin(0.26);
  c7_0->Draw();

  TPad *c7_1 = new TPad("pad7_1","pad7_1",0., 0.02, 1., 0.3);
  c7_1->SetTopMargin(0.05);
  c7_1->SetBottomMargin(0.26);
  c7_1->SetRightMargin(0.05);
  c7_1->SetGridx(1);
  c7_1->SetGridy(1);
  c7_1->Draw();

  TCanvas *c8 = new TCanvas("Jet1Eta","Jet1Eta Comparison", 600, 600);
  TPad *c8_0 = new TPad("pad7","pad7",0., 0.15, 1., 1.);
  c8_0->SetTopMargin(0.05);
  c8_0->SetBottomMargin(0.26);
  c8_0->Draw();

  TPad *c8_1 = new TPad("pad8_1","pad8_1",0., 0.02, 1., 0.3);
  c8_1->SetTopMargin(0.05);
  c8_1->SetBottomMargin(0.26);
  c8_1->SetRightMargin(0.05);
  c8_1->SetGridx(1);
  c8_1->SetGridy(1);
  c8_1->Draw();

  TCanvas *c9 = new TCanvas("Jet2Eta","Jet2Eta Comparison", 600, 600);
  TPad *c9_0 = new TPad("pad8","pad8",0., 0.15, 1., 1.);
  c9_0->SetTopMargin(0.05);
  c9_0->SetBottomMargin(0.26);
  c9_0->Draw();

  TPad *c9_1 = new TPad("pad9_1","pad9_1",0., 0.02, 1., 0.3);
  c9_1->SetTopMargin(0.05);
  c9_1->SetBottomMargin(0.26);
  c9_1->SetRightMargin(0.05);
  c9_1->SetGridx(1);
  c9_1->SetGridy(1);
  c9_1->Draw();

  // Declare legends
  TLegend *leg = new TLegend(0.5,0.7, 0.9, 0.88);
  TLegend *leg2 = new TLegend(0.5,0.7,0.9,0.88);
  TLegend *leg3 = new TLegend(0.5,0.7,0.9,0.88);
  TLegend *leg4 = new TLegend(0.5, 0.7,0.9, 0.88);
  TLegend *leg5 = new TLegend(0.5,0.7,0.9, 0.88);
  TLegend *leg6 = new TLegend(0.5,0.7,0.9, 0.88);
  TLegend *leg7 = new TLegend(0.5,0.7, 0.9, 0.88);
  TLegend *leg8 = new TLegend(0.5,0.7,0.9,0.88);
  TLegend *leg9 = new TLegend(0.5,0.7,0.9,0.88);

  TString dirname = ".";
  TString ntuple = "VBF_ntuple_125.root";
  TString DELPHES_ntuple = Dataset::fullDatasetName(id);
  
  ntuple = dirname + "/" + ntuple;
  DELPHES_ntuple = dirname + "/" + DELPHES_ntuple;
  
  delete gROOT->GetListOfFiles()->FindObject(ntuple);
  delete gROOT->GetListOfFiles()->FindObject(DELPHES_ntuple);
  

  TFile *ntuple_file = new TFile(ntuple);
  TFile *delphes_file = new TFile(DELPHES_ntuple);
 
  // Canvas 1
  c1->cd();
  c1_0->cd();
  // Get dijet invariant mass
  TH1F* hInvJMassComp = (TH1F*)ntuple_file->Get("vbfM");
  Double_t entries1 = hInvJMassComp->GetEntries();
  hInvJMassComp->Draw("hist");
  hInvJMassComp->SetLineColor(kRed);
  hInvJMassComp->GetXaxis()->SetTitle("M_{jj} [GeV]");
  hInvJMassComp->GetYaxis()->SetTitle("Events / 100 GeV");
  hInvJMassComp->Scale(1/entries1);
  // Get dijet invariant mass from DELPHES ntuple
  TH1F* hInvJMassDELPHES = (TH-1F*)delphes_file->Get("InvMass");
  Double_t entries_1 = hInvJMassDELPHES->GetEntries();
  hInvJMassDELPHES->Draw("SAME hist");
  hInvJMassDELPHES->SetLineColor(kBlue);
  hInvJMassDELPHES->Scale(1/entries_1);
  leg->AddEntry(hInvJMassComp, "M_{jj} FullSim, 19.5 fb^{-1} 8 TeV","l");
  leg->AddEntry(hInvJMassDELPHES,"M_{jj} VBFNLO + DELPHES","l");
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  if(id ==1){ leg->AddEntry((TObject*)0, "m_{h2} = 220 GeV, precut & unweighted",""); }
  if(id ==2){ leg->AddEntry((TObject*)0, "m_{h2} = 220 GeV, precut and weighted to 19.5 fb^{-1}",""); }
  if(id ==3){ leg->AddEntry((TObject*)0, "m_{h2} = 220 GeV, cut and weighted",""); }
  if(id ==4){ leg->AddEntry((TObject*)0, "m_{H} = 125 GeV, precut and unweighted",""); }
  if(id ==5){ leg->AddEntry((TObject*)0, "m_{H} = 125 GeV, precut and weighted to 19.5 fb^{-1}",""); }
  if(id ==6){ leg->AddEntry((TObject*)0, "m_{H} = 125 GeV, cut and weighted to 19.5 fb^{-1}",""); }
  leg->Draw();
  c1_0->Draw();   // Draw canvas
  // Fill Pad
  c1_1->cd();
  c1_1->SetTopMargin(0.05);
  c1_1->SetBottomMargin(0.26);
  c1_1->SetRightMargin(0.05);
  c1_1->SetGridx(1);
  c1_1->SetGridy(1);
  c1_1->SetTopMargin(0.05);
  c1_1->SetBottomMargin(0.26);
  c1_1->SetRightMargin(0.05);
  c1_1->SetGridx(1);
  c1_1->SetGridy(1);
  c1_1->Draw();
  TH1D *ratio1 = hInvJMassComp->Clone();
  TLine *l = new TLine(0,1,4000,1);
  ratio1->Divide(hInvJMassDELPHES);
  ratio1->Draw("E1");
  l->SetLineColor(kBlue);
  l->Draw("SAME");
  // Fit chi-squared to ration
  //  TF1 *fit = new TF1("fit","pol0",ratio1->GetXaxis()->GetBinLowEdge(1),ratio1->GetXaxis()->GetBinUpEdge(ratio1->GetNbinsX()));
  //  gStyle->SetOptFit(1);
  //  ratio1->Fit(fit);
  // Save histo to pdf
  c1->SaveAs(Dataset::pdfTitler(id)+".pdf(");
  

  // Canvas 2
  c2->cd();
  c2_0->cd();
  // Get Delta Eta(jj) from DELPHES ntuple
  TH1* hDeltaEtaDELPHES = (TH1F*)delphes_file->Get("DeltaEtaJJ");
  Double_t entries_2 = hDeltaEtaDELPHES->GetEntries();
  hDeltaEtaDELPHES->Draw("hist");
  hDeltaEtaDELPHES->SetLineColor(kBlue);
  hDeltaEtaDELPHES->Scale(1/entries_2);
  TH1* hDeltaEta = (TH1F*)ntuple_file->Get("vbfDEta");
  Double_t entries2 = hDeltaEta->GetEntries();
  hDeltaEta->Draw("SAME hist");
  hDeltaEta->SetLineColor(kRed);
  hDeltaEta->GetXaxis()->SetTitle("#Delta#eta_{jj}");
  hDeltaEta->GetYaxis()->SetTitle("Events / 0.2");
  hDeltaEta->Scale(1/entries2);
  leg2->AddEntry(hDeltaEta,"#Delta#eta_{jj} CMS FullSim, 19.5 fb^{-1} 8 TeV","l");
  leg2->AddEntry(hDeltaEtaDELPHES,"#Delta#eta_{jj} VBFNLO + DELPHES","l");
  leg2->SetFillStyle(0);
  leg2->SetBorderSize(0);
  if(id ==1){ leg2->AddEntry((TObject*)0, "m_{h2} = 220 GeV, precut & unweighted",""); }
  if(id ==2){ leg2->AddEntry((TObject*)0, "m_{h2} = 220 GeV, precut and weighted to 19.5 fb^{-1}",""); }
  if(id ==3){ leg2->AddEntry((TObject*)0, "m_{h2} = 220 GeV, cut and weighted",""); }
  if(id ==4){ leg2->AddEntry((TObject*)0, "m_{H} = 125 GeV, precut and unweighted",""); }
  if(id ==5){ leg2->AddEntry((TObject*)0, "m_{H} = 125 GeV, precut and weighted to 19.5 fb^{-1}",""); }
  if(id ==6){ leg2->AddEntry((TObject*)0, "m_{H} = 125 GeV, cut and weighted to 19.5 fb^{-1}",""); }
  leg2->Draw();
  c2_0->Draw();
  // Fill Pad
  c2_1->cd();
  c2_1->SetTopMargin(0.05);
  c2_1->SetBottomMargin(0.26);
  c2_1->SetRightMargin(0.05);
  c2_1->SetGridx(1);
  c2_1->SetGridy(1);
  c2_1->Draw();
  TH1 *ratio2 = hDeltaEta->Clone();
  TLine *l2 = new TLine(0,1,10,1);
  ratio2->Divide(hDeltaEtaDELPHES);
  ratio2->Draw("E1");
  ratio2->GetYaxis()->SetRangeUser(0,9);
  l2->SetLineColor(kBlue);
  l2->Draw("SAME");
  // Save histo to pdf
  c2->SaveAs(Dataset::pdfTitler(id)+".pdf(");

  // Canvas 3
  c3->cd();
  c3_0->cd();
  // Get DeltaPhi(jj) from ntuple
  TH1* hDeltaPhi = (TH1F*)ntuple_file->Get("vbfDPhi");
  Double_t entries3 = hDeltaPhi->GetEntries();
  hDeltaPhi->Draw("hist");
  hDeltaPhi->SetLineColor(kRed);
  hDeltaPhi->Scale(1/entries3);
  hDeltaPhi->GetXaxis()->SetTitle("#Delta#phi_{jj}");
  hDeltaPhi->GetYaxis()->SetTitle("Events / #pi/50");
  TH1* hDeltaPhiDELPHES = (TH1F*)delphes_file->Get("DeltaPhiJJ");
  Double_t entries_3 = hDeltaPhiDELPHES->GetEntries();
  hDeltaPhiDELPHES->Draw("SAME hist");
  hDeltaPhiDELPHES->SetLineColor(kBlue);
  hDeltaPhiDELPHES->Scale(1/entries_3);
  leg3->AddEntry(hDeltaPhi,"#Delta#phi_{jj} CMS FullSim, 19.5 fb^{-1} 8 TeV","l");
  leg3->AddEntry(hDeltaPhiDELPHES,"#Delta#phi_{jj} VBFNLO + DELPHES","l");
  leg3->SetFillStyle(0);
  leg3->SetBorderSize(0);
  if(id ==1){ leg3->AddEntry((TObject*)0, "m_{h2} = 220 GeV, precut & unweighted",""); }
  if(id ==2){ leg3->AddEntry((TObject*)0, "m_{h2} = 220 GeV, precut and weighted to 19.5 fb^{-1}",""); }
  if(id ==3){ leg3->AddEntry((TObject*)0, "m_{h2} = 220 GeV, cut and weighted",""); }
  if(id ==4){ leg3->AddEntry((TObject*)0, "m_{H} = 125 GeV, precut and unweighted",""); }
  if(id ==5){ leg3->AddEntry((TObject*)0, "m_{H} = 125 GeV, precut and weighted to 19.5 fb^{-1}",""); }
  if(id ==6){ leg3->AddEntry((TObject*)0, "m_{H} = 125 GeV, cut and weighted to 19.5 fb^{-1}",""); }
  leg3->Draw();
  c3_0->Draw();
  // Fill Pad
  c3_1->cd();
  c3_1->SetTopMargin(0.05);
  c3_1->SetBottomMargin(0.26);
  c3_1->SetRightMargin(0.05);
  c3_1->SetGridx(1);
  c3_1->SetGridy(1);
  c3_1->Draw();
  TH1 *ratio3 = hDeltaPhi->Clone();
  TLine *l3 = new TLine(0,1,4,1);
  ratio3->Divide(hDeltaPhiDELPHES);
  ratio3->Draw("E1");
  l3->SetLineColor(kBlue);
  l3->Draw("SAME");
  // Save histo to pdf
  c3->SaveAs(Dataset::pdfTitler(id)+".pdf(");

  // Canvas 4
  c4->cd();
  c4_0->cd();
  TH1* hCenJetET = (TH1F*)ntuple_file->Get("cenJetEt");
  Double_t entries4 = hCenJetET->GetEntries();
  hCenJetET->Draw("hist");
  hCenJetET->SetLineColor(kRed);
  hCenJetET->Scale(1/entries4);
  hCenJetET->GetXaxis()->SetTitle("Central Jet E_{T} [GeV]");
  hCenJetET->GetYaxis()->SetTitle("Events / 5 GeV");
  TH1* hCenJetETDELPHES = (TH1F*)delphes_file->Get("CJEt");
  Double_t entries_4 = hCenJetETDELPHES->GetEntries();
  hCenJetETDELPHES->Draw("SAME hist");
  hCenJetETDELPHES->SetLineColor(kBlue);
  hCenJetETDELPHES->Scale(1/entries_4);
  leg4->AddEntry(hCenJetET,"Central jet E_{T} FullSim 19.5 fb^{-1} 8 TeV","l");
  leg4->AddEntry(hCenJetETDELPHES,"Central jet E_{T} VBFNLO + DELPHES","l");
  leg4->SetFillStyle(0);
  leg4->SetBorderSize(0);
  if(id ==1){ leg4->AddEntry((TObject*)0, "m_{h2} = 220 GeV, precut & unweighted",""); }
  if(id ==2){ leg4->AddEntry((TObject*)0, "m_{h2} = 220 GeV, precut and weighted to 19.5 fb^{-1}",""); }
  if(id ==3){ leg4->AddEntry((TObject*)0, "m_{h2} = 220 GeV, cut and weighted",""); }
  if(id ==4){ leg4->AddEntry((TObject*)0, "m_{H} = 125 GeV, precut and unweighted",""); }
  if(id ==5){ leg4->AddEntry((TObject*)0, "m_{H} = 125 GeV, precut and weighted to 19.5 fb^{-1}",""); }
  if(id ==6){ leg4->AddEntry((TObject*)0, "m_{H} = 125 GeV, cut and weighted to 19.5 fb^{-1}",""); }
  leg4->Draw();
  c4_0->cd();
  // Fill Pad
  c4_1->cd();
  c4_1->SetTopMargin(0.05);
  c4_1->SetBottomMargin(0.26);
  c4_1->SetRightMargin(0.05);
  c4_1->SetGridx(1);
  c4_1->SetGridy(1);
  c4_1->Draw();
  TH1 *ratio4 = hCenJetET->Clone();
  TLine *l4 = new TLine(0,1,150,1);
  ratio4->Divide(hCenJetETDELPHES);
  ratio4->Draw("E1");
  ratio4->GetYaxis()->SetRangeUser(0,10);
  l4->SetLineColor(kBlue);
  l4->Draw("SAME");
  c4->SaveAs(Dataset::pdfTitler(id)+".pdf(");

  // Canvas 5
  c5->cd();
  c5_0->cd();
  TH1* hMET = (TH1F*)ntuple_file->Get("MET");
  Double_t entries5 = hMET->GetEntries();
  hMET->Draw("hist");
  hMET->SetLineColor(kRed);
  hMET->Scale(1/entries5);
  hMET->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
  hMET->GetYaxis()->SetTitle("Events / 10 GeV");
  TH1 *hMETDELPHES = (TH1F*)delphes_file->Get("MET");
  Double_t entries_5 = hMETDELPHES->GetEntries();
  hMETDELPHES->Draw("SAME hist");
  hMETDELPHES->SetLineColor(kBlue);
  hMETDELPHES->Scale(1/entries_5);
  leg5->AddEntry(hMET,"E_{T}^{miss} CMS FullSim 19.5 fb^{-1} 8 TeV", "l");
  leg5->AddEntry(hMETDELPHES,"E_{T}^{miss} VBFNLO + DELPHES","l");
  leg5->SetFillStyle(0);
  leg5->SetBorderSize(0);
  if(id ==1){ leg5->AddEntry((TObject*)0, "m_{h2} = 220 GeV, precut & unweighted",""); }
  if(id ==2){ leg5->AddEntry((TObject*)0, "m_{h2} = 220 GeV, precut and weighted to 19.5 fb^{-1}",""); }
  if(id ==3){ leg5->AddEntry((TObject*)0, "m_{h2} = 220 GeV, cut and weighted",""); }
  if(id ==4){ leg5->AddEntry((TObject*)0, "m_{H} = 125 GeV, precut and unweighted",""); }
  if(id ==5){ leg5->AddEntry((TObject*)0, "m_{H} = 125 GeV, precut and weighted to 19.5 fb^{-1}",""); }
  if(id ==6){ leg5->AddEntry((TObject*)0, "m_{H} = 125 GeV, cut and weighted to 19.5 fb^{-1}",""); }
  leg5->Draw();
  c5_0->Draw();  
  // Fill Pad
  c5_1->cd();
  c5_1->SetTopMargin(0.05);
  c5_1->SetBottomMargin(0.26);
  c5_1->SetRightMargin(0.05);
  c5_1->SetGridx(1);
  c5_1->SetGridy(1);
  c5_1->Draw();
  TH1 *ratio5 = hMET->Clone();
  TLine *l5 = new TLine(0,1,500,1);
  ratio5->Divide(hMETDELPHES);
  ratio5->Draw("E1");
  l5->SetLineColor(kBlue);
  l5->Draw("SAME");
  // Save histo to pdf
  c5->SaveAs(Dataset::pdfTitler(id)+".pdf(");
  
  // Canvas 6
  c6->cd();
  c6_0->cd();
  TH1* hJet1PT = (TH1F*)ntuple_file->Get("Jet1Pt");
  Double_t entries6 = hJet1PT->GetEntries();
  hJet1PT->Draw("hist");
  hJet1PT->SetLineColor(kRed);
  hJet1PT->Scale(1/entries6);
  hJet1PT->GetXaxis()->SetTitle("Leading jet p_{T} [GeV]");
  hJet1PT->GetYaxis()->SetTitle("Events / 5 GeV");
  TH1* hJet1PTDELPHES = (TH1F*)delphes_file->Get("Jet1PT");
  Double_t entries_6 = hJet1PTDELPHES->GetEntries();
  hJet1PTDELPHES->Draw("SAME hist");
  hJet1PTDELPHES->SetLineColor(kBlue);
  hJet1PTDELPHES->Scale(1/entries_6);
  leg6->AddEntry(hJet1PT,"Leading jet p_{T} CMS FullSim 19.5 fb^{-1} 8 TeV", "l");
  leg6->AddEntry(hJet1PTDELPHES,"Leading jet p_{T} VBFNLO + DELPHES","l");
  leg6->SetFillStyle(0);
  leg6->SetBorderSize(0);
  if(id ==1){ leg6->AddEntry((TObject*)0, "m_{h2} = 220 GeV, precut & unweighted",""); }
  if(id ==2){ leg6->AddEntry((TObject*)0, "m_{h2} = 220 GeV, precut and weighted to 19.5 fb^{-1}",""); }
  if(id ==3){ leg6->AddEntry((TObject*)0, "m_{h2} = 220 GeV, cut and weighted",""); }
  if(id ==4){ leg6->AddEntry((TObject*)0, "m_{H} = 125 GeV, precut and unweighted",""); }
  if(id ==5){ leg6->AddEntry((TObject*)0, "m_{H} = 125 GeV, precut and weighted to 19.5 fb^{-1}",""); }
  if(id ==6){ leg6->AddEntry((TObject*)0, "m_{H} = 125 GeV, cut and weighted to 19.5 fb^{-1}",""); }
  leg6->Draw();
  c6_0->Draw();
  // Fill Pad                                                                                                                                                                     
  c6_1->cd();
  c6_1->SetTopMargin(0.05);
  c6_1->SetBottomMargin(0.26);
  c6_1->SetRightMargin(0.05);
  c6_1->SetGridx(1);
  c6_1->SetGridy(1);
  c6_1->Draw();
  TH1 *ratio6 = hJet1PT->Clone();
  TLine *l6 = new TLine(0,1,400,1);
  ratio6->Divide(hJet1PTDELPHES);
  ratio6->Draw("E1");
  ratio6->GetYaxis()->SetRangeUser(0,10);
  l6->SetLineColor(kBlue);
  l6->Draw("SAME");
  // Save histo to pdf
  c6->SaveAs(Dataset::pdfTitler(id)+".pdf(");

  // Canvas 7
  c7->cd();
  c7_0->cd();
  TH1* hJet2PT = (TH1F*)ntuple_file->Get("Jet2Pt");
  Double_t entries7 = hJet2PT->GetEntries();
  hJet2PT->Draw("hist");
  hJet2PT->SetLineColor(kRed);
  hJet2PT->Scale(1/entries7);
  hJet2PT->GetXaxis()->SetTitle("Sub-leading jet p_{T} [GeV]");
  hJet2PT->GetYaxis()->SetTitle("Events / 5 GeV");
  TH1* hJet2PTDELPHES = (TH1F*)delphes_file->Get("Jet2PT");
  Double_t entries_7 = hJet2PTDELPHES->GetEntries();
  hJet2PTDELPHES->Draw("SAME hist");
  hJet2PTDELPHES->SetLineColor(kBlue);
  hJet2PTDELPHES->Scale(1/entries_7);
  leg7->AddEntry(hJet2PT,"Sub-leading jet p_{T} CMS FullSim 19.5 fb^{-1} 8 TeV", "l");
  leg7->AddEntry(hJet2PTDELPHES,"Sub-leading jet p_{T} VBFNLO + DELPHES","l");
  leg7->SetFillStyle(0);
  leg7->SetBorderSize(0);
  if(id ==1){ leg7->AddEntry((TObject*)0, "m_{h2} = 220 GeV, precut & unweighted",""); }
  if(id ==2){ leg7->AddEntry((TObject*)0, "m_{h2} = 220 GeV, precut and weighted to 19.5 fb^{-1}",""); }
  if(id ==3){ leg7->AddEntry((TObject*)0, "m_{h2} = 220 GeV, cut and weighted",""); }
  if(id ==4){ leg7->AddEntry((TObject*)0, "m_{H} = 125 GeV, precut and unweighted",""); }
  if(id ==5){ leg7->AddEntry((TObject*)0, "m_{H} = 125 GeV, precut and weighted to 19.5 fb^{-1}",""); }
  if(id ==6){ leg7->AddEntry((TObject*)0, "m_{H} = 125 GeV, cut and weighted to 19.5 fb^{-1}",""); }
  leg7->Draw();
  c7_0->Draw();
  // Fill Pad                                                                                                                                                                                                                        
  c7_1->cd();
  c7_1->SetTopMargin(0.05);
  c7_1->SetBottomMargin(0.26);
  c7_1->SetRightMargin(0.05);
  c7_1->SetGridx(1);
  c7_1->SetGridy(1);
  c7_1->Draw();
  TH1 *ratio7 = hJet2PT->Clone();
  TLine *l7 = new TLine(0,1,400,1);
  ratio7->Divide(hJet2PTDELPHES);
  ratio7->Draw("E1");
  l7->SetLineColor(kBlue);
  l7->Draw("SAME");
  // Save histo to pdf
  c7->SaveAs(Dataset::pdfTitler(id)+".pdf(");

  // Canvas 8
  c8->cd();
  c8_0->cd();
  TH1* hJet1Eta = (TH1F*)ntuple_file->Get("Jet1Eta");
  Double_t entries8 = hJet1Eta->GetEntries();
  hJet1Eta->Draw("hist");
  hJet1Eta->SetLineColor(kRed);
  hJet1Eta->Scale(1/entries8);
  hJet1Eta->GetXaxis()->SetTitle("Jet #eta");
  hJet1Eta->GetYaxis()->SetTitle("Events");
  hJet1Eta->GetYaxis()->SetRangeUser(0,0.1);
  TH1* hJet1EtaDELPHES = (TH1F*)delphes_file->Get("JetEta1");
  Double_t entries_8 = hJet1EtaDELPHES->GetEntries();
  hJet1EtaDELPHES->Draw("SAME hist");
  hJet1EtaDELPHES->SetLineColor(kBlue);
  hJet1EtaDELPHES->Scale(1/entries_8);
  leg8->AddEntry(hJet1Eta,"Jet #eta CMS FullSim 19.5 fb^{-1} 8 TeV", "l");
  leg8->AddEntry(hJet1EtaDELPHES,"Jet #eta VBFNLO + DELPHES","l");
  leg8->SetFillStyle(0);
  leg8->SetBorderSize(0);
  if(id ==1){ leg8->AddEntry((TObject*)0, "m_{h2} = 220 GeV, precut & unweighted",""); }
  if(id ==2){ leg8->AddEntry((TObject*)0, "m_{h2} = 220 GeV, precut and weighted to 19.5 fb^{-1}",""); }
  if(id ==3){ leg8->AddEntry((TObject*)0, "m_{h2} = 220 GeV, cut and weighted",""); }
  if(id ==4){ leg8->AddEntry((TObject*)0, "m_{H} = 125 GeV, precut and unweighted",""); }
  if(id ==5){ leg8->AddEntry((TObject*)0, "m_{H} = 125 GeV, precut and weighted to 19.5 fb^{-1}",""); }
  if(id ==6){ leg8->AddEntry((TObject*)0, "m_{H} = 125 GeV, cut and weighted to 19.5 fb^{-1}",""); }
  leg8->Draw();
  c8_0->Draw();
  // Fill Pad                                                                                                                                                                  
  c8_1->cd();
  c8_1->SetTopMargin(0.05);
  c8_1->SetBottomMargin(0.26);
  c8_1->SetRightMargin(0.05);
  c8_1->SetGridx(1);
  c8_1->SetGridy(1);
  c8_1->Draw();
  TH1 *ratio8 = hJet1Eta->Clone();
  TLine *l8 = new TLine(-10,1,10,1);
  ratio8->Divide(hJet1EtaDELPHES);
  ratio8->Draw("E1");
  ratio8->GetYaxis()->SetRangeUser(0,5);
  l8->SetLineColor(kBlue);
  l8->Draw("SAME");
  // Save histo to pdf
  c8->SaveAs(Dataset::pdfTitler(id)+".pdf(");


  // Canvas 9
  c9->cd();
  c9_0->cd();
  TH1* hJet2Eta = (TH1F*)ntuple_file->Get("Jet2Eta");
  Double_t entries9 = hJet2Eta->GetEntries();
  hJet2Eta->Draw("hist");
  hJet2Eta->SetLineColor(kRed);
  hJet2Eta->Scale(1/entries9);
  hJet2Eta->GetXaxis()->SetTitle("Jet 2 #eta");
  hJet2Eta->GetYaxis()->SetTitle("Events");
  hJet2Eta->GetYaxis()->SetRangeUser(0,0.1);
  TH1* hJet2EtaDELPHES = (TH1F*)delphes_file->Get("JetEta2");
  Double_t entries_9 = hJet2EtaDELPHES->GetEntries();
  hJet2EtaDELPHES->Draw("SAME hist");
  hJet2EtaDELPHES->SetLineColor(kBlue);
  hJet2EtaDELPHES->Scale(1/entries_9);
  leg9->AddEntry(hJet1Eta,"Second Jet #eta CMS FullSim 19.5 fb^{-1} 8 TeV", "l");
  leg9->AddEntry(hJet1EtaDELPHES,"Second Jet #eta VBFNLO + DELPHES","l");
  leg9->SetFillStyle(0);
  leg9->SetBorderSize(0);
  if(id ==1){ leg9->AddEntry((TObject*)0, "m_{h2} = 220 GeV, precut & unweighted",""); }
  if(id ==2){ leg9->AddEntry((TObject*)0, "m_{h2} = 220 GeV, precut and weighted to 19.5 fb^{-1}",""); }
  if(id ==3){ leg9->AddEntry((TObject*)0, "m_{h2} = 220 GeV, cut and weighted",""); }
  if(id ==4){ leg9->AddEntry((TObject*)0, "m_{H} = 125 GeV, precut and unweighted",""); }
  if(id ==5){ leg9->AddEntry((TObject*)0, "m_{H} = 125 GeV, precut and weighted to 19.5 fb^{-1}",""); }
  if(id ==6){ leg9->AddEntry((TObject*)0, "m_{H} = 125 GeV, cut and weighted to 19.5 fb^{-1}",""); }
  leg9->Draw();
  c9_0->Draw();
  // Fill Pad                                                                                                                                                                                                                        
  c9_1->cd();
  c9_1->SetTopMargin(0.05);
  c9_1->SetBottomMargin(0.26);
  c9_1->SetRightMargin(0.05);
  c9_1->SetGridx(1);
  c9_1->SetGridy(1);
  c9_1->Draw();
  TH1 *ratio9 = hJet2Eta->Clone();
  TLine *l9 = new TLine(-10,1,10,1);
  ratio9->Divide(hJet2EtaDELPHES);
  ratio9->Draw("E1");
  ratio9->GetYaxis()->SetRangeUser(0,5);
  l9->SetLineColor(kBlue);
  l9->Draw("SAME");
  // Save histo to pdf
  c9->SaveAs(Dataset::pdfTitler(id)+".pdf)");

}


#endif 
