#ifndef SAMPLE_H
#define SAMPLE_H

#include <iostream>
#include <exception>

#include "TColor.h"
#include "TString.h"

class Sample { 
 public:
  static TString toTString(unsigned int id);
  
  static TString fileNameFullSample(unsigned int id);

 private:
  static TString path;
  
  static void checkId(unsigned int id);
  
};

TString Sample::fileNameFullSample(unsigned int id) {
  checkId(id);
  
  TString name("");
  if (id == 1) name += "SignalM125_POWHEG.root";

  return name;
}

TString Sample::toTString(unsigned int id){
  checkId(id);
  
  TString str("");
  if( id == 1) str += "Data";

  return str;
}

void Sample::checkId(unsigned int id){
  if(id !=1){
    std::cerr << "\n\nERROR invalid sample id" << id << std::endl;
    throw std::exception();
  }
}

#endif
