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


  Event* evt = new Event(Sample::fileNameFullSample(id),nEvts);

  while( evt->loadNext() ) {

    std::cout << "NEW ENTRY" << std::endl;
    std::cout << "Jet PT: " << evt->JET1PT()[1] << std::endl;

  }

}
