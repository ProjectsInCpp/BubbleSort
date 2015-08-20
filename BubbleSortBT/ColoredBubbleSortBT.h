#ifndef CColoredBubbleSortBT_H_INCLUDED
#define CColoredBubbleSortBT_H_INCLUDED

#include "SortbaseBT.h"
#include "curses.h"

class CColoredBubbleSortBT : public CSortbaseBT
{
public:

  void GetColouredSorting();
  void End();

  CColoredBubbleSortBT(string aPathOfFile,int aAmountOfBits);
  CColoredBubbleSortBT(string aPathOfFile);

};
#endif

#pragma region FUNKCJE DO ZAIMPLEMENTOWANIA Update2.0


#pragma endregion