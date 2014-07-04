#include <cmath>
#include <iostream>
#include <vector>

#include "TH1.h"
#include "TH1D.h"
#include "TString.h"
#include "TVector2.h"

#include "Event.h"
#include "Sample.h"

void AnalyseNtuples(unsigned int id, int nEvts = -1){
  
  std::cout << "Analysing the '"<< Sample::toTString(id) << "' sample" << std::endl;

  TH1* hNJets = new TH1D("hNJets","hNJets",12,0,12);
  hNJets->Sumw2();
  TH1* hJet1PT = new TH1D("hJet1PT","hJetPT",100, 0, 300);
  hJet1PT->Sumw2();
  TH1* hJet1Eta = new TH1D("hJet1Eta","hJetEta",50, -10, 10);
  hJet1Eta->Sumw2();
  TH1* hJet2PT = new TH1D("hJet2PT","hJet2PT",100, 0, 300);
  hJet2PT->Sumw2();
  TH1* hJet2Eta = new TH1D("hJet2Eta","hJet2Eta",50, -10, 10);
  hJet2Eta->Sumw2();
  
    

  Event* evt = new Event(Sample::fileNameFullSample(id),nEvts);

  while( evt->loadNext() ) {

    std::cout << "NEW ENTRY" << std::endl;
    std::cout << "Jet PT: " << evt->JET1PT() << std::endl;
    //    std::cout << "JetPT: " << jet1Pt << std::endl;
  }

}
