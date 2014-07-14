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
  if (id == 1) name += "../VBF_h2_8000_precut_unweighted.root";
  if (id == 2) name += "../VBF_h2_8000_precut_weighted.root";
  if (id == 3) name += "../VBF_h2_8000_weighted.root";
  if (id == 4) name += "../VBF_inv_8000_precut_unweighted.root";
  if (id == 5) name += "../VBF_inv_8000_precut_weighted.root";
  if (id == 6) name += "../VBF_inv_8000_weighted.root";

  return name;

}

TString Dataset::toTString(unsigned int id){
  checkId(id);
  
  TString str("");
  if( id == 1) str += "h2 model 220 GeV, precut and unweighted";
  if( id == 2) str += "h2 model 220 GeV, precut and weighted to 19.5 fb^-1";
  if( id == 3) str += "h2 model 200 GeV, cut and weighted to 19.5 fb^-1";
  if( id == 4) str += "SM Inv Higgs 125 GeV, precut and unweighted";
  if( id == 5) str += "SM Inv Higgs 125 GeV, precut and weighted to 19.5 fb^-1";
  if( id == 6) str += "SM Inv Higgs 125 GeV, cut and weighted to 19.5 fb^-1";

  return str;

}

TString Dataset::pdfTitler(unsigned int id){
  checkId(id);
  
  TString title("");
  if(id ==1) title += "h2_8TeV_VBFNLO_DELPHES_precut_unweighted_FullSim_Comp";
  if(id ==2) title += "h2_8TeV_VBFNLO_DELPHES_precut_weighted_FullSim_Comp";
  if(id ==3) title += "h2_8TeV_VBFNLO_DELPHES_cut_weighted_FullSim_Comp";
  if(id ==4) title += "vbf_invH_8TeV_VBFNLO_DELPHES_precut_unweighted_FullSim_Comp";
  if(id ==5) title += "vbf_invH_8TeV_VBFNLO_DELPHES_precut_weighted_FullSim_Comp";
  if(id ==6) title += "vbf_invH_8TeV_VBFNLO_DELPHES_cut_weighted_FullSim_Comp";

  return title;
}

void Dataset::checkId(unsigned int id){
  
  if(id!=1 && id!=2 && id!=3 && id!=4 && id!=5 && id!=6){
    std::cerr << "\nERROR CAN'T OPEN FILE" << std::endl;
    throw std::exception();
  }
}

#endif
    

  
