starver pro
root4star -l -b <<EOF
.L /global/homes/z/zamiller/simu/npehOutput/storageDirectoryPWG/minBiasTemplates101015/readTreeSubmit.C++
readTree("Trees.list","readTreeOutput/readTreeOut_$JOBID.root") 
.q
EOF
