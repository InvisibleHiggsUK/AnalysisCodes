// Need to compared VBFNLO + DELPHES
// against CMS FullSim with Parton Level cuts applied


#include <iostream>
#include <TH1.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TPad.h>
#include "include/Dataset.h"

int Nminus1ComparisonUpdate(unsigned int id){

  gROOT->Reset();

  std::cout << "Running Comparison for the '" << Dataset::toTString(id) << "'  sample" << std::endl;
  std::cout << "\n Dataset is : " << Dataset::fullDatasetName(id) << "\n" << std::endl;
  
  
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
  TPad  *c3_0 = new TPad("pad3","pad3",0., 0.15, 1., 1.);
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
  
  

  TCanvas *c4 = new TCanvas("Jet1PT", "Jet1PT", 600, 600);  
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
  


  TCanvas *c5 = new TCanvas("Jet2PT", "Jet2PT", 600, 600);
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
  

  TCanvas *c6 = new TCanvas("EtaDP", "EtaDP", 600, 600);
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
  

  TCanvas *c7 = new TCanvas("MET", "MET", 600, 600);
  TPad *c7_0 = new TPad("pad7","pad7",0., 0.15, 1.,1.);
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
  

  TCanvas *c8 = new TCanvas("Jet1Eta", "Jet1Eta", 600, 600);
  TPad *c8_0 = new TPad("pad8","pad8",0., 0.15, 1., 1.);
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
  

  TCanvas *c9 = new TCanvas("Jet2Eta", "Jet2Eta", 600, 600);
  TPad *c9_0 = new TPad("pad9","pad9",0., 0.15, 1., 1.);
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

  
  TCanvas *c11 = new TCanvas("CenJetEt","CenJetEt",600,600);
  TPad *c11_0  = new TPad("pad11_0","pad11_0",0., 0.15, 1., 1.);
  c11_0->SetTopMargin(0.05);
  c11_0->SetBottomMargin(0.26);
  c11_0->Draw();
  
  TPad *c11_1  = new TPad("pad11_1","pad11_1",0., 0.02, 1., 0.3);
  c11_1->SetTopMargin(0.05);
  c11_1->SetBottomMargin(0.26);
  c11_1->SetRightMargin(0.05);
  c11_1->SetGridx(1);
  c11_1->SetGridy(1);
  c11_1->Draw();

  TCanvas *c12  = new TCanvas("Njets30","Njets30",600,600);
  TPad *c12_0 = new TPad("pad12_0","pad12_0", 0., 0.15, 1., 1.);
  c12_0->SetTopMargin(0.05);
  c12_0->SetBottomMargin(0.26);
  c12_0->Draw();

  TPad *c12_1 = new TPad("pad12_1","pad12_1", 0., 0.02, 1., 0.3);
  c12_1->SetTopMargin(0.05);
  c12_1->SetBottomMargin(0.26);
  c12_1->SetRightMargin(0.05);
  c12_1->SetGridx(1);
  c12_1->SetGridy(1);
  c12_1->Draw();


  //  TCanvas *c10 = new TCanvas("Jet2Eta", "Jet2Eta", 600, 600);

  TCanvas *c10 = new TCanvas("HistoBoard", "HistoBoard",600, 600);

  TLegend *leg = new TLegend (0.5, 0.7, 0.9, 0.88);
  TLegend *leg1 = new TLegend(0.5,0.7,0.9,0.88);
  TLegend *leg2 = new TLegend (0.5, 0.7, 0.9, 0.88);
  TLegend *leg3 = new TLegend (0.5, 0.7, 0.9, 0.88);
  TLegend *leg4 = new TLegend (0.5, 0.7, 0.9, 0.88);
  TLegend *leg5 = new TLegend (0.5, 0.7, 0.9, 0.88);
  TLegend *leg6 = new TLegend (0.5, 0.7, 0.9, 0.88);
  TLegend *leg7 = new TLegend (0.5, 0.7, 0.9, 0.88);
  TLegend *leg8 = new TLegend (0.5, 0.7, 0.9, 0.88);
  TLegend *leg9 = new TLegend (0.5, 0.7, 0.9, 0.88);
  TLegend *leg11 = new TLegend (0.5, 0.7, 0.9, 0.88);
  TLegend *leg12 = new TLegend (0.5, 0.7, 0.9, 0.88);

  TString dirname = ".";
  TString fullsim_ntuple = "NtupleAnalysis/FullSim_Nminus1_plots_invH_8TeVTEST.root";
  TString vbfnlo_ntuple = Dataset::fullDatasetName(id);
  //  TString vbfnlo_ntuple  = "VBF_inv_8000_unweighted_ZTune.root";




  fullsim_ntuple = dirname + "/" + fullsim_ntuple;
  vbfnlo_ntuple = dirname + "/" + vbfnlo_ntuple;
  
  delete gROOT->GetListOfFiles()->FindObject(fullsim_ntuple);
  delete gROOT->GetListOfFiles()->FindObject(vbfnlo_ntuple);

  TFile *fullsim_file = new TFile(fullsim_ntuple);
  TFile *vbfnlo_file = new TFile(vbfnlo_ntuple);

  
  Float_t weightfullsim = 0.308;
  Float_t weightvbfnlo = 0.108;
  
  // Canvas 1
  c1->cd();
  c1_0->cd();
  TH1D* hInvMass = (TH1D*)fullsim_file->Get("InvMass");
  Float_t entries1 = (hInvMass->GetEntries())*weightfullsim;
  hInvMass->Draw("hist");
  hInvMass->Scale(weightfullsim);
  hInvMass->SetLineColor(kRed);
  hInvMass->GetXaxis()->SetTitle("m_{jj} [GeV]");
  hInvMass->GetYaxis()->SetTitle("Entries");
  gPad->SetLogy();
  TH1D* hInvMassV = (TH1D*)vbfnlo_file->Get("InvMass");
  Float_t entries1_1 = (hInvMassV->GetEntries())*weightvbfnlo;
  hInvMassV->Draw("SAME hist");
  hInvMassV->SetLineColor(kBlue);
  hInvMassV->Scale(weightvbfnlo);
  leg1->AddEntry(hInvMass, "FullSim + 'handmade' trigger 19.5 fb^{-1}","l");
  leg1->AddEntry(hInvMassV, "VBFNLO + 'handmade' trigger 19.5 fb^{-1}","l");
  leg1->AddEntry((TObject*)0, "no PU, ZTune included","");
  //  leg1->AddEntry((TObject*)0, "FullSim entries: 303","");
  //  leg1->AddEntry((TObject*)0, "VBFNLO entries: 189","");
  leg1->SetFillStyle(0);
  leg1->SetBorderSize(0);
  leg1->Draw();
  c1_0->Draw(); // Draw canvas
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
  TH1D *ratio1 = hInvMass->Clone();
  TLine *l = new TLine(0,1,4000,1);
  ratio1->Divide(hInvMassV);
  ratio1->Draw("E1");
  ratio1->GetYaxis()->SetTitle("Ratio");
  l->SetLineColor(kBlue);
  l->Draw("SAME");
  //  c1->SaveAs("Nminus1Updated.pdf("); // Save canvas to pdf
  c1->SaveAs(Dataset::pdfTitler(id)+".pdf(");


  c2->cd();
  c2_0->cd();
  TH1D* hDeltaEtaJJ = (TH1D*)fullsim_file->Get("DeltaEtaJJ");
  Float_t entries2 = (hDeltaEtaJJ->GetEntries())*weightfullsim;
  hDeltaEtaJJ->Draw("hist");
  hDeltaEtaJJ->Scale(weightfullsim);
  hDeltaEtaJJ->SetLineColor(kRed);
  hDeltaEtaJJ->GetXaxis()->SetTitle("#Delta #eta_{jj}");
  hDeltaEtaJJ->GetYaxis()->SetTitle("Entries");
  gPad->SetLogy();
  TH1D* hDeltaEtaJJV = (TH1D*)vbfnlo_file->Get("DeltaEtaJJ");
  Float_t entries2_2 = (hDeltaEtaJJV->GetEntries())*weightvbfnlo;
  hDeltaEtaJJV->Draw("SAME hist");
  hDeltaEtaJJV->Scale(weightvbfnlo);
  hDeltaEtaJJV->SetLineColor(kBlue);
  leg2->AddEntry(hDeltaEtaJJ,"FullSim + 'handmade' trigger 19.5 fb^{-1}","l");
  leg2->AddEntry(hDeltaEtaJJV,"VBFNLO + 'handmade' trigger 19.5 fb^{-1}","l");
  leg2->AddEntry((TObject*)0, "no PU , ZTune incldued","");
  //  leg2->AddEntry((TObject*)0, "VBFNLO entries: 124","");
  leg2->SetBorderSize(0);
  leg2->SetFillStyle(0);
  leg2->Draw();
  c2_0->Draw();
  c2_1->cd();
  c2_1->SetTopMargin(0.05);
  c2_1->SetBottomMargin(0.26);
  c2_1->SetRightMargin(0.05);
  c2_1->SetGridx(1);
  c2_1->SetGridy(1);
  c2_1->SetTopMargin(0.05);
  c2_1->SetBottomMargin(0.26);
  c2_1->SetRightMargin(0.05);
  c2_1->SetGridx(1);
  c2_1->SetGridy(1);
  c2_1->Draw();
  TH1D *ratio2 = hDeltaEtaJJ->Clone();
  TLine *l = new TLine(0,1,10,1);
  ratio2->Divide(hDeltaEtaJJV);
  ratio2->Draw("E1");
  ratio2->GetYaxis()->SetTitle("Ratio");
  l->SetLineColor(kBlue);
  l->Draw("SAME");
  //  c2->SaveAs("Nminus1Updated.pdf("); // Save histo to pdf
  c2->SaveAs(Dataset::pdfTitler(id)+".pdf(");

  c3->cd();
  c3_0->cd();
  TH1D* hDeltaPhiJJ = (TH1D*)fullsim_file->Get("DeltaPhiJJ");
  Float_t entries3 = hDeltaPhiJJ->GetEntries()*weightfullsim;
  hDeltaPhiJJ->Draw("hist");
  hDeltaPhiJJ->Scale(weightfullsim);
  hDeltaPhiJJ->SetLineColor(kRed);
  hDeltaPhiJJ->GetXaxis()->SetTitle("#Delta #phi_{jj}");
  hDeltaPhiJJ->GetYaxis()->SetTitle("Entries");
  gPad->SetLogy();
  //  hDeltaPhiJJ->GetYaxis()->SetRangeUser(0,1000);
  TH1D* hDeltaPhiJJV = (TH1D*)vbfnlo_file->Get("DeltaPhiJJ");
  Float_t entries3_3 = hDeltaPhiJJV->GetEntries()*weightvbfnlo;
  hDeltaPhiJJV->Draw("SAME hist");
  hDeltaPhiJJV->Scale(weightvbfnlo);
  hDeltaPhiJJV->SetLineColor(kBlue);
  leg3->AddEntry(hDeltaPhiJJ,"FullSim + 'handmade' trigger 19.5 fb^{-1}","l");
  leg3->AddEntry(hDeltaPhiJJV,"VBFNLO + 'handmade' trigger 19.5 fb^{-1}","l");
  leg3->AddEntry((TObject*)0,"no PU, ZTune included","");
  //  leg3->AddEntry((TObject*)0,"VBFNLO entries: 262","");
  leg3->SetFillStyle(0);
  leg3->SetBorderSize(0);
  leg3->Draw();
  c3_0->Draw();
  c3_1->cd();
  c3_1->SetTopMargin(0.05);
  c3_1->SetBottomMargin(0.26);
  c3_1->SetRightMargin(0.05);
  c3_1->SetGridx(1);
  c3_1->SetGridy(1);
  c3_1->SetTopMargin(0.05);
  c3_1->SetBottomMargin(0.26);
  c3_1->SetRightMargin(0.05);
  c3_1->SetGridx(1);
  c3_1->SetGridy(1);
  c3_1->Draw();
  TH1D *ratio3 = hDeltaPhiJJ->Clone();
  TLine *l = new TLine(0,1,TMath::Pi(),1);
  ratio3->Divide(hDeltaPhiJJV);
  ratio3->Draw("E1");
  ratio3->GetYaxis()->SetTitle("Ratio");
  l->SetLineColor(kBlue);
  l->Draw("SAME");
  //  c3->SaveAs("Nminus1Updated.pdf(");
  c3->SaveAs(Dataset::pdfTitler(id)+".pdf(");


  c4->cd();
  c4_0->cd();
  TH1D* hJet1PT = (TH1D*)fullsim_file->Get("Jet1PT");
  hJet1PT->Draw("hist");
  hJet1PT->Scale(weightfullsim);
  hJet1PT->SetLineColor(kRed);
  hJet1PT->GetXaxis()->SetTitle("Jet 1 P_{T}");
  hJet1PT->GetYaxis()->SetTitle("Entries");
  gPad->SetLogy();
  TH1D* hJet1PTV = (TH1D*)vbfnlo_file->Get("Jet1PT");
  hJet1PTV->Draw("SAME hist");
  hJet1PTV->Scale(weightvbfnlo);
  hJet1PTV->SetLineColor(kBlue);
  leg4->AddEntry(hJet1PT,"FullSim + 'handmade' trigger 19.5 fb^{-1}","l");
  leg4->AddEntry(hJet1PTV,"VBFNLO + 'handmade' trigger 19.5 fb^{-1}","l");
  leg4->AddEntry((TObject*)0,"no PU, ZTune included","");
  //  leg4->AddEntry((TObject*)0,"VBFNLO entries: 139","");
  leg4->SetFillStyle(0);
  leg4->SetBorderSize(0);
  leg4->Draw();
  c4_0->Draw();
  c4_1->cd();
  c4_1->SetTopMargin(0.05);
  c4_1->SetBottomMargin(0.26);
  c4_1->SetRightMargin(0.05);
  c4_1->SetGridx(1);
  c4_1->SetGridy(1);
  c4_1->SetTopMargin(0.05);
  c4_1->SetBottomMargin(0.26);
  c4_1->SetRightMargin(0.05);
  c4_1->SetGridx(1);
  c4_1->SetGridy(1);
  c4_1->Draw();
  TH1D *ratio4 = hJet1PT->Clone();
  TLine *l = new TLine(0,1,400,1);
  ratio4->Divide(hJet1PTV);
  ratio4->Draw("E1");
  ratio4->GetYaxis()->SetTitle("Ratio");
  l->SetLineColor(kBlue);
  l->Draw("SAME");
  //  c4->SaveAs("Nminus1Updated.pdf(");
  c4->SaveAs(Dataset::pdfTitler(id)+".pdf(");


  c5->cd();
  c5_0->cd();
  TH1D* hJet2PT = (TH1D*)fullsim_file->Get("Jet2PT");
  hJet2PT->Draw("hist");
  hJet2PT->Scale(weightfullsim);
  hJet2PT->SetLineColor(kRed);
  hJet2PT->GetXaxis()->SetTitle("Jet 2 P_{T}");
  hJet2PT->GetYaxis()->SetTitle("Entries");
  gPad->SetLogy();
  TH1D* hJet2PTV = (TH1D*)vbfnlo_file->Get("Jet2PT");
  hJet2PTV->Draw("SAME hist");
  hJet2PTV->Scale(weightvbfnlo);
  hJet2PTV->SetLineColor(kBlue);
  leg5->AddEntry(hJet2PT,"FullSim + 'handmade' trigger 19.5 fb^{-1}","l");
  leg5->AddEntry(hJet2PTV,"VBFNLO + 'handmade' trigger 19.5 fb^{-1}","l");
  leg5->AddEntry((TObject*)0, "no PU, ZTune included","");
  //  leg5->AddEntry((TObject*)0, "VBFNLO entries: 139","");
  leg5->SetFillStyle(0);
  leg5->SetBorderSize(0);
  leg5->Draw();
  c5_0->Draw();
  c5_1->cd();
  c5_1->SetTopMargin(0.05);
  c5_1->SetBottomMargin(0.26);
  c5_1->SetRightMargin(0.05);
  c5_1->SetGridx(1);
  c5_1->SetGridy(1);
  c5_1->SetTopMargin(0.05);
  c5_1->SetBottomMargin(0.26);
  c5_1->SetRightMargin(0.05);
  c5_1->SetGridx(1);
  c5_1->SetGridy(1);
  c5_1->Draw();
  TH1D *ratio5 = hJet2PT->Clone();
  TLine *l = new TLine(0,1,400,1);
  ratio5->Divide(hJet2PTV);
  ratio5->Draw("E1");
  ratio5->GetYaxis()->SetTitle("Ratio");
  l->SetLineColor(kBlue);
  l->Draw("SAME");
  //  c5->SaveAs("Nminus1Updated.pdf(");
  c5->SaveAs(Dataset::pdfTitler(id)+".pdf(");

  c6->cd();
  c6_0->cd();
  TH1D* hEtaDP = (TH1D*)fullsim_file->Get("EtaDPjj");
  hEtaDP->Draw("hist");
  hEtaDP->Scale(weightfullsim);
  hEtaDP->SetLineColor(kRed);
  hEtaDP->GetXaxis()->SetTitle("#eta_{j1} . #eta_{j2}");
  hEtaDP->GetYaxis()->SetTitle("Entries");
  gPad->SetLogy();
  //  hEtaDP->GetYaxis()->SetRangeUser(0,1200);
  TH1D* hEtaDPV = (TH1D*)vbfnlo_file->Get("EtaDP");
  hEtaDPV->Draw("SAME hist");
  hEtaDPV->Scale(weightvbfnlo);
  hEtaDPV->SetLineColor(kBlue);
  leg6->AddEntry(hEtaDP,"FullSim + 'handmade trigger' 19.5 fb^{-1}","l");
  leg6->AddEntry(hEtaDPV,"VBFNLO + 'handmade' trigger 19.5 fb^{-1}","l");
  leg6->AddEntry((TObject*)0, "no PU, ZTune included ", "");
  //  leg6->AddEntry((TObject*)0, "VBFNLO entries: 117" , "");
  leg6->SetFillStyle(0);
  leg6->SetBorderSize(0);
  leg6->Draw();
  c6_0->Draw();
  c6_1->cd();
  c6_1->SetTopMargin(0.05);
  c6_1->SetBottomMargin(0.26);
  c6_1->SetRightMargin(0.05);
  c6_1->SetGridx(1);
  c6_1->SetGridy(1);
  c6_1->SetTopMargin(0.05);
  c6_1->SetBottomMargin(0.26);
  c6_1->SetRightMargin(0.05);
  c6_1->SetGridx(1);
  c6_1->SetGridy(1);
  c6_1->Draw();
  TH1D *ratio6 = hEtaDP->Clone();
  TLine *l = new TLine(-10,1,2,1);
  ratio6->Divide(hEtaDPV);
  ratio6->Draw("E1");
  ratio6->GetYaxis()->SetTitle("Ratio");
  l->SetLineColor(kBlue);
  l->Draw("SAME");
  //  c6->SaveAs("Nminus1Updated.pdf(");
  c6->SaveAs(Dataset::pdfTitler(id)+".pdf(");

  c7->cd();
  c7_0->cd();
  TH1D* hMET = (TH1D*)fullsim_file->Get("MET");
  hMET->Draw("hist");
  hMET->Scale(weightfullsim);
  hMET->SetLineColor(kRed);
  hMET->GetXaxis()->SetTitle("MET");
  hMET->GetYaxis()->SetTitle("Entries");
  gPad->SetLogy();
  TH1D* hMETV = (TH1D*)vbfnlo_file->Get("MET");
  hMETV->Draw("SAME hist");
  hMETV->Scale(weightvbfnlo);
  hMETV->SetLineColor(kBlue);
  leg7->AddEntry(hMET,"FullSim + 'handmade' trigger 19.5 fb^{-1}","l");
  leg7->AddEntry(hMETV,"VBVFNLO + 'handmade' trigger 19.5 fb^{-1}","l");
  leg7->AddEntry((TObject*)0,"no PU, ZTune included", "");
  //  leg7->AddEntry((TObject*)0, "VBFNLO entries: 141" , "");
  leg7->SetFillStyle(0);
  leg7->SetBorderSize(0);
  leg7->Draw();
  c7_0->Draw();
  c7_1->cd();
  c7_1->SetTopMargin(0.05);
  c7_1->SetBottomMargin(0.26);
  c7_1->SetRightMargin(0.05);
  c7_1->SetGridx(1);
  c7_1->SetGridy(1);
  c7_1->SetTopMargin(0.05);
  c7_1->SetBottomMargin(0.26);
  c7_1->SetRightMargin(0.05);
  c7_1->SetGridx(1);
  c7_1->SetGridy(1);
  c7_1->Draw();
  TH1D *ratio7 = hMET->Clone();
  TLine *l = new TLine(0,1,500,1);
  ratio7->Divide(hMETV);
  ratio7->Draw("E1");
  ratio7->GetYaxis()->SetTitle("Ratio");
  l->SetLineColor(kBlue);
  l->Draw("SAME");
  //  c7->SaveAs("Nminus1Updated.pdf(");
  c7->SaveAs(Dataset::pdfTitler(id)+".pdf(");
  

  c8->cd();
  c8_0->cd();
  TH1D* hJet1Eta = (TH1D*)fullsim_file->Get("Jet1Eta");
  hJet1Eta->Draw("hist");
  hJet1Eta->Scale(weightfullsim);
  hJet1Eta->SetLineColor(kRed);
  hJet1Eta->GetXaxis()->SetTitle("Jet 1 #eta");
  hJet1Eta->GetYaxis()->SetTitle("Entries");
  gPad->SetLogy();
  TH1D* hJet1EtaV = (TH1D*)vbfnlo_file->Get("JetEta1");
  hJet1EtaV->Draw("SAME hist");
  hJet1EtaV->Scale(weightvbfnlo);
  hJet1EtaV->SetLineColor(kBlue);
  leg8->AddEntry(hJet1Eta,"FullSim + 'handmade trigger' 19.5 fb^{-1}","l");
  leg8->AddEntry(hJet1EtaV,"VBFNLO + 'handmade trigger' 19.5 fb^{-1}","l");
  leg8->AddEntry((TObject*)0,"no PU, ZTune included" , "");
  //  leg8->AddEntry((TObject*)0, "VBFNLO entries: 117" , "");
  leg8->SetBorderSize(0);
  leg8->SetFillStyle(0);
  leg8->Draw();
  c8_0->Draw();
  c8_1->cd();
  c8_1->SetTopMargin(0.5);
  c8_1->SetBottomMargin(0.26);
  c8_1->SetRightMargin(0.05);
  c8_1->SetGridx(1);
  c8_1->SetGridy(1);
  c8_1->SetTopMargin(0.05);
  c8_1->SetBottomMargin(0.26);
  c8_1->SetRightMargin(0.05);
  c8_1->SetGridx(1);
  c8_1->SetGridy(1);
  c8_1->Draw();
  TH1D *ratio8 = hJet1Eta->Clone();
  TLine *l = new TLine(-10,1,10,1);
  ratio8->Divide(hJet1EtaV);
  ratio8->Draw("E1");
  ratio8->GetYaxis()->SetTitle("Ratio");
  l->SetLineColor(kBlue);
  l->Draw("SAME");
  //  c8->SaveAs("Nminus1Updated.pdf(");
  c8->SaveAs(Dataset::pdfTitler(id)+".pdf(");
  
  c9->cd();
  c9_0->cd();
  TH1D* hJet2Eta = (TH1D*)fullsim_file->Get("Jet2Eta");
  hJet2Eta->Draw("hist");
  hJet2Eta->Scale(weightfullsim);
  hJet2Eta->SetLineColor(kRed);
  hJet2Eta->GetXaxis()->SetTitle("Jet 2 #eta");
  hJet2Eta->GetYaxis()->SetTitle("Entries");
  gPad->SetLogy();
  TH1D* hJet2EtaV = (TH1D*)vbfnlo_file->Get("JetEta2");
  hJet2EtaV->Draw("SAME hist");
  hJet2EtaV->Scale(weightvbfnlo);
  hJet2EtaV->SetLineColor(kBlue);
  leg9->AddEntry(hJet2Eta,"FullSim + 'handmade' trigger 19.5 fb^{-1}","l");
  leg9->AddEntry(hJet2EtaV,"VFBNLO + 'handmade' trigger 19.5 fb^{-1}","l");
  leg9->AddEntry((TObject*)0,"no PU, ZTune included " ,"");
  //  leg9->AddEntry((TObject*)0, "VFBNLO entries: 117" ,"");
  leg9->SetFillStyle(0);
  leg9->SetBorderSize(0);
  leg9->Draw();
  c9_0->Draw();
  c9_1->cd();
  c9_1->SetTopMargin(0.05);
  c9_1->SetBottomMargin(0.26);
  c9_1->SetRightMargin(0.05);
  c9_1->SetGridx(1);
  c9_1->SetGridy(1);
  c9_1->SetTopMargin(0.05);
  c9_1->SetBottomMargin(0.26);
  c9_1->SetRightMargin(0.05);
  c9_1->SetGridx(1);
  c9_1->SetGridy(1);
  c9_1->Draw();
  TH1D *ratio9 = hJet2Eta->Clone();
  TLine *l = new TLine(-10,1,10,1);
  ratio9->Divide(hJet2EtaV);
  ratio9->Draw("E1");
  ratio9->GetYaxis()->SetTitle("Ratio");
  l->SetLineColor(kBlue);
  l->Draw("SAME");
  //  c9->SaveAs("Nminus1Updated.pdf(");
  c9->SaveAs(Dataset::pdfTitler(id)+".pdf(");


  c11->cd();
  c11_0->cd();
  TH1D* cenJetEt = (TH1D*)fullsim_file->Get("cenJetEt");
  Float_t entries11 = cenJetEt->GetEntries()*weightfullsim;
  cenJetEt->Draw("hist");
  cenJetEt->Scale(weightfullsim);
  cenJetEt->SetLineColor(kRed);
  cenJetEt->GetXaxis()->SetTitle("cenJetEt [GeV]");
  cenJetEt->GetYaxis()->SetTitle("Entries");
  gPad->SetLogy();
  TH1D* cenJetEtV = (TH1D*)vbfnlo_file->Get("CJVEt");
  Float_t entries11_11 = cenJetEtV->GetEntries()*weightvbfnlo;
  cenJetEtV->Draw("SAME hist");
  cenJetEtV->Scale(weightvbfnlo);
  cenJetEtV->SetLineColor(kBlue);
  leg11->AddEntry(cenJetEt,"FullSim + 'handmade' trigger 19.5 fb^{-1}","l");
  leg11->AddEntry(cenJetEtV,"VBFNLO + 'handmade' trigger 19.5 fb^{-1}","l");
  leg11->AddEntry((TObject*)0, "no PU, ZTune included","");
  //  leg11->AddEntry((TObject*)0, "VBFNLO entries: 152", "");
  leg11->SetFillStyle(0);
  leg11->SetBorderSize(0);
  leg11->Draw();
  c11_0->Draw();
  c11_1->cd();
  c11_1->SetTopMargin(0.05);
  c11_1->SetBottomMargin(0.26);
  c11_1->SetRightMargin(0.05);
  c11_1->SetGridx(1);
  c11_1->SetGridy(1);
  c11_1->Draw();
  TH1D* ratio11 = cenJetEt->Clone();
  TLine *l11 = new TLine(0, 1, 150,1);
  ratio11->Divide(cenJetEtV);
  ratio11->Draw("E1");
  ratio11->GetYaxis()->SetTitle("Ratio");
  l11->SetLineColor(kBlue);
  l11->Draw();
  //  c11->SaveAs("Nminus1Updated.pdf(");
  c11->SaveAs(Dataset::pdfTitler(id)+".pdf(");


  c12->cd();
  c12_0->cd();
  TH1D* njets30 = (TH1D*)fullsim_file->Get("NJets");
  Float_t entries12 = njets30->GetEntries()*weightfullsim;
  njets30->Draw("hist");
  njets30->SetLineColor(kRed);
  njets30->Scale(weightfullsim);
  njets30->GetXaxis()->SetTitle("N_{jets}");
  njets30->GetYaxis()->SetTitle("Entries");
  gPad->SetLogy();
  TH1D* njets = (TH1D*)vbfnlo_file->Get("Njets30");
  Float_t entries12_12 = njets->GetEntries()*weightvbfnlo;
  njets->Draw("SAME hist");
  njets->Scale(weightvbfnlo);
  njets->SetLineColor(kBlue);
  leg12->AddEntry(njets30,"FullSim + 'handmade' trigger 19.5 fb^{-1}","l");
  leg12->AddEntry(njets,"VBFNLO + 'handmade' trigger 19.5 fb^{-1}","l");
  leg12->AddEntry((TObject*)0, "no PU, ZTune included","");
  //  leg11->AddEntry((TObject*)0, "VBFNLO entries: 152", "");
  leg12->SetFillStyle(0);
  leg12->SetBorderSize(0);
  leg12->Draw();
  c12_0->Draw();
  c12_1->cd();
  c12_1->SetTopMargin(0.05);
  c12_1->SetBottomMargin(0.26);
  c12_1->SetRightMargin(0.05);
  c12_1->SetGridx(1);
  c12_1->SetGridy(1);
  c12_1->Draw();
  TH1D* ratio12 = njets30->Clone();
  TLine *l12 = new TLine(0, 1, 150,1);
  ratio12->Divide(njets);
  ratio12->Draw("E1");
  ratio12->GetYaxis()->SetTitle("Ratio");
  l12->SetLineColor(kBlue);
  l12->Draw();
  //  c12->SaveAs("Nminus1Updated.pdf)");
  c12->SaveAs(Dataset::pdfTitler(id)+".pdf)");

  /*
  c10.cd();
  TH1D* hCenJetEta = (TH1D*)fullsim_file->Get("cenJetEta");
  hCenJetEta->Draw("hist");
  hCenJetEta->Scale(weightfullsim);
  hCenJetEta->SetLineColor(kRed);
  hCenJetEta->GetXaxis()->SetTitle("central jet #eta");
  hCenJetEta->GetYaxis()->SetTitle("Entries");
  TH1D* hCenJetEtaV = (TH1D*)vbfnlo_file->Get("CJEta");
  hCenJetEtaV->Draw("SAME hist");
  hCenJetEtaV->Scale(weightvbfnlo);
  hCenJetEtaV->SetLineColor(kBlue);
  leg3->Draw();
*/

}
