from CRABClient.UserUtilities import config
config = config()

# 20 June: First test of saturation variables
config.General.requestName              = 'DATA_2016G_rereco'

config.General.workArea                 = './'
config.General.transferOutputs          = True
config.General.transferLogs             = True

config.JobType.pluginName               = 'Analysis'
config.JobType.psetName                 = 'SingleElectron_pset.py'
config.JobType.allowUndistributedCMSSW  = True

config.Data.inputDataset                = '/SingleElectron/Run2016G-23Sep2016-v1/MINIAOD'
config.Data.inputDBS                    = 'global'
config.Data.splitting                   = 'LumiBased'
config.Data.unitsPerJob                 = 50
config.Data.lumiMask                    = '/home/users/rclsa/RegressionTraining/newTreeMaker/CMSSW_8_0_12/src/SimpleFlatTreeProducer/SimpleNtuplizer/cfgs/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt'
config.Data.publication                 = True

config.Site.storageSite                 = 'T2_US_UCSD'
config.JobType.sendExternalFolder      = True
