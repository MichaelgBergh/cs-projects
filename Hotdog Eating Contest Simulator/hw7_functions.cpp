/*
 * Programmer:      Michael Bergh
 * MST Username:    mgb99m
 * Section:         109
 * Date:            4/20/2021
 * File:            hw7_functions.cpp
 * Purpose:         Implementation file for hw7
*/

#include "hw7.h"

void start_food_fight(int index, Customer contestants[],
                      int num_contestants, Hawtdawgmeister &meister){

   const int HEALTH_INCREASE = -2;
   const int CHANCE_TO_KEEP_THROWING = 80;
   bool can_afford = true;
   int thrower = index;
   int target = 0;

   do {
      target = make_random_number(0,num_contestants);
      Hawtdawg hd;
      if (contestants[thrower].get_cash() > hd.get_cost()) {
         cout << "            " << contestants[thrower].get_name() << " tosses a dawg at "
              << (target == num_contestants ? ("Cletus") : (contestants[target].get_name())) << endl;
         contestants[thrower].decrease_health(HEALTH_INCREASE);
         contestants[thrower].decrease_cash(hd.get_cost());

         if (target == num_contestants)  //Cletus gets hit
         {
            contestants[thrower].disqualify();
            meister += contestants[thrower].get_cash();
            contestants[thrower].decrease_cash(contestants[thrower].get_cash()); //Cletus takes all their cash
            can_afford = false;
         }
         else if (!contestants[target].get_alive())
         {
            cout << "            " << contestants[target].get_name()
               << " does not toss a dawg ... because they are dead " << endl;
            can_afford = false;
         }

      }
      else
      {
         cout << "            " << contestants[thrower].get_name() << " wants to toss a dawg at "
              << (target == num_contestants ? ("Cletus") : (contestants[target].get_name())) << " but can't afford it" << endl;
         can_afford = false;
      }
      thrower = target;
   } while (random_chance(CHANCE_TO_KEEP_THROWING) && can_afford);
   return;
}
void start_vomit_chain(int index, Customer contestants[], int num_contestants, Hawtdawgmeister &meister)
{
   const int CHANCE_TO_VOMIT = 50;
   const int CHANCE_TO_THROW = 70;
   bool did_not_barf = false;
   int backwards_index = index - 1;
   index++;
   while (index < num_contestants && !did_not_barf && contestants[index].get_alive() ) //while next person vomits
   {
      if (random_chance(CHANCE_TO_VOMIT))
      {
         contestants[index].vomits();
         index++;
         did_not_barf = false;
      }
      else
      {
         cout << "        " << contestants[index].get_name() << " does not barf" << endl;
         if (random_chance(CHANCE_TO_THROW))
         {
            start_food_fight(index, contestants, num_contestants, meister);
         }
         did_not_barf = true;
      }
   }
   if (contestants[index].get_alive() == false)
   {
      cout << "        " << contestants[index].get_name() << " does not barf... because they are dead" << endl;
   }
   did_not_barf = false;
   while (backwards_index >= 0 && !did_not_barf && contestants[backwards_index].get_alive()) // while previous person vomits
   {
      if (random_chance(CHANCE_TO_VOMIT))
      {
         contestants[backwards_index].vomits();
         backwards_index--;
         did_not_barf = false;
      }
      else
      {
         cout << "        " << contestants[backwards_index].get_name() << " does not barf" << endl;
         if (random_chance(CHANCE_TO_THROW))
         {
            start_food_fight(backwards_index, contestants, num_contestants, meister);
         }
         did_not_barf = true;
      }
   }
   if (contestants[backwards_index].get_alive() == false)
   {
      cout << "        " << contestants[backwards_index].get_name()
         << " does not barf ... because they are dead" << endl;
   }
   return;
}

int start_round(const int round_number, Customer contestants[], int num_contestants, Hawtdawgmeister &meister)
{
   const int CHANCE_TO_DIE = 100;
   static const int temp = num_contestants;
   int num_people_ate = 0;
   int winner_index = 0;
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << "\n------------------------ ROUND #" << round_number << " -------------------\n" << endl;

   num_contestants = 0;
   for (int i = 0; i < temp; i++)
   {
      if (contestants[i].is_still_contestant()) { num_contestants++; }  //updates the number of contestants left
   }
   for (int i = 0; i < temp; i++)
   {
      Hawtdawg hd = Hawtdawg();
      if (contestants[i].eat(hd,meister))
      {
         num_people_ate++;
         winner_index = i;
         if (contestants[i].get_health() <= 0)
         {
            contestants[i].kill();
            contestants[i].disqualify();
         }
         if (hd.has_virulent_pathogen())
         {
            if (make_random_number(1,CHANCE_TO_DIE) > contestants[i].get_health())  //person dies from pathogen
            {
               contestants[i].kill();
               contestants[i].disqualify();
            }

            else   //person vomits from pathogen
            {
               contestants[i].vomits();
               start_vomit_chain(i,contestants,temp,meister);
            }
         }

         cout << "    " << contestants[i].get_name() << " eats a dawg wt, "
              << contestants[i].get_weight() << ", health value " << contestants[i].get_health()
              << ", with $" << contestants[i].get_cash()
              << (contestants[i].get_alive()?(" STILL ALIVE"):(" DIED")) << endl;
      }

      else if (contestants[i].get_alive() == false)
      {
         cout << "    " << contestants[i].get_name() << " does not eat a dawg ... because they are dead" << endl;
      }

      else
      {
         cout << "    " <<contestants[i].get_name() << " does not eat a dawg ... because they can't afford it " <<endl;
      }

      }
   if (num_people_ate == 1)
   {
      num_contestants = 1;
      cout << "\n***** THE WINNER IS ... " << contestants[winner_index].get_name() <<  ", ending with a weight of "
           << contestants[winner_index].get_weight() << " a health value of "
           << contestants[winner_index].get_health() << " and $"
           << contestants[winner_index].get_cash() << " to spare! *****" << endl;
   }
   else if (num_people_ate == 0)
   {
      num_contestants = 1;

      for (int i = 0; i < temp; i++)
      {
         if (contestants[i].is_still_contestant() && contestants[i].get_alive())
         {
            if (contestants[i].get_health() > contestants[winner_index].get_health())
            {
               winner_index = i;
            }
         }
      }

      cout << "\n***** THE WINNER BY DEFAULT IS ... " << contestants[winner_index].get_name() <<  ", ending with a weight of "
           << contestants[winner_index].get_weight() << " a health value of "
           << contestants[winner_index].get_health() << " and $"
           << contestants[winner_index].get_cash() << " to spare! *****" << endl;
   }
   return num_contestants;
}