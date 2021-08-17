/*
 * Programmer:      Michael Bergh
 * MST Username:    mgb99m
 * Section:         109
 * Date:            4/27/2021
 * File:            skware.h
 * Purpose:         Header file for skware class
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifndef HW8_SKWARE_H
#define HW8_SKWARE_H

class skware
{
private:
   int size = 0;
   int **nums;
   int *row_sums;
   int *col_sums;

public:
   //Desc: Constructor. Makes dynamic array based on passed in size and fills in nums with random values.
   //Pre: None.
   //Post: A skware object is created and filled.
   skware(const int size);

   //Desc: Destructor. Deletes all dynamic arrays.
   //Pre: Called automatically.
   //Post: All dynamic arrays are deleted.
   ~skware()
   {
      delete [] row_sums;
      delete [] col_sums;
      for (int i = 0; i < size; i++){ delete [] nums[i];} delete [] nums;
   }

   //Desc: Copy Constructor. Copies all data from the passed in skware
   //Pre: The passed in skware must have already been constructed and filled.
   //Post: The calling skware's values are updated to be equal to the passed in skware's values.
   skware(const skware &s);

   //Desc: Randomly sets a certain amount of nums to -1 and then prints the skware with empty spaces in those spots.
   //Pre: The calling skware should only call this function once and must already be filled.
   //Post: A certain amount of nums are set to -1 and the skware is printed to the screen.
   void display_puzzle();

   //Desc: Brute forces the empty spaces with random values and then checks it against the passed in skware S.
   //Pre: The passed in skware must be filled and must have never called display_puzzle().
   //Post: The first correct solution that is generated is printed to the screen.
   void solve(const skware S);

   //Desc: Prints the calling skware to the screen neatly.
   //Pre: None.
   //Post: The skware is printed to the screen.
   void print();

   //Desc: Overloads the == operator by comparing all values of the calling skware to the passed in skware.
   //Pre: None.
   //Post: The bool is returned.
   bool operator == (const skware s);

   //Desc: Overloads the = operator by setting all values of the calling skware to the passed in skware.
   //Pre: None.
   //Post: The skware that got updated is returned.
   skware operator = (const skware &s);
};

#endif //HW8_SKWARE_H