#ifndef TauAnalysis_SVfitHelper_LINKDEF_H
#define TauAnalysis_SVfitHelper_LINKDEF_H
#include "TauAnalysis/SVFitHelper/interface/TSVfitter.h"
#include "TauAnalysis/SVFitHelper/interface/TSVfit.h"
#endif

#ifdef __CINT__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;
#pragma link C++ namespace mithep;

#pragma link C++ class mithep::TSVfitter+;
#pragma link C++ class mithep::TSVfit+;
#endif
