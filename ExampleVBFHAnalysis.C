/////////////////////////////////////
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

Int_t nEvt;
Float_t nTrigger;
Int_t nJetPT;
Int_t nEta;
Int_t nDPhi;
Int_t nMET;
Int_t nJetMass;
Int_t nDEta;
Int_t nDPEta;
Int_t nCJV;
Float_t nYield0;
Float_t nYield1;
Float_t nYield2;
Float_t nYield3;
Float_t nYield4;
Float_t nYield5;
Float_t nYield6;
Float_t nYield7;
Float_t nYield8;

void ExampleVBFHAnalysis::processEvents()
{

  Bool_t printout = 0;

  TH1::SetDefaultSumw2();

  // Book histograms

  _fNJets = new TH1D("NJets", "NJets" , 100, 0, 20);
  _fJetPT = new TH1D("JetPT","JetPT",100, 0, 300);
  _fJetMass = new TH1D("JetMass","JetMass",100, 0.0, 300);
  _fMjj = new TH1D("InvJetMass","InvJetMass",50,0.0,4000);
  _fDeltaEta = new TH1D("DeltaEtaJJ","DeltaEtaJJ",50, 0, 10);
  _fDeltaPhi = new TH1D("DeltaPhiJJ","DeltaPhiJJ",50, 0,4);
  _fEtaDP = new TH1D("EtaDP","EtaDP",50, -10, 2);
  _fCJV = new TH1D("CJV","CJV",50, 0, 150);
  _fMET = new TH1D("MET","MET",50, 0, 500);
  _fGenJetPT = new TH1D("GenJetPT","GenJetPT",100, 0.0, 300);
  _f1stJetPT = new TH1D("1stJetPT","1stJetPT", 100, 0, 400);
  _fJetEta1 = new TH1D("JetEta1","JetEta1",50,-10,10);
  _f2ndJetPT = new TH1D("2ndJetPT","2ndJetPT",50, 0, 300);
  _fJetEta2 = new TH1D("JetEta2","JetEta2",50, -10, 10);
  _fJetEta = new TH1D("JetEta","JetEta", 50, -5, 5);
  _fJetPhi = new TH1D("JetPhi","JetPhi", 50, -4, 4);
  _fScalarHT = new TH1D("ScalarHT","ScalarHT",100, 0, 300);
  _fHT = new TH1D("HT","HT",100, 0, 800);
  _f1stJetMass = new TH1D("1stJetMass","1stJetMass", 100, 0, 50);
  _f2ndJetMass = new TH1D("2ndJetMass","2ndJetMass", 100, 0, 50);
  _fHiggsPT = new TH1D("HiggsPT","HiggsPT",100, 0.0, 300);

  // Pre baseline cut histo
  fJetPT1_precut = new TH1D("JetPT1_precut","JetPT1_precut",50,0,400);
  fJetPT2_precut = new TH1D("JetPT2_precut","JetPT2_precut",50,0,400);
  fEtaDP_precut  = new TH1D("EtaDP_precut","EtaDP_precut",50, -10, 3);
  fDeltaEta_precut = new TH1D("DeltaEta_precut","DeltaCut_precut",50, 0, 10);
  fMET_precut = new TH1D("MET_precut","MET_precut",50, 0, 500);
  fInvMass_precut = new TH1D("InvMass_precut","InvMass_precut",50, 0.0, 4000);
  fCJV_precut = new TH1D("CJV_precut","CJV_precut",50, 0.0, 150);
  fDeltaPhi_precut = new TH1D("DeltaPhi_precut","DeltaPhi_precut",50, 0, 3.5);

  _nEvt = fChain->GetEntriesFast();       // Get total number of entries
  //  _nEvt = 1000;     
  Long64_t nbytes =0 , nb = 0;
  

   for (Long64_t entry=0; entry<_nEvt;entry++) {       
      Long64_t ientry = LoadTree(entry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(entry);   nbytes += nb;
      
      //      cout << "***** NEW ENTRY[" << entry << "]" << endl;
      
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
   
    njets.push_back(Jet_size);                  // njets is always 6 here since it is the size of array defined in the header
    jetpts.push_back(Jet_PT[i]);                // jetpts vector is probably a better alternative in finding no. of jets per event
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
    Jet3.SetPtEtaPhiM(jetpts.at(2),jeteta.at(2),jetphi.at(2),jetmass.at(2));
    jets.push_back(Jet3);
    Jet4.SetPtEtaPhiM(jetpts.at(3),jeteta.at(3),jetphi.at(3),jetmass.at(3));
    jets.push_back(Jet4);
    Jet5.SetPtEtaPhiM(jetpts.at(4),jeteta.at(4),jetphi.at(4),jetmass.at(4));
    jets.push_back(Jet5);

    Float_t pi = 3.14159265;    
    Float_t mjj = (Jet1 + Jet2).M();
    Float_t EtaDP = Jet1.Eta()*Jet2.Eta();
    Float_t DeltaEta = abs(Jet1.Eta() - Jet2.Eta());
    //    Float_t DeltaPhi = abs(abs(abs(Jet1.Phi() - Jet2.Phi()) - pi) - pi);
    Float_t DeltaPhi = (Jet1.Phi() - Jet2.Phi());
    if(-1*pi < DeltaPhi && DeltaPhi < pi){ DeltaPhi = DeltaPhi + 0; }
    else if(DeltaPhi > pi){ DeltaPhi = DeltaPhi - 2*pi; }
    else if(DeltaPhi <= -pi){ DeltaPhi = DeltaPhi + 2*pi; } 

    Float_t MET = MissingET_MET[0];
    
    // Fill pre baseline-cuts histos
    fJetPT1_precut->Fill(jets.at(0).Pt());
    fJetPT2_precut->Fill(jets.at(1).Pt());
    fEtaDP_precut->Fill(EtaDP);
    fDeltaEta_precut->Fill(DeltaEta);
    fMET_precut->Fill(MET);
    fInvMass_precut->Fill(mjj);
    fCJV_precut->Fill(jets.at(2).Pt());
    fCJV_precut->Fill(jets.at(3).Pt());
    fDeltaPhi_precut->Fill(DeltaPhi);


    if( jets.at(0).Eta() < jets.at(2).Eta() && jets.at(2).Eta() < jets.at(1).Eta() ) { _fCJV->Fill(jets.at(2).Pt()); }
    else if( jets.at(1).Eta() < jets.at(2).Eta() && jets.at(2).Eta() < jets.at(0).Eta()  ) { _fCJV->Fill(jets.at(2).Pt()); }
    else if( jets.at(1).Eta() < jets.at(3).Eta() && jets.at(3).Eta() < jets.at(0).Eta()  ) { _fCJV->Fill(jets.at(3).Pt()); }
    else if( jets.at(1).Eta() < jets.at(4).Eta() && jets.at(4).Eta() < jets.at(0).Eta() ) { _fCJV->Fill(jets.at(4).Pt()); }

    //    cout << "jets.at(0).PT() : " << jets.at(0).Pt() << "/" << "jets.at(1).Pt() : " << jets.at(1).Pt() << "/" << "EtaDP: " << EtaDP << "/ DeltaEta: " << DeltaEta << "/ mjj: " << mjj << "/ MET: " << MET << endl;
    // Apply baseline-cuts
    Bool_t CutTrigger = Selection::TriggerCuts(jets.at(0).Pt(),jets.at(1).Pt(),EtaDP,DeltaEta,mjj,MET);
    Bool_t Cut0 = Selection::EtaCut(jets.at(0).Eta()) && Selection::EtaCut(jets.at(1).Eta());
    Bool_t Cut1 = Selection::JetCut(jets.at(0).Pt()) && Selection::JetCut(jets.at(1).Pt());
    Bool_t Cut2 = Selection::DPEta(EtaDP);
    Bool_t Cut3 = Selection::DEtaCut(DeltaEta);
    Bool_t Cut4 = Selection::METcut(MET);
    Bool_t Cut5 = Selection::MassCut(mjj);
    Bool_t Cut6 = Selection::CJVCut(jets.at(0).Eta(),jets.at(1).Eta(),jets.at(2).Eta(),jets.at(2).Pt()) || Selection::CJVCut(jets.at(0).Eta(),jets.at(1).Eta(),jets.at(3).Eta(),jets.at(3).Pt());
    Bool_t Cut7 = Selection::PhiCut(DeltaPhi);


    // Count independent no. events passing baseline-cuts
    if(CutTrigger){ nTrigger++; }
    if(Cut0){ nEta++; }
    if(Cut1){ nJetPT++; }
    if(Cut2){ nDPEta++; }
    if(Cut3){ nDEta++; }
    if(Cut4){ nMET++; }
    if(Cut5){ nJetMass++; }
    if(Cut6){ nCJV++; }
    if(Cut7){ nDPhi++; }


    Float_t weight1 = 0.657;
    // Fill N-1 histograms
    if(Cut0 && Cut1 && Cut2 && Cut3 && Cut4 && Cut6 && Cut7){ _fMjj->Fill(mjj,weight1); }
    if(Cut0 && Cut1 && Cut2 && Cut4 && Cut5 && Cut6 && Cut7){ _fDeltaEta->Fill(DeltaEta,weight1); }
    if(Cut0 && Cut1 && Cut2 && Cut3 && Cut4 && Cut5 && Cut6){ _fDeltaPhi->Fill(DeltaPhi,weight1); }
    if(Cut1 && Cut2 && Cut3 && Cut4 && Cut5 && Cut6 && Cut7){ _fJetEta1->Fill(jets.at(0).Eta(),weight1); }
    if(Cut1 && Cut2 && Cut3 && Cut4 && Cut5 && Cut6 && Cut7){ _fJetEta2->Fill(jets.at(1).Eta(),weight1); }
    if(Cut0 && Cut1 && Cut2 && Cut3 && Cut5 && Cut6 && Cut7){ _fMET->Fill(MET,weight1); }
    if(Cut0 && Cut2 && Cut3 && Cut4 && Cut5 && Cut6 && Cut7){ _f1stJetPT->Fill(jetpts.at(0),weight1); }
    if(Cut0 && Cut2 && Cut3 && Cut4 && Cut5 && Cut6 && Cut7){ _f2ndJetPT->Fill(jetpts.at(1),weight1); }
    if(Cut0 && Cut1 && Cut3 && Cut4 && Cut5 && Cut6 && Cut7){ _fEtaDP->Fill(EtaDP,weight1); }

    _f1stJetMass->Fill(jetmass.at(0));
    _f2ndJetMass->Fill(jetmass.at(1));

    // Calculate surviving events for yield
    if(CutTrigger && Cut0){ nYield0++; }
    if(CutTrigger && Cut0 && Cut1){ nYield1++; }
    if(CutTrigger && Cut0 && Cut1 && Cut2){ nYield2++; }
    if(CutTrigger && Cut0 && Cut1 && Cut2 && Cut3){ nYield3++;}
    if(CutTrigger && Cut0 && Cut1 && Cut2 && Cut3 && Cut4){ nYield4++; }
    if(CutTrigger && Cut0 && Cut1 && Cut2 && Cut3 && Cut4 && Cut5){ nYield5++; }
    if(CutTrigger && Cut0 && Cut1 && Cut2 && Cut3 && Cut4 && Cut5 && Cut6){ nYield6++; }
    if(CutTrigger && Cut0 && Cut1 && Cut2 && Cut3 && Cut4 && Cut5 && Cut6 && Cut7){ nYield7++; }

    
    /*
      cout << "nTrigger: " << nTrigger*weight << endl;
    
      cout << "nYield1: " << nYield1*weight << "  " << nYield1/nTrigger << "  " << nYield1/nTrigger  << endl;
      cout << "nYield2: " << nYield2*weight << "  " << nYield2/nTrigger << "  " << nYield2/nYield1 << endl;
      cout << "nYield3: " << nYield3*weight << "  " << nYield3/nTrigger << "  " << nYield3/nYield2 << endl;
      cout << "nYield4: " << nYield4*weight << "  " << nYield4/nTrigger << "  " << nYield4/nYield3 << endl;
      cout << "nYield5: " << nYield5*weight << "  " << nYield5/nTrigger << "  " << nYield5/nYield4 << endl;
      cout << "nYield6: " << nYield6*weight << "  " << nYield6/nTrigger << "  " << nYield6/nYield5 << endl;
      cout << "nYield7: " << nYield7*weight << "  " << nYield7/nTrigger << "  " << nYield7/nYield6 << endl;
      cout << "nYield8: " << nYield8*weight << "  " << nYield8/nTrigger << "  " << nYield8/nYield7 << endl;
    */
    /*   cout << "nEta: " << nEta << endl;
	 cout << "nDPhi: " << nDPhi << endl;
	 cout << "nMET: " << nMET << endl;
	 cout << "nJetMass: " << nJetMass << endl;
	 cout << "nDEta: " << nDEta << endl;
	 cout << "nDPEta: "<< nDPEta << endl;
	 cout << "nCJV: " << nCJV << endl;
    */


    
  }
  
  Float_t weight = 0.657;
  cout << "nTrigger: " << nTrigger*weight << endl;
  
  cout << "nYield1 = dijet PT: " << nYield1*weight << "  " << nYield1/nTrigger << "  " << nYield1/nTrigger  << endl;
  cout << "nYield2 = Eta(j1).Eta(j2): " << nYield2*weight << "  " << nYield2/nTrigger << "  " << nYield2/nYield1 << endl;
  cout << "nYield3 = DeltaEta(j1j2): " << nYield3*weight << "  " << nYield3/nTrigger << "  " << nYield3/nYield2 << endl;
  cout << "nYield4 = MET: " << nYield4*weight << "  " << nYield4/nTrigger << "  " << nYield4/nYield3 << endl;
  cout << "nYield5 = M(j1j2):  " << nYield5*weight << "  " << nYield5/nTrigger << "  " << nYield5/nYield4 << endl;
  cout << "nYield6 = CJV: " << nYield6*weight << "  " << nYield6/nTrigger << "  " << nYield6/nYield5 << endl;
  cout << "nYield7 = DeltaPhi(j1j2): " << nYield7*weight << "  " << nYield7/nTrigger << "  " << nYield7/nYield6 << endl;

    
      
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

  TFile *_rootFile = new TFile("VBF_invH_8000_output.root1","RECREATE");

  _fJetPT->Write();
  _fJetMass->Write();
  _fMjj->Write();
  _fDeltaEta->Write();
  _fDeltaPhi->Write();
  _fEtaDP->Write();
  _fCJV->Write();
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

  fJetPT1_precut->Write();
  fJetPT2_precut->Write();
  fEtaDP_precut->Write();
  fDeltaEta_precut->Write();
  fMET_precut->Write();
  fInvMass_precut->Write();
  fCJV_precut->Write();
  fCJV_precut->Write();
  fDeltaPhi_precut->Write();

  
  _rootFile->Write();
  _rootFile->Close();
  
  return 0;

}
