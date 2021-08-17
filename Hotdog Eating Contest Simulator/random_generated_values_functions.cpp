/*
 * Programmer:      Michael Bergh
 * MST Username:    mgb99m
 * Section:         109
 * Date:            4/20/2021
 * File:            random_generated_values_functions.cpp
 * Purpose:         Implementation file for random output functions
*/

#include "random_generated_values.h"


int make_random_number(const int min, const int max)
{
   int random_value = rand() % (max - min + 1) + min;
   return random_value;
}
bool random_chance(const int chance)
{
   bool occurs = false;
   int random_value = rand() % 100 + 1;
   if (chance > random_value) {occurs = true;}
   return occurs;
}
