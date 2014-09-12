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
// 99877 Total Events
// xsec = 1.578 fb
// Int Lumi => 99877/1.578 = 63.29 1/fb
// Dataset int lumi = 19.5 1/fb ==> weight of 19.6/63.29 = 0.308

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
#include <fstream>
#include <stdlib.h>
#include <TMath.h>

#include "Selection.h"
#include "AnalysisCuts.h"

class ExRootTreeReader;
class ExRootResult;

using namespace std;

int Surviving_events;
int nTrigger, nJet1PT, nJet2PT, nJet1Eta, nJet2Eta, nEtaDP, nEta, nDPhi, nMET, nJetMass, nDEta, nCJV;
int n_Trigger, n_JetPT, n_EtaDP, n_DPhi, n_MET, n_JetMass, n_DEta, n_CJV;
int nYield0, nYield1, nYield2, nYield3, nYield4, nYield5, nYield6, nYield7, nYield8, nYield9;
int ANyield0, ANyield1, ANyield2, ANyield3, ANyield4, ANyield5, ANyield6, ANyield7, ANyield8, ANyield9, ANyield10;
int n_TriggerAN, n_METAN, n_EVeto, n_MuVeto, n_JetPTAN, n_EtaDPAN, n_DEtaAN, n_METClean, n_CJVAN, n_DPhiAN, n_MjjAN;


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
   hcenJetEta = new TH1D("cenJetEta","cenJetEta", 50, -10, 10);

   // GEN
   hgenJet1Pt  = new TH1D("genJet1Pt" ,"genJet1Pt" , 80,   0,  400);
   hgenJet1Eta = new TH1D("genJet1Eta","genJet1Eta", 50, -10,   10);
   hgenJet2Pt  = new TH1D("genJet2Pt" , "genJet2Pt", 80,   0,  400);
   hgenJet2Eta = new TH1D("genJet2Eta","genJet2Eta", 50, -10,   10);
   hgenVBFDEta = new TH1D("genVBFDEta","genVBFDEta", 50,   0,   10);
   hgenVBFDPhi = new TH1D("genVBFDPhi","genVBFDphi", 63,   0,    TMath::Pi());
   hgenVBFM    = new TH1D("genVBFM"   ,"genVBFM"   , 40,   0, 4000);
   

   // PARTON
//     mcQ1Pt, mcQ1Eta, mcQ2Pt, mcQ2Eta, mcVBFDEta,mcVBFDPhi,mcVBFM
   hgenQ1PT    = new TH1D("genQ1PT",   "genQ1PT"   , 100,  0,   500);
   hgenQ1Eta   = new TH1D("genQ1Eta",  "genQ1Eta"  , 100,  -6,   6);
   hgenQ2PT    = new TH1D("genQ2PT" ,  "genQ2PT"   , 100,  0,   500);
   hgenQ2Eta   = new TH1D("genQ2Eta",  "genQ2Eta"  , 100,  -6,   6);
   hgenDEta    = new TH1D("genDEta" ,  "genDEta"   , 50,   0,   10);
   hgenDPhi    = new TH1D("genDPhi" ,  "genDPhi"   , 64,   0 , TMath::Pi());
   hgenVBFMParton = new TH1D("genVBFMParton","genVBFMParton", 40, 0 , 4000);

   // PARTON with cuts, identical to VBFNLO samples
   hgenQ1PTcuts    = new TH1D("genQ1PT",   "genQ1PT"   , 100,  0,   500);
   hgenQ1Etacuts   = new TH1D("genQ1Eta",  "genQ1Eta"  , 100,  -6,   6);
   hgenQ2PTcuts    = new TH1D("genQ2PT" ,  "genQ2PT"   , 100,  0,   500);
   hgenQ2Etacuts   = new TH1D("genQ2Eta",  "genQ2Eta"  , 100,  -6,   6);
   hgenDEtacuts    = new TH1D("genDEta" ,  "genDEta"   , 50,   0,   10);
   hgenDPhicuts    = new TH1D("genDPhi" ,  "genDPhi"   , 64,   0 , TMath::Pi());
   hgenVBFMPartoncuts = new TH1D("genVBFMParton","genVBFMParton", 40, 0 , 4000);

   // N-1 Histograms
   h_Mjj        = new TH1D("InvMass","InvMass", 40, 0.0, 4000);
   h_DeltaEta   = new TH1D("DeltaEtaJJ","DeltaEtaJJ", 50, 0.0, 10);
   h_DeltaPhi   = new TH1D("DeltaPhiJJ","DeltaPhiJJ", 63, 0.0, TMath::Pi());
   h_Jet1Eta    = new TH1D("Jet1Eta", "Jet1Eta", 50, -10, 10);
   h_Jet2Eta    = new TH1D("Jet2Eta", "Jet2Eta", 50, -10, 10);
   h_MET        = new TH1D("MET", "MET", 50, 0.0, 500);
   h_Jet1PT     = new TH1D("Jet1PT", "Jet1PT", 80, 0, 400);
   h_Jet2PT     = new TH1D("Jet2PT", "Jet2PT", 80, 0, 400);
   h_EtaDP      = new TH1D("EtaDPjj","EtaDPjj", 50, -10, 2);
   h_cenJetEta  = new TH1D("cenJetEta","cenJetEta", 50, -5, 5);
   h_cenJetEt   = new TH1D("cenJetEt","cenJetEt",30, 0, 150);
   h_Njets      = new TH1D("NJets","NJets",10, 0, 10);
   
   // N-2 histograms
   h2_Mjj        = new TH1D("InvMass","InvMass", 40, 0.0, 4000);
   h2_DeltaEta   = new TH1D("DeltaEtaJJ","DeltaEtaJJ", 50, 0.0, 10);
   h2_DeltaPhi   = new TH1D("DeltaPhiJJ","DeltaPhiJJ", 63, 0.0, TMath::Pi());
   h2_Jet1Eta    = new TH1D("Jet1Eta", "Jet1Eta", 50, -10, 10);
   h2_Jet2Eta    = new TH1D("Jet2Eta", "Jet2Eta", 50, -10, 10);
   h2_MET        = new TH1D("MET", "MET", 50, 0.0, 500);
   h2_Jet1PT     = new TH1D("Jet1PT", "Jet1PT", 80, 0, 400);
   h2_Jet2PT     = new TH1D("Jet2PT", "Jet2PT", 80, 0, 400);
   h2_EtaDP      = new TH1D("EtaDPjj","EtaDPjj", 50, -10, 2);
   h2_cenJetEta  = new TH1D("cenJetEta","cenJetEta", 50, -5, 5);
   h2_cenJetEt   = new TH1D("cenJetEt","cenJetEt",30, 0, 150);
   h2_Njets      = new TH1D("NJets","NJets",10, 0, 10);
   

   // Precut Histograms

   hMjj_precut  = new TH1D("InvMass","InvMass",40, 0., 4000);
   hDeltaEta_precut = new TH1D("DeltaEtaJJ","DeltaEtaJJ", 50, 0, 10);
   hDeltaPhi_precut = new TH1D("DeltaPhiJJ","DeltaPhiJJ",63, 0.0, TMath::Pi());
   hJet1Eta_precut  = new TH1D("Jet1Eta","Jet1Eta", 50, -10, 10);
   hJet2Eta_precut  = new TH1D("Jet2Eta","Jet2Eta", 50, -10, 10);
   hJet1PT_precut   = new TH1D("Jet1PT","Jet1PT", 80, 0, 400);
   hJet2PT_precut   = new TH1D("Jet2PT","Jet2PT", 80, 0, 400);
   hCJEt_precut     = new TH1D("CenJetEt","CenJetEt", 30, 0.0, 150);
   hEtaDP_precut    = new TH1D("EtaDP","EtaDP", 50, -10, 3);
   hMET_precut      = new TH1D("MET", "MET", 50, 0, 500);
   
   // Histograms for excess of events between FullSim Jim and FullSim Dom
   hJetET_excess    = new TH1D("JetPTexcess","JetPTexcess",80, 0, 400);
   hJetEta_excess   = new TH1D("JetEtaexcess","JetEtaexcess",50, -10, 10);
   
   

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
   
      if(jentry % 1000 == 0){
      cout << "******* NEW ENTRY[" << jentry << "]" << endl;
      }

      if( printout ) continue;

      Float_t weight2 = 0.308;

      if( jentry == (nentries - 1) ) {
	  std::cout << "Suriving events follow parton cuts: " << Surviving_events << std::endl;
	  std::cout << "Trigger: " << nYield0*weight2 << "\n dijet Pt: " << nYield1*weight2 << "\n EtaDP: " << nYield2*weight2 << "\n DeltaEta: " << nYield3*weight2 << "\n MET: " << nYield4*weight2 << "\n InvMass: " << nYield5*weight2 << "\n CJVeto: " << nYield6*weight2 << "\n DeltaPhi: " << nYield7*weight2 << "\n Trigger Bit: " << nYield8*weight2 << "\n Excess events: " << nYield9*weight2 << std::endl;

	}
      // Readout of signal yields after AN cut flow
      if( jentry == (nentries - 1) ){
	std::cout << std::endl;
	std::cout << "AN Trigger: "    << ANyield0*weight2 << std::endl;
	std::cout << "AN MET filter: " << ANyield1*weight2 << std::endl;
	std::cout << "AN e veto: "     << ANyield2*weight2 << std::endl;
	std::cout << "AN mu veto: "    << ANyield3*weight2 << std::endl;
	std::cout << "AN dijet pt: "   << ANyield4*weight2 << std::endl;
	std::cout << "AN eta1*eta2: "  << ANyield5*weight2 << std::endl;
	std::cout << "AN DeltaEta: "   << ANyield6*weight2 << std::endl;
	std::cout << "AN MET: "        << ANyield7*weight2 << std::endl;
	std::cout << "AN Mjj: "        << ANyield8*weight2 << std::endl;
	std::cout << "AN CJV: "        << ANyield9*weight2 << std::endl;
	std::cout << "AN DeltaPhi: "   << ANyield10*weight2 << std::endl;
	std::cout << "" << std::endl;
	// Print out # events from N-1
	/*	std::cout << "N-1 nJet1PT: " << nJet1PT << std::endl;
	std::cout << "N-1 nJet2PT: " << nJet2PT << std::endl;
	std::cout << "N-1 nEtaDP: " << nEtaDP << std::endl;
	std::cout << "N-1 nDPhi: " << nDPhi << std::endl;
	std::cout << "N-1 nDEta: " << nDEta << std::endl;
	std::cout << "N-1 nJetMass: " << nJetMass << std::endl;
	std::cout << "N-1 nCJV: " << nCJV << std::endl;
	std::cout << "N-1 Jet1Eta: " << nJet1Eta << std::endl;
	std::cout << "N-1 Jet2Eta: " << nJet2Eta << std::endl;
	std::cout << "N-1 MET: " << nMET << std::endl;
	*/
	std::cout << std::endl;
	std::cout << "Doms cuts" << std::endl;
	std::cout << "Suriving events Trigger: " << n_Trigger*weight2 << std::endl;
	std::cout << "Surviving events DiJetPT : " << n_JetPT*weight2 << std::endl; 
	std::cout << "Surviving events EtaDP : " << n_EtaDP*weight2 << std::endl;
	std::cout << "Surviving events DeltaEta: " << n_DEta*weight2 << std::endl;
	std::cout << "Surviving events MET: " << n_MET*weight2 << std::endl;
	std::cout << "Surviving events Mjj: " << n_JetMass*weight2 << std::endl;
	std::cout << "Surviving events CJV: " << n_CJV*weight2 << std::endl;
	std::cout << "Surviving events DeltaPhi: " << n_DPhi*weight2 << std::endl;
	
	std::cout << std::endl;
	std::cout << "AN cuts (Jim)" << std::endl;
	std::cout << "Surviving events Trigger: " << n_TriggerAN*weight2 << std::endl;
	std::cout << "Surviving events MET clean: " << n_METClean*weight2 << std::endl;
	std::cout << "Surviving events e veto: " << n_EVeto*weight2 << std::endl;
	std::cout << "Surviving events mu veto: " << n_MuVeto*weight2 << std::endl;
	std::cout << "Surviving events DiJetPT: " << n_JetPTAN*weight2 << std::endl;
	std::cout << "Surviving events EtaDP: " << n_EtaDPAN*weight2 << std::endl;
	std::cout << "Surviving events DeltaEta: " << n_DEtaAN*weight2 << std::endl;
	std::cout << "Surviving events MET: " << n_METAN*weight2 << std::endl;
	std::cout << "Surviving events Mjj: " << n_MjjAN*weight2 << std::endl;
	std::cout << "Surviving events CJV: " << n_CJVAN*weight2 << std::endl;
	std::cout << "Surviving events DeltaPhi: " << n_DPhiAN*weight2 << std::endl;
      }
	        
      
      // Compute variables for cuts on GEN level quantities
      // Jets > 30 GeV, InvMass > 600 GeV
      // 

      if( mcQ1Pt > 30 && mcQ2Pt > 30 && mcVBFM > 600 ){

	hgenQ1PTcuts->Fill(mcQ1Pt);
	hgenQ1Etacuts->Fill(mcQ1Eta);
	hgenQ2PTcuts->Fill(mcQ2Pt);
	hgenQ2Etacuts->Fill(mcQ2Eta);
	hgenDEtacuts->Fill(mcVBFDEta);
	hgenDPhicuts->Fill(mcVBFDPhi);
	hgenVBFMPartoncuts->Fill(mcVBFM);
	Surviving_events++;

      }	

      // Want to have the number of events that survive following these cuts

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
      hcenJetEta->Fill(cenJetEta);

      // Fill GEN Level objects to histo
      hgenVBFDEta->Fill(mcVBFDEta);
      hgenVBFDPhi->Fill(mcVBFDPhi);
      hgenVBFM->Fill(mcVBFM);
      
      // Fill PARTON Level objecst to histo

      hgenQ1PT->Fill(mcQ1Pt);
      hgenQ1Eta->Fill(mcQ1Eta);
      hgenQ2PT->Fill(mcQ2Pt);
      hgenQ2Eta->Fill(mcQ2Eta);
      hgenDEta->Fill(mcVBFDEta);
      hgenDPhi->Fill(mcVBFDPhi);
      hgenVBFMParton->Fill(mcVBFM);


      
      
      // Apply Trigger and Offline Cuts on RECO objets to mirror Analysis Note AN-2012-403
      
      Float_t EtaDP = jet1Eta*jet2Eta;
      Int_t njets30 = 0;
      if(jet1Pt > 30){ njets30++; }
      if(jet2Pt > 30){ njets30++; }
      if(jet3Et > 30){ njets30++; } 
      if(cenJetEt > 30){ njets30++; }

      // Parton Level Cuts
      Bool_t PLCuts = Selection::PLCuts(mcQ1Pt,mcQ2Pt,mcVBFM);

      // My Offline cuts

      Bool_t TrigCut    = Selection::TriggerCuts(jet1Pt,jet2Pt,EtaDP,vbfDEta,vbfM,met);
      Bool_t TriggerAN = AnalysisCuts::Trigger(hltResult2); // AN cuts
      Bool_t EtaCut     = Selection::EtaCut(jet1Eta) && Selection::EtaCut(jet2Eta);
      Bool_t JetPTCut   = Selection::JetCut(jet1Pt, jet1Eta, jet2Pt, jet2Eta); // Eta cut incorporated here
      Bool_t EtaDPCut   = Selection::DPEta(jet1Eta, jet2Eta);
      Bool_t DEtaCut    = Selection::DEtaCut(vbfDEta);
      Bool_t METCut     = Selection::METcut(met);
      Bool_t InvMassCut = Selection::MassCut(vbfM);
      Bool_t CJVeto     = Selection::CJVCut(jet1Eta,jet2Eta,cenJetEta,cenJetEt); // Different to AN
      Bool_t CenJetVeto = Selection::CenJetVeto(cenJetEt);
      Bool_t PhiCut     = Selection::PhiCut(vbfDPhi);
            
      if(TrigCut) {  n_Trigger++; }
      if(JetPTCut){  n_JetPT++; }  // Incorportates eta < 4.7 too
      if(EtaDPCut){  n_EtaDP++; }
      if(DEtaCut) {  n_DEta++; }
      if(METCut)  {  n_MET++; }
      if(InvMassCut){ n_JetMass++; }
      if(!CJVeto) {  n_CJV++; }
      if(PhiCut)  {   n_DPhi++; }
      
      // Calculate suriving event yields
      if(TrigCut){ nYield0++; }
      if(TrigCut && JetPTCut){ nYield1++; } // JetPTcut includes eta < 4.7 too
      if(TrigCut && JetPTCut && EtaDPCut){ nYield2++; }
      if(TrigCut && JetPTCut && EtaDPCut && DEtaCut){ nYield3++; }
      if(TrigCut && JetPTCut && EtaDPCut && DEtaCut && METCut){ nYield4++; } 
      if(TrigCut && JetPTCut && EtaDPCut && DEtaCut && METCut && InvMassCut){ nYield5++; }
      if(TrigCut && JetPTCut && EtaDPCut && DEtaCut && METCut && InvMassCut && CenJetVeto){ nYield6++; }
      if(TrigCut && JetPTCut && EtaDPCut && DEtaCut && METCut && InvMassCut && CenJetVeto && PhiCut){ nYield7++; }
      if(TrigCut && JetPTCut && EtaDPCut && DEtaCut && METCut && InvMassCut && CenJetVeto && PhiCut && TriggerAN){ nYield8++; } // Applying the Trigger Bit from the AN
      
      // Want to plot only the excess of events between the FullSim Jim and the FullSim Dom
      if(TrigCut && JetPTCut && EtaDPCut && DEtaCut && METCut && InvMassCut && CenJetVeto && PhiCut && !TriggerAN){
	nYield9++; 
	hJetEta_excess->Fill(jet3Eta); 
	hJetET_excess->Fill(jet3Et); 
	JetEtas.push_back(jet3Eta);
	JetEts.push_back(jet3Et);

	ofstream JetInfo; // Printing jet2 and jet3 contents to file
	JetInfo.open("JetInfo.txt",ios::app);
	JetInfo << "Jet2 Pt: " << jet2Pt << "\n";
	JetInfo << "Jet3 Et: " << jet3Et << "\n";
	JetInfo << "---\n";
	JetInfo << "Jet2 Eta: " << jet2Eta << "\n";
	JetInfo << "Jet3 Eta: " << jet3Eta << "\n";
	JetInfo << "*** NEXT EVENT *** " << "\n\n";
	JetInfo.close();
      }
      

      // Create N-1 Histograms Apply Bit
      if(PLCuts && TrigCut && EtaCut && JetPTCut && EtaDPCut && DEtaCut && METCut && !CJVeto && PhiCut){ h_Mjj->Fill(vbfM); nJetMass++; }
      if(PLCuts && TrigCut && EtaCut && JetPTCut && EtaDPCut && METCut && InvMassCut && !CJVeto && PhiCut){ h_DeltaEta->Fill(vbfDEta); nDEta++;  }
      if(PLCuts && TrigCut && EtaCut && JetPTCut && EtaDPCut && DEtaCut && METCut && InvMassCut && !CJVeto){ h_DeltaPhi->Fill(vbfDPhi); nDPhi++; }
      if(PLCuts && TrigCut && EtaCut && EtaDPCut && DEtaCut && METCut && InvMassCut && !CJVeto && PhiCut){ h_Jet1PT->Fill(jet1Pt); nJet1PT++; }
      if(PLCuts && TrigCut && EtaCut && EtaDPCut && DEtaCut && METCut && InvMassCut && !CJVeto && PhiCut){ h_Jet2PT->Fill(jet2Pt); nJet2PT++; }
      if(PLCuts && TrigCut && EtaDPCut && JetPTCut && DEtaCut && METCut && InvMassCut && !CJVeto && PhiCut){ h_Jet1Eta->Fill(jet1Eta); nJet1Eta++; }
      if(PLCuts && TrigCut && EtaDPCut && JetPTCut && DEtaCut && METCut && InvMassCut && !CJVeto && PhiCut){ h_Jet2Eta->Fill(jet2Eta); nJet2Eta++; }
      if(PLCuts && TrigCut && EtaCut && JetPTCut && DEtaCut && METCut && InvMassCut && !CJVeto && PhiCut){ h_EtaDP->Fill(EtaDP); nEtaDP++; }
      if(PLCuts && TrigCut && EtaCut && JetPTCut && EtaDPCut && DEtaCut && InvMassCut && !CJVeto && PhiCut){ h_MET->Fill(met); nMET++; }
      if(PLCuts && TrigCut && EtaCut && JetPTCut && EtaDPCut && DEtaCut && METCut && InvMassCut && PhiCut){ h_cenJetEta->Fill(cenJetEta); }
      if(PLCuts && TrigCut && EtaCut && JetPTCut && EtaDPCut && DEtaCut && METCut && InvMassCut && PhiCut){ h_cenJetEt->Fill(cenJetEt); nCJV++; } 
      if(PLCuts && TrigCut && EtaCut && JetPTCut && EtaDPCut && DEtaCut && METCut && InvMassCut && !CJVeto && PhiCut){ h_Njets->Fill(njets30); } 
      // All cuts except CJVeto, then plot Et of central jet

      // Create N-2 plots
      if(PLCuts && TriggerAN && EtaCut && JetPTCut && EtaDPCut && DEtaCut && METCut && PhiCut){ h2_Mjj->Fill(vbfM); }
      if(PLCuts && TriggerAN && EtaCut && JetPTCut && EtaDPCut && METCut && InvMassCut && PhiCut){ h2_DeltaEta->Fill(vbfDEta);   }
      if(PLCuts && TriggerAN && EtaCut && JetPTCut && EtaDPCut && DEtaCut && METCut && InvMassCut){ h2_DeltaPhi->Fill(vbfDPhi); }
      if(PLCuts && TriggerAN && EtaCut && EtaDPCut && DEtaCut && METCut && InvMassCut && PhiCut){ h2_Jet1PT->Fill(jet1Pt); }
      if(PLCuts && TriggerAN && EtaCut && EtaDPCut && DEtaCut && METCut && InvMassCut && PhiCut){ h2_Jet2PT->Fill(jet2Pt); }
      if(PLCuts && TriggerAN && EtaDPCut && JetPTCut && DEtaCut && METCut && InvMassCut && PhiCut){ h2_Jet1Eta->Fill(jet1Eta); }
      if(PLCuts && TriggerAN && EtaDPCut && JetPTCut && DEtaCut && METCut && InvMassCut && PhiCut){ h2_Jet2Eta->Fill(jet2Eta); }
      if(PLCuts && TriggerAN && EtaCut && JetPTCut && DEtaCut && METCut && InvMassCut && PhiCut){ h2_EtaDP->Fill(EtaDP); }
      if(PLCuts && TriggerAN && EtaCut && JetPTCut && EtaDPCut && DEtaCut && InvMassCut && PhiCut){ h2_MET->Fill(met); }
      if(PLCuts && TriggerAN && EtaCut && JetPTCut && EtaDPCut && DEtaCut && METCut && InvMassCut && PhiCut){ h2_cenJetEta->Fill(cenJetEta); }
      if(PLCuts && TriggerAN && EtaCut && JetPTCut && EtaDPCut && DEtaCut && METCut && InvMassCut && PhiCut){ h2_cenJetEt->Fill(cenJetEt); } 
      

      // ************* Analysis Note Procedure


      // Applying AN Delicate Cuts
      Bool_t METClean = (metflag0 && metflag1 && metflag2 && metflag3 && metflag4 && metflag5 && metflag6 && metflag7 && metflag8);
      Bool_t EVeto = AnalysisCuts::EVeto(ele1Pt);
      Bool_t MuVeto = AnalysisCuts::MuVeto(mu1Pt);
      Bool_t DijetPair = AnalysisCuts::JJPair(jet1Pt,jet1Eta,jet2Pt,jet2Eta);
      Bool_t FwdBkd = AnalysisCuts::EtaFB(jet1Eta, jet2Eta);
      Bool_t Deltaeta = AnalysisCuts::DeltaEta(vbfDEta);
      Bool_t MET = AnalysisCuts::MET(met);
      Bool_t Mjj = AnalysisCuts::Mjj(vbfM);
      Bool_t CJVeto_AN = AnalysisCuts::CJV(cenJetEt);
      Bool_t DeltaPhi = AnalysisCuts::DeltaPhi(vbfDPhi);

      // Obtain # events after each cut
      if(TriggerAN){ n_TriggerAN++; }
      if(METClean){ n_METClean++; }
      if(EVeto){ n_EVeto++; } 
      if(MuVeto){ n_MuVeto++; }
      if(DijetPair){ n_JetPTAN++; } 
      if(FwdBkd){ n_EtaDPAN++; } 
      if(Deltaeta){ n_DEtaAN++; }
      if(MET){ n_METAN++; }
      if(Mjj){ n_MjjAN++; }
      if(CJVeto_AN){ n_CJVAN++; }
      if(DeltaPhi){ n_DPhiAN++; }

      // Calculate yields
      if(TriggerAN){ ANyield0++; }
      if(TriggerAN && METClean){ ANyield1++; }
      if(TriggerAN && METClean && EVeto){ ANyield2++; }
      if(TriggerAN && METClean && EVeto && MuVeto){ ANyield3++; }
      if(TriggerAN && METClean && EVeto && MuVeto && DijetPair){ ANyield4++; }
      if(TriggerAN && METClean && EVeto && MuVeto && DijetPair && FwdBkd){ ANyield5++; }
      if(TriggerAN && METClean && EVeto && MuVeto && DijetPair && FwdBkd && Deltaeta){ ANyield6++; }
      if(TriggerAN && METClean && EVeto && MuVeto && DijetPair && FwdBkd && Deltaeta && MET){ ANyield7++; }
      if(TriggerAN && METClean && EVeto && MuVeto && DijetPair && FwdBkd && Deltaeta && MET && Mjj){ ANyield8++; }
      if(TriggerAN && METClean && EVeto && MuVeto && DijetPair && FwdBkd && Deltaeta && MET && Mjj && CJVeto_AN){ ANyield9++; }
      if(TriggerAN && METClean && EVeto && MuVeto && DijetPair && FwdBkd && Deltaeta && MET && Mjj && CJVeto_AN && DeltaPhi) { ANyield10++; }

      

      // Filling precut histograms, Parton Level cuts must be applied when comparing between VBFNLO 
      
      if(PLCuts){ hMjj_precut->Fill(vbfM); }
      if(PLCuts){ hDeltaEta_precut->Fill(vbfDEta); }
      if(PLCuts){ hDeltaPhi_precut->Fill(vbfDPhi); }
      if(PLCuts){ hJet1Eta_precut->Fill(jet1Eta); }
      if(PLCuts){ hJet2Eta_precut->Fill(jet2Eta); }
      if(PLCuts){ hJet1PT_precut->Fill(jet1Pt); }
      if(PLCuts){ hJet2PT_precut->Fill(jet2Pt); }
      if(PLCuts){ hCJEt_precut->Fill(cenJetEt); }
      if(PLCuts){ hEtaDP_precut->Fill(EtaDP); }
      if(PLCuts){ hMET_precut->Fill(met); }
      
      
      
      //****** OUTPUT *******
      

      // Outputing histos to file

      // GEN & RECO Level ROOTFILE
      /*      TFile *_rootfile = new TFile("VBF_ntuple_125_weightedTEST.root","RECREATE");
      hJet1Pt->Write();
      hJet1Eta->Write();
      hJet2Pt->Write();
      hJet2Eta->Write();
      hvbfDEta->Write();
      hvbfDPhi->Write();
      hvbfM->Write();
      hMET->Write();
      hcenJetEta->Write();
      hcenJetEt->Write();
      hJetET_excess->Write();
      hJetEta_excess->Write();
      // Close GEN & RECO Level ROOTFILE
      _rootfile->Write();
      _rootfile->Close();
      */
      /*      
      // PARTON Level ROOTFILE
      TFile *_rootfile2 = new TFile("FullSim_ntuple_partonlevel_8TeVTEST.root","RECREATE");
      hgenQ1PT->Write();
      hgenQ1Eta->Write();
      hgenQ2PT->Write();
      hgenQ2Eta->Write();
      hgenDEta->Write();
      hgenDPhi->Write();
      hgenVBFMParton->Write();
      _rootfile2->Write();
      _rootfile2->Close();
      
      TFile *_rootfile3 = new TFile("FullSim_ntuple_partonlevel_withCuts_8TeVTEST.root","RECREATE");
      hgenQ1PTcuts->Write();
      hgenQ1Etacuts->Write();
      hgenQ2PTcuts->Write();
      hgenQ2Etacuts->Write();
      hgenDEtacuts->Write();
      hgenDPhicuts->Write();
      hgenVBFMPartoncuts->Write();
      _rootfile3->Write();
      _rootfile3->Close();
      */

      TFile *_rootfile4 = new TFile("FullSim_Nminus1_plots_invH_8TeVTEST.root","RECREATE");
      h_Mjj->Write();
      h_DeltaEta->Write();
      h_DeltaPhi->Write();
      h_Jet1Eta->Write();
      h_Jet2Eta->Write();
      h_MET->Write();
      h_Jet1PT->Write();
      h_Jet2PT->Write();
      h_EtaDP->Write();
      h_cenJetEt->Write();
      h_cenJetEta->Write();
      h_Njets->Write();
      _rootfile4->Write();
      _rootfile4->Close();
      
      /*
      TFile *_rootfile5 = new TFile("FullSim_precut_invH_8TeV.root","RECREATE");
      hMjj_precut->Write();
      hDeltaEta_precut->Write();
      hDeltaPhi_precut->Write();
      hJet1Eta_precut->Write();
      hJet2Eta_precut->Write();
      hJet1PT_precut->Write();
      hJet2PT_precut->Write();
      hCJEt_precut->Write();
      hEtaDP_precut->Write();
      hMET_precut->Write();
      _rootfile5->Write();
      _rootfile5->Close();


      TFile *_rootfile6 = new TFile("FullSim_Nminus2_plots_invH_8TeVTEST.root","RECREATE");
      h2_Mjj->Write();
      h2_DeltaEta->Write();
      h2_DeltaPhi->Write();
      h2_Jet1Eta->Write();
      h2_Jet2Eta->Write();
      h2_MET->Write();
      h2_Jet1PT->Write();
      h2_Jet2PT->Write();
      h2_EtaDP->Write();
      h2_cenJetEt->Write();
      h2_cenJetEta->Write();
      _rootfile6->Write();
      _rootfile6->Close();
      
      */
   }

}
