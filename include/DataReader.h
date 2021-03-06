#ifndef DataReader_h
#define DataReader_h 1

#include <iostream>
#include <vector>

using namespace std;

class Calendar;
class TBranch;
class TFile;
class TH1D;
class TTree;

class DataReader {
public:
    DataReader(string inputDatafileName);
    ~DataReader();

    void      execute();
    void      test();

    void      runFillingLoop(TH1D* inputH);
    void      runFillingWithWindow(TH1D* inputH, double low, double up);

    Calendar* getEndDT()   { return endDT; };
    Calendar* getStartDT() { return startDT; };

    void      setDatafile(string inputFilename);
    void      setEndDT(string inputDTStr);
    void      setQuantity(string inputStr) { quantity = inputStr; };
    void      setStartDT(string inputDTStr);

private:
    vector<double> vd;
    string    datafileName;
    string    actualDTStr;
    
    TFile*    file;
    TTree*    tree;

    float     ch0;
    float     timestamp;

    TBranch*  b_ch0;
    TBranch*  b_timestamp;

    string    quantity;

    Calendar* fileDT;
    Calendar* startDT;
    Calendar* endDT;

    double convertVolt2MeV(double inputV);
};

#endif
