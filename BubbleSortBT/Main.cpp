#include <iostream>
#include "curses.h"
#include <iomanip>
#include "DatebaseBT.h"
#include "SortbaseBT.h"
#include "ColoredBubbleSortBT.h"

using namespace std;

void main()
{
  char mPathOfFile[120];

  CColoredBubbleSortBT *mainSorting;

  int chEndOfSorting;

  initscr();
  do
  {
    clear();

    printw("**********************Witam w programie sortujacym********************** \n\n");
    printw("Podaj sciezke dostepu do pliku: ");
    getstr(mPathOfFile);

    if (mPathOfFile != "")
    {
      mainSorting = new CColoredBubbleSortBT(mPathOfFile,40);
      mainSorting->GetColouredSorting();
      mainSorting->End();
    }

    printw("\nDzieki za skorzystanie z programu .Czy chcesz posortowac kolejny dokument ? \nNacisnij t/T aby kontynuowac : ");
    chEndOfSorting = getch();

  } while (chEndOfSorting == 84 || chEndOfSorting == 116);

  refresh();

  mainSorting = 0;
  delete mainSorting;

  endwin();
}
