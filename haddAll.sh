cd Oct26_set2
find *.root -size -7000k -delete
hadd pythia_tree_Oct26_2.root *.root
cd ../Oct26_set3
find *.root -size -7000k -delete
hadd pythia_tree_Oct26_3.root *.root
cd ../Oct26_set4
find *.root -size -7000k -delete
hadd pythia_tree_Oct26_4.root *.root
cd ../Oct26_set5
find *.root -size -7000k -delete
hadd pythia_tree_Oct26_5.root *.root
cd ..
