#ifndef DATASET_H
#define DATASET_H

#include "TString.h"

class Dataset{

 public: 
  
  static TString toTString(unsigned int id);
  static TString fullDatasetName(unsigned int id);
  static TString pdfTitler(unsigned int id);

 private:
  
  static TString path;
  static TString checkId(unsigned int id);
  
};

TString Dataset::fullDatasetName(unsigned int id){
  checkId(id);
  
  TString name("");
  if (id == 0) name += "VBF_inv_8000_unweighted_ZTune.root";
  if (id == 1) name += "VBF_inv_8000_unweighted_ZTune_PU.root";



  return name;

}

TString Dataset::toTString(unsigned int id){
  checkId(id);
  
  TString str("");
  if( id == 0) str += "SM Inv Higgs 125 GeV, ZTune";
  if (id == 1) str += "SM Inv Higgs 125 GeV, ZTune & Pile Up";

  return str;

}

TString Dataset::pdfTitler(unsigned int id){
  checkId(id);
  
  TString title("");
  if(id ==0) title += "Nminus1Comparison_vbfH_8TeV_ZTune";
  if(id ==1) title += "Nminus1 Comparison, FullSim & VBFNLO + DELPHES";


  return title;
}

void Dataset::checkId(unsigned int id){
  
  if(id!=0 && id!=1 && id!=2 && id!=3 && id!=4 && id!=5 && id!=6){
    std::cerr << "\nERROR CAN'T OPEN FILE" << std::endl;
    throw std::exception();
  }
}

#endif
    

  
