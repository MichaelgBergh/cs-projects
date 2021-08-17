/*
 * Programmer:      Michael Bergh
 * MST Username:    mgb99m
 * Section:         109
 * Date:            4/27/2021
 * File:            skware_functions.cpp
 * Purpose:         Implementation file for skware class
*/

#include "skware.h"

skware::skware(const skware &s)
{
   size = s.size;
   nums = new int*[size];
   for (int i = 0; i < size; i++)
   {
      nums[i] = new int[size];
      for (int j = 0; j < size; j++)
      {
         nums[i][j] = s.nums[i][j];
      }
   }
   row_sums = new int[size];
   for (int i = 0; i < size; i++)
   {
      row_sums[i] = s.row_sums[i];
   }
   col_sums = new int[size];
   for (int i = 0; i < size; i++)
   {
      col_sums[i] = s.col_sums[i];
   }
}

skware::skware(const int sizes)
{
   size = sizes;
   nums = new int*[size];
   row_sums = new int[size];
   col_sums = new int[size];
   int random_num;

   for (int i = 0; i < size; i++) {col_sums[i] = 0;}

   for (int i = 0; i < size; i++)
   {
      nums[i] = new int[size]();
      row_sums[i] = 0;

      for (int j = 0; j < size; j++)
      {
         random_num = rand() % 7 + 1;
         nums[i][j] = random_num;

         col_sums[j] += random_num;
         row_sums[i] += random_num;
      }
   }
}
skware skware::operator = (const skware &s)
{
   {
      size = s.size;
      nums = new int *[size];
      for (int i = 0; i < size; i++)
      {
         nums[i] = new int[size];
         for (int j = 0; j < size; j++)
         {
            nums[i][j] = s.nums[i][j];
         }
      }
      row_sums = new int[size];
      for (int i = 0; i < size; i++)
      {
         row_sums[i] = s.row_sums[i];
      }
      col_sums = new int[size];
      for (int i = 0; i < size; i++)
      {
         col_sums[i] = s.col_sums[i];
      }
      return *this;
   }
}
bool skware::operator == (const skware s)
{
   bool is_same = true;

   for (int i = 0; i < size; i++)
   {
      for (int j = 0; j < size; j++)
      {
         if (nums[i][j]!= s.nums[i][j])
         {
            is_same = false;
         }
      }
   }
   return is_same;
}

void skware::display_puzzle()
{
   const int NUM_BLANK_SPACES = 5;
   int random_row;
   int random_col;
   int count = 0;

   while (count != NUM_BLANK_SPACES)
   {
      random_row = rand() % size;
      random_col = rand() % size;
      for (int i = 0; i < size; i++)
      {
         for (int j = 0; j < size; j++)
         {
            if (random_row == i && random_col == j && nums[i][j] > 0) {
               nums[i][j] = -1;
               count++;
            }
         }
      }
   }
   print();
   return;
}


void skware::print()
{
   for (int i = 0; i < size; i++) {cout << "|-----";}
   cout << "|" << endl;
   for (int i = 0; i < size; i++)
   {
      cout << "|  ";
      for (int j = 0; j < size; j++)
      {
         if (nums[i][j] > 0) {cout << nums[i][j] << "  |  ";}
         else {cout << "   |  ";}
         if (j == size - 1) {cout << row_sums[i];}
      }
      cout << endl;
      for (int i = 0; i < size; i++) {cout << "|-----";}
      cout << "|" << endl;
      if (i == size - 1)
      {
         for (int i = 0; i < size; i++)
         {
            cout << "  " << col_sums[i] << "  ";
         }
      }
   }
   return;
}



void skware::solve(const skware S)
{
   bool exit = false;
   bool equal_skware;
   int count;
   int random_solution;
   skware raw_copy(*this);

   while (!exit)
   {
      equal_skware = true;
      skware raw_copy(*this);
      for (int i = 0; i < size; i++) { raw_copy.col_sums[i] = 0; }
      for (int i = 0; i < size; i++) {
         raw_copy.row_sums[i] = 0;
         for (int j = 0; j < size; j++) {
            if (raw_copy.nums[i][j] < 0)
            {
               random_solution = rand() % 7 + 1;
               raw_copy.nums[i][j] = random_solution;            //randomly fills the holes
            }
            //new rol and col sums with the randomly filled values
            raw_copy.col_sums[j] += raw_copy.nums[i][j];
            raw_copy.row_sums[i] += raw_copy.nums[i][j];
         }
      }
      //check to see if the sums are equal
      count = 0;
      while (equal_skware && count < size)
      {
         if (raw_copy.col_sums[count] == S.col_sums[count] && raw_copy.row_sums[count] == S.row_sums[count])
         {
            exit = true;
            if (count == size - 1)
            {
               cout << "    This is a correct solution!" << endl;
               raw_copy.print();
            }
         }
         else
         {
            exit = false;
            equal_skware = false;
         }
         count++;
      }
   }

   cout << endl;

   return;
}