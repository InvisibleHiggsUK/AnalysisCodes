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

  static bool JetCut(float pt){ return pt > 50.; }
  
  static bool EtaCut(float eta){ return abs(eta) < 4.7; }

  static bool PhiCut(float phi){ return phi < 1; }

  static bool METcut(float met){ return met > 130; }

  static bool MassCut(float m_jj){ return m_jj > 1100; }

  static bool DEtaCut(float dEtajj){ return dEtajj > 4.2; }

  static bool DPEta(float etaDP){ return etaDP < 0; }



  static float NJets() { return 2; } 
  
  static float JetPTCut() { return 50; }
  
  static float JetEtaCut() { return 4.7; } 
  
  static float JetEtaDPCut() { return 0; } 
  
  static float InvJetMassCut() { return 1100; }
  
  static float DeltaPhiJJCut() { return 1; } 
  
  static float DeltaEtaJJCut() { return 4.2; } 
  
  static float METCut() { return 150; }
  
  //  extern  Float_t pi = 3.14159265;


};

#endif
