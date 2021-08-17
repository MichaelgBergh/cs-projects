/*
 * Programmer:      Michael Bergh
 * MST Username:    mgb99m
 * Section:         109
 * Date:            4/20/2021
 * File:            Hawtdawg_functions.cpp
 * Purpose:         Implementation file for Hawtdawg class
*/

#include "Hawtdawg.h"
#include "random_generated_values.h"

Hawtdawg::Hawtdawg()
{
   const int MAX_VALUES = 4;
   const int PATHOGEN_CHANCE = 10;
   const int RELISH_CHEESE_CHANCE = 50;
   const float COST_PER_ANIMAL = 0.75;
   const float COST_PER_ONION = 0.5;
   const float COST_PER_PICKLE = 0.25;
   const float COST_BREAD = 0.5;
   const float COST_RELISH = 0.25;
   const float COST_CHEESE = 0.5;

   num_animals = make_random_number(0,MAX_VALUES);
   num_pickles = make_random_number(0,MAX_VALUES);
   ounces_of_onion = make_random_number(0,MAX_VALUES);

   if (random_chance(PATHOGEN_CHANCE))
   {
      has_pathogen = true;
   }
   else {has_pathogen = false;}

   if (random_chance(RELISH_CHEESE_CHANCE))
   {
      has_cheese = true;
   }
   else {has_cheese = false;}

   if (random_chance(RELISH_CHEESE_CHANCE))
   {
      has_relish = true;
   }
   else {has_relish = false;}

   cost = COST_BREAD + (num_animals * COST_PER_ANIMAL) + (num_pickles * COST_PER_PICKLE) +
          (ounces_of_onion * COST_PER_ONION + has_relish?(COST_RELISH):(0) + has_cheese?(COST_CHEESE):(0));

}

