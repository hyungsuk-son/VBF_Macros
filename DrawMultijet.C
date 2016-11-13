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

void DrawMultijet(TString HISTO,TString XTITLE,float XMIN,float XMAX,int REBIN,bool LOGY,bool PRINT,int XDIV,TString UNITS)
{
  gROOT->ForceStyle();
  const int N = 1 // Data
    +25 // Znunu
    +25 // Wenu
    +25 // Wmunu
    +25 // Wtaunu
    +25 // Zee
    +25 // Zmumu
    +25 // Ztautau
    +8 // ttbar and single top
    +13 // multijet
    +8; // diboson
  TFile *inf[N];
  TH1F *h_all_lepton[N];
  TH1F *h_os_lepton[N];
  TH1F *h_ss_lepton[N];
  TH1D *h_SumofWeight;
  TString PATH("/home/hson/Work/Run2_Study/VBF_study/Histo/");
  float LUMI = 3158.13; //inverse pb

  TString fileName[N] = {
    "VBF_study_all_period_25ns_2015.root", // DATA
    "hist-mc15_13TeV.363414.Sherpa_NNPDF30NNLO_Znunu_Pt0_70_BFilter.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363413.Sherpa_NNPDF30NNLO_Znunu_Pt0_70_CFilterBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363412.Sherpa_NNPDF30NNLO_Znunu_Pt0_70_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363417.Sherpa_NNPDF30NNLO_Znunu_Pt70_140_BFilter.merge.DAOD_EXOT5.e4772_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363416.Sherpa_NNPDF30NNLO_Znunu_Pt70_140_CFilterBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363415.Sherpa_NNPDF30NNLO_Znunu_Pt70_140_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363420.Sherpa_NNPDF30NNLO_Znunu_Pt140_280_BFilter.merge.DAOD_EXOT5.e4772_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363419.Sherpa_NNPDF30NNLO_Znunu_Pt140_280_CFilterBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363418.Sherpa_NNPDF30NNLO_Znunu_Pt140_280_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363423.Sherpa_NNPDF30NNLO_Znunu_Pt280_500_BFilter.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363422.Sherpa_NNPDF30NNLO_Znunu_Pt280_500_CFilterBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363421.Sherpa_NNPDF30NNLO_Znunu_Pt280_500_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363426.Sherpa_NNPDF30NNLO_Znunu_Pt500_700_BFilter.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363425.Sherpa_NNPDF30NNLO_Znunu_Pt500_700_CFilterBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363424.Sherpa_NNPDF30NNLO_Znunu_Pt500_700_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363429.Sherpa_NNPDF30NNLO_Znunu_Pt700_1000_BFilter.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363428.Sherpa_NNPDF30NNLO_Znunu_Pt700_1000_CFilterBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363427.Sherpa_NNPDF30NNLO_Znunu_Pt700_1000_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363432.Sherpa_NNPDF30NNLO_Znunu_Pt1000_2000_BFilter.merge.DAOD_EXOT5.e4772_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363431.Sherpa_NNPDF30NNLO_Znunu_Pt1000_2000_CFilterBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363430.Sherpa_NNPDF30NNLO_Znunu_Pt1000_2000_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363435.Sherpa_NNPDF30NNLO_Znunu_Pt2000_E_CMS_BFilter.merge.DAOD_EXOT5.e4772_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363434.Sherpa_NNPDF30NNLO_Znunu_Pt2000_E_CMS_CFilterBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363433.Sherpa_NNPDF30NNLO_Znunu_Pt2000_E_CMS_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.304018.Sherpa_CT10_Znunu2JetsEW1JetQCD15GeV.merge.DAOD_EXOT5.e4523_s2608_r7326_r6282_p2495.root", // Znunu + Jets
    "hist-mc15_13TeV.363462.Sherpa_NNPDF30NNLO_Wenu_Pt0_70_BFilter.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363461.Sherpa_NNPDF30NNLO_Wenu_Pt0_70_CFilterBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363460.Sherpa_NNPDF30NNLO_Wenu_Pt0_70_CVetoBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363465.Sherpa_NNPDF30NNLO_Wenu_Pt70_140_BFilter.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363464.Sherpa_NNPDF30NNLO_Wenu_Pt70_140_CFilterBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363463.Sherpa_NNPDF30NNLO_Wenu_Pt70_140_CVetoBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363468.Sherpa_NNPDF30NNLO_Wenu_Pt140_280_BFilter.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363467.Sherpa_NNPDF30NNLO_Wenu_Pt140_280_CFilterBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363466.Sherpa_NNPDF30NNLO_Wenu_Pt140_280_CVetoBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363471.Sherpa_NNPDF30NNLO_Wenu_Pt280_500_BFilter.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363470.Sherpa_NNPDF30NNLO_Wenu_Pt280_500_CFilterBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363469.Sherpa_NNPDF30NNLO_Wenu_Pt280_500_CVetoBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363474.Sherpa_NNPDF30NNLO_Wenu_Pt500_700_BFilter.merge.DAOD_EXOT5.e4771_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363473.Sherpa_NNPDF30NNLO_Wenu_Pt500_700_CFilterBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363472.Sherpa_NNPDF30NNLO_Wenu_Pt500_700_CVetoBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363477.Sherpa_NNPDF30NNLO_Wenu_Pt700_1000_BFilter.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363476.Sherpa_NNPDF30NNLO_Wenu_Pt700_1000_CFilterBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363475.Sherpa_NNPDF30NNLO_Wenu_Pt700_1000_CVetoBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363480.Sherpa_NNPDF30NNLO_Wenu_Pt1000_2000_BFilter.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363479.Sherpa_NNPDF30NNLO_Wenu_Pt1000_2000_CFilterBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363478.Sherpa_NNPDF30NNLO_Wenu_Pt1000_2000_CVetoBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363483.Sherpa_NNPDF30NNLO_Wenu_Pt2000_E_CMS_BFilter.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363482.Sherpa_NNPDF30NNLO_Wenu_Pt2000_E_CMS_CFilterBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363481.Sherpa_NNPDF30NNLO_Wenu_Pt2000_E_CMS_CVetoBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.304015.Sherpa_CT10_Wenu2JetsEW1JetQCD15GeV.merge.DAOD_EXOT5.e4523_s2608_r7326_r6282_p2495.root", // Wenu + Jets
    "hist-mc15_13TeV.363438.Sherpa_NNPDF30NNLO_Wmunu_Pt0_70_BFilter.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363437.Sherpa_NNPDF30NNLO_Wmunu_Pt0_70_CFilterBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363436.Sherpa_NNPDF30NNLO_Wmunu_Pt0_70_CVetoBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363441.Sherpa_NNPDF30NNLO_Wmunu_Pt70_140_BFilter.merge.DAOD_EXOT5.e4771_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363440.Sherpa_NNPDF30NNLO_Wmunu_Pt70_140_CFilterBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363439.Sherpa_NNPDF30NNLO_Wmunu_Pt70_140_CVetoBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363444.Sherpa_NNPDF30NNLO_Wmunu_Pt140_280_BFilter.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363443.Sherpa_NNPDF30NNLO_Wmunu_Pt140_280_CFilterBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363442.Sherpa_NNPDF30NNLO_Wmunu_Pt140_280_CVetoBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363447.Sherpa_NNPDF30NNLO_Wmunu_Pt280_500_BFilter.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363446.Sherpa_NNPDF30NNLO_Wmunu_Pt280_500_CFilterBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363445.Sherpa_NNPDF30NNLO_Wmunu_Pt280_500_CVetoBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363450.Sherpa_NNPDF30NNLO_Wmunu_Pt500_700_BFilter.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363449.Sherpa_NNPDF30NNLO_Wmunu_Pt500_700_CFilterBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363448.Sherpa_NNPDF30NNLO_Wmunu_Pt500_700_CVetoBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363453.Sherpa_NNPDF30NNLO_Wmunu_Pt700_1000_BFilter.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363452.Sherpa_NNPDF30NNLO_Wmunu_Pt700_1000_CFilterBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363451.Sherpa_NNPDF30NNLO_Wmunu_Pt700_1000_CVetoBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363456.Sherpa_NNPDF30NNLO_Wmunu_Pt1000_2000_BFilter.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363455.Sherpa_NNPDF30NNLO_Wmunu_Pt1000_2000_CFilterBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363454.Sherpa_NNPDF30NNLO_Wmunu_Pt1000_2000_CVetoBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363459.Sherpa_NNPDF30NNLO_Wmunu_Pt2000_E_CMS_BFilter.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363458.Sherpa_NNPDF30NNLO_Wmunu_Pt2000_E_CMS_CFilterBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363457.Sherpa_NNPDF30NNLO_Wmunu_Pt2000_E_CMS_CVetoBVeto.merge.DAOD_EXOT5.e4715_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.304016.Sherpa_CT10_Wmunu2JetsEW1JetQCD15GeV.merge.DAOD_EXOT5.e4523_s2608_r7326_r6282_p2495.root", // Wmunu + Jet
    "hist-mc15_13TeV.363333.Sherpa_NNPDF30NNLO_Wtaunu_Pt0_70_BFilter.merge.DAOD_EXOT5.e4709_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363332.Sherpa_NNPDF30NNLO_Wtaunu_Pt0_70_CFilterBVeto.merge.DAOD_EXOT5.e4709_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363331.Sherpa_NNPDF30NNLO_Wtaunu_Pt0_70_CVetoBVeto.merge.DAOD_EXOT5.e4709_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363336.Sherpa_NNPDF30NNLO_Wtaunu_Pt70_140_BFilter.merge.DAOD_EXOT5.e4779_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363335.Sherpa_NNPDF30NNLO_Wtaunu_Pt70_140_CFilterBVeto.merge.DAOD_EXOT5.e4709_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363334.Sherpa_NNPDF30NNLO_Wtaunu_Pt70_140_CVetoBVeto.merge.DAOD_EXOT5.e4709_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363339.Sherpa_NNPDF30NNLO_Wtaunu_Pt140_280_BFilter.merge.DAOD_EXOT5.e4709_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363338.Sherpa_NNPDF30NNLO_Wtaunu_Pt140_280_CFilterBVeto.merge.DAOD_EXOT5.e4709_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363337.Sherpa_NNPDF30NNLO_Wtaunu_Pt140_280_CVetoBVeto.merge.DAOD_EXOT5.e4709_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363342.Sherpa_NNPDF30NNLO_Wtaunu_Pt280_500_BFilter.merge.DAOD_EXOT5.e4779_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363341.Sherpa_NNPDF30NNLO_Wtaunu_Pt280_500_CFilterBVeto.merge.DAOD_EXOT5.e4779_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363340.Sherpa_NNPDF30NNLO_Wtaunu_Pt280_500_CVetoBVeto.merge.DAOD_EXOT5.e4709_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363345.Sherpa_NNPDF30NNLO_Wtaunu_Pt500_700_BFilter.merge.DAOD_EXOT5.e4779_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363344.Sherpa_NNPDF30NNLO_Wtaunu_Pt500_700_CFilterBVeto.merge.DAOD_EXOT5.e4709_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363343.Sherpa_NNPDF30NNLO_Wtaunu_Pt500_700_CVetoBVeto.merge.DAOD_EXOT5.e4709_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363348.Sherpa_NNPDF30NNLO_Wtaunu_Pt700_1000_BFilter.merge.DAOD_EXOT5.e4779_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363347.Sherpa_NNPDF30NNLO_Wtaunu_Pt700_1000_CFilterBVeto.merge.DAOD_EXOT5.e4709_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363346.Sherpa_NNPDF30NNLO_Wtaunu_Pt700_1000_CVetoBVeto.merge.DAOD_EXOT5.e4709_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363351.Sherpa_NNPDF30NNLO_Wtaunu_Pt1000_2000_BFilter.merge.DAOD_EXOT5.e4779_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363350.Sherpa_NNPDF30NNLO_Wtaunu_Pt1000_2000_CFilterBVeto.merge.DAOD_EXOT5.e4709_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363349.Sherpa_NNPDF30NNLO_Wtaunu_Pt1000_2000_CVetoBVeto.merge.DAOD_EXOT5.e4709_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363354.Sherpa_NNPDF30NNLO_Wtaunu_Pt2000_E_CMS_BFilter.merge.DAOD_EXOT5.e4709_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363353.Sherpa_NNPDF30NNLO_Wtaunu_Pt2000_E_CMS_CFilterBVeto.merge.DAOD_EXOT5.e4709_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363352.Sherpa_NNPDF30NNLO_Wtaunu_Pt2000_E_CMS_CVetoBVeto.merge.DAOD_EXOT5.e4709_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.304017.Sherpa_CT10_Wtaunu2JetsEW1JetQCD15GeV.merge.DAOD_EXOT5.e4523_s2608_r7326_r6282_p2495.root", // Wtaunu + Jets
    "hist-mc15_13TeV.363390.Sherpa_NNPDF30NNLO_Zee_Pt0_70_BFilter.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363389.Sherpa_NNPDF30NNLO_Zee_Pt0_70_CFilterBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363388.Sherpa_NNPDF30NNLO_Zee_Pt0_70_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363393.Sherpa_NNPDF30NNLO_Zee_Pt70_140_BFilter.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363392.Sherpa_NNPDF30NNLO_Zee_Pt70_140_CFilterBVeto.merge.DAOD_EXOT5.e4772_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363391.Sherpa_NNPDF30NNLO_Zee_Pt70_140_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363396.Sherpa_NNPDF30NNLO_Zee_Pt140_280_BFilter.merge.DAOD_EXOT5.e4772_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363395.Sherpa_NNPDF30NNLO_Zee_Pt140_280_CFilterBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363394.Sherpa_NNPDF30NNLO_Zee_Pt140_280_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363399.Sherpa_NNPDF30NNLO_Zee_Pt280_500_BFilter.merge.DAOD_EXOT5.e4772_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363398.Sherpa_NNPDF30NNLO_Zee_Pt280_500_CFilterBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363397.Sherpa_NNPDF30NNLO_Zee_Pt280_500_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363402.Sherpa_NNPDF30NNLO_Zee_Pt500_700_BFilter.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363401.Sherpa_NNPDF30NNLO_Zee_Pt500_700_CFilterBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363400.Sherpa_NNPDF30NNLO_Zee_Pt500_700_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363405.Sherpa_NNPDF30NNLO_Zee_Pt700_1000_BFilter.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363404.Sherpa_NNPDF30NNLO_Zee_Pt700_1000_CFilterBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363403.Sherpa_NNPDF30NNLO_Zee_Pt700_1000_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363408.Sherpa_NNPDF30NNLO_Zee_Pt1000_2000_BFilter.merge.DAOD_EXOT5.e4772_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363407.Sherpa_NNPDF30NNLO_Zee_Pt1000_2000_CFilterBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363406.Sherpa_NNPDF30NNLO_Zee_Pt1000_2000_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363411.Sherpa_NNPDF30NNLO_Zee_Pt2000_E_CMS_BFilter.merge.DAOD_EXOT5.e4772_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363410.Sherpa_NNPDF30NNLO_Zee_Pt2000_E_CMS_CFilterBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363409.Sherpa_NNPDF30NNLO_Zee_Pt2000_E_CMS_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.304019.Sherpa_CT10_Zee2JetsEW1JetQCD15GeVM40.merge.DAOD_EXOT5.e4523_s2608_r7326_r6282_p2495.root", // Zee + Jets
    "hist-mc15_13TeV.363366.Sherpa_NNPDF30NNLO_Zmumu_Pt0_70_BFilter.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363365.Sherpa_NNPDF30NNLO_Zmumu_Pt0_70_CFilterBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363364.Sherpa_NNPDF30NNLO_Zmumu_Pt0_70_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363369.Sherpa_NNPDF30NNLO_Zmumu_Pt70_140_BFilter.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363368.Sherpa_NNPDF30NNLO_Zmumu_Pt70_140_CFilterBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363367.Sherpa_NNPDF30NNLO_Zmumu_Pt70_140_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363372.Sherpa_NNPDF30NNLO_Zmumu_Pt140_280_BFilter.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363371.Sherpa_NNPDF30NNLO_Zmumu_Pt140_280_CFilterBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363370.Sherpa_NNPDF30NNLO_Zmumu_Pt140_280_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363375.Sherpa_NNPDF30NNLO_Zmumu_Pt280_500_BFilter.merge.DAOD_EXOT5.e4772_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363374.Sherpa_NNPDF30NNLO_Zmumu_Pt280_500_CFilterBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363373.Sherpa_NNPDF30NNLO_Zmumu_Pt280_500_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363378.Sherpa_NNPDF30NNLO_Zmumu_Pt500_700_BFilter.merge.DAOD_EXOT5.e4772_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363377.Sherpa_NNPDF30NNLO_Zmumu_Pt500_700_CFilterBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363376.Sherpa_NNPDF30NNLO_Zmumu_Pt500_700_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363381.Sherpa_NNPDF30NNLO_Zmumu_Pt700_1000_BFilter.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363380.Sherpa_NNPDF30NNLO_Zmumu_Pt700_1000_CFilterBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363379.Sherpa_NNPDF30NNLO_Zmumu_Pt700_1000_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363384.Sherpa_NNPDF30NNLO_Zmumu_Pt1000_2000_BFilter.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363383.Sherpa_NNPDF30NNLO_Zmumu_Pt1000_2000_CFilterBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363382.Sherpa_NNPDF30NNLO_Zmumu_Pt1000_2000_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363387.Sherpa_NNPDF30NNLO_Zmumu_Pt2000_E_CMS_BFilter.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363386.Sherpa_NNPDF30NNLO_Zmumu_Pt2000_E_CMS_CFilterBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363385.Sherpa_NNPDF30NNLO_Zmumu_Pt2000_E_CMS_CVetoBVeto.merge.DAOD_EXOT5.e4716_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.304020.Sherpa_CT10_Zmumu2JetsEW1JetQCD15GeVM40.merge.DAOD_EXOT5.e4523_s2608_r7326_r6282_p2495.root", // Zmumu + Jets
    "hist-mc15_13TeV.363363.Sherpa_NNPDF30NNLO_Ztautau_Pt0_70_BFilter.merge.DAOD_EXOT5.e4743_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363362.Sherpa_NNPDF30NNLO_Ztautau_Pt0_70_CFilterBVeto.merge.DAOD_EXOT5.e4689_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363361.Sherpa_NNPDF30NNLO_Ztautau_Pt0_70_CVetoBVeto.merge.DAOD_EXOT5.e4689_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363104.Sherpa_NNPDF30NNLO_Ztautau_Pt70_140_BFilter.merge.DAOD_EXOT5.e4792_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363103.Sherpa_NNPDF30NNLO_Ztautau_Pt70_140_CFilterBVeto.merge.DAOD_EXOT5.e4742_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363102.Sherpa_NNPDF30NNLO_Ztautau_Pt70_140_CVetoBVeto.merge.DAOD_EXOT5.e4742_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363107.Sherpa_NNPDF30NNLO_Ztautau_Pt140_280_BFilter.merge.DAOD_EXOT5.e4742_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363106.Sherpa_NNPDF30NNLO_Ztautau_Pt140_280_CFilterBVeto.merge.DAOD_EXOT5.e4666_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363105.Sherpa_NNPDF30NNLO_Ztautau_Pt140_280_CVetoBVeto.merge.DAOD_EXOT5.e4666_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363110.Sherpa_NNPDF30NNLO_Ztautau_Pt280_500_BFilter.merge.DAOD_EXOT5.e4792_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363109.Sherpa_NNPDF30NNLO_Ztautau_Pt280_500_CFilterBVeto.merge.DAOD_EXOT5.e4792_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363108.Sherpa_NNPDF30NNLO_Ztautau_Pt280_500_CVetoBVeto.merge.DAOD_EXOT5.e4666_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363113.Sherpa_NNPDF30NNLO_Ztautau_Pt500_700_BFilter.merge.DAOD_EXOT5.e4742_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363112.Sherpa_NNPDF30NNLO_Ztautau_Pt500_700_CFilterBVeto.merge.DAOD_EXOT5.e4742_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363111.Sherpa_NNPDF30NNLO_Ztautau_Pt500_700_CVetoBVeto.merge.DAOD_EXOT5.e4666_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363116.Sherpa_NNPDF30NNLO_Ztautau_Pt700_1000_BFilter.merge.DAOD_EXOT5.e4742_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363115.Sherpa_NNPDF30NNLO_Ztautau_Pt700_1000_CFilterBVeto.merge.DAOD_EXOT5.e4792_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363114.Sherpa_NNPDF30NNLO_Ztautau_Pt700_1000_CVetoBVeto.merge.DAOD_EXOT5.e4742_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363119.Sherpa_NNPDF30NNLO_Ztautau_Pt1000_2000_BFilter.merge.DAOD_EXOT5.e4666_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363118.Sherpa_NNPDF30NNLO_Ztautau_Pt1000_2000_CFilterBVeto.merge.DAOD_EXOT5.e4666_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363117.Sherpa_NNPDF30NNLO_Ztautau_Pt1000_2000_CVetoBVeto.merge.DAOD_EXOT5.e4666_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363122.Sherpa_NNPDF30NNLO_Ztautau_Pt2000_E_CMS_BFilter.merge.DAOD_EXOT5.e4792_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363121.Sherpa_NNPDF30NNLO_Ztautau_Pt2000_E_CMS_CFilterBVeto.merge.DAOD_EXOT5.e4690_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.363120.Sherpa_NNPDF30NNLO_Ztautau_Pt2000_E_CMS_CVetoBVeto.merge.DAOD_EXOT5.e4690_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.304021.Sherpa_CT10_Ztautau2JetsEW1JetQCD15GeVM40.merge.DAOD_EXOT5.e4523_s2608_r7326_r6282_p2495.root", // Ztautau + Jets
    "hist-mc15_13TeV.410007.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_allhad.merge.DAOD_EXOT5.e4135_s2608_s2183_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.merge.DAOD_EXOT5.e3698_s2608_s2183_r7267_r6282_p2495.root",
    "hist-mc15_13TeV.410025.PowhegPythiaEvtGen_P2012_SingleTopSchan_noAllHad_top.merge.DAOD_EXOT5.e3998_s2608_s2183_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.410026.PowhegPythiaEvtGen_P2012_SingleTopSchan_noAllHad_antitop.merge.DAOD_EXOT5.e3998_s2608_s2183_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.410011.PowhegPythiaEvtGen_P2012_singletop_tchan_lept_top.merge.DAOD_EXOT5.e3824_s2608_s2183_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.410012.PowhegPythiaEvtGen_P2012_singletop_tchan_lept_antitop.merge.DAOD_EXOT5.e3824_s2608_s2183_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.410013.PowhegPythiaEvtGen_P2012_Wt_inclusive_top.merge.DAOD_EXOT5.e3753_s2608_s2183_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.410014.PowhegPythiaEvtGen_P2012_Wt_inclusive_antitop.merge.DAOD_EXOT5.e3753_s2608_s2183_r7326_r6282_p2495.root", // ttbar and single top
    "hist-mc15_13TeV.361020.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ0W.merge.DAOD_EXOT5.e3569_s2576_s2132_r7267_r6282_p2495.root",
    "hist-mc15_13TeV.361021.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ1W.merge.DAOD_EXOT5.e3569_s2576_s2132_r7267_r6282_p2495.root",
    "hist-mc15_13TeV.361022.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ2W.merge.DAOD_EXOT5.e3668_s2576_s2132_r7267_r6282_p2495.root",
    "hist-mc15_13TeV.361023.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ3W.merge.DAOD_EXOT5.e3668_s2576_s2132_r7267_r6282_p2495.root",
    "hist-mc15_13TeV.361024.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ4W.merge.DAOD_EXOT5.e3668_s2576_s2132_r7267_r6282_p2495.root",
    "hist-mc15_13TeV.361025.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ5W.merge.DAOD_EXOT5.e3668_s2576_s2132_r7267_r6282_p2495.root",
    "hist-mc15_13TeV.361026.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ6W.merge.DAOD_EXOT5.e3569_s2608_s2183_r7267_r6282_p2495.root",
    "hist-mc15_13TeV.361027.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ7W.merge.DAOD_EXOT5.e3668_s2608_s2183_r7267_r6282_p2495.root",
    "hist-mc15_13TeV.361028.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ8W.merge.DAOD_EXOT5.e3569_s2576_s2132_r7267_r6282_p2495.root",
    "hist-mc15_13TeV.361029.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ9W.merge.DAOD_EXOT5.e3569_s2576_s2132_r7267_r6282_p2495.root",
    "hist-mc15_13TeV.361030.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ10W.merge.DAOD_EXOT5.e3569_s2576_s2132_r7267_r6282_p2495.root",
    "hist-mc15_13TeV.361031.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ11W.merge.DAOD_EXOT5.e3569_s2608_s2183_r7267_r6282_p2495.root",
    "hist-mc15_13TeV.361032.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ12W.merge.DAOD_EXOT5.e3668_s2608_s2183_r7267_r6282_p2495.root", // multijet
    "hist-mc15_13TeV.361063.Sherpa_CT10_llll.merge.DAOD_EXOT5.e3836_s2608_s2183_r7267_r6282_p2495.root",
    "hist-mc15_13TeV.361064.Sherpa_CT10_lllvSFMinus.merge.DAOD_EXOT5.e3836_s2608_s2183_r7267_r6282_p2495.root",
    "hist-mc15_13TeV.361065.Sherpa_CT10_lllvOFMinus.merge.DAOD_EXOT5.e3836_s2608_s2183_r7267_r6282_p2495.root",
    "hist-mc15_13TeV.361066.Sherpa_CT10_lllvSFPlus.merge.DAOD_EXOT5.e3836_s2608_s2183_r7267_r6282_p2495.root",
    "hist-mc15_13TeV.361067.Sherpa_CT10_lllvOFPlus.merge.DAOD_EXOT5.e3836_s2608_s2183_r7267_r6282_p2495.root",
    "hist-mc15_13TeV.361068.Sherpa_CT10_llvv.merge.DAOD_EXOT5.e3836_s2608_s2183_r7267_r6282_p2495.root",
    "hist-mc15_13TeV.361088.Sherpa_CT10_lvvv.merge.DAOD_EXOT5.e4483_s2726_r7326_r6282_p2495.root",
    "hist-mc15_13TeV.361089.Sherpa_CT10_vvvv.merge.DAOD_EXOT5.e4483_s2726_r7326_r6282_p2495.root" // diboson
  };
  char name[1000];

  float XSEC[N]    = {1., //Data
    777.421359616,1261.784832,8849.62366464,49.146861389,78.642619761,262.063481626,8.724743422,14.581374106,37.875959148,0.7032228,1.067477005,2.696142542,0.044365312,0.070385103,0.167775035,0.007852498,0.012964171,0.02770973,0.001036761 ,0.001711101,0.003623487,4.16E-06,6.627E-06,1.0433E-05,13.587, // Znunu + Jets
    912.150989719,2684.61495225,15813.6777927,49.376826267,146.400460335,376.41531567,8.635509901,22.599123229,50.191601517,0.729320539,1.680719916,3.43565825,0.051038517,0.107245951,0.211528021,0.00948474,0.019023648,0.036964172,0.001307192,0.002444187,0.004645048,3.705E-06,2.364E-06,1.2973E-05,26.653, // Wenu + Jets
    907.616822112,2675.17332482,15795.1948618,49.37500785,145.131941493,377.749548487,8.640805039,22.576834194,50.151421849,0.732282814,1.686521076,3.533801265,0.050487154,0.107132134,0.213331248,0.009428206,0.018196255,0.037111165,0.001284408,0.002494854,0.00478857,5.314E-06,9.812E-06,1.2348E-05,26.64, //Wmunu + Jets
    909.56502252,2683.83259267,15821.9692868,49.107324606,144.539591316,375.759077047,8.611129318,22.558816959,50.173358226,0.711433732,1.687956502,3.450438494,0.048001365,0.108804181,0.209886778,0.009455976,0.01927425,0.039884689,0.001236195,0.00251029,0.004868065,5.143E-06,8.707e-06,1.4245E-05,26.583, // Wtaunu + Jets
    140.517436867,241.466440999,1641.4628707,8.850204229,14.049268454,46.790575075,1.558081087,2.42660918,6.789837772,0.123000982,0.198314112,0.48716142,0.007968854,0.012936803,0.02875511,0.001494724,0.002400844,0.005414517,0.000189395,0.00033278,0.000697776,6.99E-07,1.218E-06,2.524E-06,2.5455, // Zee + Jets
    142.586650552,240.030832472,1642.54477535,8.955685233,14.009508576,46.639099307,1.561047731,2.407495134,6.776899365,0.123565964,0.195283767,0.481671305,0.007654784,0.01296887,0.030237082,0.001495305,0.002371048,0.005363995,0.000184686,0.000318973,0.00069072,6.69E-07,1.38E-06,2.451E-06,2.5382, //Zmumu + Jets
    140.512238804,240.97383023,1643.85019048,8.832529157,14.026868379,46.751851426,1.555402702,2.413076391,6.73378408,0.124324067,0.196832713,0.486837566,0.008163159,0.013210254,0.030084735,0.001473957,0.002395235,0.005386908,0.000144828,0.000317704,0.0006955,8.36E-07,1.285E-06,2.416E-06,2.5413, //Ztautau + Jets
    380.21072415,451.69533735,2.06121,1.288662,44.152092,26.27637,35.845486,35.824406, //ttbar and single top
    80302080000.0,52696671.6,809379.648,8455.49202,134.9080666,4.200831425,0.242119405,0.006369576,0.006351453,0.000236729,7.05E-06,1.14E-07,4.1468E-10, //multijet
    11.69259,1.678222,3.299114,2.331238,4.572568,12.75365,3.094091,0.6002997 //diboson
  };
  int FILLCOLOR[N] = {kBlack,kRed,kBlue,kMagenta-10,kYellow-10,kGreen+2,kGreen-8,kGreen-8,kGreen-8,kGreen-8,kGreen-8,kGreen-8,kBlue-6};
  int LINECOLOR[N] = {kBlack,kRed,kBlue,kBlack,kBlack,kBlack,kBlack,kBlack,kBlack,kBlack,kBlack,kBlack,kBlack};
  int LINESIZE[N]  = {1,1,1,1,1,1,1,1,1,1,1,1,1};
  int LINESTYLE[N] = {1,1,1,1,1,1,1,1,1,1,1,1,1};

  std::map<TString, TH1*> m_all_lepton;
  std::map<TString, TH1*> m_os_lepton;
  std::map<TString, TH1*> m_ss_lepton;
  TString type;

  for(int iFile=0;iFile<N;iFile++) {
    inf[iFile] = TFile::Open(PATH+fileName[iFile]);
    h_SumofWeight = (TH1D*)inf[iFile]->Get("h_sumOfWeights");

    h_all_lepton[iFile] = (TH1F*)inf[iFile]->Get(HISTO+"_all_lep");
    h_os_lepton[iFile] = (TH1F*)inf[iFile]->Get(HISTO+"_os_lep");
    h_ss_lepton[iFile] = (TH1F*)inf[iFile]->Get(HISTO+"_ss_lep");

    h_all_lepton[iFile]->Rebin(REBIN);
    h_os_lepton[iFile]->Rebin(REBIN);
    h_ss_lepton[iFile]->Rebin(REBIN);

    if (iFile == 0) {
      // Data
      type = "data";
      m_all_lepton[type] = (TH1F*)h_all_lepton[iFile]->Clone(type+"_all_lepton");
      m_os_lepton[type] = (TH1F*)h_os_lepton[iFile]->Clone(type+"_os_lepton");
      m_ss_lepton[type] = (TH1F*)h_ss_lepton[iFile]->Clone(type+"_ss_lepton");

      m_all_lepton[type]->SetLineColor(kBlack);
      m_all_lepton[type]->SetMarkerStyle(kFullCircle);
      m_all_lepton[type]->SetMarkerSize(1.0);
      m_os_lepton[type]->SetLineColor(kBlue-3);
      m_ss_lepton[type]->SetLineColor(kRed-4);
      m_os_lepton[type]->SetLineWidth(2);
      m_ss_lepton[type]->SetLineWidth(2);
    }
    else {
      float wt = LUMI*XSEC[iFile]/h_SumofWeight->GetBinContent(4);
      //cout << "wt = " << wt << endl;
      h_all_lepton[iFile]->Scale(wt);
      h_os_lepton[iFile]->Scale(wt);
      h_ss_lepton[iFile]->Scale(wt);

      // Multijet background
      type = "multijet";
      if (iFile == 25+25+25+25+25+25+25+8+1) {
        m_all_lepton[type] = (TH1F*)h_all_lepton[iFile]->Clone(type+"_all_lepton");
        m_os_lepton[type] = (TH1F*)h_os_lepton[iFile]->Clone(type+"_os_lepton");
        m_ss_lepton[type] = (TH1F*)h_ss_lepton[iFile]->Clone(type+"_ss_lepton");
        m_all_lepton[type]->Reset();
        m_os_lepton[type]->Reset();
        m_ss_lepton[type]->Reset();

        m_all_lepton[type]->SetLineColor(kBlack);
        m_all_lepton[type]->SetMarkerStyle(kFullCircle);
        m_all_lepton[type]->SetMarkerSize(1.0);
        m_os_lepton[type]->SetLineColor(kBlue-3);
        m_ss_lepton[type]->SetLineColor(kRed-4);
        m_os_lepton[type]->SetLineWidth(2);
        m_ss_lepton[type]->SetLineWidth(2);
      }
      if (iFile > 25+25+25+25+25+25+25+8 && iFile < 1+25+25+25+25+25+25+25+8+13) {
        m_all_lepton[type]->Add(h_all_lepton[iFile]);
        m_os_lepton[type]->Add(h_os_lepton[iFile]);
        m_ss_lepton[type]->Add(h_ss_lepton[iFile]);
      }

      // All MC backgrounds
      type = "allbkg";
      if (iFile == 1) {
        m_all_lepton[type] = (TH1F*)h_all_lepton[iFile]->Clone(type+"_all_lepton");
        m_os_lepton[type] = (TH1F*)h_os_lepton[iFile]->Clone(type+"_os_lepton");
        m_ss_lepton[type] = (TH1F*)h_ss_lepton[iFile]->Clone(type+"_ss_lepton");
        m_all_lepton[type]->Reset();
        m_os_lepton[type]->Reset();
        m_ss_lepton[type]->Reset();

        m_all_lepton[type]->SetLineColor(kBlack);
        m_all_lepton[type]->SetMarkerStyle(kFullCircle);
        m_all_lepton[type]->SetMarkerSize(1.0);
        m_os_lepton[type]->SetLineColor(kBlue-3);
        m_ss_lepton[type]->SetLineColor(kRed-4);
        m_os_lepton[type]->SetLineWidth(2);
        m_ss_lepton[type]->SetLineWidth(2);
      }
      if (iFile > 0) {
          m_all_lepton[type]->Add(h_all_lepton[iFile]);
          m_os_lepton[type]->Add(h_os_lepton[iFile]);
          m_ss_lepton[type]->Add(h_ss_lepton[iFile]);
      } 

      // MC signal background
      type = "signalbkg";
      if (iFile == 1) {
        m_all_lepton[type] = (TH1F*)h_all_lepton[iFile]->Clone(type+"_all_lepton");
        m_os_lepton[type] = (TH1F*)h_os_lepton[iFile]->Clone(type+"_os_lepton");
        m_ss_lepton[type] = (TH1F*)h_ss_lepton[iFile]->Clone(type+"_ss_lepton");
        m_all_lepton[type]->Reset();
        m_os_lepton[type]->Reset();
        m_ss_lepton[type]->Reset();

        m_all_lepton[type]->SetLineColor(kBlack);
        m_all_lepton[type]->SetMarkerStyle(kFullCircle);
        m_all_lepton[type]->SetMarkerSize(1.0);
        m_os_lepton[type]->SetLineColor(kBlue-3);
        m_ss_lepton[type]->SetLineColor(kRed-4);
        m_os_lepton[type]->SetLineWidth(2);
        m_ss_lepton[type]->SetLineWidth(2);
      }
      if ( HISTO.Contains("ee") ) {
        if (iFile > 25+25+25+25 && iFile < 1+25+25+25+25+25) { // MC samples for Z->ee + Jets
          m_all_lepton[type]->Add(h_all_lepton[iFile]);
          m_os_lepton[type]->Add(h_os_lepton[iFile]);
          m_ss_lepton[type]->Add(h_ss_lepton[iFile]);
        }   
      }   
      if ( HISTO.Contains("mumu") ) {
        if (iFile > 25+25+25+25+25 && iFile < 1+25+25+25+25+25+25) { // MC samples for Z->mumu + Jets
          m_all_lepton[type]->Add(h_all_lepton[iFile]);
          m_os_lepton[type]->Add(h_os_lepton[iFile]);
          m_ss_lepton[type]->Add(h_ss_lepton[iFile]);
        }   
      }   

    }
  }








  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);

/*

    // Draw MC/Data Comparison plots
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
    //h_aux->SetMaximum(1.2*h_sample[0]->GetBinContent(h_sample[0]->GetMaximumBin()));
    float ymax; // Set maximum y xaxis depending on Logy or not
    if (LOGY) ymax = 100.*h_sample[0]->GetBinContent(h_sample[0]->GetMaximumBin());
    else ymax = 2.*h_sample[0]->GetBinContent(h_sample[0]->GetMaximumBin());
    h_aux->SetMaximum(ymax);
    h_aux->Draw();
    h_stackSM->Draw("same hist");
    h_sample[0]->Draw("same E");
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
    leg->AddEntry(h_sample[0],"Data 2015","P");
    //sprintf(name,"QCD (#times %1.2f)",kfactor);
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
    h_Ratio->SetMinimum(0);
    h_Ratio->SetMaximum(2);
    h_Ratio->GetYaxis()->SetTitle("MC / Data");
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

    */



    // Draw data (Same sign and opposite sign leptons)
    TCanvas *can = new TCanvas("can_data_"+HISTO,"can_data_"+HISTO,700,600);
    can->cd();

    type = "data";

    if (LOGY) gPad->SetLogy();
    m_all_lepton[type]->GetYaxis()->SetTitle("Events");

    m_all_lepton[type]->GetYaxis()->SetTitleSize(0.028);
    m_all_lepton[type]->GetYaxis()->SetLabelSize(0.028);
    m_all_lepton[type]->GetYaxis()->SetTitleOffset(1.4);
    m_all_lepton[type]->GetYaxis()->SetNdivisions(707);
    m_all_lepton[type]->GetXaxis()->SetNdivisions(XDIV);
    m_all_lepton[type]->GetXaxis()->SetRangeUser(XMIN,XMAX);
    if (UNITS == "") {
      m_all_lepton[type]->GetXaxis()->SetTitle(XTITLE);
    }
    else {
      m_all_lepton[type]->GetXaxis()->SetTitle(XTITLE+" ["+UNITS+"]");
    }
    m_all_lepton[type]->Draw("");
    m_os_lepton[type]->Draw("same hist");
    m_ss_lepton[type]->Draw("same hist");

    TLegend *leg = new TLegend(0.63,0.70,0.90,0.88);

    leg->SetShadowColor(0);
    leg->SetLineColor(0);
    leg->SetFillStyle(0);
    leg->SetFillColor(0);
    leg->SetTextFont(42);
    leg->SetTextSize(0.025);
    leg->SetBorderSize(0);
    leg->AddEntry(m_all_lepton[type],"All lepton passed","P");
    leg->AddEntry(m_os_lepton[type],"Opposite sign lepton","l");
    leg->AddEntry(m_ss_lepton[type],"Same sign lepton","l");
    leg->Draw();

    //gPad->RedrawAxis();





    // Draw multijet background (MC)
    TCanvas *can2 = new TCanvas("can_multijet_mc_"+HISTO,"can_multijet_mc_"+HISTO,700,600);
    can2->cd();

    type = "multijet";

    if (LOGY) gPad->SetLogy();
    m_all_lepton[type]->GetYaxis()->SetTitle("Events");

    m_all_lepton[type]->GetYaxis()->SetTitleSize(0.028);
    m_all_lepton[type]->GetYaxis()->SetLabelSize(0.028);
    m_all_lepton[type]->GetYaxis()->SetTitleOffset(1.4);
    m_all_lepton[type]->GetYaxis()->SetNdivisions(707);
    m_all_lepton[type]->GetXaxis()->SetNdivisions(XDIV);
    m_all_lepton[type]->GetXaxis()->SetRangeUser(XMIN,XMAX);
    if (UNITS == "") {
      m_all_lepton[type]->GetXaxis()->SetTitle(XTITLE);
    }
    else {
      m_all_lepton[type]->GetXaxis()->SetTitle(XTITLE+" ["+UNITS+"]");
    }
    m_all_lepton[type]->Draw("");
    m_os_lepton[type]->Draw("same hist");
    m_ss_lepton[type]->Draw("same hist");

    TLegend *leg2 = new TLegend(0.63,0.70,0.90,0.88);

    leg2->SetShadowColor(0);
    leg2->SetLineColor(0);
    leg2->SetFillStyle(0);
    leg2->SetFillColor(0);
    leg2->SetTextFont(42);
    leg2->SetTextSize(0.025);
    leg2->SetBorderSize(0);
    leg2->AddEntry(m_all_lepton[type],"All lepton passed","P");
    leg2->AddEntry(m_os_lepton[type],"Opposite sign lepton","l");
    leg2->AddEntry(m_ss_lepton[type],"Same sign lepton","l");
    leg2->Draw();

    //gPad->RedrawAxis();


    // Draw all background (MC)
    TCanvas *can3 = new TCanvas("can_all_bkg_mc_"+HISTO,"can_all_bkg_mc_"+HISTO,700,600);
    can3->cd();

    type = "allbkg";

    if (LOGY) gPad->SetLogy();
    m_all_lepton[type]->GetYaxis()->SetTitle("Events");

    m_all_lepton[type]->GetYaxis()->SetTitleSize(0.028);
    m_all_lepton[type]->GetYaxis()->SetLabelSize(0.028);
    m_all_lepton[type]->GetYaxis()->SetTitleOffset(1.4);
    m_all_lepton[type]->GetYaxis()->SetNdivisions(707);
    m_all_lepton[type]->GetXaxis()->SetNdivisions(XDIV);
    m_all_lepton[type]->GetXaxis()->SetRangeUser(XMIN,XMAX);
    if (UNITS == "") {
      m_all_lepton[type]->GetXaxis()->SetTitle(XTITLE);
    }
    else {
      m_all_lepton[type]->GetXaxis()->SetTitle(XTITLE+" ["+UNITS+"]");
    }
    m_all_lepton[type]->Draw("");
    m_os_lepton[type]->Draw("same hist");
    m_ss_lepton[type]->Draw("same hist");

    TLegend *leg3 = new TLegend(0.63,0.70,0.90,0.88);

    leg3->SetShadowColor(0);
    leg3->SetLineColor(0);
    leg3->SetFillStyle(0);
    leg3->SetFillColor(0);
    leg3->SetTextFont(42);
    leg3->SetTextSize(0.025);
    leg3->SetBorderSize(0);
    leg3->AddEntry(m_all_lepton[type],"All lepton passed","P");
    leg3->AddEntry(m_os_lepton[type],"Opposite sign lepton","l");
    leg3->AddEntry(m_ss_lepton[type],"Same sign lepton","l");
    leg3->Draw();


    // QCD multijet study using Method 1

    TH1F *h_multijet_est;
    h_multijet_est = (TH1F*)m_ss_lepton["data"]->Clone();
    h_multijet_est->Reset();
    h_multijet_est->SetName("h_multijet_est");
    for (int binno = 0; binno < h_multijet_est->GetNbinsX() + 2; ++binno) {
      float ss_data_val = m_ss_lepton["data"]->GetBinContent(binno); // S-S Data
      float ss_mc_zll_val = m_ss_lepton["signalbkg"]->GetBinContent(binno); // S-S MC Zll
      float multijet_est_val = ss_data_val - ss_mc_zll_val;
      if (multijet_est_val < 0.) multijet_est_val = 0.; // If # of estimated multijet is negative, # is considered as zero.
      h_multijet_est->SetBinContent(binno, multijet_est_val);
    }


    // Draw SS data and MC (Zee)
    TCanvas *can4 = new TCanvas("can_ss_data_mc_zll_"+HISTO,"can_ss_data_mc_zll_"+HISTO,700,600);
    can4->cd();

    type = "data";

    if (LOGY) gPad->SetLogy();
    m_ss_lepton[type]->GetYaxis()->SetTitle("Events");

    m_ss_lepton[type]->GetYaxis()->SetTitleSize(0.028);
    m_ss_lepton[type]->GetYaxis()->SetLabelSize(0.028);
    m_ss_lepton[type]->GetYaxis()->SetTitleOffset(1.4);
    m_ss_lepton[type]->GetYaxis()->SetNdivisions(707);
    m_ss_lepton[type]->GetXaxis()->SetNdivisions(XDIV);
    m_ss_lepton[type]->GetXaxis()->SetRangeUser(XMIN,XMAX);
    m_ss_lepton[type]->SetMinimum(0.01);
    if (UNITS == "") {
      m_ss_lepton[type]->GetXaxis()->SetTitle(XTITLE);
    }
    else {
      m_ss_lepton[type]->GetXaxis()->SetTitle(XTITLE+" ["+UNITS+"]");
    }
    //m_all_lepton[type]->Draw("");
    m_ss_lepton["data"]->SetLineColor(kRed-4);
    m_ss_lepton["signalbkg"]->SetLineColor(kBlue-3);
    h_multijet_est->SetLineColor(kBlack);
    h_multijet_est->SetMarkerStyle(20);
    m_ss_lepton["data"]->Draw("hist");
    m_ss_lepton["signalbkg"]->Draw("same hist");
    h_multijet_est->Draw("same p");

    TLegend *leg4 = new TLegend(0.58,0.70,0.85,0.88);

    leg4->SetShadowColor(0);
    leg4->SetLineColor(0);
    leg4->SetFillStyle(0);
    leg4->SetFillColor(0);
    leg4->SetTextFont(42);
    leg4->SetTextSize(0.025);
    leg4->SetBorderSize(0);
    //leg4->AddEntry(m_all_lepton[type],"All lepton passed","P");
    leg4->AddEntry(m_ss_lepton["data"],"S-S Data","l");
    if (HISTO.Contains("ee")) leg4->AddEntry(m_ss_lepton["signalbkg"],"S-S MC Z(#rightarrow ee+jets)","l");
    if (HISTO.Contains("mumu")) leg4->AddEntry(m_ss_lepton["signalbkg"],"S-S MC Z(#rightarrow #mu#mu+jets)","l");
    leg4->AddEntry(h_multijet_est,"Estimated QCD background","P");

    leg4->Draw();




/*


  // Retrieve Systematic

  TString PATH_sys("/home/hson/Work/Run2_Study/VBF_study/Macro/");
  TString fileName_sys("hist_sys_uncertain.root");

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


  // Open file
  TFile *inf_sys;
  inf_sys = TFile::Open(PATH_sys+fileName_sys);

  // Systematics histogram
  std::map<TString, TH1*> h_background_sys;

  // Retrieve All systematic histograms
  int count_color = 2;
  std::vector<std::string>::const_iterator sys;
  for (sys = systematics.begin(); sys != systematics.end(); sys++){
    TString sys_name = *sys;
    h_background_sys[sys_name] = (TH1F*)inf_sys->Get("McEstBkg_"+HISTO+sys_name);
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


    // Draw Uncertainty for SS data and MC (Zee)
    TCanvas *can5 = new TCanvas("can_var_ss_data_mc_zll_"+HISTO,"can_var_ss_data_mc_zll_"+HISTO,700,600);
    can5->cd();
*/








    /* 
       TPaveText *paveKS = new TPaveText(0.81,0.4,0.92,0.5,"NDC");
       sprintf(name,"KS = %1.1e",KS);
       paveKS->AddText(name);
       paveKS->SetFillColor(0);
       paveKS->SetLineColor(0);
       paveKS->SetBorderSize(0);
       paveKS->SetTextFont(42);
       paveKS->SetTextSize(0.03);
    //paveKS->Draw();
    TPaveText *pave = new TPaveText(0.81,0.75,0.92,0.92,"NDC");
    pave->AddText("CMS");
    pave->AddText("#sqrt{s} = 8 TeV");
    sprintf(name,"L = %1.1f fb^{-1}",LUMI/1000);
    pave->AddText(name); 
    pave->SetFillColor(0);
    pave->SetLineColor(0);
    pave->SetBorderSize(0);
    pave->SetTextFont(62);
    pave->SetTextSize(0.04);
     */
    /*  
        if (PRINT_PAS) {
        pave->Draw(); 
        } 
     */ 
    if (PRINT) {
      //can->Print(TString(can->GetTitle())+".png");
      can->Print(HISTO+"_data.pdf");
      can2->Print(HISTO+"_MC_multijet_bkg.pdf");
      can3->Print(HISTO+"_MC_all_bkg.pdf");

      // Delete objects
      delete can;
      delete can2;
      delete can3;
      for(int iFile=0;iFile<N;iFile++){
        delete inf[iFile];
      }
    }


}
/*
#ifndef __CINT__
int main(){
DrawHistogram(HISTO,XTITLE,XMIN,XMAX,REBIN,LOGY,PRINT,XDIV,UNITS);
}
#endif
 */
