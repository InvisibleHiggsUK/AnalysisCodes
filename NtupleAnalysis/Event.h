#ifndef EVENT_H
#define EVENT_H

#include <cmath>
#include <exception>
#include <iostream>

#include "TChain.h"
#include "TFile.h"
#include "TString.h"
#include "TBranch.h"

class Event{
 public:
  
  Event(const TString &fileName, int numProcessed);
  ~Event();
  
  int nTotEvents() const { return nTotEvts_; }
  
  bool loadNext();
  
  Float_t ID() const { return id_; }
  
  Int_t JETSINDEX() const { return jet1index_; }
  Double_t* JET1PT() const { return jet1pt_; }
  Double_t* JET1ETA() const { return jet1eta_; }
  Double_t* JET1PHI() const { return jet1phi_; }
  Double_t* JET1M() const { return jet1m_; }
  Double_t* JET2PT() const { return jet2pt_; } 
  Double_t* JET2ETA() const { return jet2eta_; }
  Double_t* JET2PHI() const { return jet2phi_; }
  Double_t* JET2M() const { return jet2m_; }
  Double_t MET() const { return met_; } 
  Double_t METPHI() const { return metphi_; }
  Double_t MHT() const { return mht_; } 
  Double_t* JET3ET() const { return jet3et_; }
  Double_t* JET3ETA() const { return jet3eta_; }
  Double_t* JET3PHI() const { return jet3phi_; }
  Double_t* JET3M() const { return jet3m_; }
  


 private:
  const unsigned int maxColSize_;
  int nTotEvts_;
  int currentEntry_;
  
  TChain* chain_;
  
  Double_t id_;
  Int_t jet1index_;
  Double_t* jet1pt_;
  Double_t* jet1eta_;
  Double_t* jet1phi_;
  Double_t* jet1m_;
  Double_t* jet2pt_;
  Double_t* jet2eta_;
  Double_t* jet2phi_;
  Double_t* jet2m_;
  Double_t met_;
  Double_t metphi_;
  Double_t mht_;
  Double_t* jet3et_;
  Double_t* jet3eta_;
  Double_t* jet3phi_;
  Double_t* jet3m_;
  
};

Event::Event(const TString &fileName, int numProcessed)
: maxColSize_(50), currentEntry_(-1){
  std::cout << "Setting up event variables\n" << std::flush;
  
  jet1pt_ = new Double_t[maxColSize_];
  jet1eta_ = new Double_t[maxColSize_];
  jet1phi_ = new Double_t[maxColSize_];
  jet1m_ = new Double_t[maxColSize_];

  jet2pt_ = new Double_t[maxColSize_];
  jet2eta_ = new Double_t[maxColSize_];
  jet2phi_ = new Double_t[maxColSize_];
  jet2m_ = new Double_t[maxColSize_];

  jet3et_ = new Double_t[maxColSize_];
  jet3eta_ = new Double_t[maxColSize_];
  jet3phi_ = new Double_t[maxColSize_];
  jet3m_ = new Double_t[maxColSize_];
  
  chain_ = new TChain("invHiggsInfo/InvHiggsInfo");

  chain_->Add(fileName);

  nTotEvts_ = ( numProcessed < 0 ) ? chain_->GetEntries() : std::min(numProcessed,static_cast<int>(chain_->GetEntries()));
  
  chain_->SetBranchAddress("jet1Index",&jet1index_);
  chain_->SetBranchAddress("jet1Pt",jet1pt_);
  chain_->SetBranchAddress("jet1Eta",jet1eta_);
  chain_->SetBranchAddress("jet1Phi",jet1phi_);
  chain_->SetBranchAddress("jet1M",jet1m_);
  chain_->SetBranchAddress("jet2Pt",jet2pt_);
  chain_->SetBranchAddress("jet2Eta",jet2eta_);
  chain_->SetBranchAddress("jet2Phi",jet2phi_);
  chain_->SetBranchAddress("jet2M",jet2m_);
  chain_->SetBranchAddress("met",&met_);
  chain_->SetBranchAddress("metPhi",&metphi_);
  chain_->SetBranchAddress("mht",&mht_);
  chain_->SetBranchAddress("jet3Et",jet3et_);
  chain_->SetBranchAddress("jet3Eta",jet3eta_);
  chain_->SetBranchAddress("jet3Phi",jet3phi_);
  chain_->SetBranchAddress("jet3M",jet3m_);

}

Event::~Event(){
  for(unsigned int i=0; i < maxColSize_; ++i){
    //    delete [] jet1pt_;
    delete [] jet1eta_;
    delete [] jet1phi_;
    delete [] jet1m_;
    delete [] jet2pt_;
    delete [] jet2eta_;
    delete [] jet2phi_;
    delete [] jet2m_;
    delete [] jet3et_;
    delete [] jet3eta_;
    delete [] jet3phi_;
    delete [] jet3m_;
    
  }
 
  delete chain_;
  
}

bool Event::loadNext() { 
  if( currentEntry_ < 0){
    std::cout << "Processing " << nTotEvents() << " events" << std::endl;
  }
  ++currentEntry_;
  
  if(currentEntry_ == nTotEvts_){
    return false;
  }
  else {
    if( currentEntry_ > 0 && currentEntry_%100000 == 0){
      std::cout << "Processed " << currentEntry_ << " events" << std::endl;
    }

    chain_->GetEntry(currentEntry_);




    return true;
  }
}

#endif
