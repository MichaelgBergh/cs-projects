/*
 * Programmer:      Michael Bergh
 * MST Username:    mgb99m
 * Section:         109
 * Date:            3/9/2021
 * File:            hw5_functions.cpp
 * Purpose:         Function definitions for Assignment 5
*/

#include <iostream>
#include<cstdlib>
#include<ctime>
#include "hw5.h"

using namespace std;

void prompt_user(int &min, int &max)
{
   cout << "Enter the minimum distance from the casino to home: " << endl;
   cin >> min;

   cout << "Enter the maximum distance from the casino to home: " << endl;
   cin >> max;

   if (min <= 2 || max <= 2 || max < min)
   {
      cout << "!!!!!Please enter values greater than 2 and max must be greater than min!!!!!" << endl;
      prompt_user(min,max);
   }

   return;
}

void fill_array(int **array,const int min, const int max)
{
   for (int i = 0; i < max - min + 1; i++)
   {
      for (int j = 0; j < max; j++)
      {
         if (j == 1)
         {
            array[i][j] = 1; //fills second column with 1's
         }
         else
         {
            array[i][j] = 0; //fills everything else with 0's
         }
      }
   }
   return;
}

bool does_adult_moves_forward(const int rand,const int chance)
{
   bool forward;
   (chance > rand)? (forward = true) : (forward = false);
   return forward;
}

void move_adult_forward(int **array, const int run)
{
   bool exit = false;
   int i=0;
   do
   {
      if (array[run][i] == 1)
      {
         array[run][i + 1] = 1;
         array[run][i] = 0;
         exit = true;
      }
      i++;
   }while(!exit);
}

void move_adult_backward(int **array, const int run, const int max)
{
   bool exit = false;
   int i=max;
   do
   {
      if (array[run][i] == 1)
      {
         array[run][i - 1] = 1;
         array[run][i] = 0;
         exit = true;
      }
      i--;
   }while(!exit);
}

bool simulate(int **array, const int run, const int max, const int min)
{
   const int MAX_CHANCE = 100;
   const int DECREASE_CHANCE = 5;
   int chance = MAX_CHANCE;
   bool exit = false;
   bool did_adult_make_it = false;

   static bool first = true;
   if (first)
   {
      srand(time(0));       //seeds the random values once every program run
      first = false;
   }

   do
   {
      int random_num = rand() % MAX_CHANCE + 1; //random number with range [1,100] inclusive
      if (does_adult_moves_forward(random_num,chance))
      {
         move_adult_forward(array,run);      //moves the adult one index higher
         if (array[run][min + run - 1] == 1)
         {
            did_adult_make_it = true;       //adult made it to the casino
            exit = true;
         }
      }
      else
      {
         move_adult_backward(array,run,max);      //moves the adult one index lower
      }
      if (array[run][0] == 1)
      {
         did_adult_make_it = false;       //adult ended up back home
         exit = true;
      }
      chance -= DECREASE_CHANCE;   //chance to move forward decreases by 5% each time the adult moves.
   } while(!exit);
   return did_adult_make_it;
}