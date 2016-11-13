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

void DrawSystematic(TString HISTO,TString XTITLE,float XMIN,float XMAX,int REBIN,bool LOGY,bool PRINT,int XDIV,TString UNITS,TString sysObj1,TString sysObj2)
{
  gROOT->ForceStyle();
  TString PATH("/home/hson/Work/Run2_Study/VBF_study/Macro/");
  TString fileName("hist_sys_uncertain.root");

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

  char name[1000];

  // Open file
  TFile *inf;
  inf = TFile::Open(PATH+fileName);

  // Systematics histogram
  std::map<TString, TH1*> h_background_sys;

  // Retrieve All systematic histograms
  //int FILLCOLOR[16] = {kBlack,kRed,kBlue,kMagenta-10,kYellow-10,kGreen+2,kGreen-8,kGreen-8,kGreen-8,kGreen-8,kGreen-8,kGreen-8,kBlue-6,kBlue-8,kBlue-9,kBlue-10};
  int count_color = 2;
  std::vector<std::string>::const_iterator sys;
  for (sys = systematics.begin(); sys != systematics.end(); sys++){
    TString sys_name = *sys;
    h_background_sys[sys_name] = (TH1F*)inf->Get(HISTO+sys_name);
    if ( sys_name.BeginsWith(sysObj1) || sys_name.BeginsWith(sysObj2)){
    //h_background_sys[sys_name]->SetLineColor(FILLCOLOR[count_color]);
    if (count_color == 10) count_color = 41;
    h_background_sys[sys_name]->SetLineColor(count_color);
    count_color++;
    }
  }


  /////////////////////
  // Ratio histogram //
  std::map<TString, TH1*> h_ratio_sys;

  TString ratio_sys_name = "h_ratio_sys_";

  for (sys = systematics.begin(); sys != systematics.end(); sys++){
    TString sys_name = *sys;
    h_ratio_sys[sys_name] = (TH1F*)h_background_sys[sys_name]->Clone();
    h_ratio_sys[sys_name]->SetName(ratio_sys_name+sys_name);
    h_ratio_sys[sys_name]->Divide( (TH1F*)h_background_sys[""] ); // Divide systematics by nominal
    //h_ratio_sys[sys_name]->SetMarkerStyle(kFullCircle);
    //h_ratio_sys[sys_name]->SetMarkerSize(0.8);
  }



  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);


  ///////////////////////////////////
  // Draw Systematic Uncertainties //
  TCanvas *can = new TCanvas("can_"+HISTO,"can_"+HISTO,700,600);

  can->cd(1);
  can->SetBottomMargin(0.3);
  //can->SetRightMargin(0.2);
  if (LOGY) gPad->SetLogy();
  //TH1F *h_aux = (TH1F*)h_Bkg->Clone("aux");



  //h_aux->Reset();
  if ( h_background_sys[""]->GetBinWidth(1) !=  h_background_sys[""]->GetBinWidth(4)) sprintf(name,"Entries");
  else {
    if (h_background_sys[""]->GetBinWidth(1) >= 1) {
      sprintf(name,"Events / %1.0f %s",h_background_sys[""]->GetBinWidth(1),UNITS.Data());
    }
    else {
      sprintf(name,"Events / %1.2f %s",h_background_sys[""]->GetBinWidth(1),UNITS.Data());
    }
  }
  h_background_sys[""]->GetYaxis()->SetTitle(name);

  //h_background_sys[""]->GetXaxis()->SetTitle(XTITLE);
  h_background_sys[""]->GetXaxis()->SetTitleSize(0.0);
  h_background_sys[""]->GetXaxis()->SetLabelSize(0.0);
  h_background_sys[""]->GetYaxis()->SetTitleSize(0.028);
  h_background_sys[""]->GetYaxis()->SetLabelSize(0.028);
  h_background_sys[""]->GetYaxis()->SetTitleOffset(1.4);
  h_background_sys[""]->GetYaxis()->SetNdivisions(505);
  h_background_sys[""]->GetXaxis()->SetNdivisions(XDIV);
  h_background_sys[""]->GetXaxis()->SetRangeUser(XMIN,XMAX);
  if ( HISTO.Contains("mjj") || HISTO.Contains("Mjj") ) {
    h_background_sys[""]->SetMinimum(0.0001);
  } else if ( HISTO.Contains("dPhijj") || HISTO.Contains("DeltaPhiAll") ) {
    h_background_sys[""]->SetMinimum(1.);
  } else {
    h_background_sys[""]->SetMinimum(0.001);
  }

  //h_background_sys[""]->SetMaximum(1.2*h_sample[0]->GetBinContent(h_sample[0]->GetMaximumBin()));
  float ymax; // Set maximum y xaxis depending on Logy or not
  if (LOGY) ymax = 10.*h_background_sys[""]->GetBinContent(h_background_sys[""]->GetMaximumBin());
  else ymax = 2.*h_background_sys[""]->GetBinContent(h_background_sys[""]->GetMaximumBin());
  h_background_sys[""]->SetMaximum(ymax);
  h_background_sys[""]->SetLineWidth(2);
  h_background_sys[""]->SetLineColor(kBlack);
  h_background_sys[""]->Draw("HIST"); //To visualize it without errors use HIST together with the required option.
  for (sys = systematics.begin(); sys != systematics.end(); sys++){
    TString sys_name = *sys;
    if ( sys_name.BeginsWith(sysObj1) || sys_name.BeginsWith(sysObj2) ){
      h_background_sys[sys_name]->SetLineWidth(2);
      h_background_sys[sys_name]->Draw("SAME HIST");
    }
  }
  TLegend *leg = new TLegend(0.47,0.66,0.78,0.88);
  //leg->SetHeader("Presel. & Trigger");

  //leg->SetMargin(0.1);
  leg->SetShadowColor(0);
  leg->SetLineColor(0);
  leg->SetFillStyle(0);
  leg->SetFillColor(0);
  leg->SetTextFont(42);
  leg->SetTextSize(0.020);
  leg->SetBorderSize(0);
  leg->AddEntry(h_background_sys[""],"nominal","l");
  for (sys = systematics.begin(); sys != systematics.end(); sys++){
    TString sys_name = *sys;
    if ( sys_name.BeginsWith(sysObj1) || sys_name.BeginsWith(sysObj2)){
      //sprintf(name,"QCD (#times %1.2f)",kfactor);
      leg->AddEntry(h_background_sys[sys_name],sys_name,"l");
    }
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
  if (HISTO.BeginsWith("McEstBkg")) { // systematics plots with only MC backgrounds
    h_ratio_sys[""]->SetMinimum(0.7);
    h_ratio_sys[""]->SetMaximum(1.3);
  }
  if (HISTO.BeginsWith("SM")) { // systematics plots with all MC backgrounds including signal
    h_ratio_sys[""]->SetMinimum(0.88);
    h_ratio_sys[""]->SetMaximum(1.12);
  }
  h_ratio_sys[""]->GetYaxis()->SetTitle("ratio to nominal");
  if (UNITS == "") {
    h_ratio_sys[""]->GetXaxis()->SetTitle(XTITLE);
  }
  else {
    h_ratio_sys[""]->GetXaxis()->SetTitle(XTITLE+" ["+UNITS+"]");
  }
  h_ratio_sys[""]->GetYaxis()->SetNdivisions(505);
  h_ratio_sys[""]->GetYaxis()->SetTickLength(0.06);
  h_ratio_sys[""]->GetXaxis()->SetTitleSize(0.028);
  h_ratio_sys[""]->GetXaxis()->SetLabelSize(0.028);
  h_ratio_sys[""]->GetYaxis()->SetTitleSize(0.028);
  h_ratio_sys[""]->GetYaxis()->SetLabelSize(0.028);
  h_ratio_sys[""]->GetYaxis()->SetTitleOffset(1.4);
  h_ratio_sys[""]->GetXaxis()->SetNdivisions(XDIV);
  h_ratio_sys[""]->GetYaxis()->CenterTitle(kTRUE);
  h_ratio_sys[""]->GetXaxis()->SetRangeUser(XMIN,XMAX);
  h_ratio_sys[""]->SetMarkerColor(0);
  h_ratio_sys[""]->SetLineColor(0);
  h_ratio_sys[""]->Draw();
  for (sys = systematics.begin(); sys != systematics.end(); sys++){
    TString sys_name = *sys;
    if ( sys_name.BeginsWith(sysObj1) || sys_name.BeginsWith(sysObj2)){
      h_ratio_sys[sys_name]->SetLineWidth(2);
      h_ratio_sys[sys_name]->Draw("same hist");
    }
  }









  ////////////////////////////
  // Uncertainty percentage //
  ////////////////////////////
  //The uncertainty % for the systematic source is obtained by:
  // 100.* (Dist_syst_i - central prediction)/central prediction
  std::map<TString, TH1*> h_percent_sys;
  TH1F *h_percent_aux; // for drawing

  TString percent_sys_name = "h_percent_sys_";

  for (sys = systematics.begin(); sys != systematics.end(); sys++){
    TString sys_name = *sys;
    // Calculate Uncertainty percentage for each systematics source
    //if ( sys_name.BeginsWith(sysObj1) || sys_name.BeginsWith(sysObj2)){
      h_percent_sys[sys_name] = (TH1F*)h_background_sys[sys_name]->Clone();
      h_percent_sys[sys_name]->Reset();
      h_percent_sys[sys_name]->SetName(percent_sys_name+sys_name);
      for (int binno = 0; binno < h_percent_sys[sys_name]->GetNbinsX() + 2; ++binno) {
        float nominal_val = h_background_sys[""]->GetBinContent(binno); // nominal value
        float uncertain_val = h_background_sys[sys_name]->GetBinContent(binno); // Uncertainty value
        float percent_uncertain_val = 0.;
        if (nominal_val != 0.) percent_uncertain_val = 100.*(uncertain_val - nominal_val)/nominal_val; // Uncertainty %
        h_percent_sys[sys_name]->SetBinContent(binno, percent_uncertain_val);
        //cout << "binno = " << binno << "  nominal_val = " << nominal_val << endl;
        //cout << "binno = " << binno << "  uncertain_val = " << uncertain_val << endl;
        //cout << "binno = " << binno << "  percent_uncertain_val = " << percent_uncertain_val << endl;
      }
      //h_percent_sys[sys_name]->SetMarkerStyle(kFullCircle);
      //h_percent_sys[sys_name]->SetMarkerSize(0.8);
      h_percent_aux = (TH1F*)h_percent_sys[sys_name]->Clone();
    //}
  }


  // Draw Systematic Uncertainties (Hugo)
  TCanvas *can2 = new TCanvas("can2_"+HISTO,"can2_"+HISTO,700,600);

  can2->cd();
  // For drawing guide
  h_percent_aux->GetYaxis()->SetTitle("Percent");
  h_percent_aux->GetXaxis()->SetTitleSize(0.0);
  h_percent_aux->GetXaxis()->SetLabelSize(0.0);
  if (UNITS == "") {
    h_percent_aux->GetXaxis()->SetTitle(XTITLE);
  }
  else {
    h_percent_aux->GetXaxis()->SetTitle(XTITLE+" ["+UNITS+"]");
  }
  h_percent_aux->GetYaxis()->SetTitleSize(0.028);
  h_percent_aux->GetYaxis()->SetLabelSize(0.028);
  h_percent_aux->GetYaxis()->SetTitleOffset(1.4);
  h_percent_aux->GetYaxis()->SetNdivisions(505);
  h_percent_aux->GetXaxis()->SetTitleSize(0.028);
  h_percent_aux->GetXaxis()->SetLabelSize(0.028);
  h_percent_aux->GetXaxis()->SetNdivisions(XDIV);
  h_percent_aux->GetXaxis()->SetRangeUser(XMIN,XMAX);
  h_percent_aux->SetMinimum(-10.);
  h_percent_aux->SetMaximum(20.);
  h_percent_aux->SetMarkerColor(0);
  h_percent_aux->SetLineColor(0);
  h_percent_aux->Draw();

  for (sys = systematics.begin(); sys != systematics.end(); sys++){
    TString sys_name = *sys;
    if ( sys_name.BeginsWith(sysObj1) || sys_name.BeginsWith(sysObj2) ){
      h_percent_sys[sys_name]->Draw("SAME HIST");
    }
  }
  TLegend *leg2 = new TLegend(0.47,0.66,0.78,0.88);
  //leg2->SetHeader("Presel. & Trigger");

  //leg2->SetMargin(0.1);
  leg2->SetShadowColor(0);
  leg2->SetLineColor(0);
  leg2->SetFillStyle(0);
  leg2->SetFillColor(0);
  leg2->SetTextFont(42);
  leg2->SetTextSize(0.021);
  leg2->SetBorderSize(0);
  for (sys = systematics.begin(); sys != systematics.end(); sys++){
    TString sys_name = *sys;
    if ( sys_name.BeginsWith(sysObj1) || sys_name.BeginsWith(sysObj2) ){
      //sprintf(name,"QCD (#times %1.2f)",kfactor);
      leg2->AddEntry(h_percent_sys[sys_name],sys_name,"l");
    }
  }
  leg2->Draw();
  gPad->RedrawAxis();









  //////////////////////////////////
  // Total systematic uncertainty //
  //////////////////////////////////
  //The Total systematic uncertainty is obtained by:
  // Syst_tot = sqrt[max(S1up, S1down)^2 + max(S2up, S2down)^2+…]

  /*
  // Calculate the total systematic uncertainty from all systematics sources
  TH1F *h_total_sys = (TH1F*)h_background_sys["JET_GroupedNP_1__1up"]->Clone("h_total_sys");
  h_total_sys->Reset();

  for (int binno = 0; binno < h_background_sys["JET_GroupedNP_1__1up"]->GetNbinsX() + 2; ++binno) {
    float syst_tot = std::sqrt( std::pow(std::max(h_background_sys["EG_RESOLUTION_ALL__1down"]->GetBinContent(binno),h_background_sys["EG_RESOLUTION_ALL__1up"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["EG_SCALE_ALL__1down"]->GetBinContent(binno),h_background_sys["EG_SCALE_ALL__1up"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["EL_EFF_ID_TotalCorrUncertainty__1down"]->GetBinContent(binno),h_background_sys["EL_EFF_ID_TotalCorrUncertainty__1up"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["EL_EFF_Iso_TotalCorrUncertainty__1down"]->GetBinContent(binno),h_background_sys["EL_EFF_Iso_TotalCorrUncertainty__1up"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["EL_EFF_Reco_TotalCorrUncertainty__1down"]->GetBinContent(binno),h_background_sys["EL_EFF_Reco_TotalCorrUncertainty__1up"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["EL_EFF_TriggerEff_TotalCorrUncertainty__1down"]->GetBinContent(binno),h_background_sys["EL_EFF_TriggerEff_TotalCorrUncertainty__1up"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["EL_EFF_Trigger_TotalCorrUncertainty__1down"]->GetBinContent(binno),h_background_sys["EL_EFF_Trigger_TotalCorrUncertainty__1up"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["JET_EtaIntercalibration_NonClosure__1up"]->GetBinContent(binno),h_background_sys["JET_EtaIntercalibration_NonClosure__1down"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["JET_GroupedNP_1__1up"]->GetBinContent(binno),h_background_sys["JET_GroupedNP_1__1down"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["JET_GroupedNP_2__1up"]->GetBinContent(binno),h_background_sys["JET_GroupedNP_2__1down"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["JET_GroupedNP_3__1up"]->GetBinContent(binno),h_background_sys["JET_GroupedNP_3__1down"]->GetBinContent(binno)),2.) +
        std::pow(h_background_sys["JET_JER_SINGLE_NP__1up"]->GetBinContent(binno),2.) +
        std::pow(std::max(h_background_sys["JvtEfficiencyDown"]->GetBinContent(binno),h_background_sys["JvtEfficiencyUp"]->GetBinContent(binno)),2.) +
        std::pow(h_background_sys["MET_SoftTrk_ResoPara"]->GetBinContent(binno),2.) +
        std::pow(h_background_sys["MET_SoftTrk_ResoPerp"]->GetBinContent(binno),2.) +
        std::pow(std::max(h_background_sys["MET_SoftTrk_ScaleDown"]->GetBinContent(binno),h_background_sys["MET_SoftTrk_ScaleUp"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["MUONS_ID__1down"]->GetBinContent(binno),h_background_sys["MUONS_ID__1up"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["MUONS_MS__1down"]->GetBinContent(binno),h_background_sys["MUONS_MS__1up"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["MUONS_SCALE__1down"]->GetBinContent(binno),h_background_sys["MUONS_SCALE__1up"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["MUON_EFF_STAT__1down"]->GetBinContent(binno),h_background_sys["MUON_EFF_STAT__1up"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["MUON_EFF_STAT_LOWPT__1down"]->GetBinContent(binno),h_background_sys["MUON_EFF_STAT_LOWPT__1up"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["MUON_EFF_SYS__1down"]->GetBinContent(binno),h_background_sys["MUON_EFF_SYS__1up"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["MUON_EFF_SYS_LOWPT__1down"]->GetBinContent(binno),h_background_sys["MUON_EFF_SYS_LOWPT__1up"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["MUON_EFF_TrigStatUncertainty__1down"]->GetBinContent(binno),h_background_sys["MUON_EFF_TrigStatUncertainty__1up"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["MUON_EFF_TrigSystUncertainty__1down"]->GetBinContent(binno),h_background_sys["MUON_EFF_TrigSystUncertainty__1up"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["MUON_ISO_STAT__1down"]->GetBinContent(binno),h_background_sys["MUON_ISO_STAT__1up"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["MUON_ISO_SYS__1down"]->GetBinContent(binno),h_background_sys["MUON_ISO_SYS__1up"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["MUON_TTVA_STAT__1down"]->GetBinContent(binno),h_background_sys["MUON_TTVA_STAT__1up"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["MUON_TTVA_SYS__1down"]->GetBinContent(binno),h_background_sys["MUON_TTVA_SYS__1up"]->GetBinContent(binno)),2.) +
        std::pow(std::max(h_background_sys["PRW_DATASF__1down"]->GetBinContent(binno),h_background_sys["PRW_DATASF__1up"]->GetBinContent(binno)),2.)
        );
    h_total_sys->SetBinContent(binno, syst_tot);
  }
  */


  // Calculate the total systematic uncertainty in percentage from all systematics sources
  // Tot_sys_in_% = Sqrt( max( abs(sys1_up - 1.) ,sys1_down - 1.)^2 + max(sys2_up,sys2_down)^2 + ... ) * 100  where sys1_up is the ratio of sys1_up to nominal
  TH1F *h_total_percent_sys = (TH1F*)h_ratio_sys["JET_GroupedNP_1__1up"]->Clone("h_total_percent_sys");
  h_total_percent_sys->Reset();

  for (int binno = 0; binno < h_ratio_sys["JET_GroupedNP_1__1up"]->GetNbinsX() + 2; ++binno) {
    if ( h_background_sys["JET_GroupedNP_1__1up"]->GetBinContent(binno) == 0. ) { // When using blinded histograms, bin contents has 0 values which turns out that total uncertainty become very high in blinded regions.
      h_total_percent_sys->SetBinContent(binno, 0.); // Make contents 0% in blinded region.
    }
    else {
      float syst_tot = std::sqrt( std::pow(std::max(std::abs(h_ratio_sys["EG_RESOLUTION_ALL__1down"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["EG_RESOLUTION_ALL__1up"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["EG_SCALE_ALL__1down"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["EG_SCALE_ALL__1up"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["EL_EFF_ID_TotalCorrUncertainty__1down"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["EL_EFF_ID_TotalCorrUncertainty__1up"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["EL_EFF_Iso_TotalCorrUncertainty__1down"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["EL_EFF_Iso_TotalCorrUncertainty__1up"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["EL_EFF_Reco_TotalCorrUncertainty__1down"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["EL_EFF_Reco_TotalCorrUncertainty__1up"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["EL_EFF_TriggerEff_TotalCorrUncertainty__1down"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["EL_EFF_TriggerEff_TotalCorrUncertainty__1up"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["EL_EFF_Trigger_TotalCorrUncertainty__1down"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["EL_EFF_Trigger_TotalCorrUncertainty__1up"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["JET_EtaIntercalibration_NonClosure__1up"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["JET_EtaIntercalibration_NonClosure__1down"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["JET_GroupedNP_1__1up"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["JET_GroupedNP_1__1down"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["JET_GroupedNP_2__1up"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["JET_GroupedNP_2__1down"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["JET_GroupedNP_3__1up"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["JET_GroupedNP_3__1down"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::abs(h_ratio_sys["JET_JER_SINGLE_NP__1up"]->GetBinContent(binno)-1.),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["JvtEfficiencyDown"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["JvtEfficiencyUp"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::abs(h_ratio_sys["MET_SoftTrk_ResoPara"]->GetBinContent(binno)-1.),2.) +
          std::pow(std::abs(h_ratio_sys["MET_SoftTrk_ResoPerp"]->GetBinContent(binno)-1.),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["MET_SoftTrk_ScaleDown"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["MET_SoftTrk_ScaleUp"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["MUONS_ID__1down"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["MUONS_ID__1up"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["MUONS_MS__1down"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["MUONS_MS__1up"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["MUONS_SCALE__1down"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["MUONS_SCALE__1up"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["MUON_EFF_STAT__1down"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["MUON_EFF_STAT__1up"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["MUON_EFF_STAT_LOWPT__1down"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["MUON_EFF_STAT_LOWPT__1up"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["MUON_EFF_SYS__1down"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["MUON_EFF_SYS__1up"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["MUON_EFF_SYS_LOWPT__1down"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["MUON_EFF_SYS_LOWPT__1up"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["MUON_EFF_TrigStatUncertainty__1down"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["MUON_EFF_TrigStatUncertainty__1up"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["MUON_EFF_TrigSystUncertainty__1down"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["MUON_EFF_TrigSystUncertainty__1up"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["MUON_ISO_STAT__1down"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["MUON_ISO_STAT__1up"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["MUON_ISO_SYS__1down"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["MUON_ISO_SYS__1up"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["MUON_TTVA_STAT__1down"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["MUON_TTVA_STAT__1up"]->GetBinContent(binno)-1.)),2.) +
          std::pow(std::max(std::abs(h_ratio_sys["MUON_TTVA_SYS__1down"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["MUON_TTVA_SYS__1up"]->GetBinContent(binno)-1.)),2.)
          // + std::pow(std::max(std::abs(h_ratio_sys["PRW_DATASF__1down"]->GetBinContent(binno)-1.),std::abs(h_ratio_sys["PRW_DATASF__1up"]->GetBinContent(binno)-1.)),2.) // commented out asked by Prof. Beauchemin
          ) * 100.; // Calculate percentage
      h_total_percent_sys->SetBinContent(binno, syst_tot);
    }
  }




  // Draw total systematic uncertainty (Asked by Prof. Beauchemin)
  TCanvas *can3 = new TCanvas("can3_"+HISTO,"can3_"+HISTO,700,600);

  can3->cd();
  // For drawing guide
  h_total_percent_sys->GetYaxis()->SetTitle("Percent");
  h_total_percent_sys->GetXaxis()->SetTitleSize(0.0);
  h_total_percent_sys->GetXaxis()->SetLabelSize(0.0);
  if (UNITS == "") {
    h_total_percent_sys->GetXaxis()->SetTitle(XTITLE);
  }
  else {
    h_total_percent_sys->GetXaxis()->SetTitle(XTITLE+" ["+UNITS+"]");
  }
  h_total_percent_sys->GetYaxis()->SetTitleSize(0.028);
  h_total_percent_sys->GetYaxis()->SetLabelSize(0.028);
  h_total_percent_sys->GetYaxis()->SetTitleOffset(1.4);
  h_total_percent_sys->GetYaxis()->SetNdivisions(710);
  h_total_percent_sys->GetXaxis()->SetTitleSize(0.028);
  h_total_percent_sys->GetXaxis()->SetLabelSize(0.028);
  h_total_percent_sys->GetXaxis()->SetNdivisions(XDIV);
  h_total_percent_sys->GetXaxis()->SetRangeUser(XMIN,XMAX);
  h_total_percent_sys->SetMinimum(0.);
  //h_total_percent_sys->SetMaximum(10.);
  //h_percent_aux->SetMarkerColor(0);
  //h_percent_aux->SetLineColor(0);
  h_total_percent_sys->Draw();

  TLegend *leg3 = new TLegend(0.35,0.83,0.88,0.86);

  leg3->SetShadowColor(0);
  leg3->SetLineColor(0);
  leg3->SetFillStyle(0);
  leg3->SetFillColor(0);
  leg3->SetTextFont(42);
  leg3->SetTextSize(0.025);
  leg3->SetBorderSize(0);

  if ( HISTO.BeginsWith("Bkg") ) {
    leg3->AddEntry(h_total_percent_sys,"Total systematics uncertainty for backgrounds","l");
  }
  if ( HISTO.BeginsWith("McEstBkg") ) {
    leg3->AddEntry(h_total_percent_sys,"Total systematics uncertainty for MC estimated backgrounds","l");
  }

  //leg3->Draw();
  //gPad->RedrawAxis();





  if (PRINT) {
    can->Print(HISTO+"_sys_"+sysObj1+"_"+sysObj2+".pdf");
    //can2->Print(HISTO+"_uncertain_percent_"+sysObj1+"_"+sysObj2+".pdf");
    if (sysObj1 == "JET" && sysObj2 == "JET") { // Print only when JET systematics source is processed among my Macro list because total systematics is needed to run only once.
      can3->Print(HISTO+"_totsys.pdf");
    }

    // Delete objects
    delete can;
    delete can2;
    delete can3;
  }


}
/*
#ifndef __CINT__
int main(){
DrawHistogram(HISTO,XTITLE,XMIN,XMAX,REBIN,LOGY,PRINT,XDIV,UNITS);
}
#endif
 */
