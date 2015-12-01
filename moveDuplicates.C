{
  int numDates = 5;
  char dates[5][100] = {"Nov6","Oct20","Oct21","Oct26","Oct30"};
  for(int i=0; i<numDates; i++){
    char line[1000],filenm[100];
    string fileName;
    int memSize;
    vector<string> fNames;
    vector<int> fSizes;
    int numSameSize=0;
    string currentName;
    int currentSize;
    int isFirst = 1;
    ifstream fp(Form("%s_Duplicates.txt",dates[i]),ios::in);
    ostringstream out;
    while (!fp.eof()){
      fp.getline(line,1000);
      sscanf(line,"%s - %i",&filenm,&memSize);
      // printf("%s %i\n",filenm,memSize);
      fileName=string(filenm);
      if(isFirst)
      {
        isFirst = 0;
        currentName=fileName;
        currentSize = memSize;
        fNames.push_back(fileName);
        fSizes.push_back(memSize);
      }
      else if(memSize == currentSize)
      {
        fNames.push_back(fileName);
        fSizes.push_back(memSize);
      }
      else if(memSize != currentSize)
      {
        for(int j=1;j<fNames.size();j++) // move all elements of the vector save the first.
        {
          //printf("mem: %i, name: %s\n", fSizes.at(j), fNames.at(j));  
          //cout << "mem: " << fSizes.at(j) << " name: " << fNames.at(j) << "\n";
          out.str("");
          out << "mv " << fNames.at(j) << " duplicateFileStorage/.";
          const char *cstr = out.str().c_str();
          gSystem->Exec(cstr);
        }
        currentSize = memSize;
        currentName = fileName;
        fSizes.clear();
        fNames.clear();
        fSizes.push_back(currentSize);
        fNames.push_back(currentName);
      }

    }
    fp.close();
  }

  for(int j=1;j<fNames.size();j++) // move all elements of the vector save the first. Handle EOF case.
  {
    //cout << "mem: " << fSizes.at(j) << " name: " << fNames.at(j) << "\n";
    out.str("");
    out << "mv " << fNames.at(j) << " duplicateFileStorage/.";
    const char *cstr = out.str().c_str();
    gSystem->Exec(cstr);
  }

}
