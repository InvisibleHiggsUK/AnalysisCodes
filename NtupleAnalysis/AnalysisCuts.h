#ifndef ANALYSISCUTS_H
#define ANALYSISCUTS_H

#include <iostream>

class AnalysisCuts{
  
 public:
  
  static bool Trigger(float hltResult2){ return hltResult2 > 0; }

  // MET Cleaning goes in the source code

  static bool EVeto(float elec1Pt){ return elec1Pt < 10.;}
  
  static bool MuVeto(float mu1Pt){ return mu1Pt < 10; } 
  
  static bool JJPair(float jet1Pt, float jet1Eta, float jet2Pt, float jet2Eta){ 
    return (jet1Pt > 50. && abs(jet1Eta) < 4.7 && jet2Pt > 50. && abs(jet2Eta) < 4.7); 
  }
  
  static bool EtaFB(float jet1Eta, float jet2Eta){ return (jet1Eta*jet2Eta) < 0. ; }
  
  static bool DeltaEta(float vbfDeta){ return vbfDeta > 4.2; }
  
  static bool MET(float met){ return met > 130. ; }
  
  static bool Mjj(float vbfM){ return vbfM > 1100.; }
  
  static bool CJV(float cenJetet) { return cenJetet < 30.; }
  
  static bool DeltaPhi(float vbfDPhi){ return vbfDPhi < 1.0; } 

};


#endif
