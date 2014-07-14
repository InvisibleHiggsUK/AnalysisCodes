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

#include "Partons.h"

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
      Int_t nQ1 = 0 , nQ2 = 0;

     }
}
