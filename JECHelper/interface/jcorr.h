#ifndef JEC_JECHelper_jcorr_H
#define JEC_JECHelper_jcorr_H

#include <stdio.h> 
#include <assert.h>
#include <string>
#include <vector>
#include <iostream>

#include "CondFormats/JetMETObjects/interface/FactorizedJetCorrector.h"


//class FactorizedJetCorrector;

namespace mithep
{
  class jcorr 
  {
  public:
    /// default contstructor
    jcorr();
    /// default destructor
    ~jcorr();
    
    void setup();

    double getCorrection(double pT, double eta, double rho, double area);
  
    inline void AddJetCorr(const char* name) 
    {
      fJetCorrParsv.push_back(name);
    }
  
  private:
    FactorizedJetCorrector* fJetCorrector;
    std::vector<TString> fJetCorrParsv;
    ClassDef(jcorr, 1);
  };
}  
#endif
