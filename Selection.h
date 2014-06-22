#ifndef SELECTION_h
#define SELECTION_h

#include <iostream>

// Here go the offline cuts:
//    pT(j1),pT(j2) > 50 GeV
//    |eta| < 4.7
//    eta(j1).eta(j2) < 0
//    Delta(eta_jj) > 4.2
//    Di-jet mass > 1100 GeV
//    MET > 130 GeV
//    Delta(phi_jj) < 1 radians
//    CJV to any event with additional jet pT > 30 GeV

class Selection{

 public:
  
  //static float GetEntries() { return 1000; }
  
  static float NJets() { return 2; } 
  
  static float JetPTCut() { return 50; }
  
  static float JetEtaCut() { return 4.7; } 
  
  static float JetEtaDPCut() { return 0; } 
  
  static float InvJetMassCut() { return 1100; }
  
  static float DeltaPhiJJCut() { return 1; } 
  
  static float DeltaEtaJJCut() { return 4.2; } 
  
  static float METCut() { return 150; }
  

};

#endif
