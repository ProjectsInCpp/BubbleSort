#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <vector>
#include <string>

using namespace std;

struct COMPLEXVALUETYPE
{
  vector<double> DoubleShape;
  vector<string> StringShape;
  vector<string> ZmBinaryStringShape;
};
int AmountOfSpaces(string aChainOfNumbers);

//*************MathMethodsConvertingToBinary*******************
double DifferenceWithPowerOf2BT(double aValueToConvert, int aCurrentPower);
bool SignAfterDifferencingBT(double aValueToConvert, int aCurrentPower);
string DifferenceMethodBT(double aValueToConvert,int aNumberOfBits);

#endif //CDatebaseBT_H_INCLUDED

#pragma region Functions to Implement in V2.0

//bool DoubleBackslashesInPath(string aPathToFile);

#pragma endregion


