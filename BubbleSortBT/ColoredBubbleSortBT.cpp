#include "ColoredBubbleSortBT.h"

#pragma region CTOR

CColoredBubbleSortBT::CColoredBubbleSortBT(string aPathOfFile, int aAmountOfBits) : CSortbaseBT(aPathOfFile, aAmountOfBits)
{
}

CColoredBubbleSortBT::CColoredBubbleSortBT(string aPathOfFile) : CSortbaseBT(aPathOfFile)
{
}



#pragma endregion
# pragma region **************PUBLIC ELEMENTS OF INTERFACE

void CColoredBubbleSortBT::GetColouredSorting()// pobieranie pokolorowanego vectora wartosci
{
  start_color();
  int mAttrColor;
 

  init_pair(1, COLOR_BLACK, COLOR_RED);
  init_pair(2, COLOR_BLACK, COLOR_GREEN);

     for (int i = 0; i < getAmountOfNumbers(); i++) // wlaczam kolory dla poszczegolnych lini kolorowan
     {

       for (int j = 0; j < getAmountOfNumbers(); j++) // wlaczam kolory dla poszczegolnych kolumn kolorowan
       {        
           if (has_colors() == TRUE) // sprawdzanie posiadanie mozliwosci kolorowania
           {
             if (getTableOfShifts()[i][j] == '1') // jak w tym miejscu jest przestawienie to podswietl na czerwono
             {
               attron(COLOR_PAIR(1));
               printw("%s ", (getSortings()[i][j]).c_str());
               mAttrColor = 1;
             }
             else
             {              
               attron(COLOR_PAIR(2)); // jesli nie to podswietl na zielono
               printw("%s ", (getSortings()[i][j]).c_str());
               mAttrColor = 2;
             }

             attroff(COLOR_PAIR(mAttrColor));
           }
           else
           {
             printw("Brak obslugi kolorow");
             refresh();
           }   
       }


       printw("\n");
     }
} 

void CColoredBubbleSortBT::End() // ustawienie sciezki pliku wyjsciowego i zapisanie danych
{
  setPathOfOutputFile();
  writeFile(); 
}

#pragma endregion
#pragma region FUNKCJE DO ZAIMPLEMENTOWANIA Update2.0

//void CColoredBubbleSortBT::Start(char *aPathToFile)
//{
//  printw("\n");
//  refresh();
//}

#pragma endregion