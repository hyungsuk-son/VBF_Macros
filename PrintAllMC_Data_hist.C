void PrintAllMC_Data_hist() {
  gROOT->ProcessLine(".L DrawHistogram.C+");
  gROOT->ProcessLine(".rm hist_all_MC_Data.root");

  // How to print all MC backgrounds and Data?
  // DrawHistogram(TString HISTO,TString XTITLE,float XMIN,float XMAX,int REBIN,bool LOGY,bool PRINT,int XDIV,TString UNITS,bool OUTPUT_BKG,bool OUTPUT_SYS)

  Float_t pi = TMath::Pi();

  // Znunu + Jets
  // For Blind
  DrawHistogram("Znunu_MET_mono","MET",200.,1400.,1,true,false,707,"GeV",true,false);
  DrawHistogram("Znunu_MET_search","MET",200.,1400.,1,true,false,707,"GeV",true,false);
  DrawHistogram("Znunu_Mjj_search","M_{jj}",200.,4000.,1,true,false,707,"GeV",true,false);
  DrawHistogram("Znunu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,false,707,"rad",true,false);
  // For Publication
  DrawHistogram("h_znunu_monojet_met","MET",200.,1400.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_znunu_vbf_met","MET",200.,1400.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_znunu_vbf_mjj","M_{jj}",200.,4000.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_znunu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,false,707,"rad",true,false);


  // Zmumu + Jets
  // For Blind
  DrawHistogram("Zmumu_MET_mono","MET",200.,1400.,1,true,false,707,"GeV",true,false);
  DrawHistogram("Zmumu_MET_search","MET",200.,1400.,1,true,false,707,"GeV",true,false);
  DrawHistogram("Zmumu_Mjj_search","M_{jj}",200.,4000.,1,true,false,707,"GeV",true,false);
  DrawHistogram("Zmumu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,false,707,"rad",true,false);
  // For Publication
  DrawHistogram("h_zmumu_monojet_met_emulmet","MET",200.,1400.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zmumu_vbf_met_emulmet","MET",200.,1400.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zmumu_vbf_mjj","M_{jj}",200.,4000.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zmumu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,false,707,"rad",true,false);
  /*
  // For Monojet
  DrawHistogram("h_zmumu_monojet_met_emulmet","MET",0.,1500.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zmumu_monojet_njet","Number of jets",0.,20.,1,true,false,707,"",true,false);
  DrawHistogram("h_zmumu_monojet_jet_pt","leading jet p_{T}",0.,1500.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zmumu_monojet_jet_phi","leading jet #phi",-3.2,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zmumu_monojet_jet_eta","leading jet #eta",-5.,5.,1,true,false,707,"",true,false);
  DrawHistogram("h_zmumu_monojet_dPhimetjet","#Delta#Phi(E_{T}^{miss},j_{1})",0.,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zmumu_monojet_dPhiMinmetjet","#Delta#Phi_{min}(E_{T}^{miss},jet)",0.,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zmumu_monojet_lepton1_pt","leading muon p_{T}",0.,1500.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zmumu_monojet_lepton2_pt","2nd leading muon p_{T}",0.,1500.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zmumu_monojet_lepton1_phi","leading muon #phi",-3.2,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zmumu_monojet_lepton2_phi","2nd leading muon #phi",-3.2,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zmumu_monojet_lepton1_eta","leading muon #eta",-5.,5.,1,true,false,707,"",true,false);
  DrawHistogram("h_zmumu_monojet_lepton2_eta","2nd leading muon #eta",-5.,5.,1,true,false,707,"",true,false);
  DrawHistogram("h_zmumu_monojet_mll","Invariant mass (m_{#mu#mu})",60.,130.,1,true,false,707,"GeV",true,false);
  // For VBF
  DrawHistogram("h_zmumu_vbf_met_emulmet","MET",0.,1500.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zmumu_vbf_njet","Number of jets",0.,20.,1,true,false,707,"",true,false);
  DrawHistogram("h_zmumu_vbf_jet1_pt","leading jet p_{T}",0.,1500.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zmumu_vbf_jet2_pt","2nd leading jet p_{T}",0.,1500.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zmumu_vbf_jet3_pt","3rd jet p_{T}",0.,1500.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zmumu_vbf_jet1_phi","leading jet #phi",-3.2,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zmumu_vbf_jet2_phi","2nd leading jet #phi",-3.2,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zmumu_vbf_jet3_phi","3rd jet #phi",-3.2,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zmumu_vbf_jet1_eta","leading jet #eta",-5.,5.,1,true,false,707,"",true,false);
  DrawHistogram("h_zmumu_vbf_jet2_eta","2nd leading jet #eta",-5.,5.,1,true,false,707,"",true,false);
  DrawHistogram("h_zmumu_vbf_jet3_eta","3rd jet #eta",-5.,5.,1,true,false,707,"",true,false);
  DrawHistogram("h_zmumu_vbf_mjj","M_{jj}",0.,4000.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zmumu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zmumu_vbf_dRjj","#DeltaR(j_{1},j_{2})",0.,5.,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zmumu_vbf_dPhimetj1","#Delta#Phi(E_{T}^{miss},j_{1})",0.,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zmumu_vbf_dPhimetj2","#Delta#Phi(E_{T}^{miss},j_{2})",0.,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zmumu_vbf_dPhimetj3","#Delta#Phi(E_{T}^{miss},j_{3})",0.,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zmumu_vbf_dPhiMinmetjet","#Delta#Phi_{min}(E_{T}^{miss},jet)",0.,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zmumu_vbf_lepton1_pt","leading muon p_{T}",0.,1500.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zmumu_vbf_lepton2_pt","2nd leading muon p_{T}",0.,1500.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zmumu_vbf_lepton1_phi","leading muon #phi",-3.2,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zmumu_vbf_lepton2_phi","2nd leading muon #phi",-3.2,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zmumu_vbf_lepton1_eta","leading muon #eta",-5.,5.,1,true,false,707,"",true,false);
  DrawHistogram("h_zmumu_vbf_lepton2_eta","2nd leading muon #eta",-5.,5.,1,true,false,707,"",true,false);
  DrawHistogram("h_zmumu_vbf_mll","Invariant mass (m_{#mu#mu})",60.,130.,1,true,false,707,"GeV",true,false);
  */


  // Zee + Jets
  // For Blind
  DrawHistogram("Zee_MET_mono","MET",200.,1400.,1,true,false,707,"GeV",true,false);
  DrawHistogram("Zee_MET_search","MET",200.,1400.,1,true,false,707,"GeV",true,false);
  DrawHistogram("Zee_Mjj_search","M_{jj}",200.,4000.,1,true,false,707,"GeV",true,false);
  DrawHistogram("Zee_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,false,707,"rad",true,false);
  // For Publication
  DrawHistogram("h_zee_monojet_met_emulmet","MET",200.,1400.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zee_vbf_met_emulmet","MET",200.,1400.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zee_vbf_mjj","M_{jj}",200.,4000.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zee_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,false,707,"rad",true,false);
  /*
  // For Monojet
  DrawHistogram("h_zee_monojet_met_emulmet","MET",0.,1500.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zee_monojet_njet","Number of jets",0.,20.,1,true,false,707,"",true,false);
  DrawHistogram("h_zee_monojet_jet_pt","leading jet p_{T}",0.,1500.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zee_monojet_jet_phi","leading jet #phi",-3.2,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zee_monojet_jet_eta","leading jet #eta",-5.,5.,1,true,false,707,"",true,false);
  DrawHistogram("h_zee_monojet_dPhimetjet","#Delta#Phi(E_{T}^{miss},j_{1})",0.,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zee_monojet_dPhiMinmetjet","#Delta#Phi_{min}(E_{T}^{miss},jet)",0.,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zee_monojet_lepton1_pt","leading electron p_{T}",0.,1500.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zee_monojet_lepton2_pt","2nd leading electron p_{T}",0.,1500.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zee_monojet_lepton1_phi","leading electron #phi",-3.2,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zee_monojet_lepton2_phi","2nd leading electron #phi",-3.2,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zee_monojet_lepton1_eta","leading electron #eta",-5.,5.,1,true,false,707,"",true,false);
  DrawHistogram("h_zee_monojet_lepton2_eta","2nd leading electron #eta",-5.,5.,1,true,false,707,"",true,false);
  DrawHistogram("h_zee_monojet_mll","Invariant mass (m_{ee})",60.,130.,1,true,false,707,"GeV",true,false);
  // For VBF
  DrawHistogram("h_zee_vbf_met_emulmet","MET",0.,1500.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zee_vbf_njet","Number of jets",0.,20.,1,true,false,707,"",true,false);
  DrawHistogram("h_zee_vbf_jet1_pt","leading jet p_{T}",0.,1500.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zee_vbf_jet2_pt","2nd leading jet p_{T}",0.,1500.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zee_vbf_jet3_pt","3rd jet p_{T}",0.,1500.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zee_vbf_jet1_phi","leading jet #phi",-3.2,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zee_vbf_jet2_phi","2nd leading jet #phi",-3.2,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zee_vbf_jet3_phi","3rd jet #phi",-3.2,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zee_vbf_jet1_eta","leading jet #eta",-5.,5.,1,true,false,707,"",true,false);
  DrawHistogram("h_zee_vbf_jet2_eta","2nd leading jet #eta",-5.,5.,1,true,false,707,"",true,false);
  DrawHistogram("h_zee_vbf_jet3_eta","3rd jet #eta",-5.,5.,1,true,false,707,"",true,false);
  DrawHistogram("h_zee_vbf_mjj","M_{jj}",0.,4000.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zee_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zee_vbf_dRjj","#DeltaR(j_{1},j_{2})",0.,5.,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zee_vbf_dPhimetj1","#Delta#Phi(E_{T}^{miss},j_{1})",0.,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zee_vbf_dPhimetj2","#Delta#Phi(E_{T}^{miss},j_{2})",0.,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zee_vbf_dPhimetj3","#Delta#Phi(E_{T}^{miss},j_{3})",0.,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zee_vbf_dPhiMinmetjet","#Delta#Phi_{min}(E_{T}^{miss},jet)",0.,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zee_vbf_lepton1_pt","leading electron p_{T}",0.,1500.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zee_vbf_lepton2_pt","2nd leading electron p_{T}",0.,1500.,1,true,false,707,"GeV",true,false);
  DrawHistogram("h_zee_vbf_lepton1_phi","leading electron #phi",-3.2,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zee_vbf_lepton2_phi","2nd leading electron #phi",-3.2,3.2,1,true,false,707,"rad",true,false);
  DrawHistogram("h_zee_vbf_lepton1_eta","leading electron #eta",-5.,5.,1,true,false,707,"",true,false);
  DrawHistogram("h_zee_vbf_lepton2_eta","2nd leading electron #eta",-5.,5.,1,true,false,707,"",true,false);
  DrawHistogram("h_zee_vbf_mll","Invariant mass (m_{ee})",60.,130.,1,true,false,707,"GeV",true,false);
  */
}



