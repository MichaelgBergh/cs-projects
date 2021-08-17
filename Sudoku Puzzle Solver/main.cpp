/*
 * Programmer:      Michael Bergh
 * MST Username:    mgb99m
 * Section:         109
 * Date:            4/27/2021
 * File:            main.cpp
 * Purpose:         Driver file for hw8
*/

#include "skware.h"

int main()
{
   int size;
   char response1,response2;
   srand(time(0));  //seeds random values

   do
   {
      cout << "How big of a skware?" << endl;
      cin >> size;
      while (size < 6 || size > 10)
      {
         cout << "Enter a number between 6 and 10." << endl;
         cin >> size;
      }
      skware S = skware(size);
      skware soln(S);
      cout << "\nHere is your puzzle. Solve it if you can." << endl;
      soln.display_puzzle();
      cout << "\nDo you want the solution? (y/n)" << endl;
      cin >> response1;
      if (response1 == 'y')
      {
         cout << endl;
         soln.solve(S);
      }
      cout << "Would you like to see another puzzle? (y/n)" << endl;
      cin >> response2;
   } while (response2 == 'y');
   cout << "Thank you for playing.";
   return 0;
}