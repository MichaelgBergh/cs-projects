/*
 * Programmer:      Michael Bergh
 * MST Username:    mgb99m
 * Section:         109
 * Date:            3/9/2021
 * File:            main.cpp
 * Purpose:         Driver for Assignment 5
*/

/*
 *  The original 2-D array is set up in the following format
 *
 *  0 1 0 0 0 0 0 0 0  (run 0 is minimum distance)
 *  0 1 0 0 0 0 0 0 0  (run 1 is minimum distance + run)
 *  0 1 0 0 0 0 0 0 0  (run 2 is minimum distance + run)
 *  ...
 *
 *  Where the index of the '1' is the current location of the adult.
 *  The amount of rows is (max - min + 1)
 *  The amount of zeros that follow the '1' is the maximum distance value.
 *  The location of the casino has an index of (min + run -1).
*/

#include <iostream>
#include "hw5.h"

using namespace std;

int main()
{
   const int num_runs = 10000;
   const int dec_to_percent = 100;
   int count;
   int min = 0;
   int max = 0;

   prompt_user(min,max);
   int **array = new int *[max]; //creates array object
   for (int i = 0; i < max; i++)
   {
      array[i] = new int[max];
   }
   for (int i = 0; i < max - min + 1; i++)
   {
      count = 0;
      for (int j = 0; j < num_runs; j++)
      {
         fill_array(array, min, max);
         if (simulate(array,i,max,min))
         {
            count++;
         }
      }
      cout << "***************************************************" << endl  //prints results
           << "Distance: " << min + i << " blocks" << endl
           << "Total Trials ran: " << num_runs << endl
           << "Made it to the Casino: " << count << endl
           << "Amount of Mid-Life Crisis: " << num_runs - count << endl
           << "Percentage of successful adults: " << static_cast<float>(count) / num_runs * dec_to_percent << "%"
           << endl;
   }
   return 0;
}