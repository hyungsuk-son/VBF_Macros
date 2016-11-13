#include <iostream>
#include <cmath>

#include "Rtypes.h"

#include "TCanvas.h"
#include "TFile.h"
#include "TROOT.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TRandom.h"
#include "TGraphErrors.h"
#include "TString.h"
#include "TAxis.h"
#include "TF1.h"
#include "THStack.h"
#include "map"
#include "TGraphAsymmErrors.h"
#include "TLegend.h"
#include "TStyle.h"
#include "vector"
#include "string"

void Draw_Data_MC_with_Sys(TString HISTO,TString XTITLE,float XMIN,float XMAX,int REBIN,bool LOGY,bool PRINT,int XDIV,TString UNITS)
{
  gROOT->ForceStyle();

  TString PATH("/home/hson/Work/Run2_Study/VBF_study/Macro/");

  // Retrieve files
  TString filename_MCData("hist_all_MC_Data.root");
  TString filename_Sys("hist_sys_uncertain.root");
  TFile *file_MCData = TFile::Open(PATH+filename_MCData);
  TFile *file_Sys = TFile::Open(PATH+filename_Sys);

  char name[1000];

  ///////////////////////////////////////
  // Retrieve Histograms (MC and Data) //
  ///////////////////////////////////////

  // Retrieve Data
  TH1F *h_Data = (TH1F*)file_MCData->Get("Data_"+HISTO);
  // Retirieve MC
  TH1F *h_SM = (TH1F*)file_MCData->Get("SM_MC_"+HISTO);
  //TH1F *h_Bkg = (TH1F*)file_MCData->Get("Bkg_MC_"+HISTO);
  TH1F *h_Znunu = (TH1F*)file_MCData->Get("Znunu_MC_"+HISTO);
  TH1F *h_Wenu = (TH1F*)file_MCData->Get("Wenu_MC_"+HISTO);
  TH1F *h_Wmunu = (TH1F*)file_MCData->Get("Wmunu_MC_"+HISTO);
  TH1F *h_Wtaunu = (TH1F*)file_MCData->Get("Wtaunu_MC_"+HISTO);
  TH1F *h_Zee = (TH1F*)file_MCData->Get("Zee_MC_"+HISTO);
  TH1F *h_Zmumu = (TH1F*)file_MCData->Get("Zmumu_MC_"+HISTO);
  TH1F *h_Ztautau = (TH1F*)file_MCData->Get("Ztautau_MC_"+HISTO);
  TH1F *h_ttbar = (TH1F*)file_MCData->Get("TTbar_MC_"+HISTO);
  TH1F *h_Multijet = (TH1F*)file_MCData->Get("Multijet_MC_"+HISTO);
  TH1F *h_Diboson = (TH1F*)file_MCData->Get("Diboson_MC_"+HISTO);

  // Define Stack
  THStack *h_stackSM = new THStack("sm","sm");


  // Set Style for Data
  h_Data->SetMarkerStyle(kFullCircle);
  h_Data->SetMarkerSize(0.8);
  h_Data->SetLineColor(kBlack);

  // Ratio of Data/MC
  TH1F *h_Ratio = (TH1F*)h_Data->Clone("Ratio");

  h_Ratio->Divide( (TH1F*)h_SM ); // Divided by MC (Data/MC)
  h_Ratio->SetMarkerStyle(kFullCircle);
  h_Ratio->SetMarkerSize(0.8);


  // Set style for MC backgrounds
  h_Multijet->SetLineColor(kBlack);
  h_Znunu->SetLineColor(kBlack);
  h_Wenu->SetLineColor(kBlack);
  h_Wmunu->SetLineColor(kBlack);
  h_Wtaunu->SetLineColor(kBlack);
  h_Zee->SetLineColor(kBlack);
  h_Zmumu->SetLineColor(kBlack);
  h_Ztautau->SetLineColor(kBlack);
  h_ttbar->SetLineColor(kBlack);
  h_Diboson->SetLineColor(kBlack);

  h_Multijet->SetFillColor(kGray);
  h_Znunu->SetFillColor(kRed-4);
  h_Wenu->SetFillColor(kCyan+1);
  h_Wmunu->SetFillColor(kBlue-3);
  h_Wtaunu->SetFillColor(kYellow-7);
  h_Zee->SetFillColor(kOrange+1);
  h_Zmumu->SetFillColor(kOrange+8);
  h_Ztautau->SetFillColor(kOrange-1);
  h_ttbar->SetFillColor(kGreen+2);
  h_Diboson->SetFillColor(kMagenta+1);


  // Fill Stack
  // Zmumu
  if ( HISTO.Contains("mumu") ) {
    h_stackSM->Add(h_Zee);
    h_stackSM->Add(h_Multijet);
    h_stackSM->Add(h_Znunu);
    h_stackSM->Add(h_Ztautau);
    h_stackSM->Add(h_Wtaunu);
    h_stackSM->Add(h_Wmunu);
    h_stackSM->Add(h_Wenu);
    h_stackSM->Add(h_Diboson);
    h_stackSM->Add(h_ttbar);
    h_stackSM->Add(h_Zmumu);
  }

  // Zee
  if ( HISTO.Contains("ee") ) {
    h_stackSM->Add(h_Zmumu);
    h_stackSM->Add(h_Multijet);
    h_stackSM->Add(h_Znunu);
    h_stackSM->Add(h_Ztautau);
    h_stackSM->Add(h_Wtaunu);
    h_stackSM->Add(h_Wmunu);
    h_stackSM->Add(h_Wenu);
    h_stackSM->Add(h_Diboson);
    h_stackSM->Add(h_ttbar);
    h_stackSM->Add(h_Zee);
  }

  // Znunu
  if ( HISTO.Contains("nunu") ){
    h_stackSM->Add(h_Multijet);
    h_stackSM->Add(h_Zee);
    h_stackSM->Add(h_Ztautau);
    h_stackSM->Add(h_Zmumu);
    h_stackSM->Add(h_Diboson);
    h_stackSM->Add(h_ttbar);
    h_stackSM->Add(h_Wenu);
    h_stackSM->Add(h_Wmunu);
    h_stackSM->Add(h_Wtaunu);
    h_stackSM->Add(h_Znunu);
  }




  ///////////////////////////////////////
  // Retrieve systematic uncertainties //
  ///////////////////////////////////////


  std::vector<std::string> systematics;
  systematics.push_back("");
  systematics.push_back("EG_RESOLUTION_ALL__1down");
  systematics.push_back("EG_RESOLUTION_ALL__1up");
  systematics.push_back("EG_SCALE_ALL__1down");
  systematics.push_back("EG_SCALE_ALL__1up");
  systematics.push_back("EL_EFF_ID_TotalCorrUncertainty__1down");
  systematics.push_back("EL_EFF_ID_TotalCorrUncertainty__1up");
  systematics.push_back("EL_EFF_Iso_TotalCorrUncertainty__1down");
  systematics.push_back("EL_EFF_Iso_TotalCorrUncertainty__1up");
  systematics.push_back("EL_EFF_Reco_TotalCorrUncertainty__1down");
  systematics.push_back("EL_EFF_Reco_TotalCorrUncertainty__1up");
  systematics.push_back("EL_EFF_TriggerEff_TotalCorrUncertainty__1down");
  systematics.push_back("EL_EFF_TriggerEff_TotalCorrUncertainty__1up");
  systematics.push_back("EL_EFF_Trigger_TotalCorrUncertainty__1down");
  systematics.push_back("EL_EFF_Trigger_TotalCorrUncertainty__1up");
  systematics.push_back("JET_EtaIntercalibration_NonClosure__1up");
  systematics.push_back("JET_EtaIntercalibration_NonClosure__1down");
  systematics.push_back("JET_GroupedNP_1__1up");
  systematics.push_back("JET_GroupedNP_1__1down");
  systematics.push_back("JET_GroupedNP_2__1up");
  systematics.push_back("JET_GroupedNP_2__1down");
  systematics.push_back("JET_GroupedNP_3__1up");
  systematics.push_back("JET_GroupedNP_3__1down");
  systematics.push_back("JET_JER_SINGLE_NP__1up");
  systematics.push_back("JvtEfficiencyDown");
  systematics.push_back("JvtEfficiencyUp");
  systematics.push_back("MET_SoftTrk_ResoPara");
  systematics.push_back("MET_SoftTrk_ResoPerp");
  systematics.push_back("MET_SoftTrk_ScaleDown");
  systematics.push_back("MET_SoftTrk_ScaleUp");
  systematics.push_back("MUONS_ID__1down");
  systematics.push_back("MUONS_ID__1up");
  systematics.push_back("MUONS_MS__1down");
  systematics.push_back("MUONS_MS__1up");
  systematics.push_back("MUONS_SCALE__1down");
  systematics.push_back("MUONS_SCALE__1up");
  systematics.push_back("MUON_EFF_STAT__1down");
  systematics.push_back("MUON_EFF_STAT__1up");
  systematics.push_back("MUON_EFF_STAT_LOWPT__1down");
  systematics.push_back("MUON_EFF_STAT_LOWPT__1up");
  systematics.push_back("MUON_EFF_SYS__1down");
  systematics.push_back("MUON_EFF_SYS__1up");
  systematics.push_back("MUON_EFF_SYS_LOWPT__1down");
  systematics.push_back("MUON_EFF_SYS_LOWPT__1up");
  systematics.push_back("MUON_EFF_TrigStatUncertainty__1down");
  systematics.push_back("MUON_EFF_TrigStatUncertainty__1up");
  systematics.push_back("MUON_EFF_TrigSystUncertainty__1down");
  systematics.push_back("MUON_EFF_TrigSystUncertainty__1up");
  systematics.push_back("MUON_ISO_STAT__1down");
  systematics.push_back("MUON_ISO_STAT__1up");
  systematics.push_back("MUON_ISO_SYS__1down");
  systematics.push_back("MUON_ISO_SYS__1up");
  systematics.push_back("MUON_TTVA_STAT__1down");
  systematics.push_back("MUON_TTVA_STAT__1up");
  systematics.push_back("MUON_TTVA_SYS__1down");
  systematics.push_back("MUON_TTVA_SYS__1up");
  systematics.push_back("PRW_DATASF__1down");
  systematics.push_back("PRW_DATASF__1up");



  // Systematics histogram
  std::map<TString, TH1*> h_background_sys;

  // Retrieve All systematic histograms (for SM backgrounds)
  std::vector<std::string>::const_iterator sys;
  for (sys = systematics.begin(); sys != systematics.end(); sys++){
    TString sys_name = *sys;
    h_background_sys[sys_name] = (TH1F*)file_Sys->Get("SM_"+HISTO+sys_name);
  }



  //////////////////////////////////
  // Total systematic uncertainty //
  //////////////////////////////////

  // Calculate the total systematic uncertainty from all systematics sources
  // Tot_sys_error = Sqrt( max( abs(sys1_up - nominal) ,abs(sys1_down - nominal))^2 + max( abs(sys2_up - nominal) ,abs(sys2_down - nominal))^2 + ... )  where sys1_up is the ratio of sys1_up to nominal
  TH1F *h_total_sys = (TH1F*)h_background_sys[""]->Clone("h_total_sys");
  h_total_sys->SetLineColor(kBlack);

  for (int binno = 0; binno < h_background_sys[""]->GetNbinsX() + 2; ++binno) {
    if ( h_background_sys[""]->GetBinContent(binno) == 0. ) { // When using blinded histograms, bin contents has 0 values which turns out that total uncertainty become very high in blinded regions.
      h_total_sys->SetBinError(binno, 0.); // Make errors 0% in blinded region.
    }
    else {
      float nominal = h_background_sys[""]->GetBinContent(binno);
      float syst_tot = std::sqrt( std::pow(std::max(std::abs(h_background_sys["EG_RESOLUTION_ALL__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["EG_RESOLUTION_ALL__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["EG_SCALE_ALL__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["EG_SCALE_ALL__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["EL_EFF_ID_TotalCorrUncertainty__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["EL_EFF_ID_TotalCorrUncertainty__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["EL_EFF_Iso_TotalCorrUncertainty__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["EL_EFF_Iso_TotalCorrUncertainty__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["EL_EFF_Reco_TotalCorrUncertainty__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["EL_EFF_Reco_TotalCorrUncertainty__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["EL_EFF_TriggerEff_TotalCorrUncertainty__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["EL_EFF_TriggerEff_TotalCorrUncertainty__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["EL_EFF_Trigger_TotalCorrUncertainty__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["EL_EFF_Trigger_TotalCorrUncertainty__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["JET_EtaIntercalibration_NonClosure__1up"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["JET_EtaIntercalibration_NonClosure__1down"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["JET_GroupedNP_1__1up"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["JET_GroupedNP_1__1down"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["JET_GroupedNP_2__1up"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["JET_GroupedNP_2__1down"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["JET_GroupedNP_3__1up"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["JET_GroupedNP_3__1down"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::abs(h_background_sys["JET_JER_SINGLE_NP__1up"]->GetBinContent(binno)-nominal),2.) +
          std::pow(std::max(std::abs(h_background_sys["JvtEfficiencyDown"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["JvtEfficiencyUp"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::abs(h_background_sys["MET_SoftTrk_ResoPara"]->GetBinContent(binno)-nominal),2.) +
          std::pow(std::abs(h_background_sys["MET_SoftTrk_ResoPerp"]->GetBinContent(binno)-nominal),2.) +
          std::pow(std::max(std::abs(h_background_sys["MET_SoftTrk_ScaleDown"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MET_SoftTrk_ScaleUp"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUONS_ID__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUONS_ID__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUONS_MS__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUONS_MS__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUONS_SCALE__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUONS_SCALE__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUON_EFF_STAT__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUON_EFF_STAT__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUON_EFF_STAT_LOWPT__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUON_EFF_STAT_LOWPT__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUON_EFF_SYS__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUON_EFF_SYS__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUON_EFF_SYS_LOWPT__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUON_EFF_SYS_LOWPT__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUON_EFF_TrigStatUncertainty__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUON_EFF_TrigStatUncertainty__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUON_EFF_TrigSystUncertainty__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUON_EFF_TrigSystUncertainty__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUON_ISO_STAT__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUON_ISO_STAT__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUON_ISO_SYS__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUON_ISO_SYS__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUON_TTVA_STAT__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUON_TTVA_STAT__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUON_TTVA_SYS__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUON_TTVA_SYS__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["PRW_DATASF__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["PRW_DATASF__1up"]->GetBinContent(binno)-nominal)),2.) // commented out asked by Prof. Beauchemin
          );
      h_total_sys->SetBinError(binno, syst_tot);
    }
  }

  // Set style for h_total_sys
  h_total_sys->SetFillColor(kBlack);
  h_total_sys->SetFillStyle(3004);
  h_total_sys->SetMarkerSize(0);




  // Calculate the total fraction uncertainty from all systematics sources (add it to the ratio)
  // Tot_sys_frac = Sqrt( max( abs(sys1_up - nominal) ,sys1_down - nominal)^2 + max( abs(sys2_up - nominal) ,sys2_down - nominal)^2 + ... ) / nominal  , where sys1_up is the ratio of sys1_up to nominal
  TH1F *h_total_sys_frac = (TH1F*)h_background_sys[""]->Clone("h_total_sys_frac");
  h_total_sys_frac->Reset();
  h_total_sys_frac->SetLineColor(kBlack);

  for (int binno = 0; binno < h_background_sys[""]->GetNbinsX() + 2; ++binno) {
    if ( h_background_sys[""]->GetBinContent(binno) == 0. ) { // When using blinded histograms, bin contents has 0 values which turns out that total uncertainty become very high in blinded regions.
      h_total_sys_frac->SetBinContent(binno, 0.); // Make contents 0% in blinded region.
      h_total_sys_frac->SetBinError(binno, 0.); // Make errors 0% in blinded region.
    }
    else {
      h_total_sys_frac->SetBinContent(binno, 1.); // Make contents 1. for each bin for ratio plot
      float nominal = h_background_sys[""]->GetBinContent(binno);
      float syst_tot_frac = std::sqrt( std::pow(std::max(std::abs(h_background_sys["EG_RESOLUTION_ALL__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["EG_RESOLUTION_ALL__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["EG_SCALE_ALL__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["EG_SCALE_ALL__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["EL_EFF_ID_TotalCorrUncertainty__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["EL_EFF_ID_TotalCorrUncertainty__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["EL_EFF_Iso_TotalCorrUncertainty__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["EL_EFF_Iso_TotalCorrUncertainty__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["EL_EFF_Reco_TotalCorrUncertainty__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["EL_EFF_Reco_TotalCorrUncertainty__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["EL_EFF_TriggerEff_TotalCorrUncertainty__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["EL_EFF_TriggerEff_TotalCorrUncertainty__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["EL_EFF_Trigger_TotalCorrUncertainty__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["EL_EFF_Trigger_TotalCorrUncertainty__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["JET_EtaIntercalibration_NonClosure__1up"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["JET_EtaIntercalibration_NonClosure__1down"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["JET_GroupedNP_1__1up"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["JET_GroupedNP_1__1down"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["JET_GroupedNP_2__1up"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["JET_GroupedNP_2__1down"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["JET_GroupedNP_3__1up"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["JET_GroupedNP_3__1down"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::abs(h_background_sys["JET_JER_SINGLE_NP__1up"]->GetBinContent(binno)-nominal),2.) +
          std::pow(std::max(std::abs(h_background_sys["JvtEfficiencyDown"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["JvtEfficiencyUp"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::abs(h_background_sys["MET_SoftTrk_ResoPara"]->GetBinContent(binno)-nominal),2.) +
          std::pow(std::abs(h_background_sys["MET_SoftTrk_ResoPerp"]->GetBinContent(binno)-nominal),2.) +
          std::pow(std::max(std::abs(h_background_sys["MET_SoftTrk_ScaleDown"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MET_SoftTrk_ScaleUp"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUONS_ID__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUONS_ID__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUONS_MS__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUONS_MS__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUONS_SCALE__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUONS_SCALE__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUON_EFF_STAT__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUON_EFF_STAT__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUON_EFF_STAT_LOWPT__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUON_EFF_STAT_LOWPT__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUON_EFF_SYS__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUON_EFF_SYS__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUON_EFF_SYS_LOWPT__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUON_EFF_SYS_LOWPT__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUON_EFF_TrigStatUncertainty__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUON_EFF_TrigStatUncertainty__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUON_EFF_TrigSystUncertainty__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUON_EFF_TrigSystUncertainty__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUON_ISO_STAT__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUON_ISO_STAT__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUON_ISO_SYS__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUON_ISO_SYS__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUON_TTVA_STAT__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUON_TTVA_STAT__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["MUON_TTVA_SYS__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["MUON_TTVA_SYS__1up"]->GetBinContent(binno)-nominal)),2.) +
          std::pow(std::max(std::abs(h_background_sys["PRW_DATASF__1down"]->GetBinContent(binno)-nominal),std::abs(h_background_sys["PRW_DATASF__1up"]->GetBinContent(binno)-nominal)),2.) // commented out asked by Prof. Beauchemin
          ) / nominal;
      h_total_sys_frac->SetBinError(binno, syst_tot_frac);
    }
  }


  // Set style for h_total_sys_frac
  h_total_sys_frac->SetFillColor(kBlack);
  h_total_sys_frac->SetFillStyle(3004);
  h_total_sys_frac->SetMarkerSize(0);












  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);


  // Draw Data/MC Comparison plots
  TCanvas *can = new TCanvas("can_"+HISTO,"can_"+HISTO,700,600);
  can->cd(1);
  can->SetBottomMargin(0.3);
  //can->SetRightMargin(0.2);
  if (LOGY) gPad->SetLogy();
  TH1F *h_aux = (TH1F*)h_SM->Clone("aux");
  h_aux->Reset();
  if (h_aux->GetBinWidth(1) != h_aux->GetBinWidth(4)) sprintf(name,"Entries");
  else {
    if (h_aux->GetBinWidth(1) >= 1) {
      sprintf(name,"Events / %1.0f %s",h_aux->GetBinWidth(1),UNITS.Data());
    }
    else {
      sprintf(name,"Events / %1.2f %s",h_aux->GetBinWidth(1),UNITS.Data());
    }
  }
  h_aux->GetYaxis()->SetTitle(name);

  //h_aux->GetXaxis()->SetTitle(XTITLE);
  h_aux->GetXaxis()->SetTitleSize(0.0);
  h_aux->GetXaxis()->SetLabelSize(0.0);
  h_aux->GetYaxis()->SetTitleSize(0.028);
  h_aux->GetYaxis()->SetLabelSize(0.028);
  h_aux->GetYaxis()->SetTitleOffset(1.4);
  h_aux->GetYaxis()->SetNdivisions(505);
  h_aux->GetXaxis()->SetNdivisions(XDIV);
  h_aux->GetXaxis()->SetRangeUser(XMIN,XMAX);
  h_aux->SetMinimum(0.5);
  //h_aux->SetMaximum(1.2*h_Data->GetBinContent(h_Data->GetMaximumBin()));
  float ymax; // Set maximum y xaxis depending on Logy or not
  if (LOGY) ymax = 100.*h_Data->GetBinContent(h_Data->GetMaximumBin());
  else ymax = 2.*h_Data->GetBinContent(h_Data->GetMaximumBin());
  h_aux->SetMaximum(ymax);
  h_aux->Draw();
  h_stackSM->Draw("same hist");
  h_Data->Draw("same E");
  h_total_sys->Draw("same E2");
  TLegend *leg = new TLegend(0.69,0.63,0.90,0.88);
  //leg->SetHeader("Presel. & Trigger");

  //leg->SetMargin(0.1);
  leg->SetShadowColor(0);
  leg->SetLineColor(0);
  leg->SetFillStyle(0);
  leg->SetFillColor(0);
  leg->SetTextFont(42);
  leg->SetTextSize(0.025);
  leg->SetBorderSize(0);
  leg->AddEntry(h_Data,"Data 2015","P");
  leg->AddEntry(h_total_sys,"MC Syst. Unc.","F");
  if (HISTO.Contains("mumu") || HISTO.Contains("ee") ) {
    if (HISTO.Contains("mumu")) leg->AddEntry(h_Zmumu,"Z(#rightarrow #mu#mu)+jets","F"); // Z->mumu
    if (HISTO.Contains("ee")) leg->AddEntry(h_Zee,"Z(#rightarrow ee)+jets","F"); // Z->ee
    leg->AddEntry(h_ttbar,"t#bar{t} (+X) + single top","F");
    leg->AddEntry(h_Diboson,"Diboson","F");
    leg->AddEntry(h_Wenu,"W(#rightarrow e#nu)+jets","F");
    leg->AddEntry(h_Wmunu,"W(#rightarrow #mu#nu)+jets","F");
    leg->AddEntry(h_Wtaunu,"W(#rightarrow #tau#nu)+jets","F");
    leg->AddEntry(h_Ztautau,"Z(#rightarrow #tau#tau)+jets","F");
    leg->AddEntry(h_Multijet,"Multijet","F");
  }
  if (HISTO.Contains("nunu")) {
    leg->AddEntry(h_Znunu,"Z(#rightarrow #nu#nu)+jets","F"); // Z->nunu
    leg->AddEntry(h_Wtaunu,"W(#rightarrow #tau#nu)+jets","F");
    leg->AddEntry(h_Wmunu,"W(#rightarrow #mu#nu)+jets","F");
    leg->AddEntry(h_Wenu,"W(#rightarrow e#nu)+jets","F");
    leg->AddEntry(h_ttbar,"t#bar{t} (+X) + single top","F");
    leg->AddEntry(h_Diboson,"Diboson","F");
    leg->AddEntry(h_Zmumu,"Z(#rightarrow #mu#mu)+jets","F"); // Z->mumu
    leg->AddEntry(h_Ztautau,"Z(#rightarrow #tau#tau)+jets","F");
    leg->AddEntry(h_Zee,"Z(#rightarrow ee)+jets","F"); // Z->ee
    leg->AddEntry(h_Multijet,"Multijet","F");
  }
  leg->Draw();
  gPad->RedrawAxis();
  TPad* pad = new TPad("pad", "pad", 0., 0., 1., 1.);
  pad->SetTopMargin(0.7);
  //pad->SetRightMargin(0.2);
  pad->SetFillColor(0);
  pad->SetFillStyle(0);
  pad->Draw();
  pad->cd(0);
  gPad->SetGridy();
  h_Ratio->SetMinimum(0.5);
  h_Ratio->SetMaximum(1.5);
  h_Ratio->GetYaxis()->SetTitle("Data / MC");
  if (UNITS == "") {
    h_Ratio->GetXaxis()->SetTitle(XTITLE);
  }
  else {
    h_Ratio->GetXaxis()->SetTitle(XTITLE+" ["+UNITS+"]");
  }
  h_Ratio->GetYaxis()->SetNdivisions(505);
  h_Ratio->GetYaxis()->SetTickLength(0.06);
  h_Ratio->GetXaxis()->SetTitleSize(0.028);
  h_Ratio->GetXaxis()->SetLabelSize(0.028);
  h_Ratio->GetYaxis()->SetTitleSize(0.028);
  h_Ratio->GetYaxis()->SetLabelSize(0.028);
  h_Ratio->GetYaxis()->SetTitleOffset(1.4);
  h_Ratio->GetXaxis()->SetNdivisions(XDIV);
  h_Ratio->GetYaxis()->CenterTitle(kTRUE);
  h_Ratio->GetXaxis()->SetRangeUser(XMIN,XMAX);
  h_Ratio->Draw();
  h_total_sys_frac->Draw("same E2");



  if (PRINT) {
    //can->Print(TString(can->GetTitle())+".png");
    can->Print(HISTO+".pdf");

    // Delete objects
    delete can;
    delete file_MCData;
    delete file_Sys;
  }

}


/*
#ifndef __CINT__
int main(){
DrawHistogram(HISTO,XTITLE,XMIN,XMAX,REBIN,LOGY,PRINT,XDIV,UNITS);
}
#endif
 */
