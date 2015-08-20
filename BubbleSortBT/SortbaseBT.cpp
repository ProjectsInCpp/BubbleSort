#include "SortbaseBT.h"

#pragma region CTOR

CSortbaseBT::CSortbaseBT(string aPathOfFile) : CDatebaseBT(aPathOfFile)
{
  mSortedContainers = mContainers;
  sorting();
}

CSortbaseBT::CSortbaseBT(string aPathOfFile, int aAmountOfBits) : CDatebaseBT(aPathOfFile, aAmountOfBits)
{
  mSortedContainers = mContainers;
  sorting();
}

#pragma endregion
#pragma region Protected Getters

vector<string> CSortbaseBT::getTableOfShifts()
{
  return mTableOfShifts;
}

vector<vector<string>> CSortbaseBT::getSortings()
{
  return mSortings;
}

#pragma endregion
#pragma region PrivateSortingFunctions

void CSortbaseBT::setTypeOfSorting()
{
  if (getAmountOfBits() != 0)
  {
    mIfBinarySorting = true;
  }
  else
  {
    mIfBinarySorting = false;
  }
}

void CSortbaseBT::sorting()
{
  setTypeOfSorting();

  if (mIfBinarySorting)
  {
    for (int i = 0; i < getAmountOfNumbers(); i++)
    {
      mTableOfShifts.push_back("");

      mSortings.push_back(getStringShape());

      for (int j = 0; j < getAmountOfNumbers() - 1; j++)
      {
        if (binaryComparing(j))
        {
          swap(mContainers.DoubleShape[j], mContainers.DoubleShape[j + 1]);
          swap(mContainers.StringShape[j], mContainers.StringShape[j + 1]);
          swap(mContainers.ZmBinaryStringShape[j], mContainers.ZmBinaryStringShape[j + 1]);
          fillTableOfShifts(i, "1");
        }
        else
        {
          fillTableOfShifts(i, "0");
        }
      }

      bool BreakNextLoop = false;

    //  for (int k = 0; k < mTableOfShifts[k].length(); i++)
    //  {
    //    if (mTableOfShifts[i][k] == '0') BreakNextLoop ^= false;
    //  }
    //
    //  if (BreakNextLoop == false) return;
    }
  }
  else
  {
    for (int i = 0; i < getAmountOfNumbers(); i++)
    {
      mTableOfShifts.push_back("");

      mSortings.push_back(getStringShape());

      for (int j = 0; j < getAmountOfNumbers() - 1; j++)
      {
        if (doubleComparing(j))
        {
          swap(mContainers.DoubleShape[j], mContainers.DoubleShape[j + 1]);
          swap(mContainers.StringShape[j], mContainers.StringShape[j + 1]);
          swap(mContainers.ZmBinaryStringShape[j], mContainers.ZmBinaryStringShape[j + 1]);
          fillTableOfShifts(i, "1");
        }
        else
        {
          fillTableOfShifts(i, "0");
        }
      }

    //  bool BreakNextLoop = false;
    //
    //  for (int k = 0; k < mTableOfShifts[k].length(); i++)
    //  {
    //    if (mTableOfShifts[i][k] == '0') BreakNextLoop ^= false;
    //  }
    //
    //  if (BreakNextLoop == false) return;
     
    }
  }

}

void CSortbaseBT::fillTableOfShifts(int aLine, string aLogicValue)
{
  mTableOfShifts[aLine].append( aLogicValue);
}

#pragma endregion

#pragma region Funkcje do zaimplementowania v.20

bool CSortbaseBT::binaryComparing( int aCurrentNumber)
{
  string mValue1 = getZmBinaryStringShape()[aCurrentNumber];                     
  string mValue2 = getZmBinaryStringShape()[aCurrentNumber + 1];                 

  bool mIsBothMinus = false;
  bool mIfCreateBubble = false;   


  for (int n = 0; n < getAmountOfBits(); n++)                                           // porownywanie poszczegolnych bitow
  {
    string mCurrentSubValue1 = mValue1.substr(n, 1);
    string mCurrentSubValue2 = mValue2.substr(n, 1);

    if (n == 0) //*******************Ustalenie znaku Liczby*******************8
    {
      if ((mCurrentSubValue1 == mCurrentSubValue2) && (mCurrentSubValue2 == "1")) mIsBothMinus = true;
      else mIsBothMinus = false;
    }
    else
      if (n>1)
      {
        if (mIsBothMinus) // V
        {
          if (mCurrentSubValue1 == mCurrentSubValue2)
          {
            mIfCreateBubble = false;
            continue;
          }
          else
            if (!IsFirstBigger(mCurrentSubValue1, mCurrentSubValue2))
            {
              mIfCreateBubble = true;
              return mIfCreateBubble;
            }
            else
              if (IsFirstBigger(mCurrentSubValue1, mCurrentSubValue2))
              {
                mIfCreateBubble = false;
                return mIfCreateBubble;
              }
        }
        else
        {
          if (mCurrentSubValue1 == mCurrentSubValue2)
          {
            mIfCreateBubble = false;
            continue;
          }
          else
            if (IsFirstBigger(mCurrentSubValue1, mCurrentSubValue2))
            {
              mIfCreateBubble = true;
              return mIfCreateBubble;
            }
            else
              if (!IsFirstBigger(mCurrentSubValue1, mCurrentSubValue2))
              {
                mIfCreateBubble = false;
                return mIfCreateBubble;
              }
        }
      }
  }

  return mIfCreateBubble;
}

bool CSortbaseBT::IsFirstBigger(string aFirstValue, string aSecondValue)
{
  return (aFirstValue > aSecondValue);
}

bool CSortbaseBT::IfSwap(bool aIsFirstBigger, bool isBothMinus)
{
 return (aIsFirstBigger == !isBothMinus);
}



//bool CSortbaseBT::IfBoothMinus(string aFirstValue, string aSecondValue)
//{
//  if ((aFirstValue == aSecondValue) && (aSecondValue == "1")) return true;
//  else return false;
//}
#pragma endregion

bool CSortbaseBT::doubleComparing(int aCurrentNumber)
{
  bool mIfCreateBubble = false;

  if (getDoubleShape()[aCurrentNumber] > getDoubleShape()[aCurrentNumber + 1])
  {
    mIfCreateBubble = true;
  }
  else
  {
    mIfCreateBubble = false;
  }
  
  return mIfCreateBubble;
}