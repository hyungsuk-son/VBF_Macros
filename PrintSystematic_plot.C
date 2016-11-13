void PrintSystematic_plot() {
  gROOT->ProcessLine(".L DrawSystematic.C+");

  Float_t pi = TMath::Pi();

  ////////////////////////
  // Only MC background //
  ////////////////////////
  // Znunu + Jets
  // For blinded
  // JET
  DrawSystematic("McEstBkg_Znunu_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("McEstBkg_Znunu_MET_search","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("McEstBkg_Znunu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("McEstBkg_Znunu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","JET","JET");
  // Muon Efficiency
  DrawSystematic("McEstBkg_Znunu_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("McEstBkg_Znunu_MET_search","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("McEstBkg_Znunu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("McEstBkg_Znunu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUON_EFF","MUON_EFF");
  // Muon
  DrawSystematic("McEstBkg_Znunu_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("McEstBkg_Znunu_MET_search","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("McEstBkg_Znunu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("McEstBkg_Znunu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUONS","MUON_TTVA");
  // Electron
  DrawSystematic("McEstBkg_Znunu_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("McEstBkg_Znunu_MET_search","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("McEstBkg_Znunu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("McEstBkg_Znunu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","EG","EL");
  // MET
  DrawSystematic("McEstBkg_Znunu_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("McEstBkg_Znunu_MET_search","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("McEstBkg_Znunu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("McEstBkg_Znunu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MET","MET");
  // PRW
  DrawSystematic("McEstBkg_Znunu_MET_mono","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("McEstBkg_Znunu_MET_search","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("McEstBkg_Znunu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("McEstBkg_Znunu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","PRW","PRW");

  // For unblinded
  // JET
  DrawSystematic("McEstBkg_h_znunu_monojet_met","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("McEstBkg_h_znunu_vbf_met","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("McEstBkg_h_znunu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("McEstBkg_h_znunu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","JET","JET");
  // Muon Efficiency
  DrawSystematic("McEstBkg_h_znunu_monojet_met","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("McEstBkg_h_znunu_vbf_met","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("McEstBkg_h_znunu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("McEstBkg_h_znunu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUON_EFF","MUON_EFF");
  // Muon
  DrawSystematic("McEstBkg_h_znunu_monojet_met","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("McEstBkg_h_znunu_vbf_met","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("McEstBkg_h_znunu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("McEstBkg_h_znunu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUONS","MUON_TTVA");
  // Electron
  DrawSystematic("McEstBkg_h_znunu_monojet_met","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("McEstBkg_h_znunu_vbf_met","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("McEstBkg_h_znunu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("McEstBkg_h_znunu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","EG","EL");
  // MET
  DrawSystematic("McEstBkg_h_znunu_monojet_met","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("McEstBkg_h_znunu_vbf_met","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("McEstBkg_h_znunu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("McEstBkg_h_znunu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MET","MET");
  // PRW
  DrawSystematic("McEstBkg_h_znunu_monojet_met","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("McEstBkg_h_znunu_vbf_met","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("McEstBkg_h_znunu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("McEstBkg_h_znunu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","PRW","PRW");




  // Zmumu + Jets
  // For blinded
  // JET
  DrawSystematic("McEstBkg_Zmumu_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("McEstBkg_Zmumu_MET_search","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("McEstBkg_Zmumu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("McEstBkg_Zmumu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","JET","JET");
  // Muon Efficiency
  DrawSystematic("McEstBkg_Zmumu_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("McEstBkg_Zmumu_MET_search","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("McEstBkg_Zmumu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("McEstBkg_Zmumu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUON_EFF","MUON_EFF");
  // Muon
  DrawSystematic("McEstBkg_Zmumu_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("McEstBkg_Zmumu_MET_search","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("McEstBkg_Zmumu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("McEstBkg_Zmumu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUONS","MUON_TTVA");
  // Electron
  DrawSystematic("McEstBkg_Zmumu_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("McEstBkg_Zmumu_MET_search","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("McEstBkg_Zmumu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("McEstBkg_Zmumu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","EG","EL");
  // MET
  DrawSystematic("McEstBkg_Zmumu_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("McEstBkg_Zmumu_MET_search","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("McEstBkg_Zmumu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("McEstBkg_Zmumu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MET","MET");
  // PRW
  DrawSystematic("McEstBkg_Zmumu_MET_mono","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("McEstBkg_Zmumu_MET_search","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("McEstBkg_Zmumu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("McEstBkg_Zmumu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","PRW","PRW");

  // For unblinded
  // JET
  DrawSystematic("McEstBkg_h_zmumu_monojet_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("McEstBkg_h_zmumu_vbf_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("McEstBkg_h_zmumu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("McEstBkg_h_zmumu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","JET","JET");
  // Muon Efficiency
  DrawSystematic("McEstBkg_h_zmumu_monojet_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("McEstBkg_h_zmumu_vbf_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("McEstBkg_h_zmumu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("McEstBkg_h_zmumu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUON_EFF","MUON_EFF");
  // Muon
  DrawSystematic("McEstBkg_h_zmumu_monojet_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("McEstBkg_h_zmumu_vbf_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("McEstBkg_h_zmumu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("McEstBkg_h_zmumu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUONS","MUON_TTVA");
  // Electron
  DrawSystematic("McEstBkg_h_zmumu_monojet_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("McEstBkg_h_zmumu_vbf_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("McEstBkg_h_zmumu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("McEstBkg_h_zmumu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","EG","EL");
  // MET
  DrawSystematic("McEstBkg_h_zmumu_monojet_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("McEstBkg_h_zmumu_vbf_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("McEstBkg_h_zmumu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("McEstBkg_h_zmumu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MET","MET");
  // PRW
  DrawSystematic("McEstBkg_h_zmumu_monojet_met_emulmet","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("McEstBkg_h_zmumu_vbf_met_emulmet","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("McEstBkg_h_zmumu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("McEstBkg_h_zmumu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","PRW","PRW");


  // Zee + Jets
  // For blinded
  // JET
  DrawSystematic("McEstBkg_Zee_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("McEstBkg_Zee_MET_search","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("McEstBkg_Zee_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("McEstBkg_Zee_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","JET","JET");
  // Muon Efficiency
  DrawSystematic("McEstBkg_Zee_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("McEstBkg_Zee_MET_search","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("McEstBkg_Zee_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("McEstBkg_Zee_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUON_EFF","MUON_EFF");
  // Muon
  DrawSystematic("McEstBkg_Zee_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("McEstBkg_Zee_MET_search","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("McEstBkg_Zee_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("McEstBkg_Zee_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUONS","MUON_TTVA");
  // Electron
  DrawSystematic("McEstBkg_Zee_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("McEstBkg_Zee_MET_search","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("McEstBkg_Zee_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("McEstBkg_Zee_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","EG","EL");
  // MET
  DrawSystematic("McEstBkg_Zee_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("McEstBkg_Zee_MET_search","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("McEstBkg_Zee_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("McEstBkg_Zee_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MET","MET");
  // PRW
  DrawSystematic("McEstBkg_Zee_MET_mono","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("McEstBkg_Zee_MET_search","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("McEstBkg_Zee_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("McEstBkg_Zee_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","PRW","PRW");

  // For unblinded
  // JET
  DrawSystematic("McEstBkg_h_zee_monojet_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("McEstBkg_h_zee_vbf_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("McEstBkg_h_zee_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("McEstBkg_h_zee_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","JET","JET");
  // Muon Efficiency
  DrawSystematic("McEstBkg_h_zee_monojet_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("McEstBkg_h_zee_vbf_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("McEstBkg_h_zee_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("McEstBkg_h_zee_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUON_EFF","MUON_EFF");
  // Muon
  DrawSystematic("McEstBkg_h_zee_monojet_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("McEstBkg_h_zee_vbf_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("McEstBkg_h_zee_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("McEstBkg_h_zee_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUONS","MUON_TTVA");
  // Electron
  DrawSystematic("McEstBkg_h_zee_monojet_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("McEstBkg_h_zee_vbf_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("McEstBkg_h_zee_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("McEstBkg_h_zee_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","EG","EL");
  // MET
  DrawSystematic("McEstBkg_h_zee_monojet_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("McEstBkg_h_zee_vbf_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("McEstBkg_h_zee_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("McEstBkg_h_zee_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MET","MET");
  // PRW
  DrawSystematic("McEstBkg_h_zee_monojet_met_emulmet","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("McEstBkg_h_zee_vbf_met_emulmet","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("McEstBkg_h_zee_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("McEstBkg_h_zee_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","PRW","PRW");



  ////////////////////////////////////////
  // All MC background including signal //
  ////////////////////////////////////////
  // Znunu + Jets
  // For blinded
  // JET
  DrawSystematic("SM_Znunu_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("SM_Znunu_MET_search","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("SM_Znunu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("SM_Znunu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","JET","JET");
  // Muon Efficiency
  DrawSystematic("SM_Znunu_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("SM_Znunu_MET_search","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("SM_Znunu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("SM_Znunu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUON_EFF","MUON_EFF");
  // Muon
  DrawSystematic("SM_Znunu_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("SM_Znunu_MET_search","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("SM_Znunu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("SM_Znunu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUONS","MUON_TTVA");
  // Electron
  DrawSystematic("SM_Znunu_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("SM_Znunu_MET_search","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("SM_Znunu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("SM_Znunu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","EG","EL");
  // MET
  DrawSystematic("SM_Znunu_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("SM_Znunu_MET_search","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("SM_Znunu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("SM_Znunu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MET","MET");
  // PRW
  DrawSystematic("SM_Znunu_MET_mono","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("SM_Znunu_MET_search","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("SM_Znunu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("SM_Znunu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","PRW","PRW");

  // For unblinded
  // JET
  DrawSystematic("SM_h_znunu_monojet_met","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("SM_h_znunu_vbf_met","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("SM_h_znunu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("SM_h_znunu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","JET","JET");
  // Muon Efficiency
  DrawSystematic("SM_h_znunu_monojet_met","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("SM_h_znunu_vbf_met","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("SM_h_znunu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("SM_h_znunu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUON_EFF","MUON_EFF");
  // Muon
  DrawSystematic("SM_h_znunu_monojet_met","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("SM_h_znunu_vbf_met","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("SM_h_znunu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("SM_h_znunu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUONS","MUON_TTVA");
  // Electron
  DrawSystematic("SM_h_znunu_monojet_met","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("SM_h_znunu_vbf_met","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("SM_h_znunu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("SM_h_znunu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","EG","EL");
  // MET
  DrawSystematic("SM_h_znunu_monojet_met","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("SM_h_znunu_vbf_met","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("SM_h_znunu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("SM_h_znunu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MET","MET");
  // PRW
  DrawSystematic("SM_h_znunu_monojet_met","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("SM_h_znunu_vbf_met","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("SM_h_znunu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("SM_h_znunu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","PRW","PRW");




  // Zmumu + Jets
  // For blinded
  // JET
  DrawSystematic("SM_Zmumu_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("SM_Zmumu_MET_search","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("SM_Zmumu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("SM_Zmumu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","JET","JET");
  // Muon Efficiency
  DrawSystematic("SM_Zmumu_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("SM_Zmumu_MET_search","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("SM_Zmumu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("SM_Zmumu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUON_EFF","MUON_EFF");
  // Muon
  DrawSystematic("SM_Zmumu_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("SM_Zmumu_MET_search","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("SM_Zmumu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("SM_Zmumu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUONS","MUON_TTVA");
  // Electron
  DrawSystematic("SM_Zmumu_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("SM_Zmumu_MET_search","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("SM_Zmumu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("SM_Zmumu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","EG","EL");
  // MET
  DrawSystematic("SM_Zmumu_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("SM_Zmumu_MET_search","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("SM_Zmumu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("SM_Zmumu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MET","MET");
  // PRW
  DrawSystematic("SM_Zmumu_MET_mono","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("SM_Zmumu_MET_search","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("SM_Zmumu_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("SM_Zmumu_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","PRW","PRW");

  // For unblinded
  // JET
  DrawSystematic("SM_h_zmumu_monojet_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("SM_h_zmumu_vbf_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("SM_h_zmumu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("SM_h_zmumu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","JET","JET");
  // Muon Efficiency
  DrawSystematic("SM_h_zmumu_monojet_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("SM_h_zmumu_vbf_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("SM_h_zmumu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("SM_h_zmumu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUON_EFF","MUON_EFF");
  // Muon
  DrawSystematic("SM_h_zmumu_monojet_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("SM_h_zmumu_vbf_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("SM_h_zmumu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("SM_h_zmumu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUONS","MUON_TTVA");
  // Electron
  DrawSystematic("SM_h_zmumu_monojet_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("SM_h_zmumu_vbf_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("SM_h_zmumu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("SM_h_zmumu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","EG","EL");
  // MET
  DrawSystematic("SM_h_zmumu_monojet_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("SM_h_zmumu_vbf_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("SM_h_zmumu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("SM_h_zmumu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MET","MET");
  // PRW
  DrawSystematic("SM_h_zmumu_monojet_met_emulmet","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("SM_h_zmumu_vbf_met_emulmet","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("SM_h_zmumu_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("SM_h_zmumu_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","PRW","PRW");


  // Zee + Jets
  // For blinded
  // JET
  DrawSystematic("SM_Zee_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("SM_Zee_MET_search","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("SM_Zee_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("SM_Zee_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","JET","JET");
  // Muon Efficiency
  DrawSystematic("SM_Zee_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("SM_Zee_MET_search","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("SM_Zee_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("SM_Zee_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUON_EFF","MUON_EFF");
  // Muon
  DrawSystematic("SM_Zee_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("SM_Zee_MET_search","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("SM_Zee_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("SM_Zee_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUONS","MUON_TTVA");
  // Electron
  DrawSystematic("SM_Zee_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("SM_Zee_MET_search","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("SM_Zee_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("SM_Zee_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","EG","EL");
  // MET
  DrawSystematic("SM_Zee_MET_mono","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("SM_Zee_MET_search","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("SM_Zee_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("SM_Zee_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MET","MET");
  // PRW
  DrawSystematic("SM_Zee_MET_mono","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("SM_Zee_MET_search","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("SM_Zee_Mjj_search","M_{jj}",200.,4000.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("SM_Zee_DeltaPhiAll","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","PRW","PRW");

  // For unblinded
  // JET
  DrawSystematic("SM_h_zee_monojet_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("SM_h_zee_vbf_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("SM_h_zee_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","JET","JET");
  DrawSystematic("SM_h_zee_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","JET","JET");
  // Muon Efficiency
  DrawSystematic("SM_h_zee_monojet_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("SM_h_zee_vbf_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("SM_h_zee_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUON_EFF","MUON_EFF");
  DrawSystematic("SM_h_zee_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUON_EFF","MUON_EFF");
  // Muon
  DrawSystematic("SM_h_zee_monojet_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("SM_h_zee_vbf_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("SM_h_zee_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","MUONS","MUON_TTVA");
  DrawSystematic("SM_h_zee_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MUONS","MUON_TTVA");
  // Electron
  DrawSystematic("SM_h_zee_monojet_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("SM_h_zee_vbf_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("SM_h_zee_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","EG","EL");
  DrawSystematic("SM_h_zee_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","EG","EL");
  // MET
  DrawSystematic("SM_h_zee_monojet_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("SM_h_zee_vbf_met_emulmet","MET",200.,1400.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("SM_h_zee_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","MET","MET");
  DrawSystematic("SM_h_zee_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","MET","MET");
  // PRW
  DrawSystematic("SM_h_zee_monojet_met_emulmet","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("SM_h_zee_vbf_met_emulmet","PRW",200.,1400.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("SM_h_zee_vbf_mjj","M_{jj}",200.,4000.,1,true,true,707,"GeV","PRW","PRW");
  DrawSystematic("SM_h_zee_vbf_dPhijj","#Delta#Phi(j_{1},j_{2})",0.,pi,1,true,true,707,"rad","PRW","PRW");



}



