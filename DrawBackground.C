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

void DrawBackground(TString HISTO,TString XTITLE,float XMIN,float XMAX,int REBIN,bool LOGY,bool PRINT,int XDIV,TString UNITS)
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
  TH1F *h_sample[N];
  TH1D *h_SumofWeight;
  TString PATH("/home/hson/Work/Run2_Study/VBF_study/Histo/");
  float LUMI = 3316.68; //inverse pb
  //float LUMI = 3209.05; //inverse pb

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
    777.421359616,1261.784832,8849.62366464,49.007402629,78.642619761,262.063481626,8.773751393,14.581374106,37.875959148,0.7032228,1.067477005,2.696142542,0.044365312,0.070385103,0.167775035,0.007852498,0.012964171,0.02770973,0.001036761,0.001711101,0.003623487,4.16E-06,6.627E-06,1.0433E-05,13.587, // Znunu + Jets
    912.150989719,2684.61495225,15813.6777927,49.551285758,146.400460335,376.41531567,8.658354152,22.595721591,50.212399035,0.732911329,1.69556209,3.438223853,0.051038517,0.107245951,0.211528021,0.00948474,0.019023648,0.036964172,0.001307192,0.002444187,0.004645048,3.705E-06,2.364E-06,1.2973E-05,26.653, // Wenu + Jets
    907.616822112,2675.17332482,15795.1948618,49.820615432,145.131941493,377.749548487,8.646363179,22.617359448,50.117877494,0.730840739,1.688434939,3.691386319,0.050487154,0.107132134,0.213331248,0.009428206,0.018196255,0.037111165,0.001284408,0.002494854,0.00478857,5.314E-06,9.812E-06,1.2348E-05,26.64, //Wmunu + Jets
    909.56502252,2683.83259267,15821.9692868,49.107324606,144.539591316,375.759077047,8.611129318,22.558816959,50.173358226,0.711433732,1.687956502,3.450438494,0.048001365,0.108804181,0.209886778,0.009455976,0.01927425,0.039884689,0.001236195,0.00251029,0.004868065,5.143E-06,8.707e-06,1.4245E-05,26.583, // Wtaunu + Jets
    140.517436867,241.466440999,1641.4628707,8.861525949,14.049268454,46.790575075,1.559604271,2.42660918,6.789837772,0.123000982,0.198314112,0.48716142,0.007968854,0.012936803,0.02875511,0.001494724,0.002400844,0.005414517,0.000189395,0.00033278,0.000697776,6.99E-07,1.218E-06,2.524E-06,2.5455, // Zee + Jets
    142.586650552,240.030832472,1642.54477535,8.904736706,14.009508576,46.639099307,1.557995219,2.407495134,6.776899365,0.123565964,0.195283767,0.481671305,0.007654784,0.01296887,0.030237082,0.001495305,0.002371048,0.005363995,0.000184686,0.000318973,0.00069072,6.69E-07,1.38E-06,2.451E-06,2.5382, //Zmumu + Jets
    140.512238804,240.97383023,1643.85019048,8.832529157,14.026868379,46.751851426,1.555402702,2.413076391,6.73378408,0.124324067,0.196832713,0.486837566,0.008163159,0.013210254,0.030084735,0.001473957,0.002395235,0.005386908,0.000144828,0.000317704,0.0006955,4.448E-06,1.285E-06,2.416E-06,2.5413, //Ztautau + Jets
    380.09057885,451.59151575,2.06121,1.288662,44.152092,26.27637,35.845486,35.824406, //ttbar and single top
    80302080000.0,52696671.6,809379.648,8455.49202,134.9080666,4.200831425,0.242119405,0.006369576,0.006351453,0.000236729,7.05E-06,1.14E-07,4.1468E-10, //multijet
    11.69259,1.678222,3.299114,2.331238,4.572568,12.74,3.094091,0.6002997 //diboson
  };
  int FILLCOLOR[N] = {kBlack,kRed,kBlue,kMagenta-10,kYellow-10,kGreen+2,kGreen-8,kGreen-8,kGreen-8,kGreen-8,kGreen-8,kGreen-8,kBlue-6,kBlue-8,kBlue-9,kBlue-10};
  int LINECOLOR[N] = {kBlack,kRed,kBlue,kBlack,kBlack,kBlack,kBlack,kBlack,kBlack,kBlack,kBlack,kBlack,kBlack,kBlack};
  int LINESIZE[N]  = {1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1};
  int LINESTYLE[N] = {1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1};
  THStack *h_stack = new THStack("bkg","bkg");
  TH1F *h_Bkg;
  TH1F *h_Znunu;
  TH1F *h_Wenu;
  TH1F *h_Wmunu;
  TH1F *h_Wtaunu;
  TH1F *h_Zee;
  TH1F *h_Zmumu;
  TH1F *h_Ztautau;
  TH1F *h_ttbar;
  TH1F *h_Multijet;
  TH1F *h_Diboson;


  for(int iFile=0;iFile<N;iFile++) {
    inf[iFile] = TFile::Open(PATH+fileName[iFile]);
    h_SumofWeight = (TH1D*)inf[iFile]->Get("h_sumOfWeights");
    h_sample[iFile] = (TH1F*)inf[iFile]->Get(HISTO);
    //h_sample[iFile]->Sumw2();
    h_sample[iFile]->Rebin(REBIN);
    h_sample[iFile]->SetLineColor(LINECOLOR[iFile]);
    h_sample[iFile]->SetLineWidth(LINESIZE[iFile]);
    h_sample[iFile]->SetLineStyle(LINESTYLE[iFile]);
    if (iFile == 0) {
      h_Bkg = (TH1F*)h_sample[iFile]->Clone("h_Bkg");
      h_Bkg->Reset();
      h_Znunu = (TH1F*)h_sample[iFile]->Clone("h_Znunu");
      h_Znunu->Reset();
      h_Wenu = (TH1F*)h_sample[iFile]->Clone("h_Wenu");
      h_Wenu->Reset();
      h_Wmunu = (TH1F*)h_sample[iFile]->Clone("h_Wmunu");
      h_Wmunu->Reset();
      h_Wtaunu = (TH1F*)h_sample[iFile]->Clone("h_Wtaunu");
      h_Wtaunu->Reset();
      h_Zee = (TH1F*)h_sample[iFile]->Clone("h_Zee");
      h_Zee->Reset();
      h_Zmumu = (TH1F*)h_sample[iFile]->Clone("h_Zmumu");
      h_Zmumu->Reset();
      h_Ztautau = (TH1F*)h_sample[iFile]->Clone("h_Ztautau");
      h_Ztautau->Reset();
      h_ttbar = (TH1F*)h_sample[iFile]->Clone("h_ttbar");
      h_ttbar->Reset();
      h_Multijet = (TH1F*)h_sample[iFile]->Clone("h_Multijet");
      h_Multijet->Reset();
      h_Diboson = (TH1F*)h_sample[iFile]->Clone("h_Diboson");
      h_Diboson->Reset();
    }
    else {
      float wt = LUMI*XSEC[iFile]/h_SumofWeight->GetBinContent(4);
      //cout << "wt = " << wt << endl;
      h_sample[iFile]->Scale(wt);
      h_sample[iFile]->SetFillColor(FILLCOLOR[iFile]);
      if (iFile > 0 && iFile < 1+25) {
        h_Znunu->Add(h_sample[iFile]);
        h_Bkg->Add(h_sample[iFile]);
      } 
      if (iFile > 25 && iFile < 1+25+25) {
        h_Wenu->Add(h_sample[iFile]);
        h_Bkg->Add(h_sample[iFile]);
      }
      if (iFile > 25+25 && iFile < 1+25+25+25) {
        h_Wmunu->Add(h_sample[iFile]);
        h_Bkg->Add(h_sample[iFile]);
      }
      if (iFile > 25+25+25 && iFile < 1+25+25+25+25) {
        h_Wtaunu->Add(h_sample[iFile]);
        h_Bkg->Add(h_sample[iFile]);
      }
      if (iFile > 25+25+25+25 && iFile < 1+25+25+25+25+25) {
        h_Zee->Add(h_sample[iFile]);
        if (HISTO.Contains("mumu")) h_Bkg->Add(h_sample[iFile]);
      }
      if (iFile > 25+25+25+25+25 && iFile < 1+25+25+25+25+25+25) {
        h_Zmumu->Add(h_sample[iFile]);
        if (HISTO.Contains("ee")) h_Bkg->Add(h_sample[iFile]);
      }
      if (iFile > 25+25+25+25+25+25 && iFile < 1+25+25+25+25+25+25+25) {
        h_Ztautau->Add(h_sample[iFile]);
        h_Bkg->Add(h_sample[iFile]);
      }
      if (iFile > 25+25+25+25+25+25+25  && iFile < 1+25+25+25+25+25+25+25+8) {
        h_ttbar->Add(h_sample[iFile]);
        h_Bkg->Add(h_sample[iFile]);
      }
      if (iFile > 25+25+25+25+25+25+25+8 && iFile < 1+25+25+25+25+25+25+25+8+13) {
        h_Multijet->Add(h_sample[iFile]);
        h_Bkg->Add(h_sample[iFile]);
      }
      if (iFile > 25+25+25+25+25+25+25+8+13 && iFile < 1+25+25+25+25+25+25+25+8+13+8) {
        h_Diboson->Add(h_sample[iFile]);
        h_Bkg->Add(h_sample[iFile]);
      }

    }
  }


  /*
     float NQCD = h_QCD->Integral();
     float NTOT = h_Bkg->Integral();
     float NDAT = h_sample[0]->Integral();
     float kfactor = (NDAT - NTOT)/NQCD + 1;
     cout<<"k-factor: "<<kfactor<<endl;
     for(int iFile=6;iFile<N;iFile++) {
     if (iFile > 6) {
     h_sample[iFile]->Scale(kfactor);
     }  
     }
     h_sampleQCD->Scale(kfactor);
     h_sampleBkg->Scale(1+(kfactor-1)*NQCD/NTOT);
   */

  h_sample[0]->SetMarkerStyle(kFullCircle);
  h_sample[0]->SetMarkerSize(0.8);

  TH1F *h_Ratio = (TH1F*)h_Bkg->Clone("Ratio");
  //double KS = h_sample[0]->KolmogorovTest(h_Bkg);
  //cout<<"KS = "<<KS<<endl;

  h_Ratio->Divide( (TH1F*)h_sample[0] ); // Divided by Data (MC/Data)
  h_Ratio->SetMarkerStyle(kFullCircle);
  h_Ratio->SetMarkerSize(0.8);

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

  h_stack->Add(h_Multijet);
  if (HISTO.Contains("mumu")) h_stack->Add(h_Zee);
  if (HISTO.Contains("ee")) h_stack->Add(h_Zmumu);
  h_stack->Add(h_Znunu);
  h_stack->Add(h_Ztautau);
  h_stack->Add(h_Wtaunu);
  h_stack->Add(h_Wmunu);
  h_stack->Add(h_Wenu);
  h_stack->Add(h_Diboson);
  h_stack->Add(h_ttbar);

  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);


  TCanvas *can = new TCanvas("can_"+HISTO,"can_"+HISTO,700,600);
  if (LOGY) gPad->SetLogy();
  TH1F *h_aux = (TH1F*)h_Bkg->Clone("aux");
  //h_aux->Reset();
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

  h_aux->GetYaxis()->SetTitleSize(0.028);
  h_aux->GetYaxis()->SetLabelSize(0.028);
  h_aux->GetYaxis()->SetTitleOffset(1.4);
  h_aux->GetYaxis()->SetNdivisions(505);
  h_aux->GetXaxis()->SetNdivisions(XDIV);
  h_aux->GetXaxis()->SetRangeUser(XMIN,XMAX);
  if (UNITS == "") {
    h_aux->GetXaxis()->SetTitle(XTITLE);
  }
  else {
    h_aux->GetXaxis()->SetTitle(XTITLE+" ["+UNITS+"]");
  }
  h_aux->SetMinimum(0.5);
  //h_aux->SetMaximum(1.2*h_sample[0]->GetBinContent(h_sample[0]->GetMaximumBin()));
  float ymax; // Set maximum y xaxis depending on Logy or not
  if (LOGY) ymax = 10.*h_aux->GetBinContent(h_aux->GetMaximumBin());
  else ymax = 2.*h_aux->GetBinContent(h_aux->GetMaximumBin());
  h_aux->SetMaximum(ymax);
  h_aux->SetMarkerColor(0);
  h_aux->SetLineColor(0);
  h_aux->Draw();
  h_stack->Draw("same hist");
  //h_sample[0]->Draw("same E");
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
  //leg->AddEntry(h_sample[0],"Data 2015","P");
  //sprintf(name,"QCD (#times %1.2f)",kfactor);
  leg->AddEntry(h_ttbar,"t#bar{t} (+X) + single top","F");
  leg->AddEntry(h_Diboson,"Diboson","F");
  leg->AddEntry(h_Wenu,"W(#rightarrow e#nu)+jets","F");
  leg->AddEntry(h_Wmunu,"W(#rightarrow #mu#nu)+jets","F");
  leg->AddEntry(h_Wtaunu,"W(#rightarrow #tau#nu)+jets","F");
  leg->AddEntry(h_Ztautau,"Z(#rightarrow #tau#tau)+jets","F");
  //leg->AddEntry(h_Znunu,"Z(#rightarrow #nu#nu)+jets","F");
  if (HISTO.Contains("mumu")) leg->AddEntry(h_Zee,"Z(#rightarrow ee)+jets","F"); // Z->ee
  if (HISTO.Contains("ee")) leg->AddEntry(h_Zmumu,"Z(#rightarrow #mu#mu)+jets","F"); // Z->mumu
  leg->AddEntry(h_Multijet,"Multijet","F");
  leg->Draw();
  
  gPad->RedrawAxis();
  
  
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
    can->Print(HISTO+"_bkg.pdf");

    // Delete objects
    delete can;
    for(int iFile=0;iFile<N;iFile++){
      delete inf[iFile];
    }
  }
}

/*
#ifndef __CINT__
int main(){
DrawBackground(HISTO,XTITLE,XMIN,XMAX,REBIN,LOGY,PRINT,XDIV,UNITS);
}
#endif
 */
