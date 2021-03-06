#define PartonAnalysis_cxx
#include "PartonAnalysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1.h>
#include <TMath.h>
#include <TCanvas.h>
#include <vector>
#include <iterator>
#include <TLorentzVector.h>
#include <iostream>
#include <string>

#include "include/Partons.h"

using namespace std;

Int_t nEvt;
Int_t nPartons;


void PartonAnalysis::processEvents()
{

  Bool_t printout = 0;

  TH1::SetDefaultSumw2();
  
  fQ1PT  =   new TH1D("q1Pt"   , "q1Pt"   , 100,  0, 500);
  fQ1Eta =   new TH1D("q1Eta"  , "q1Eta"  , 100, -6,  -6);
  fQ2PT  =   new TH1D("q2Pt"   , "q2Pt"   , 100,  0, 500);
  fQ2Eta =   new TH1D("q2Eta"  , "q2Eta"  , 100, -6,  -6);

  fGenDEta = new TH1D("GenDEta", "GenDEta",  50,  0,  10);
  fGenDPhi = new TH1D("GenDPhi", "GenDPhi",  64,  0,  TMath::Pi()) ;
  fGenM    = new TH1D("GenM"   , "GenM"   ,  40,  0, 4000);
  

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      if ( printout ) continue;

      cout << "***** NEW ENTRY[" << jentry << "]" << endl;
      
      Int_t nParticles = sizeof(Particle_PID)/sizeof(Particle_PID[0]);

      for(Int_t i=0; i<nParticles; ++i){
	particles.push_back(Particle_PID[i]);
	particlepts.push_back(Particle_PT[i]);
	particlestatus.push_back(Particle_Status[i]);
	particlepx.push_back(Particle_Px[i]);
	particlepy.push_back(Particle_Py[i]);
	particlepz.push_back(Particle_Pz[i]);
	particlee.push_back(Particle_E[i]);

	Int_t pdgCode = TMath::Abs(particles.at(i));
	Int_t Status = particlestatus.at(i);
	Int_t nqs = 0;

	// Want to separate the two quarks from the VBF, and plot Pt and Eta.
	// If possible assign them TLorentzVectors

	// Function quarks, which takes pdgCodes as parameters and returns which parton it is
	
	if(      (Partons::quarks(pdgCode)) == 1){ nqs++; }
	else if( (Partons::quarks(pdgCode)) == 2){ nqs++; }
	else if( (Partons::quarks(pdgCode)) == 3){ nqs++; }
	else if( (Partons::quarks(pdgCode)) == 4){ nqs++; }
	else if( (Partons::quarks(pdgCode)) == 5){ nqs++; }
	else if( (Partons::quarks(pdgCode)) == 6){ nqs++; }
	else if( (Partons::quarks(pdgCode)) == 21){ nqs++; }

	// Check the Pt of incoming partons, and the Pt of outgoing partons, denoted by status -1/1

	// To split the two quarks, we use a boolean function that returns true if one quark from above is
	// discovered. The loop runs over all pdgCodes per event.

	if( Partons::findPartons(pdgCode, Status ) )
	  {
	    //	    cout << "Found an outgoing parton level quark" << flush;
	    Qs.SetPxPyPzE(particlepx.at(i),particlepy.at(i),particlepz.at(i),particlee.at(i));
	    quarks.push_back(Qs); // Storing the outgoing parton level quarks to vector 'quarks'
	  }
	
      }  // end of particle loop
      
      // Begin parton-level object definitions

      Float_t pi = TMath::Pi();
      Float_t genQ1PT = quarks.at(0).Pt();       // Gen-level parton-level quark PT
      Float_t genQ1Eta = quarks.at(0).Eta();
      Float_t genQ2PT = quarks.at(1).Pt();
      Float_t genQ2Eta = quarks.at(1).Eta();
      Float_t genVBFDEta = abs(quarks.at(0).Eta() - quarks.at(1).Eta());  // Delta Eta between parton-level quarks
      Float_t genVBFDPhi = abs(abs(abs(quarks.at(0).Phi() - quarks.at(1).Phi()) - pi) - pi);
      Float_t genVBFM = (quarks.at(0) + quarks.at(1)).M(); // Invariant mass between parton-level quarks
   
      fQ1PT->Fill(   genQ1PT);
      fQ1Eta->Fill(  genQ1Eta);
      fQ2PT->Fill(   genQ2PT);
      fQ2Eta->Fill(  genQ2Eta);
      fGenDEta->Fill(genVBFDEta);
      fGenDPhi->Fill(genVBFDPhi);
      fGenM->Fill(   genVBFM);
       
      particles.clear();
      particlepts.clear();
      particlestatus.clear();
      particlepx.clear();
      particlepy.clear();
      particlepz.clear();
      particlee.clear();
      quarks.clear();
      
   }
   this->Output();
}

Int_t PartonAnalysis::Output()
{
  TFile *rootfile = new TFile("VBF_inv_8TeV_partonlevel_objects.root","RECREATE");
  fQ1PT->Write();
  fQ1Eta->Write();
  fQ2PT->Write();
  fQ2Eta->Write();
  fGenDEta->Write();
  fGenDPhi->Write();
  fGenM->Write();
  rootfile->Write();
  rootfile->Close();

  return 0;
}



