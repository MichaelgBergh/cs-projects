/*
 * Programmer:      Michael Bergh
 * MST Username:    mgb99m
 * Section:         109
 * Date:            4/20/2021
 * File:            Customer_functions.cpp
 * Purpose:         Implementation file for Customer class
*/

#include "Customer.h"


Customer::Customer()
{
   const int MIN_CASH = 25;
   const int MAX_CASH = 75;
   const int MIN_HEALTH = 1;
   const int MAX_HEALTH = 100;
   const int MIN_WEIGHT= 70;
   const int MAX_WEIGHT = 300;
   static int count = 0;
   string trash;
   ifstream fin;
   fin.open("names.dat");
   for (int i = 0; i < 15; i++)
   {
      if (i == count){fin >> name;}
      else {fin >> trash;}
   }
   count++;
   fin.close();
   customer_cash = make_random_number(MIN_CASH,MAX_CASH);
   health = make_random_number(MIN_HEALTH,MAX_HEALTH);
   weight = make_random_number(MIN_WEIGHT,MAX_WEIGHT);
   is_alive = true;
}

void Customer::introduce_contestant()
{
   cout  << "    " << name << " " << weight << " lbs, health value " << health << ", with $" << customer_cash << endl;
}

bool Customer::eat(Hawtdawg hd, Hawtdawgmeister &meister)
{
   const int WEIGHT_GAIN = 4;
   bool can_eat = false;
   if (is_alive && customer_cash > hd.get_cost())
   {
      customer_cash -= hd.get_cost();
      weight += WEIGHT_GAIN;
      health -= 2;
      meister += hd.get_cost();

      can_eat = true;
   }
   return can_eat;

}
void Customer::vomits()
{
   decrease_health(health / 2);
   cout << "        " <<name << " barfs "<< vomit_phrase[make_random_number(0,num_phrases - 1)] << endl;
   return;
}