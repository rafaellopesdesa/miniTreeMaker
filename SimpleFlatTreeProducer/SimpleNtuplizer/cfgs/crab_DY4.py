from CRABClient.UserUtilities import config
config = config()

# 20 June: First test of saturation variables
config.General.requestName              = 'madgraphDY_FNAL'

config.General.workArea                 = './'
config.General.transferOutputs          = True
config.General.transferLogs             = True

config.JobType.pluginName               = 'Analysis'
config.JobType.psetName                 = 'DY_pset.py'
config.JobType.allowUndistributedCMSSW  = True
#config.JobType.sendExternalFolder      = True

config.Data.inputDataset                = '/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v2/MINIAODSIM'

config.Data.inputDBS                    = 'global'
config.Data.splitting                   = 'FileBased'
config.Data.unitsPerJob                 = 5
config.Data.publication                 = True

config.Site.storageSite                 = 'T3_US_FNALLPC'
