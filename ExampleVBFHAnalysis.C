//////////////////////////////////////
//
//  Analysis for VBV Invisible Higgs
//
//  University of Bristol
//  Date: June 2014
//
//////////////////////////////////////

#define ExampleVBFHAnalysis_cxx
#include "ExampleVBFHAnalysis.h"
#include <TH2.h>
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <vector>
#include <iterator>
#include <iostream>

#include "Selection.h"      // Contains the necessary offline cuts

class ExRootTreeTreader;
class ExRootResult;


using namespace std;

Int_t nJetPT;
Int_t nEta;
Int_t nPhi;
Int_t nMET;
Int_t nJetMass;
Int_t nDEta;
Int_t nDPEta;

void ExampleVBFHAnalysis::processEvents()
{

  Bool_t printout = 0;

  TH1::SetDefaultSumw2();

  // Book histograms

  _fNJets = new TH1D("NJets", "NJets" , 100, 0, 20);
  _fJetPT = new TH1D("JetPT","JetPT",100, 0, 300);
  _fJetMass = new TH1D("JetMass","JetMass",100, 0.0, 300);
  _fMjj = new TH1D("InvJetMass","InvJetMass",100,0.0,3000);
  _fDeltaEta = new TH1D("DeltaEtaJJ","DeltaEtaJJ",100, 3, 10);
  _fDeltaPhi = new TH1D("DeltaPhiJJ","DeltaPhiJJ",100, -6,6);
  _fEtaDP = new TH1D("EtaDP","EtaDP",100, -10, 2);
  _fMET = new TH1D("MET","MET",100, 0, 500);
  _fGenJetPT = new TH1D("GenJetPT","GenJetPT",100, 0.0, 300);
  _f1stJetPT = new TH1D("1stJetPT","1stJetPT", 100, 0, 300);
  _fJetEta1 = new TH1D("JetEta1","JetEta1",100,-10,10);
  _f2ndJetPT = new TH1D("2ndJetPT","2ndJetPT",100, 0, 300);
  _fJetEta2 = new TH1D("JetEta2","JetEta2",100, -10, 10);
  _fJetEta = new TH1D("JetEta","JetEta", 100, -5, 5);
  _fJetPhi = new TH1D("JetPhi","JetPhi", 100, -4, 4);
  _fScalarHT = new TH1D("ScalarHT","ScalarHT",100, 0, 300);
  _fHT = new TH1D("HT","HT",100, 0, 800);
  _f1stJetMass = new TH1D("1stJetMass","1stJetMass", 100, 0, 50);
  _f2ndJetMass = new TH1D("2ndJetMass","2ndJetMass", 100, 0, 50);
  _fHiggsPT = new TH1D("HiggsPT","HiggsPT",100, 0.0, 300);



  _nEvt = fChain->GetEntriesFast();       // Get total number of entries
  //  _nEvt = 1000;     
  Long64_t nbytes =0 , nb = 0;
  

   for (Long64_t entry=0; entry<_nEvt;entry++) {       
      Long64_t ientry = LoadTree(entry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(entry);   nbytes += nb;
      
      cout << "***** NEW ENTRY[" << entry << "]" << endl;
      
      if ( printout ) continue;

      this->Analysis();
      this->ParticleAnalysis();
      this->Output();
      
   }
}

Int_t ExampleVBFHAnalysis::Analysis()
{

  Int_t _nJets = sizeof(Jet_PT)/sizeof(Jet_PT[0]);
  Long64_t HT = 0;

  for(Int_t i=0; i < _nJets; i++){
   
    njets.push_back(Jet_size);                   // Transfering array information to vectors
    jetpts.push_back(Jet_PT[i]);
    jeteta.push_back(Jet_Eta[i]);
    jetphi.push_back(Jet_Phi[i]);
    jetmass.push_back(Jet_Mass[i]);
    
    _fNJets->Fill(njets.at(i));
    _fJetMass->Fill(jetmass.at(i));
    _fJetEta->Fill(jeteta.at(i));
    _fJetPhi->Fill(jetphi.at(i));
    
    HT += jetpts.at(i);                          // Note this the conventional definition of HT, a Delphes equivalent exists 
    _fHT->Fill(HT);
  }
  if(njets.size() > Selection::NJets() ){
    
    Jet1.SetPtEtaPhiM(jetpts.at(0),jeteta.at(0),jetphi.at(0),jetmass.at(0));
    jets.push_back(Jet1);
    Jet2.SetPtEtaPhiM(jetpts.at(1),jeteta.at(1),jetphi.at(1),jetmass.at(1));
    jets.push_back(Jet2);
    
    Float_t mjj = (Jet1 + Jet2).M();
    Float_t EtaDP = Jet1.Eta()*Jet2.Eta();
    Float_t DeltaEta = Jet1.Eta() - Jet2.Eta();
    //      Float_t DeltaPhi = Jet1.Phi() - Jet2.Phi();
    Float_t pi = 3.14159265;
    Float_t DeltaPhi = abs(abs(abs(Jet1.Phi() - Jet2.Phi()) - pi) - pi);
    Float_t MET = MissingET_MET[0];

    if(Selection::JetCut(jets.at(0).Pt()) && Selection::JetCut(jets.at(1).Pt()) ) { nJetPT++; }
    if(Selection::EtaCut(jets.at(0).Eta()) && Selection::EtaCut(jets.at(1).Eta()) ) { nEta++; }
    if(Selection::PhiCut(DeltaPhi)) { nPhi++; }
    if(Selection::METcut(MET)) { nMET++; }
    if(Selection::MassCut(mjj)) { nJetMass++; }
    if(Selection::DEtaCut(DeltaEta)) { nDEta++; }
    if(Selection::DPEta(EtaDP)){ nDPEta++; } 


    // Apply the Jet PT baseline-cuts
    /*   if(jets.at(0).Pt() && jets.at(1).Pt() < Selection::JetPTCut() ) continue;
    
    // Apply the Eta scalar product baseline-cuts 
    if( EtaDP > Selection::JetEtaDPCut() ) continue;
    
    // Apply the Delta Eta j1, j2 baseline-cuts
    if( DeltaEta < Selection::DeltaEtaJJCut() ) continue;
    
    // Apply the MET baseline cuts
    if( MET < Selection::METCut() ) continue;
    
    // Apply the Mjj baseline-cuts
    if( mjj < Selection::InvJetMassCut() ) continue;
    
    // Apply the Delta Phi j1, j2 baseline-cuts
    if( DeltaPhi > Selection::DeltaPhiJJCut() ) continue;
    
    // Apply the absolute value of Eta baseline-cuts
    if( abs(jets.at(0).Eta()) && abs(jets.at(1).Eta()) > Selection::JetEtaCut() ) continue;
    */
    
    // Fill histograms
    _fMjj->Fill(mjj);
    _fDeltaEta->Fill(DeltaEta);
    _fDeltaPhi->Fill(DeltaPhi);
    _fEtaDP->Fill(EtaDP);
    _fMET->Fill(MET);
    _f1stJetPT->Fill(jetpts.at(0));
    _fJetEta1->Fill(jets.at(0).Eta());
    _f1stJetMass->Fill(jetmass.at(0));
    _f2ndJetPT->Fill(jetpts.at(1));  
    _f2ndJetMass->Fill(jetmass.at(1));
    _fJetEta2->Fill(jets.at(1).Eta());


    cout << "nJetPT: " << nJetPT << endl;
    cout << "nEta: " << nEta << endl;
    cout << "nPhi: " << nPhi << endl;
    cout << "nMET: " << nMET << endl;
    cout << "nJetMass: " << nJetMass << endl;
    cout << "nDEta: " << nDEta << endl;
    cout << "nDPEta: "<< nDPEta << endl;
    
  }

      
      _fScalarHT->Fill(ScalarHT_HT[0]);
  
      Int_t _nGenJets = sizeof(GenJet_PT)/sizeof(GenJet_PT[0]);
  
      for(Int_t j=0; j < _nGenJets; j++){
	ngenjets.push_back(GenJet_size);
	genjetpts.push_back(GenJet_PT[j]);
	_fGenJetPT->Fill(genjetpts.at(j));
      }
      
      njets.clear();
      jetpts.clear();
      ngenjets.clear();
      genjetpts.clear();
      jeteta.clear();
      jetphi.clear();
      jetmass.clear();
      jets.clear();
      

      
      return 0;
}

Int_t ExampleVBFHAnalysis::ParticleAnalysis(){
  
  Int_t _nParts = sizeof(Particle_PID)/sizeof(Particle_PID[0]);

  for(Int_t i=0; i<_nParts; i++){
    particles.push_back(Particle_PID[i]);
    particlestatus.push_back(Particle_Status[i]);
    particlepts.push_back(Particle_PT[i]);
    
    Int_t pdgCode = abs(particles.at(i));
    Int_t status = particlestatus.at(i);

    if(pdgCode == 25 && status != 3){
      cout << "Found a Higgs" << endl;
      Higgs.SetPxPyPzE(Particle_Px[i],Particle_Py[i],Particle_Pz[i],Particle_E[i]);
      higgs.push_back(Higgs);
      _fHiggsPT->Fill(Higgs.Pt());
    }
  }
  
  higgs.clear();
  return 0;
}

Int_t ExampleVBFHAnalysis::Output()
{

  TFile *_rootFile = new TFile("VBF_invH_8000_output.root","RECREATE");

  _fJetPT->Write();
  _fJetMass->Write();
  _fMjj->Write();
  _fDeltaEta->Write();
  _fDeltaPhi->Write();
  _fEtaDP->Write();
  _fGenJetPT->Write();
  _f1stJetPT->Write();
  _f2ndJetPT->Write();
  _f1stJetMass->Write();
  _f2ndJetMass->Write();
  _fJetEta1->Write();
  _fJetEta2->Write();
  _fJetEta->Write();
  _fJetPhi->Write();
  _fHT->Write();
  _fMET->Write();
  _fNJets->Write();
  _fHiggsPT->Write();
  _rootFile->Write();
  _rootFile->Close();
  
  return 0;

}
