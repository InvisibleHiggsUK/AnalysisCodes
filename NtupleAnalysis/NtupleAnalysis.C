// Analysis on Invisible Higgs ntuples
//
// Objects to plot are:
// RECO:
//      jet1Pt, jet1Eta, jet2Pt, jet2Eta, vbfDEta, vbfDPhi, vbfM, MET, cenJetEt
// GEN:
//      genJet1Pt, genJet1Eta, genJet2Pt, genJet2Eta, genVBFDEta, genVBFDPhi, genVBFM
// PARTON:
//     mcQ1Pt, mcQ1Eta, mcQ2Pt, mcQ2Eta, mcVBFDEta,mcVBFDPhi,mcVBFM
//


#define NtupleAnalysis_cxx
#include "NtupleAnalysis.h"
#include <TH2.h>
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <vector>
#include <iterator>
#include <iostream>
#include <stdlib.h>
#include <TMath.h>

class ExRootTreeReader;
class ExRootResult;

using namespace std;

void NtupleAnalysis::processEvents()
{
   Long64_t nentries = fChain->GetEntriesFast();

   Bool_t printout = 0;

   TH1::SetDefaultSumw2();

   // RECO
   hNJets   = new TH1D("NJets","NJets",   100,   0,  20);
   hJet1Pt  = new TH1D("Jet1Pt","Jet1Pt",  80,   0, 400);
   hJet1Eta = new TH1D("Jet1Eta","Jet1Eta",50, -10,  10);
   hJet2Pt  = new TH1D("Jet2Pt","Jet2Pt",  80,   0, 400);
   hJet2Eta = new TH1D("Jet2Eta","Jet2Eta",50, -10,  10);
   hvbfDEta = new TH1D("vbfDEta","vbfDEta",50,   0,  10);
   hvbfDPhi = new TH1D("vbfDPhi","vbfDPhi",63,   0,   TMath::Pi());
   hvbfM    = new TH1D("vbfM","vbfM",      40,   0, 4000);
   hMET     = new TH1D("MET","MET",        50,   0,  500);
   hcenJetEt= new TH1D("cenJetEt","cenJetEt", 30, 0, 150);

   // GEN
   hgenJet1Pt  = new TH1D("genJet1Pt" ,"genJet1Pt" , 80,   0,  400);
   hgenJet1Eta = new TH1D("genJet1Eta","genJet1Eta", 50, -10,   10);
   hgenJet2Pt  = new TH1D("genJet2Pt" , "genJet2Pt", 80,   0,  400);
   hgenJet2Eta = new TH1D("genJet2Eta","genJet2Eta", 50, -10,   10);
   hgenVBFDEta = new TH1D("genVBFDEta","genVBFDEta", 50,   0,   10);
   hgenVBFDPhi = new TH1D("genVBFDPhi","genVBFDphi", 63,   0,    TMath::Pi());
   hgenVBFM    = new TH1D("genVBFM"   ,"genVBFM"   , 40,   0, 4000);
   

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
   
      cout << "******* NEW ENTRY[" << jentry << "]" << endl;

      if( printout ) continue;

      //      Float_t weight2 = 0.308;
      Float_t weight2 = 1;
      cout << "weight: " << weight2 << endl;
      cout << "nentries: " << nentries << endl;
      
      // Fill RECO Level objects to histo
      hJet1Pt->Fill(jet1Pt);
      hJet1Eta->Fill(jet1Eta);
      hJet2Pt->Fill(jet2Pt);
      hJet2Eta->Fill(jet2Eta);
      hvbfDEta->Fill(vbfDEta);
      hvbfDPhi->Fill(vbfDPhi);
      hvbfM->Fill(vbfM);
      hMET->Fill(met);
      hcenJetEt->Fill(cenJetEt);
      
      // Fill GEN Level objects to histo
      hgenVBFDEta->Fill(mcVBFDEta);
      hgenVBFDPhi->Fill(mcVBFDPhi);
      hgenVBFM->Fill(mcVBFM);
      
      TFile *_rootfile = new TFile("VBF_ntuple_125_unweighted.root","RECREATE");
      hJet1Pt->Write();
      hJet1Eta->Write();
      hJet2Pt->Write();
      hJet2Eta->Write();
      hvbfDEta->Write();
      hvbfDPhi->Write();
      hvbfM->Write();
      hMET->Write();
      hcenJetEt->Write();
      


      _rootfile->Write();
      _rootfile->Close();
	
      
   
      




   }
}
