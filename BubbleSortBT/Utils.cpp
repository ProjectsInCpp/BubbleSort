#include "Utils.h"


int AmountOfSpaces(string aChainOfNumbers)
{
  int returnedValue = 0;

  for (int i = 0; i < aChainOfNumbers.length(); i++)
  {
    if (aChainOfNumbers[i] == ' ')
    {
      ++returnedValue;
    }
  }

  return returnedValue;
} 

bool SignAfterDifferencingBT(double aValueToConvert, int aCurrentPower)
{
  bool returnedValue = false;

  if (DifferenceWithPowerOf2BT(aValueToConvert, aCurrentPower) >= 0)
  {
    returnedValue = true;
  }
  else
  {
    returnedValue = false;
  }

  return returnedValue;
}

double DifferenceWithPowerOf2BT(double aValueToConvert, int aCurrentPower)
{
  double returnedValue = 0.0;

  returnedValue = (aValueToConvert - pow(2, aCurrentPower));

  return returnedValue;

}

string DifferenceMethodBT(double aValueToConvert, int aNumberOfBits)
{
  string returnedBinaryString = "";
  bool reachedResult = false;
  int aEndPower;
  int startOfLoop = aNumberOfBits / 2;
  int endOfLoop = aNumberOfBits - startOfLoop;

  if (aValueToConvert > 0)
  {
    returnedBinaryString.append("0.");
  }
  else
  {
    returnedBinaryString.append("1.");
  }

  for (int iPower = startOfLoop; iPower >= -endOfLoop; --iPower)
  {
    aEndPower = iPower;

    if (SignAfterDifferencingBT(aValueToConvert, iPower))
    {
      aValueToConvert = DifferenceWithPowerOf2BT(aValueToConvert, iPower);

      returnedBinaryString.append("1");

      if (DifferenceWithPowerOf2BT(aValueToConvert, iPower) == 0)
      {
        reachedResult = true;
        break;
      }
    }
    else
    {
      returnedBinaryString.append("0");
    }
  }
  if (reachedResult)
  {
    for (int iPower = aEndPower; iPower >= -13; --iPower)
    {
      returnedBinaryString.append("0");
    }
  }

  return returnedBinaryString;
}
#pragma region FunctionsTOImplement v2.0

//bool DoubleBackslashesInPath(string aPathToFile)
//{
//  bool returningValue = false;
//
//  for (int i = 0; i < aPathToFile.length(); i++)
//  {
//    if (aPathToFile[i] == '\\')
//    {
//      aPathToFile.insert(i + 1, "\\");
//      returningValue = true;
//    }
//  }
//
//  return returningValue;
//}



#pragma endregion