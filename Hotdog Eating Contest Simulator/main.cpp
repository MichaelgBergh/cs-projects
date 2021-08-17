/*
 * Programmer:      Michael Bergh
 * MST Username:    mgb99m
 * Section:         109
 * Date:            4/20/2021
 * File:            main.cpp
 * Purpose:         Driver file for hw7
*/

#include "hw7.h"
int main()
{
   const int TOTAL_CUSTOMERS = 15;
   int round = 0;
   int num_contestants = TOTAL_CUSTOMERS;
   srand(time(0));  //seeds random values

   cout << "Begin the Contest!!!\n\nThe Contestants are\n" << endl;
   Customer customers[TOTAL_CUSTOMERS];
   Hawtdawgmeister meister("Cletus",0);
   for (int i = 0; i < TOTAL_CUSTOMERS; i++)
   {
      customers[i].introduce_contestant();
   }
   do
   {
      round++;
      num_contestants = start_round(round,customers,num_contestants,meister);

   } while(num_contestants != 1);

   return 0;
}