find $1_set* -name "*.root" -type f -printf "%p - %s\n" | sort -nr -k3 | uniq -D -f1 > $1_Duplicates.txt


