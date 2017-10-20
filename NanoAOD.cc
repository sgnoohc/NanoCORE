#include "NanoAOD.h"
NanoAOD nano;

void NanoAOD::Init(TTree *tree) {

  tree->SetMakeClass(1);

  run_branch = tree->GetBranch("run");
  if (run_branch) run_branch->SetAddress(&run_);
  luminosityBlock_branch = tree->GetBranch("luminosityBlock");
  if (luminosityBlock_branch) luminosityBlock_branch->SetAddress(&luminosityBlock_);
  event_branch = tree->GetBranch("event");
  if (event_branch) event_branch->SetAddress(&event_);

  tree->SetMakeClass(0);
}

void NanoAOD::GetEntry(unsigned int idx) {
  // this only marks branches as not loaded, saving a lot of time
  index = idx;
  run_isLoaded = false;
  luminosityBlock_isLoaded = false;
  event_isLoaded = false;
}

void NanoAOD::LoadAllBranches() {
  // load all branches
  if (run_branch != 0) run();
  if (luminosityBlock_branch != 0) luminosityBlock();
  if (event_branch != 0) event();
}

const unsigned int &NanoAOD::run() {
  if (not run_isLoaded) {
    if (run_branch != 0) {
      run_branch->GetEntry(index);
    } else {
      printf("branch run_branch does not exist!\n");
      exit(1);
    }
    run_isLoaded = true;
  }
  return run_;
}

const unsigned int &NanoAOD::luminosityBlock() {
  if (not luminosityBlock_isLoaded) {
    if (luminosityBlock_branch != 0) {
      luminosityBlock_branch->GetEntry(index);
    } else {
      printf("branch luminosityBlock_branch does not exist!\n");
      exit(1);
    }
    luminosityBlock_isLoaded = true;
  }
  return luminosityBlock_;
}

const unsigned long long &NanoAOD::event() {
  if (not event_isLoaded) {
    if (event_branch != 0) {
      event_branch->GetEntry(index);
    } else {
      printf("branch event_branch does not exist!\n");
      exit(1);
    }
    event_isLoaded = true;
  }
  return event_;
}


void NanoAOD::progress( int nEventsTotal, int nEventsChain ){
  int period = 1000;
  if (nEventsTotal%1000 == 0) {
    // xterm magic from L. Vacavant and A. Cerri
    if (isatty(1)) {
      if ((nEventsChain - nEventsTotal) > period) {
        float frac = (float)nEventsTotal/(nEventsChain*0.01);
        printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
             "\033[0m\033[32m <---\033[0m\015", frac);
        fflush(stdout);
      }
      else {
        printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
               "\033[0m\033[32m <---\033[0m\015", 100.);
        cout << endl;
      }
    }
  }
}

namespace nanoAOD {

const unsigned int &run() { return nano.run(); }
const unsigned int &luminosityBlock() { return nano.luminosityBlock(); }
const unsigned long long &event() { return nano.event(); }

}
