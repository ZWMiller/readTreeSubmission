starver pro
echo $FILELIST
root4star -l -b <<EOF
.L /global/homes/z/zamiller/simu/npehOutput/storageDirectoryPWG/minBiasTemplates111915/readTreeSubmit_C.so
readTree("$FILELIST","readTreeOutput/readTreeOut_$JOBID.root") 
.q
EOF
