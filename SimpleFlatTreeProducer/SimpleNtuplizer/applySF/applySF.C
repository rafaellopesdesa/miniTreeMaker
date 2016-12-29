void applySF() {

  float lumi[] = {5.934, 2.646, 4.353, 4.050, 3.160, 7.554, 8.545, 0.217};
  float lumip[] = {0.,0.,0.,0.,0.,0.,0.,0.};
  float lumisum = 0.;
  for (int i=0; i<8; i++) {
    lumisum += lumi[i];
    lumip[i] = lumisum;
  }
  
  TFile* f = TFile::Open("/data/userdata/rclsa/mc_2016.root");
  TFile* fo = TFile::Open("mc_2016.root", "RECREATE");

  TTree* t = (TTree*) f->Get("een_analyzer/ElectronTree");  
  fo->mkdir("een_analyzer");
  fo->cd("een_analyzer");
  TTree* to = (TTree*) t->CloneTree(0);

  float SF_RECO, SF_ID, tp_tagSF_RECO, tp_tagSF_ID;
  t->SetBranchAddress("SF_RECO", &SF_RECO);
  t->SetBranchAddress("SF_ID", &SF_ID);
  t->SetBranchAddress("tp_tagSF_RECO", &tp_tagSF_RECO);
  t->SetBranchAddress("tp_tagSF_ID", &tp_tagSF_ID);

  float pt, tagpt;
  t->SetBranchAddress("pt", &pt);
  t->SetBranchAddress("tagpt", &tagpt);
  
  float trkEta, tageta;
  t->SetBranchAddress("trkEta", &trkEta);
  t->SetBranchAddress("tageta", &tageta);

  float trueNumInteractions;
  t->SetBranchAddress("trueNumInteractions", &trueNumInteractions);
  
  float SF_pileup;
  to->Branch("SF_pileup", &SF_pileup);

  TFile* RECO = TFile::Open("../scaleFactors/RECO.root");
  TH2F* RECO_EGamma_SF2D = (TH2F*) RECO->Get("EGamma_SF2D");

  TFile* idBCD = TFile::Open("../scaleFactors/idBCD.root");
  TH2F* idBCD_EGamma_SF2D = (TH2F*) idBCD->Get("EGamma_SF2D");
  
  TFile* idEF = TFile::Open("../scaleFactors/idEF.root");
  TH2F* idEF_EGamma_SF2D = (TH2F*) idEF->Get("EGamma_SF2D");
  
  TFile* idGH = TFile::Open("../scaleFactors/idGH.root");
  TH2F* idGH_EGamma_SF2D = (TH2F*) idGH->Get("EGamma_SF2D");

  double integral = 1.;
  
  TFile* pu_dist_MC_692 = TFile::Open("../pileup/pu_dist_MC_692.root");
  TH1F* pu_dist_MC_692_pileup = (TH1F*) pu_dist_MC_692->Get("pileup");
  integral = pu_dist_MC_692_pileup->Integral();
  pu_dist_MC_692_pileup->Scale(1/integral);

  TFile* pu_dist_runB_692 = TFile::Open("../pileup/pu_dist_runB_692.root");
  TH1D* pu_dist_runB_692_pileup = (TH1D*) pu_dist_runB_692->Get("pileup");
  integral = pu_dist_runB_692_pileup->Integral();
  pu_dist_runB_692_pileup->Scale(1/integral);

  TFile* pu_dist_runC_692 = TFile::Open("../pileup/pu_dist_runC_692.root");
  TH1D* pu_dist_runC_692_pileup = (TH1D*) pu_dist_runC_692->Get("pileup");
  integral = pu_dist_runC_692_pileup->Integral();
  pu_dist_runC_692_pileup->Scale(1/integral);

  TFile* pu_dist_runD_692 = TFile::Open("../pileup/pu_dist_runD_692.root");
  TH1D* pu_dist_runD_692_pileup = (TH1D*) pu_dist_runD_692->Get("pileup");
  integral = pu_dist_runD_692_pileup->Integral();
  pu_dist_runD_692_pileup->Scale(1/integral);

  TFile* pu_dist_runE_692 = TFile::Open("../pileup/pu_dist_runE_692.root");
  TH1D* pu_dist_runE_692_pileup = (TH1D*) pu_dist_runE_692->Get("pileup");
  integral = pu_dist_runE_692_pileup->Integral();
  pu_dist_runE_692_pileup->Scale(1/integral);

  TFile* pu_dist_runF_692 = TFile::Open("../pileup/pu_dist_runF_692.root");
  TH1D* pu_dist_runF_692_pileup = (TH1D*) pu_dist_runF_692->Get("pileup");
  integral = pu_dist_runF_692_pileup->Integral();
  pu_dist_runF_692_pileup->Scale(1/integral);

  TFile* pu_dist_runG_692 = TFile::Open("../pileup/pu_dist_runG_692.root");
  TH1D* pu_dist_runG_692_pileup = (TH1D*) pu_dist_runG_692->Get("pileup");
  integral = pu_dist_runG_692_pileup->Integral();
  pu_dist_runG_692_pileup->Scale(1/integral);
  
  TFile* pu_dist_runHv2_692 = TFile::Open("../pileup/pu_dist_runHv2_692.root");
  TH1D* pu_dist_runHv2_692_pileup = (TH1D*) pu_dist_runHv2_692->Get("pileup");
  integral = pu_dist_runHv2_692_pileup->Integral();
  pu_dist_runHv2_692_pileup->Scale(1/integral);
  
  TFile* pu_dist_runHv3_692 = TFile::Open("../pileup/pu_dist_runHv3_692.root");
  TH1D* pu_dist_runHv3_692_pileup = (TH1D*) pu_dist_runHv3_692->Get("pileup");
  integral = pu_dist_runHv3_692_pileup->Integral();
  pu_dist_runHv3_692_pileup->Scale(1/integral);

  
  int nentries = t->GetEntries();  
  for (int i=0; i<nentries; i++) {
    t->GetEntry(i);

    int run = 0;
    float rnd = gRandom->Rndm()*lumisum;
    for (int i=0; i<8; i++) {
      if (rnd < lumip[i]) {
	run = i;
	break;
      }
    }    
    
    if (run==0) {
      SF_pileup = pu_dist_runB_692_pileup->GetBinContent(trueNumInteractions)/pu_dist_MC_692_pileup->GetBinContent(trueNumInteractions);
      SF_RECO = RECO_EGamma_SF2D->GetBinContent(trkEta, pt);
      tp_tagSF_RECO = RECO_EGamma_SF2D->GetBinContent(tageta, tagpt);
      SF_ID = idBCD_EGamma_SF2D->GetBinContent(trkEta, pt);
      tp_tagSF_ID = idBCD_EGamma_SF2D->GetBinContent(tageta, tagpt);
    } else if (run==1) {
      SF_pileup = pu_dist_runC_692_pileup->GetBinContent(trueNumInteractions)/pu_dist_MC_692_pileup->GetBinContent(trueNumInteractions);
      SF_RECO = RECO_EGamma_SF2D->GetBinContent(trkEta, pt);
      tp_tagSF_RECO = RECO_EGamma_SF2D->GetBinContent(tageta, tagpt);
      SF_ID = idBCD_EGamma_SF2D->GetBinContent(trkEta, pt);
      tp_tagSF_ID = idBCD_EGamma_SF2D->GetBinContent(tageta, tagpt);
    } else if (run==2) {
      SF_pileup = pu_dist_runD_692_pileup->GetBinContent(trueNumInteractions)/pu_dist_MC_692_pileup->GetBinContent(trueNumInteractions);
      SF_RECO = RECO_EGamma_SF2D->GetBinContent(trkEta, pt);
      tp_tagSF_RECO = RECO_EGamma_SF2D->GetBinContent(tageta, tagpt);
      SF_ID = idBCD_EGamma_SF2D->GetBinContent(trkEta, pt);
      tp_tagSF_ID = idBCD_EGamma_SF2D->GetBinContent(tageta, tagpt);
    } else if (run==3) {
      SF_pileup = pu_dist_runE_692_pileup->GetBinContent(trueNumInteractions)/pu_dist_MC_692_pileup->GetBinContent(trueNumInteractions);
      SF_RECO = RECO_EGamma_SF2D->GetBinContent(trkEta, pt);
      tp_tagSF_RECO = RECO_EGamma_SF2D->GetBinContent(tageta, tagpt);
      SF_ID = idEF_EGamma_SF2D->GetBinContent(trkEta, pt);
      tp_tagSF_ID = idEF_EGamma_SF2D->GetBinContent(tageta, tagpt);
    } else if (run==4) {
      SF_pileup = pu_dist_runF_692_pileup->GetBinContent(trueNumInteractions)/pu_dist_MC_692_pileup->GetBinContent(trueNumInteractions);
      SF_RECO = RECO_EGamma_SF2D->GetBinContent(trkEta, pt);
      tp_tagSF_RECO = RECO_EGamma_SF2D->GetBinContent(tageta, tagpt);
      SF_ID = idEF_EGamma_SF2D->GetBinContent(trkEta, pt);
      tp_tagSF_ID = idEF_EGamma_SF2D->GetBinContent(tageta, tagpt);
    } else if (run==5) {
      SF_pileup = pu_dist_runG_692_pileup->GetBinContent(trueNumInteractions)/pu_dist_MC_692_pileup->GetBinContent(trueNumInteractions);
      SF_RECO = RECO_EGamma_SF2D->GetBinContent(trkEta, pt);
      tp_tagSF_RECO = RECO_EGamma_SF2D->GetBinContent(tageta, tagpt);
      SF_ID = idGH_EGamma_SF2D->GetBinContent(trkEta, pt);
      tp_tagSF_ID = idGH_EGamma_SF2D->GetBinContent(tageta, tagpt);
    } else if (run==6) {
      SF_pileup = pu_dist_runHv2_692_pileup->GetBinContent(trueNumInteractions)/pu_dist_MC_692_pileup->GetBinContent(trueNumInteractions);
      SF_RECO = RECO_EGamma_SF2D->GetBinContent(trkEta, pt);
      tp_tagSF_RECO = RECO_EGamma_SF2D->GetBinContent(tageta, tagpt);
      SF_ID = idGH_EGamma_SF2D->GetBinContent(trkEta, pt);
      tp_tagSF_ID = idGH_EGamma_SF2D->GetBinContent(tageta, tagpt);
    } else if (run==7) {
      SF_pileup = pu_dist_runHv3_692_pileup->GetBinContent(trueNumInteractions)/pu_dist_MC_692_pileup->GetBinContent(trueNumInteractions);
      SF_RECO = RECO_EGamma_SF2D->GetBinContent(trkEta, pt);
      tp_tagSF_RECO = RECO_EGamma_SF2D->GetBinContent(tageta, tagpt);
      SF_ID = idGH_EGamma_SF2D->GetBinContent(trkEta, pt);
      tp_tagSF_ID = idGH_EGamma_SF2D->GetBinContent(tageta, tagpt);
    } else {
      continue;
    }

    to->Fill();
  }
  fo->cd("een_analyzer");
  to->Write("ElectronTree");
}
    
