// -*- C++ -*-
// This is a header file generated with the command:
// makeCMS3ClassFiles("/hadoop/cms/store/user/namin/NanoAODv1/ProjectMetis/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8_RunIISummer17MiniAOD-92X_upgrade2017_realistic_v10_ext1-v1_MINIAODSIM_NanoAODv1/merged_ntuple_1.root", "Events", "NanoAOD", "nanoAOD", "nano")

#ifndef NanoAOD_H
#define NanoAOD_H

#include "Math/LorentzVector.h"
#include "Math/Point3D.h"
#include "TMath.h"
#include "TBranch.h"
#include "TTree.h"
#include "TH1F.h"
#include "TFile.h"
#include "TBits.h"
#include <vector> 
#include <unistd.h> 
typedef ROOT::Math::LorentzVector< ROOT::Math::PxPyPzE4D<float> > LorentzVector;

using namespace std; 
class NanoAOD {
 private: 
 protected: 
  unsigned int index;
  unsigned int run_;
  TBranch *run_branch;
  bool     run_isLoaded;
  unsigned int luminosityBlock_;
  TBranch *luminosityBlock_branch;
  bool     luminosityBlock_isLoaded;
  unsigned long long event_;
  TBranch *event_branch;
  bool     event_isLoaded;
public: 
void Init(TTree *tree);
void GetEntry(unsigned int idx); 
void LoadAllBranches(); 
  const unsigned int &run();
  const unsigned int &luminosityBlock();
  const unsigned long long &event();

  static void progress(int nEventsTotal, int nEventsChain);
};

#ifndef __CINT__
extern NanoAOD nano;
#endif

namespace nanoAOD {
  const unsigned int &run();
  const unsigned int &luminosityBlock();
  const unsigned long long &event();
}
#endif
