#include "JEC/JECHelper/interface/jcorr.h"
#include "CondFormats/JetMETObjects/interface/FactorizedJetCorrector.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"

using namespace mithep;

ClassImp(mithep::jcorr)

jcorr::jcorr()
{
  fJetCorrector=0;
}

jcorr::~jcorr()
{}

void jcorr::setup()
{
  std::vector<JetCorrectorParameters> correctionParameters;
  std::cout << fJetCorrParsv.size() << std::endl;
  std::cout << fJetCorrParsv[0].Data() << std::endl;
  std::cout << fJetCorrParsv[1].Data() << std::endl;
  std::cout << fJetCorrParsv[2].Data() << std::endl;
  if(fJetCorrParsv.size()==0)
    {
      std::cout << "No correction inputs were provided" << std::endl;
    }
  for(unsigned int icorr=0; icorr<fJetCorrParsv.size(); icorr++)
    { 
      correctionParameters.push_back(JetCorrectorParameters(fJetCorrParsv[icorr].Data())); 
    }
  fJetCorrector = new FactorizedJetCorrector(correctionParameters); 
}

double jcorr::getCorrection(double pT, double eta, double rho, double area)
{
  fJetCorrector->setJetEta(eta);
  fJetCorrector->setJetPt(pT);
  fJetCorrector->setRho(rho);
  fJetCorrector->setJetA(area);
  return fJetCorrector->getCorrection();
}
