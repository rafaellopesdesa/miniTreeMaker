from CRABClient.UserUtilities import config
config = config()

# 20 June: First test of saturation variables
config.General.requestName              = 'aMCatNLODY2'

config.General.workArea                 = './'
config.General.transferOutputs          = True
config.General.transferLogs             = True

config.JobType.pluginName               = 'Analysis'
config.JobType.psetName                 = 'DY_pset.py'
config.JobType.allowUndistributedCMSSW  = True
config.JobType.sendExternalFolder      = True

config.Data.inputDataset                = '/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM'

config.Data.inputDBS                    = 'global'
config.Data.splitting                   = 'FileBased'
config.Data.unitsPerJob                 = 5
config.Data.publication                 = True

config.Site.storageSite                 = 'T2_US_UCSD'
