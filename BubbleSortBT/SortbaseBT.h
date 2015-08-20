#ifndef CSortbaseBT_H_INCLUDED
#define CSortbaseBT_H_INCLUDED

#include "DatebaseBT.h"
#include <utility>

class CSortbaseBT : public CDatebaseBT
{

private:
  bool mIfBinarySorting;
  vector<string> mTableOfShifts;
  COMPLEXVALUETYPE mSortedContainers;
  vector<vector<string>> mSortings; 
 // implementowane
    bool IsFirstBigger(string aFirstValue, string aSecondValue);
    bool IfSwap(bool aIsFirstBigger, bool isBothMinus);
    bool IfBoothMinus(string aFirstValue, string aSecondValue);

protected:  
  vector<string> getTableOfShifts();
  vector<vector<string>> getSortings();

public:
  CSortbaseBT(string aPathOfFile);
  CSortbaseBT(string aPathOfFile, int aAmountOfBits);

private:
  void sorting( );
  void setTypeOfSorting();
  bool doubleComparing(int aCurrentNumber);
  bool binaryComparing(int aCurrentNumber);

  void fillTableOfShifts(int aLine,string aLogicValue);

};
#endif
