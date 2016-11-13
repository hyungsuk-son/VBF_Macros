void PrintBackground() {
  gROOT->ProcessLine(".L DrawBackground.C+");

  Float_t pi = TMath::Pi();

  // Zmumu + Jets
  // For publication
  DrawBackground("ZmumuMET_mono","MET",200.,1400.,1,true,true,505,"GeV");
  DrawBackground("ZmumuMET_search","MET",200.,1400.,1,true,true,505,"GeV");
  DrawBackground("ZmumuMjj_search","M_{jj}",200.,4000.,1,true,true,505,"GeV");
  DrawBackground("ZmumuDeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,false,true,505,"rad");
  /*
  // For Monojet
  DrawBackground("h_zmumu_monojet_met_emulmet","MET",0.,1500.,1,true,true,505,"GeV");
  DrawBackground("h_zmumu_monojet_njet","Number of jets",0.,20.,1,true,true,505,"");
  DrawBackground("h_zmumu_monojet_jet_pt","leading jet p_{T}",0.,1500.,1,true,true,505,"GeV");
  DrawBackground("h_zmumu_monojet_jet_phi","leading jet #phi",-3.2,3.2,1,true,true,505,"rad");
  DrawBackground("h_zmumu_monojet_jet_eta","leading jet #eta",-5.,5.,1,true,true,505,"");
  DrawBackground("h_zmumu_monojet_dPhimetjet","#Delta#Phi(E_{T}^{miss},j_{1})",0.,3.2,1,false,true,505,"rad");
  DrawBackground("h_zmumu_monojet_dPhiMinmetjet","#Delta#Phi_{min}(E_{T}^{miss},jet)",0.,3.2,1,false,true,505,"rad");
  DrawBackground("h_zmumu_monojet_lepton1_pt","leading muon p_{T}",0.,1500.,1,true,true,505,"GeV");
  DrawBackground("h_zmumu_monojet_lepton2_pt","2nd leading muon p_{T}",0.,1500.,1,true,true,505,"GeV");
  DrawBackground("h_zmumu_monojet_lepton1_phi","leading muon #phi",-3.2,3.2,1,true,true,505,"rad");
  DrawBackground("h_zmumu_monojet_lepton2_phi","2nd leading muon #phi",-3.2,3.2,1,true,true,505,"rad");
  DrawBackground("h_zmumu_monojet_lepton1_eta","leading muon #eta",-5.,5.,1,true,true,505,"");
  DrawBackground("h_zmumu_monojet_lepton2_eta","2nd leading muon #eta",-5.,5.,1,true,true,505,"");
  DrawBackground("h_zmumu_monojet_mll","Invariant mass (m_{#mu#mu})",60.,130.,1,true,true,505,"GeV");
  // For VBF
  DrawBackground("h_zmumu_vbf_met_emulmet","MET",0.,1500.,1,true,true,505,"GeV");
  DrawBackground("h_zmumu_vbf_njet","Number of jets",0.,20.,1,true,true,505,"");
  DrawBackground("h_zmumu_vbf_jet1_pt","leading jet p_{T}",0.,1500.,1,true,true,505,"GeV");
  DrawBackground("h_zmumu_vbf_jet2_pt","2nd leading jet p_{T}",0.,1500.,1,true,true,505,"GeV");
  DrawBackground("h_zmumu_vbf_jet3_pt","3rd jet p_{T}",0.,1500.,1,true,true,505,"GeV");
  DrawBackground("h_zmumu_vbf_jet1_phi","leading jet #phi",-3.2,3.2,1,true,true,505,"rad");
  DrawBackground("h_zmumu_vbf_jet2_phi","2nd leading jet #phi",-3.2,3.2,1,true,true,505,"rad");
  DrawBackground("h_zmumu_vbf_jet3_phi","3rd jet #phi",-3.2,3.2,1,true,true,505,"rad");
  DrawBackground("h_zmumu_vbf_jet1_eta","leading jet #eta",-5.,5.,1,true,true,505,"");
  DrawBackground("h_zmumu_vbf_jet2_eta","2nd leading jet #eta",-5.,5.,1,true,true,505,"");
  DrawBackground("h_zmumu_vbf_jet3_eta","3rd jet #eta",-5.,5.,1,true,true,505,"");
  DrawBackground("h_zmumu_vbf_mjj","M_{jj}",0.,4000.,1,true,true,505,"GeV");
  DrawBackground("h_zmumu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,3.2,1,false,true,505,"rad");
  DrawBackground("h_zmumu_vbf_dRjj","#DeltaR(j_{1},j_{2})",0.,5.,1,false,true,505,"rad");
  DrawBackground("h_zmumu_vbf_dPhimetj1","#Delta#Phi(E_{T}^{miss},j_{1})",0.,3.2,1,false,true,505,"rad");
  DrawBackground("h_zmumu_vbf_dPhimetj2","#Delta#Phi(E_{T}^{miss},j_{2})",0.,3.2,1,false,true,505,"rad");
  DrawBackground("h_zmumu_vbf_dPhimetj3","#Delta#Phi(E_{T}^{miss},j_{3})",0.,3.2,1,false,true,505,"rad");
  DrawBackground("h_zmumu_vbf_dPhiMinmetjet","#Delta#Phi_{min}(E_{T}^{miss},jet)",0.,3.2,1,false,true,505,"rad");
  DrawBackground("h_zmumu_vbf_lepton1_pt","leading muon p_{T}",0.,1500.,1,true,true,505,"GeV");
  DrawBackground("h_zmumu_vbf_lepton2_pt","2nd leading muon p_{T}",0.,1500.,1,true,true,505,"GeV");
  DrawBackground("h_zmumu_vbf_lepton1_phi","leading muon #phi",-3.2,3.2,1,true,true,505,"rad");
  DrawBackground("h_zmumu_vbf_lepton2_phi","2nd leading muon #phi",-3.2,3.2,1,true,true,505,"rad");
  DrawBackground("h_zmumu_vbf_lepton1_eta","leading muon #eta",-5.,5.,1,true,true,505,"");
  DrawBackground("h_zmumu_vbf_lepton2_eta","2nd leading muon #eta",-5.,5.,1,true,true,505,"");
  DrawBackground("h_zmumu_vbf_mll","Invariant mass (m_{#mu#mu})",60.,130.,1,true,true,505,"GeV");
  */


  // Zee + Jets
  // For publication
  DrawBackground("ZeeMET_mono","MET",200.,1400.,1,true,true,505,"GeV");
  DrawBackground("ZeeMET_search","MET",200.,1400.,1,true,true,505,"GeV");
  DrawBackground("ZeeMjj_search","M_{jj}",200.,4000.,1,true,true,505,"GeV");
  DrawBackground("ZeeDeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,false,true,505,"rad");
  /*
  // For Monojet
  DrawBackground("h_zee_monojet_met_emulmet","MET",0.,1500.,1,true,true,505,"GeV");
  DrawBackground("h_zee_monojet_njet","Number of jets",0.,20.,1,true,true,505,"");
  DrawBackground("h_zee_monojet_jet_pt","leading jet p_{T}",0.,1500.,1,true,true,505,"GeV");
  DrawBackground("h_zee_monojet_jet_phi","leading jet #phi",-3.2,3.2,1,true,true,505,"rad");
  DrawBackground("h_zee_monojet_jet_eta","leading jet #eta",-5.,5.,1,true,true,505,"");
  DrawBackground("h_zee_monojet_dPhimetjet","#Delta#Phi(E_{T}^{miss},j_{1})",0.,3.2,1,false,true,505,"rad");
  DrawBackground("h_zee_monojet_dPhiMinmetjet","#Delta#Phi_{min}(E_{T}^{miss},jet)",0.,3.2,1,false,true,505,"rad");
  DrawBackground("h_zee_monojet_lepton1_pt","leading electron p_{T}",0.,1500.,1,true,true,505,"GeV");
  DrawBackground("h_zee_monojet_lepton2_pt","2nd leading electron p_{T}",0.,1500.,1,true,true,505,"GeV");
  DrawBackground("h_zee_monojet_lepton1_phi","leading electron #phi",-3.2,3.2,1,true,true,505,"rad");
  DrawBackground("h_zee_monojet_lepton2_phi","2nd leading electron #phi",-3.2,3.2,1,true,true,505,"rad");
  DrawBackground("h_zee_monojet_lepton1_eta","leading electron #eta",-5.,5.,1,true,true,505,"");
  DrawBackground("h_zee_monojet_lepton2_eta","2nd leading electron #eta",-5.,5.,1,true,true,505,"");
  DrawBackground("h_zee_monojet_mll","Invariant mass (m_{ee})",60.,130.,1,true,true,505,"GeV");
  // For VBF
  DrawBackground("h_zee_vbf_met_emulmet","MET",0.,1500.,1,true,true,505,"GeV");
  DrawBackground("h_zee_vbf_njet","Number of jets",0.,20.,1,true,true,505,"");
  DrawBackground("h_zee_vbf_jet1_pt","leading jet p_{T}",0.,1500.,1,true,true,505,"GeV");
  DrawBackground("h_zee_vbf_jet2_pt","2nd leading jet p_{T}",0.,1500.,1,true,true,505,"GeV");
  DrawBackground("h_zee_vbf_jet3_pt","3rd jet p_{T}",0.,1500.,1,true,true,505,"GeV");
  DrawBackground("h_zee_vbf_jet1_phi","leading jet #phi",-3.2,3.2,1,true,true,505,"rad");
  DrawBackground("h_zee_vbf_jet2_phi","2nd leading jet #phi",-3.2,3.2,1,true,true,505,"rad");
  DrawBackground("h_zee_vbf_jet3_phi","3rd jet #phi",-3.2,3.2,1,true,true,505,"rad");
  DrawBackground("h_zee_vbf_jet1_eta","leading jet #eta",-5.,5.,1,true,true,505,"");
  DrawBackground("h_zee_vbf_jet2_eta","2nd leading jet #eta",-5.,5.,1,true,true,505,"");
  DrawBackground("h_zee_vbf_jet3_eta","3rd jet #eta",-5.,5.,1,true,true,505,"");
  DrawBackground("h_zee_vbf_mjj","M_{jj}",0.,4000.,1,true,true,505,"GeV");
  DrawBackground("h_zee_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,3.2,1,false,true,505,"rad");
  DrawBackground("h_zee_vbf_dRjj","#DeltaR(j_{1},j_{2})",0.,5.,1,false,true,505,"rad");
  DrawBackground("h_zee_vbf_dPhimetj1","#Delta#Phi(E_{T}^{miss},j_{1})",0.,3.2,1,false,true,505,"rad");
  DrawBackground("h_zee_vbf_dPhimetj2","#Delta#Phi(E_{T}^{miss},j_{2})",0.,3.2,1,false,true,505,"rad");
  DrawBackground("h_zee_vbf_dPhimetj3","#Delta#Phi(E_{T}^{miss},j_{3})",0.,3.2,1,false,true,505,"rad");
  DrawBackground("h_zee_vbf_dPhiMinmetjet","#Delta#Phi_{min}(E_{T}^{miss},jet)",0.,3.2,1,false,true,505,"rad");
  DrawBackground("h_zee_vbf_lepton1_pt","leading electron p_{T}",0.,1500.,1,true,true,505,"GeV");
  DrawBackground("h_zee_vbf_lepton2_pt","2nd leading electron p_{T}",0.,1500.,1,true,true,505,"GeV");
  DrawBackground("h_zee_vbf_lepton1_phi","leading electron #phi",-3.2,3.2,1,true,true,505,"rad");
  DrawBackground("h_zee_vbf_lepton2_phi","2nd leading electron #phi",-3.2,3.2,1,true,true,505,"rad");
  DrawBackground("h_zee_vbf_lepton1_eta","leading electron #eta",-5.,5.,1,true,true,505,"");
  DrawBackground("h_zee_vbf_lepton2_eta","2nd leading electron #eta",-5.,5.,1,true,true,505,"");
  DrawBackground("h_zee_vbf_mll","Invariant mass (m_{ee})",60.,130.,1,true,true,505,"GeV");
  */
}



