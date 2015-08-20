#include "DatebaseBT.h"

#pragma region CTOR

CDatebaseBT::CDatebaseBT(string aPathOfFile)
{
  mAmountOfBits = 0;
  setPathOfFile(aPathOfFile);
  readFile(mPathOfFile);
  convertValuesToOtherTypes();
}

#pragma endregion
#pragma region FileManagment

bool CDatebaseBT::readFile(string aPathOfFile) // 10 // funkcyjnie rozpisac , to w funkcje wsadzic i przypisac do wartosci zwracanej
{                                               // jak DetectSpaceAndShift zwroci true to kolejna wartosc bedzie tempString->NextElementOfVector
  ifstream tempInputStream;
  tempInputStream.open(aPathOfFile, ios::in);

  string tempAllValueContainer = "";
  bool returnValue = true;

  if (tempInputStream) getline(tempInputStream, tempAllValueContainer); returnValue &= true;

  if (tempAllValueContainer == "") returnValue &= false;

  setAmountOfNumbers(AmountOfSpaces(tempAllValueContainer));

  if (returnValue) mTempStringChain = tempAllValueContainer;
  
  tempInputStream.close();

  return returnValue;
}
void CDatebaseBT::writeFile()  // 0
{
  setOutputStringChain();
  fstream tempOutputStream;
  tempOutputStream.open("posortowane.txt", std::ios::out);
  tempOutputStream.write(mOutputStringChain.c_str(), mOutputStringChain.size());
  tempOutputStream.close();


}

#pragma endregion
#pragma region ********** Private Getters ***********

string CDatebaseBT::getPathOfFile()
{
  return mPathOfFile;
}

#pragma endregion
#pragma region ********** Protected Getters ***********

vector<string> CDatebaseBT::getStringShape()
{
  return mContainers.StringShape;
}

vector<string> CDatebaseBT::getZmBinaryStringShape()
{
  return mContainers.ZmBinaryStringShape;
}

vector<double> CDatebaseBT::getDoubleShape()
{
  return mContainers.DoubleShape;
}

int CDatebaseBT::getAmountOfNumbers()
{
  return mAmountOfNumbers;
}

string CDatebaseBT::getPathOfOutputFile()
{
  return mPathOfOutputFile;
}

#pragma endregion
#pragma region ********** Private Setters ***********

void CDatebaseBT::setPathOfFile(string aPathOfFile)
{

  string strWyjatek="Error File Path";

  try
  {
    if (aPathOfFile[1] != ':') 
      throw strWyjatek;
    else
      mPathOfFile = aPathOfFile;
  }
  catch (string e)
  {
    printw(strWyjatek.c_str());
  }
}

void CDatebaseBT::setPathOfOutputFile()
{
  mPathOfOutputFile = mPathOfFile;

  for (int i = mPathOfOutputFile.length(); i >= 0; i--)
    {
      if (mPathOfOutputFile[i] == '\\')
      {
        mPathOfOutputFile.erase(i+1);
        break;
      }
  }
}

void CDatebaseBT::setAmountOfNumbers(int aAmountOfSpaces)
{
  mAmountOfNumbers = aAmountOfSpaces + 1;
}

void CDatebaseBT::setOutputStringChain()
{
  for (unsigned int i = 0; i < getStringShape().size(); i++)
  {
    mOutputStringChain.append(getStringShape()[i] + " ");
  }
}


#pragma endregion
#pragma region **************** Private Converters **********

bool CDatebaseBT::convertValuesToOtherTypes()
{
  convertChainToStringVector();
  convertValuesToDoubleVector();
  convertValuesToZmBinaryStringVector();
  return true;
}

bool CDatebaseBT::convertValuesToDoubleVector()
{
  for (unsigned int i = 0; i < mContainers.StringShape.size(); i++)
  {
    mContainers.DoubleShape.push_back(strtod(mContainers.StringShape[i].c_str(),NULL));
  }
 return true;
}

bool CDatebaseBT::convertValuesToZmBinaryStringVector() // 0
{
  for (unsigned int i = 0; i < mContainers.DoubleShape.size(); i++)
  {
    mContainers.ZmBinaryStringShape.push_back(DifferenceMethodBT(mContainers.DoubleShape[i],mAmountOfBits));
  }

  return true;
}

bool CDatebaseBT::convertChainToStringVector()
{
  bool returnedValue = false;

  for (int i = mTempStringChain.length() - 1, counter = 0; i >= 0; i--, counter++)
  {
    if (mTempStringChain[i] == ' ')
    {
      string ValueToVector = mTempStringChain.substr(mTempStringChain.length() - counter);
      mTempStringChain.erase(mTempStringChain.length() - (counter + 1));
      mContainers.StringShape.push_back(ValueToVector);
      counter = 0;
      counter--;
    }
    else if (i==0)
    {
      string ValueToVector = mTempStringChain.substr(0, counter + 1);
       // aValueToConvert.erase(0);
        mContainers.StringShape.push_back(ValueToVector);
        cout << endl << i << endl;
        counter = 0;
    }
  }
  //odwracanie elementow tablicy

  vector<string> tempVectorAfterRotate;
  for (int i = mContainers.StringShape.size()-1; i>=0; i--) 
  {
    tempVectorAfterRotate.push_back(mContainers.StringShape[i]);
  }
  mContainers.StringShape.swap(tempVectorAfterRotate);
  //

  return returnedValue;
}
#pragma endregion

#pragma region FUNKCJE DO ZAIMPLEMENTOWANIA Update2.0

CDatebaseBT::CDatebaseBT(string aPathOfFile, int aAmountOfBits) // 10
{
  // Zabezpieczenie ze sciezka iostnieje do napisania
  mAmountOfBits = aAmountOfBits;
  setPathOfFile(aPathOfFile);
  readFile(mPathOfFile);
  convertValuesToOtherTypes();
  //setAmountOfNumbers(getDoubleShape().size());
}


int CDatebaseBT::getAmountOfBits()
{
  return mAmountOfBits;
}

#pragma endregion