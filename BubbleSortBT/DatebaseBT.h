#ifndef CDatebaseBT_H_INCLUDED
#define CDatebaseBT_H_INCLUDED

#include "Utils.h"
#include <iostream>
#include <iomanip>
#include "curses.h"
#include <fstream>

public class CDatebaseBT
{
private: // ifManaged
    int mAmountOfBits;
    bool mBinarySorting;
    string mTempStringChain;
    string mPathOfFile;  
    int mAmountOfNumbers;
    string mOutputStringChain;
    string mPathOfOutputFile;

protected:
    COMPLEXVALUETYPE mContainers;
    void writeFile();
    void setPathOfOutputFile();
    string getPathOfOutputFile();

    vector<string> getStringShape();
    vector<double> getDoubleShape();
    vector<string> getZmBinaryStringShape();
    int getAmountOfNumbers();
    int getAmountOfBits();
                                                
public:          
  CDatebaseBT(string aPathOfFile);
  CDatebaseBT(string aPathOfFile, int aAmountOfBits);

                              
private:
  bool readFile(string aPathOfFile);
  bool convertValuesToOtherTypes();
  bool convertValuesToDoubleVector(); 
  bool convertValuesToZmBinaryStringVector(); 
  bool convertChainToStringVector();

  void setPathOfFile(string aPathOfFile);
  void setOutputStringChain();
  void setAmountOfNumbers(int aAmountOfSpaces);

  string getPathOfFile();
};

#endif //CDatebaseBT_H_INCLUDED
