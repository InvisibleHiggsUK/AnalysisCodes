//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Jun 30 13:32:46 2014 by ROOT version 5.34/18
// from TTree InvHiggsInfo/
// found on file: SignalM125_POWHEG.root
//////////////////////////////////////////////////////////

#ifndef NtupleAnalysis_h
#define NtupleAnalysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TRef.h>
#include <TH1.h>
#include <TObject.h>
#include <TLorentzVector.h>
#include <TRefArray.h>


class NtupleAnalysis {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
 //InvHiggsInfo    *events;
   ULong_t         id;
   ULong_t         bx;
   ULong_t         lb;
   ULong_t         run;
   Bool_t          l1Result;
   Double_t        l1ET;
   Double_t        l1MET;
   Double_t        l1ETPhi;
   Double_t        l1HT;
   Double_t        l1MHT;
   Double_t        l1HTPhi;
   Bool_t          hltResult1;
   Bool_t          hltResult2;
   Bool_t          hltResult3;
   Bool_t          hltResult4;
   Bool_t          metflag0;
   Bool_t          metflag1;
   Bool_t          metflag2;
   Bool_t          metflag3;
   Bool_t          metflag4;
   Bool_t          metflag5;
   Bool_t          metflag6;
   Bool_t          metflag7;
   Bool_t          metflag8;
   Int_t           jet1Index;
   Double_t        jet1Pt;
   Double_t        jet1Eta;
   Double_t        jet1Phi;
   Double_t        jet1M;
   Double_t        jet1PUMVA;
   Int_t           jet1PUFlag;
   Double_t        jet1unc;
   Double_t        jet1DeltaT;
   Int_t           jet2Index;
   Double_t        jet2Pt;
   Double_t        jet2Eta;
   Double_t        jet2Phi;
   Double_t        jet2M;
   Double_t        jet2PUMVA;
   Int_t           jet2PUFlag;
   Double_t        jet2unc;
   Double_t        jet2DeltaT;
   Double_t        met;
   Double_t        metPhi;
   Double_t        jmDPhi;
   Double_t        jmDPhiN1;
   Double_t        jmDPhiN2;
   Double_t        jmDPhiNMin;
   Double_t        metNoMuon;
   Double_t        metNoMuonPhi;
   Double_t        metNoElectron;
   Double_t        metNoElectronPhi;
   Double_t        metNo2Muon;
   Double_t        metNo2MuonPhi;
   Double_t        jmNo2MuonDPhi;
   Double_t        jmNo2MuonDPhiN1;
   Double_t        jmNo2MuonDPhiN2;
   Double_t        jmNo2MuonDPhiNMin;
   Double_t        metNoWLepton;
   Double_t        metNoWLeptonPhi;
   Double_t        jmNoWLeptonDPhi;
   Double_t        jmNoWLeptonDPhiN1;
   Double_t        jmNoWLeptonDPhiN2;
   Double_t        jmNoWLeptonDPhiNMin;
   Double_t        mht;
   Double_t        mhtPhi;
   Double_t        vbfEt;
   Double_t        vbfEta;
   Double_t        vbfPhi;
   Double_t        vbfM;
   Double_t        vbfDEta;
   Double_t        vbfDPhi;
   Int_t           numTrackerJet3;
   Double_t        jet3Et;
   Double_t        jet3Eta;
   Double_t        jet3Phi;
   Double_t        jet3M;
   Double_t        jet3EtaStar;
   Double_t        cenJetEt;
   Double_t        cenJetEta;
   Double_t        cenJetPhi;
   Double_t        cenJetM;
   Double_t        cenJetEtaStar;
   Double_t        ele1Pt;
   Double_t        ele1Eta;
   Double_t        ele1Phi;
   Double_t        ele1M;
   Double_t        ele2Pt;
   Double_t        ele2Eta;
   Double_t        ele2Phi;
   Double_t        ele2M;
   Double_t        ele3Pt;
   Double_t        ele3Eta;
   Double_t        ele3Phi;
   Double_t        ele3M;
   Double_t        mu1Pt;
   Double_t        mu1Eta;
   Double_t        mu1Phi;
   Double_t        mu1M;
   Double_t        mu2Pt;
   Double_t        mu2Eta;
   Double_t        mu2Phi;
   Double_t        mu2M;
   Double_t        mu3Pt;
   Double_t        mu3Eta;
   Double_t        mu3Phi;
   Double_t        mu3M;
   Int_t           nTaus_tot;
   Int_t           nTaus_pass;
   Double_t        tau_dz;
   Double_t        tau1Pt;
   Double_t        tau1Eta;
   Double_t        tau1Phi;
   Double_t        tau1M;
   Double_t        tau1mT;
   Double_t        tau1dR;
   Double_t        tau2Pt;
   Double_t        tau2Eta;
   Double_t        tau2Phi;
   Double_t        tau2M;
   Double_t        tau2mT;
   Int_t           nTaus_match;
   Int_t           nW;
   Double_t        wPt;
   Double_t        wEta;
   Double_t        wPhi;
   Double_t        wMt;
   Double_t        wChannel;
   Double_t        wDaulPt;
   Double_t        wDaulEta;
   Double_t        wDaulPhi;
   Double_t        wDaulM;
   Double_t        wDaulCharge;
   Int_t           nZ;
   Double_t        zPt;
   Double_t        zEta;
   Double_t        zPhi;
   Double_t        zMass;
   Double_t        zChannel;
   Double_t        zDau1Pt;
   Double_t        zDau1Eta;
   Double_t        zDau1Phi;
   Double_t        zDau1M;
   Double_t        zDau1Charge;
   Double_t        zDau2Pt;
   Double_t        zDau2Eta;
   Double_t        zDau2Phi;
   Double_t        zDau2M;
   Double_t        zDau2Charge;
   Int_t           nVtx;
   Double_t        puWeight;
   Double_t        trigCorrWeight;
   Double_t        mcHiggsMass;
   Double_t        mcHiggsPt;
   Double_t        mcHiggsEta;
   Double_t        mcHiggsPhi;
   Double_t        mcQ1Pt;
   Double_t        mcQ1Eta;
   Double_t        mcQ1Phi;
   Double_t        mcQ1M;
   Double_t        mcQ2Pt;
   Double_t        mcQ2Eta;
   Double_t        mcQ2Phi;
   Double_t        mcQ2M;
   Double_t        mcVBFEt;
   Double_t        mcVBFEta;
   Double_t        mcVBFPhi;
   Double_t        mcVBFM;
   Double_t        mcVBFDEta;
   Double_t        mcVBFDPhi;
   Double_t        wgennj;
   Double_t        wgenmass;
   Double_t        wgenpt;
   Double_t        wgenmt;
   Double_t        wgeneta;
   Double_t        wgenphi;
   Double_t        wgene;
   Int_t           wltype;
   Double_t        wlpt;
   Double_t        wleta;
   Double_t        wlphi;
   Double_t        wle;
   Int_t           wtauhadron;
   Double_t        wmetpt;
   Double_t        wmeteta;
   Double_t        wmetphi;
   Double_t        wmete;
   Double_t        zgenmass;
   Double_t        zgenpt;
   Double_t        zgenmt;
   Double_t        zgeneta;
   Double_t        zgenphi;
   Double_t        zgene;
   Int_t           zltype;
   Double_t        zlmpt;
   Double_t        zlmeta;
   Double_t        zlmphi;
   Double_t        zlme;
   Double_t        zlppt;
   Double_t        zlpeta;
   Double_t        zlpphi;
   Double_t        zlpe;

   // List of branches
   TBranch        *b_events_id;   //!
   TBranch        *b_events_bx;   //!
   TBranch        *b_events_lb;   //!
   TBranch        *b_events_run;   //!
   TBranch        *b_events_l1Result;   //!
   TBranch        *b_events_l1ET;   //!
   TBranch        *b_events_l1MET;   //!
   TBranch        *b_events_l1ETPhi;   //!
   TBranch        *b_events_l1HT;   //!
   TBranch        *b_events_l1MHT;   //!
   TBranch        *b_events_l1HTPhi;   //!
   TBranch        *b_events_hltResult1;   //!
   TBranch        *b_events_hltResult2;   //!
   TBranch        *b_events_hltResult3;   //!
   TBranch        *b_events_hltResult4;   //!
   TBranch        *b_events_metflag0;   //!
   TBranch        *b_events_metflag1;   //!
   TBranch        *b_events_metflag2;   //!
   TBranch        *b_events_metflag3;   //!
   TBranch        *b_events_metflag4;   //!
   TBranch        *b_events_metflag5;   //!
   TBranch        *b_events_metflag6;   //!
   TBranch        *b_events_metflag7;   //!
   TBranch        *b_events_metflag8;   //!
   TBranch        *b_events_jet1Index;   //!
   TBranch        *b_events_jet1Pt;   //!
   TBranch        *b_events_jet1Eta;   //!
   TBranch        *b_events_jet1Phi;   //!
   TBranch        *b_events_jet1M;   //!
   TBranch        *b_events_jet1PUMVA;   //!
   TBranch        *b_events_jet1PUFlag;   //!
   TBranch        *b_events_jet1unc;   //!
   TBranch        *b_events_jet1DeltaT;   //!
   TBranch        *b_events_jet2Index;   //!
   TBranch        *b_events_jet2Pt;   //!
   TBranch        *b_events_jet2Eta;   //!
   TBranch        *b_events_jet2Phi;   //!
   TBranch        *b_events_jet2M;   //!
   TBranch        *b_events_jet2PUMVA;   //!
   TBranch        *b_events_jet2PUFlag;   //!
   TBranch        *b_events_jet2unc;   //!
   TBranch        *b_events_jet2DeltaT;   //!
   TBranch        *b_events_met;   //!
   TBranch        *b_events_metPhi;   //!
   TBranch        *b_events_jmDPhi;   //!
   TBranch        *b_events_jmDPhiN1;   //!
   TBranch        *b_events_jmDPhiN2;   //!
   TBranch        *b_events_jmDPhiNMin;   //!
   TBranch        *b_events_metNoMuon;   //!
   TBranch        *b_events_metNoMuonPhi;   //!
   TBranch        *b_events_metNoElectron;   //!
   TBranch        *b_events_metNoElectronPhi;   //!
   TBranch        *b_events_metNo2Muon;   //!
   TBranch        *b_events_metNo2MuonPhi;   //!
   TBranch        *b_events_jmNo2MuonDPhi;   //!
   TBranch        *b_events_jmNo2MuonDPhiN1;   //!
   TBranch        *b_events_jmNo2MuonDPhiN2;   //!
   TBranch        *b_events_jmNo2MuonDPhiNMin;   //!
   TBranch        *b_events_metNoWLepton;   //!
   TBranch        *b_events_metNoWLeptonPhi;   //!
   TBranch        *b_events_jmNoWLeptonDPhi;   //!
   TBranch        *b_events_jmNoWLeptonDPhiN1;   //!
   TBranch        *b_events_jmNoWLeptonDPhiN2;   //!
   TBranch        *b_events_jmNoWLeptonDPhiNMin;   //!
   TBranch        *b_events_mht;   //!
   TBranch        *b_events_mhtPhi;   //!
   TBranch        *b_events_vbfEt;   //!
   TBranch        *b_events_vbfEta;   //!
   TBranch        *b_events_vbfPhi;   //!
   TBranch        *b_events_vbfM;   //!
   TBranch        *b_events_vbfDEta;   //!
   TBranch        *b_events_vbfDPhi;   //!
   TBranch        *b_events_numTrackerJet3;   //!
   TBranch        *b_events_jet3Et;   //!
   TBranch        *b_events_jet3Eta;   //!
   TBranch        *b_events_jet3Phi;   //!
   TBranch        *b_events_jet3M;   //!
   TBranch        *b_events_jet3EtaStar;   //!
   TBranch        *b_events_cenJetEt;   //!
   TBranch        *b_events_cenJetEta;   //!
   TBranch        *b_events_cenJetPhi;   //!
   TBranch        *b_events_cenJetM;   //!
   TBranch        *b_events_cenJetEtaStar;   //!
   TBranch        *b_events_ele1Pt;   //!
   TBranch        *b_events_ele1Eta;   //!
   TBranch        *b_events_ele1Phi;   //!
   TBranch        *b_events_ele1M;   //!
   TBranch        *b_events_ele2Pt;   //!
   TBranch        *b_events_ele2Eta;   //!
   TBranch        *b_events_ele2Phi;   //!
   TBranch        *b_events_ele2M;   //!
   TBranch        *b_events_ele3Pt;   //!
   TBranch        *b_events_ele3Eta;   //!
   TBranch        *b_events_ele3Phi;   //!
   TBranch        *b_events_ele3M;   //!
   TBranch        *b_events_mu1Pt;   //!
   TBranch        *b_events_mu1Eta;   //!
   TBranch        *b_events_mu1Phi;   //!
   TBranch        *b_events_mu1M;   //!
   TBranch        *b_events_mu2Pt;   //!
   TBranch        *b_events_mu2Eta;   //!
   TBranch        *b_events_mu2Phi;   //!
   TBranch        *b_events_mu2M;   //!
   TBranch        *b_events_mu3Pt;   //!
   TBranch        *b_events_mu3Eta;   //!
   TBranch        *b_events_mu3Phi;   //!
   TBranch        *b_events_mu3M;   //!
   TBranch        *b_events_nTaus_tot;   //!
   TBranch        *b_events_nTaus_pass;   //!
   TBranch        *b_events_tau_dz;   //!
   TBranch        *b_events_tau1Pt;   //!
   TBranch        *b_events_tau1Eta;   //!
   TBranch        *b_events_tau1Phi;   //!
   TBranch        *b_events_tau1M;   //!
   TBranch        *b_events_tau1mT;   //!
   TBranch        *b_events_tau1dR;   //!
   TBranch        *b_events_tau2Pt;   //!
   TBranch        *b_events_tau2Eta;   //!
   TBranch        *b_events_tau2Phi;   //!
   TBranch        *b_events_tau2M;   //!
   TBranch        *b_events_tau2mT;   //!
   TBranch        *b_events_nTaus_match;   //!
   TBranch        *b_events_nW;   //!
   TBranch        *b_events_wPt;   //!
   TBranch        *b_events_wEta;   //!
   TBranch        *b_events_wPhi;   //!
   TBranch        *b_events_wMt;   //!
   TBranch        *b_events_wChannel;   //!
   TBranch        *b_events_wDaulPt;   //!
   TBranch        *b_events_wDaulEta;   //!
   TBranch        *b_events_wDaulPhi;   //!
   TBranch        *b_events_wDaulM;   //!
   TBranch        *b_events_wDaulCharge;   //!
   TBranch        *b_events_nZ;   //!
   TBranch        *b_events_zPt;   //!
   TBranch        *b_events_zEta;   //!
   TBranch        *b_events_zPhi;   //!
   TBranch        *b_events_zMass;   //!
   TBranch        *b_events_zChannel;   //!
   TBranch        *b_events_zDau1Pt;   //!
   TBranch        *b_events_zDau1Eta;   //!
   TBranch        *b_events_zDau1Phi;   //!
   TBranch        *b_events_zDau1M;   //!
   TBranch        *b_events_zDau1Charge;   //!
   TBranch        *b_events_zDau2Pt;   //!
   TBranch        *b_events_zDau2Eta;   //!
   TBranch        *b_events_zDau2Phi;   //!
   TBranch        *b_events_zDau2M;   //!
   TBranch        *b_events_zDau2Charge;   //!
   TBranch        *b_events_nVtx;   //!
   TBranch        *b_events_puWeight;   //!
   TBranch        *b_events_trigCorrWeight;   //!
   TBranch        *b_events_mcHiggsMass;   //!
   TBranch        *b_events_mcHiggsPt;   //!
   TBranch        *b_events_mcHiggsEta;   //!
   TBranch        *b_events_mcHiggsPhi;   //!
   TBranch        *b_events_mcQ1Pt;   //!
   TBranch        *b_events_mcQ1Eta;   //!
   TBranch        *b_events_mcQ1Phi;   //!
   TBranch        *b_events_mcQ1M;   //!
   TBranch        *b_events_mcQ2Pt;   //!
   TBranch        *b_events_mcQ2Eta;   //!
   TBranch        *b_events_mcQ2Phi;   //!
   TBranch        *b_events_mcQ2M;   //!
   TBranch        *b_events_mcVBFEt;   //!
   TBranch        *b_events_mcVBFEta;   //!
   TBranch        *b_events_mcVBFPhi;   //!
   TBranch        *b_events_mcVBFM;   //!
   TBranch        *b_events_mcVBFDEta;   //!
   TBranch        *b_events_mcVBFDPhi;   //!
   TBranch        *b_events_wgennj;   //!
   TBranch        *b_events_wgenmass;   //!
   TBranch        *b_events_wgenpt;   //!
   TBranch        *b_events_wgenmt;   //!
   TBranch        *b_events_wgeneta;   //!
   TBranch        *b_events_wgenphi;   //!
   TBranch        *b_events_wgene;   //!
   TBranch        *b_events_wltype;   //!
   TBranch        *b_events_wlpt;   //!
   TBranch        *b_events_wleta;   //!
   TBranch        *b_events_wlphi;   //!
   TBranch        *b_events_wle;   //!
   TBranch        *b_events_wtauhadron;   //!
   TBranch        *b_events_wmetpt;   //!
   TBranch        *b_events_wmeteta;   //!
   TBranch        *b_events_wmetphi;   //!
   TBranch        *b_events_wmete;   //!
   TBranch        *b_events_zgenmass;   //!
   TBranch        *b_events_zgenpt;   //!
   TBranch        *b_events_zgenmt;   //!
   TBranch        *b_events_zgeneta;   //!
   TBranch        *b_events_zgenphi;   //!
   TBranch        *b_events_zgene;   //!
   TBranch        *b_events_zltype;   //!
   TBranch        *b_events_zlmpt;   //!
   TBranch        *b_events_zlmeta;   //!
   TBranch        *b_events_zlmphi;   //!
   TBranch        *b_events_zlme;   //!
   TBranch        *b_events_zlppt;   //!
   TBranch        *b_events_zlpeta;   //!
   TBranch        *b_events_zlpphi;   //!
   TBranch        *b_events_zlpe;   //!

   NtupleAnalysis(TTree *tree=0);
   virtual ~NtupleAnalysis();
   virtual Int_t    Cut();
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     processEvents();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);   
   
 private: 

   // RECO Level
   TH1D* hNJets;
   TH1D* hJet1Pt;
   TH1D* hJet1Eta;
   TH1D* hJet2Pt;
   TH1D* hJet2Eta;
   TH1D* hvbfDEta;
   TH1D* hvbfDPhi;
   TH1D* hvbfM;
   TH1D* hMET;
   TH1D* hcenJetEt;
   

   // GEN Level
   TH1D* hgenJet1Pt;
   TH1D* hgenJet1Eta;
   TH1D* hgenJet2Pt;
   TH1D* hgenJet2Eta;
   TH1D* hgenVBFDEta;
   TH1D* hgenVBFDPhi;
   TH1D* hgenVBFM;
    
   // Parton Level
   TH1D* hgenQ1PT;
   TH1D* hgenQ1Eta;
   TH1D* hgenQ2PT;
   TH1D* hgenQ2Eta;
   TH1D* hgenDEta;
   TH1D* hgenDPhi;
   TH1D* hgenVBFMParton;
   
   // Parton Level GEN
   TH1D* hgenQ1PTcuts;
   TH1D* hgenQ1Etacuts;
   TH1D* hgenQ2PTcuts;
   TH1D* hgenQ2Etacuts;
   TH1D* hgenDEtacuts;
   TH1D* hgenDPhicuts;
   TH1D* hgenVBFMPartoncuts;

   
   // N-1 Histograms
   TH1D* h_Mjj;
   TH1D* h_DeltaEta;
   TH1D* h_DeltaPhi;
   TH1D* h_Jet1Eta;
   TH1D* h_Jet2Eta;
   TH1D* h_MET;
   TH1D* h_Jet1PT;
   TH1D* h_Jet2PT;
   TH1D* h_EtaDP;
   TH1D* h_cenJetEta;
   TH1D* h_cenJetEt;
   TH1D* h_Njets;

   // Precut histograms
   TH1D* hMjj_precut;
   TH1D* hDeltaEta_precut;
   TH1D* hDeltaPhi_precut;
   TH1D* hJet1Eta_precut;
   TH1D* hJet2Eta_precut;
   TH1D* hJet1PT_precut;
   TH1D* hJet2PT_precut;
   TH1D* hCJEt_precut;
   TH1D* hEtaDP_precut;

};

#endif

#ifdef NtupleAnalysis_cxx
NtupleAnalysis::NtupleAnalysis(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("SignalM125_POWHEG.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("SignalM125_POWHEG.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("SignalM125_POWHEG.root:/invHiggsInfo");
      dir->GetObject("InvHiggsInfo",tree);

   }
   Init(tree);
}

NtupleAnalysis::~NtupleAnalysis()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t NtupleAnalysis::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t NtupleAnalysis::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void NtupleAnalysis::Init(TTree *tree)
{

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("id", &id, &b_events_id);
   fChain->SetBranchAddress("bx", &bx, &b_events_bx);
   fChain->SetBranchAddress("lb", &lb, &b_events_lb);
   fChain->SetBranchAddress("run", &run, &b_events_run);
   fChain->SetBranchAddress("l1Result", &l1Result, &b_events_l1Result);
   fChain->SetBranchAddress("l1ET", &l1ET, &b_events_l1ET);
   fChain->SetBranchAddress("l1MET", &l1MET, &b_events_l1MET);
   fChain->SetBranchAddress("l1ETPhi", &l1ETPhi, &b_events_l1ETPhi);
   fChain->SetBranchAddress("l1HT", &l1HT, &b_events_l1HT);
   fChain->SetBranchAddress("l1MHT", &l1MHT, &b_events_l1MHT);
   fChain->SetBranchAddress("l1HTPhi", &l1HTPhi, &b_events_l1HTPhi);
   fChain->SetBranchAddress("hltResult1", &hltResult1, &b_events_hltResult1);
   fChain->SetBranchAddress("hltResult2", &hltResult2, &b_events_hltResult2);
   fChain->SetBranchAddress("hltResult3", &hltResult3, &b_events_hltResult3);
   fChain->SetBranchAddress("hltResult4", &hltResult4, &b_events_hltResult4);
   fChain->SetBranchAddress("metflag0", &metflag0, &b_events_metflag0);
   fChain->SetBranchAddress("metflag1", &metflag1, &b_events_metflag1);
   fChain->SetBranchAddress("metflag2", &metflag2, &b_events_metflag2);
   fChain->SetBranchAddress("metflag3", &metflag3, &b_events_metflag3);
   fChain->SetBranchAddress("metflag4", &metflag4, &b_events_metflag4);
   fChain->SetBranchAddress("metflag5", &metflag5, &b_events_metflag5);
   fChain->SetBranchAddress("metflag6", &metflag6, &b_events_metflag6);
   fChain->SetBranchAddress("metflag7", &metflag7, &b_events_metflag7);
   fChain->SetBranchAddress("metflag8", &metflag8, &b_events_metflag8);
   fChain->SetBranchAddress("jet1Index", &jet1Index, &b_events_jet1Index);
   fChain->SetBranchAddress("jet1Pt", &jet1Pt, &b_events_jet1Pt);
   fChain->SetBranchAddress("jet1Eta", &jet1Eta, &b_events_jet1Eta);
   fChain->SetBranchAddress("jet1Phi", &jet1Phi, &b_events_jet1Phi);
   fChain->SetBranchAddress("jet1M", &jet1M, &b_events_jet1M);
   fChain->SetBranchAddress("jet1PUMVA", &jet1PUMVA, &b_events_jet1PUMVA);
   fChain->SetBranchAddress("jet1PUFlag", &jet1PUFlag, &b_events_jet1PUFlag);
   fChain->SetBranchAddress("jet1unc", &jet1unc, &b_events_jet1unc);
   fChain->SetBranchAddress("jet1DeltaT", &jet1DeltaT, &b_events_jet1DeltaT);
   fChain->SetBranchAddress("jet2Index", &jet2Index, &b_events_jet2Index);
   fChain->SetBranchAddress("jet2Pt", &jet2Pt, &b_events_jet2Pt);
   fChain->SetBranchAddress("jet2Eta", &jet2Eta, &b_events_jet2Eta);
   fChain->SetBranchAddress("jet2Phi", &jet2Phi, &b_events_jet2Phi);
   fChain->SetBranchAddress("jet2M", &jet2M, &b_events_jet2M);
   fChain->SetBranchAddress("jet2PUMVA", &jet2PUMVA, &b_events_jet2PUMVA);
   fChain->SetBranchAddress("jet2PUFlag", &jet2PUFlag, &b_events_jet2PUFlag);
   fChain->SetBranchAddress("jet2unc", &jet2unc, &b_events_jet2unc);
   fChain->SetBranchAddress("jet2DeltaT", &jet2DeltaT, &b_events_jet2DeltaT);
   fChain->SetBranchAddress("met", &met, &b_events_met);
   fChain->SetBranchAddress("metPhi", &metPhi, &b_events_metPhi);
   fChain->SetBranchAddress("jmDPhi", &jmDPhi, &b_events_jmDPhi);
   fChain->SetBranchAddress("jmDPhiN1", &jmDPhiN1, &b_events_jmDPhiN1);
   fChain->SetBranchAddress("jmDPhiN2", &jmDPhiN2, &b_events_jmDPhiN2);
   fChain->SetBranchAddress("jmDPhiNMin", &jmDPhiNMin, &b_events_jmDPhiNMin);
   fChain->SetBranchAddress("metNoMuon", &metNoMuon, &b_events_metNoMuon);
   fChain->SetBranchAddress("metNoMuonPhi", &metNoMuonPhi, &b_events_metNoMuonPhi);
   fChain->SetBranchAddress("metNoElectron", &metNoElectron, &b_events_metNoElectron);
   fChain->SetBranchAddress("metNoElectronPhi", &metNoElectronPhi, &b_events_metNoElectronPhi);
   fChain->SetBranchAddress("metNo2Muon", &metNo2Muon, &b_events_metNo2Muon);
   fChain->SetBranchAddress("metNo2MuonPhi", &metNo2MuonPhi, &b_events_metNo2MuonPhi);
   fChain->SetBranchAddress("jmNo2MuonDPhi", &jmNo2MuonDPhi, &b_events_jmNo2MuonDPhi);
   fChain->SetBranchAddress("jmNo2MuonDPhiN1", &jmNo2MuonDPhiN1, &b_events_jmNo2MuonDPhiN1);
   fChain->SetBranchAddress("jmNo2MuonDPhiN2", &jmNo2MuonDPhiN2, &b_events_jmNo2MuonDPhiN2);
   fChain->SetBranchAddress("jmNo2MuonDPhiNMin", &jmNo2MuonDPhiNMin, &b_events_jmNo2MuonDPhiNMin);
   fChain->SetBranchAddress("metNoWLepton", &metNoWLepton, &b_events_metNoWLepton);
   fChain->SetBranchAddress("metNoWLeptonPhi", &metNoWLeptonPhi, &b_events_metNoWLeptonPhi);
   fChain->SetBranchAddress("jmNoWLeptonDPhi", &jmNoWLeptonDPhi, &b_events_jmNoWLeptonDPhi);
   fChain->SetBranchAddress("jmNoWLeptonDPhiN1", &jmNoWLeptonDPhiN1, &b_events_jmNoWLeptonDPhiN1);
   fChain->SetBranchAddress("jmNoWLeptonDPhiN2", &jmNoWLeptonDPhiN2, &b_events_jmNoWLeptonDPhiN2);
   fChain->SetBranchAddress("jmNoWLeptonDPhiNMin", &jmNoWLeptonDPhiNMin, &b_events_jmNoWLeptonDPhiNMin);
   fChain->SetBranchAddress("mht", &mht, &b_events_mht);
   fChain->SetBranchAddress("mhtPhi", &mhtPhi, &b_events_mhtPhi);
   fChain->SetBranchAddress("vbfEt", &vbfEt, &b_events_vbfEt);
   fChain->SetBranchAddress("vbfEta", &vbfEta, &b_events_vbfEta);
   fChain->SetBranchAddress("vbfPhi", &vbfPhi, &b_events_vbfPhi);
   fChain->SetBranchAddress("vbfM", &vbfM, &b_events_vbfM);
   fChain->SetBranchAddress("vbfDEta", &vbfDEta, &b_events_vbfDEta);
   fChain->SetBranchAddress("vbfDPhi", &vbfDPhi, &b_events_vbfDPhi);
   fChain->SetBranchAddress("numTrackerJet3", &numTrackerJet3, &b_events_numTrackerJet3);
   fChain->SetBranchAddress("jet3Et", &jet3Et, &b_events_jet3Et);
   fChain->SetBranchAddress("jet3Eta", &jet3Eta, &b_events_jet3Eta);
   fChain->SetBranchAddress("jet3Phi", &jet3Phi, &b_events_jet3Phi);
   fChain->SetBranchAddress("jet3M", &jet3M, &b_events_jet3M);
   fChain->SetBranchAddress("jet3EtaStar", &jet3EtaStar, &b_events_jet3EtaStar);
   fChain->SetBranchAddress("cenJetEt", &cenJetEt, &b_events_cenJetEt);
   fChain->SetBranchAddress("cenJetEta", &cenJetEta, &b_events_cenJetEta);
   fChain->SetBranchAddress("cenJetPhi", &cenJetPhi, &b_events_cenJetPhi);
   fChain->SetBranchAddress("cenJetM", &cenJetM, &b_events_cenJetM);
   fChain->SetBranchAddress("cenJetEtaStar", &cenJetEtaStar, &b_events_cenJetEtaStar);
   fChain->SetBranchAddress("ele1Pt", &ele1Pt, &b_events_ele1Pt);
   fChain->SetBranchAddress("ele1Eta", &ele1Eta, &b_events_ele1Eta);
   fChain->SetBranchAddress("ele1Phi", &ele1Phi, &b_events_ele1Phi);
   fChain->SetBranchAddress("ele1M", &ele1M, &b_events_ele1M);
   fChain->SetBranchAddress("ele2Pt", &ele2Pt, &b_events_ele2Pt);
   fChain->SetBranchAddress("ele2Eta", &ele2Eta, &b_events_ele2Eta);
   fChain->SetBranchAddress("ele2Phi", &ele2Phi, &b_events_ele2Phi);
   fChain->SetBranchAddress("ele2M", &ele2M, &b_events_ele2M);
   fChain->SetBranchAddress("ele3Pt", &ele3Pt, &b_events_ele3Pt);
   fChain->SetBranchAddress("ele3Eta", &ele3Eta, &b_events_ele3Eta);
   fChain->SetBranchAddress("ele3Phi", &ele3Phi, &b_events_ele3Phi);
   fChain->SetBranchAddress("ele3M", &ele3M, &b_events_ele3M);
   fChain->SetBranchAddress("mu1Pt", &mu1Pt, &b_events_mu1Pt);
   fChain->SetBranchAddress("mu1Eta", &mu1Eta, &b_events_mu1Eta);
   fChain->SetBranchAddress("mu1Phi", &mu1Phi, &b_events_mu1Phi);
   fChain->SetBranchAddress("mu1M", &mu1M, &b_events_mu1M);
   fChain->SetBranchAddress("mu2Pt", &mu2Pt, &b_events_mu2Pt);
   fChain->SetBranchAddress("mu2Eta", &mu2Eta, &b_events_mu2Eta);
   fChain->SetBranchAddress("mu2Phi", &mu2Phi, &b_events_mu2Phi);
   fChain->SetBranchAddress("mu2M", &mu2M, &b_events_mu2M);
   fChain->SetBranchAddress("mu3Pt", &mu3Pt, &b_events_mu3Pt);
   fChain->SetBranchAddress("mu3Eta", &mu3Eta, &b_events_mu3Eta);
   fChain->SetBranchAddress("mu3Phi", &mu3Phi, &b_events_mu3Phi);
   fChain->SetBranchAddress("mu3M", &mu3M, &b_events_mu3M);
   fChain->SetBranchAddress("nTaus_tot", &nTaus_tot, &b_events_nTaus_tot);
   fChain->SetBranchAddress("nTaus_pass", &nTaus_pass, &b_events_nTaus_pass);
   fChain->SetBranchAddress("tau_dz", &tau_dz, &b_events_tau_dz);
   fChain->SetBranchAddress("tau1Pt", &tau1Pt, &b_events_tau1Pt);
   fChain->SetBranchAddress("tau1Eta", &tau1Eta, &b_events_tau1Eta);
   fChain->SetBranchAddress("tau1Phi", &tau1Phi, &b_events_tau1Phi);
   fChain->SetBranchAddress("tau1M", &tau1M, &b_events_tau1M);
   fChain->SetBranchAddress("tau1mT", &tau1mT, &b_events_tau1mT);
   fChain->SetBranchAddress("tau1dR", &tau1dR, &b_events_tau1dR);
   fChain->SetBranchAddress("tau2Pt", &tau2Pt, &b_events_tau2Pt);
   fChain->SetBranchAddress("tau2Eta", &tau2Eta, &b_events_tau2Eta);
   fChain->SetBranchAddress("tau2Phi", &tau2Phi, &b_events_tau2Phi);
   fChain->SetBranchAddress("tau2M", &tau2M, &b_events_tau2M);
   fChain->SetBranchAddress("tau2mT", &tau2mT, &b_events_tau2mT);
   fChain->SetBranchAddress("nTaus_match", &nTaus_match, &b_events_nTaus_match);
   fChain->SetBranchAddress("nW", &nW, &b_events_nW);
   fChain->SetBranchAddress("wPt", &wPt, &b_events_wPt);
   fChain->SetBranchAddress("wEta", &wEta, &b_events_wEta);
   fChain->SetBranchAddress("wPhi", &wPhi, &b_events_wPhi);
   fChain->SetBranchAddress("wMt", &wMt, &b_events_wMt);
   fChain->SetBranchAddress("wChannel", &wChannel, &b_events_wChannel);
   fChain->SetBranchAddress("wDaulPt", &wDaulPt, &b_events_wDaulPt);
   fChain->SetBranchAddress("wDaulEta", &wDaulEta, &b_events_wDaulEta);
   fChain->SetBranchAddress("wDaulPhi", &wDaulPhi, &b_events_wDaulPhi);
   fChain->SetBranchAddress("wDaulM", &wDaulM, &b_events_wDaulM);
   fChain->SetBranchAddress("wDaulCharge", &wDaulCharge, &b_events_wDaulCharge);
   fChain->SetBranchAddress("nZ", &nZ, &b_events_nZ);
   fChain->SetBranchAddress("zPt", &zPt, &b_events_zPt);
   fChain->SetBranchAddress("zEta", &zEta, &b_events_zEta);
   fChain->SetBranchAddress("zPhi", &zPhi, &b_events_zPhi);
   fChain->SetBranchAddress("zMass", &zMass, &b_events_zMass);
   fChain->SetBranchAddress("zChannel", &zChannel, &b_events_zChannel);
   fChain->SetBranchAddress("zDau1Pt", &zDau1Pt, &b_events_zDau1Pt);
   fChain->SetBranchAddress("zDau1Eta", &zDau1Eta, &b_events_zDau1Eta);
   fChain->SetBranchAddress("zDau1Phi", &zDau1Phi, &b_events_zDau1Phi);
   fChain->SetBranchAddress("zDau1M", &zDau1M, &b_events_zDau1M);
   fChain->SetBranchAddress("zDau1Charge", &zDau1Charge, &b_events_zDau1Charge);
   fChain->SetBranchAddress("zDau2Pt", &zDau2Pt, &b_events_zDau2Pt);
   fChain->SetBranchAddress("zDau2Eta", &zDau2Eta, &b_events_zDau2Eta);
   fChain->SetBranchAddress("zDau2Phi", &zDau2Phi, &b_events_zDau2Phi);
   fChain->SetBranchAddress("zDau2M", &zDau2M, &b_events_zDau2M);
   fChain->SetBranchAddress("zDau2Charge", &zDau2Charge, &b_events_zDau2Charge);
   fChain->SetBranchAddress("nVtx", &nVtx, &b_events_nVtx);
   fChain->SetBranchAddress("puWeight", &puWeight, &b_events_puWeight);
   fChain->SetBranchAddress("trigCorrWeight", &trigCorrWeight, &b_events_trigCorrWeight);
   fChain->SetBranchAddress("mcHiggsMass", &mcHiggsMass, &b_events_mcHiggsMass);
   fChain->SetBranchAddress("mcHiggsPt", &mcHiggsPt, &b_events_mcHiggsPt);
   fChain->SetBranchAddress("mcHiggsEta", &mcHiggsEta, &b_events_mcHiggsEta);
   fChain->SetBranchAddress("mcHiggsPhi", &mcHiggsPhi, &b_events_mcHiggsPhi);
   fChain->SetBranchAddress("mcQ1Pt", &mcQ1Pt, &b_events_mcQ1Pt);
   fChain->SetBranchAddress("mcQ1Eta", &mcQ1Eta, &b_events_mcQ1Eta);
   fChain->SetBranchAddress("mcQ1Phi", &mcQ1Phi, &b_events_mcQ1Phi);
   fChain->SetBranchAddress("mcQ1M", &mcQ1M, &b_events_mcQ1M);
   fChain->SetBranchAddress("mcQ2Pt", &mcQ2Pt, &b_events_mcQ2Pt);
   fChain->SetBranchAddress("mcQ2Eta", &mcQ2Eta, &b_events_mcQ2Eta);
   fChain->SetBranchAddress("mcQ2Phi", &mcQ2Phi, &b_events_mcQ2Phi);
   fChain->SetBranchAddress("mcQ2M", &mcQ2M, &b_events_mcQ2M);
   fChain->SetBranchAddress("mcVBFEt", &mcVBFEt, &b_events_mcVBFEt);
   fChain->SetBranchAddress("mcVBFEta", &mcVBFEta, &b_events_mcVBFEta);
   fChain->SetBranchAddress("mcVBFPhi", &mcVBFPhi, &b_events_mcVBFPhi);
   fChain->SetBranchAddress("mcVBFM", &mcVBFM, &b_events_mcVBFM);
   fChain->SetBranchAddress("mcVBFDEta", &mcVBFDEta, &b_events_mcVBFDEta);
   fChain->SetBranchAddress("mcVBFDPhi", &mcVBFDPhi, &b_events_mcVBFDPhi);
   fChain->SetBranchAddress("wgennj", &wgennj, &b_events_wgennj);
   fChain->SetBranchAddress("wgenmass", &wgenmass, &b_events_wgenmass);
   fChain->SetBranchAddress("wgenpt", &wgenpt, &b_events_wgenpt);
   fChain->SetBranchAddress("wgenmt", &wgenmt, &b_events_wgenmt);
   fChain->SetBranchAddress("wgeneta", &wgeneta, &b_events_wgeneta);
   fChain->SetBranchAddress("wgenphi", &wgenphi, &b_events_wgenphi);
   fChain->SetBranchAddress("wgene", &wgene, &b_events_wgene);
   fChain->SetBranchAddress("wltype", &wltype, &b_events_wltype);
   fChain->SetBranchAddress("wlpt", &wlpt, &b_events_wlpt);
   fChain->SetBranchAddress("wleta", &wleta, &b_events_wleta);
   fChain->SetBranchAddress("wlphi", &wlphi, &b_events_wlphi);
   fChain->SetBranchAddress("wle", &wle, &b_events_wle);
   fChain->SetBranchAddress("wtauhadron", &wtauhadron, &b_events_wtauhadron);
   fChain->SetBranchAddress("wmetpt", &wmetpt, &b_events_wmetpt);
   fChain->SetBranchAddress("wmeteta", &wmeteta, &b_events_wmeteta);
   fChain->SetBranchAddress("wmetphi", &wmetphi, &b_events_wmetphi);
   fChain->SetBranchAddress("wmete", &wmete, &b_events_wmete);
   fChain->SetBranchAddress("zgenmass", &zgenmass, &b_events_zgenmass);
   fChain->SetBranchAddress("zgenpt", &zgenpt, &b_events_zgenpt);
   fChain->SetBranchAddress("zgenmt", &zgenmt, &b_events_zgenmt);
   fChain->SetBranchAddress("zgeneta", &zgeneta, &b_events_zgeneta);
   fChain->SetBranchAddress("zgenphi", &zgenphi, &b_events_zgenphi);
   fChain->SetBranchAddress("zgene", &zgene, &b_events_zgene);
   fChain->SetBranchAddress("zltype", &zltype, &b_events_zltype);
   fChain->SetBranchAddress("zlmpt", &zlmpt, &b_events_zlmpt);
   fChain->SetBranchAddress("zlmeta", &zlmeta, &b_events_zlmeta);
   fChain->SetBranchAddress("zlmphi", &zlmphi, &b_events_zlmphi);
   fChain->SetBranchAddress("zlme", &zlme, &b_events_zlme);
   fChain->SetBranchAddress("zlppt", &zlppt, &b_events_zlppt);
   fChain->SetBranchAddress("zlpeta", &zlpeta, &b_events_zlpeta);
   fChain->SetBranchAddress("zlpphi", &zlpphi, &b_events_zlpphi);
   fChain->SetBranchAddress("zlpe", &zlpe, &b_events_zlpe);
   Notify();
}

Bool_t NtupleAnalysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void NtupleAnalysis::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t NtupleAnalysis::Cut()
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef NtupleAnalysis_cxx
