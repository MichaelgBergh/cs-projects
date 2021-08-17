/*
 * Programmer:      Michael Bergh
 * MST Username:    mgb99m
 * Section:         109
 * Date:            3/30/2021
 * File:            hw6_functions.cpp
 * Purpose:         Implementation file for Assignment 6
*/

#include "hw6.h"

void Pants::fill_catalog()
{
   static bool first = true;
   int random_num;
   int inseam_data = 0;
   int num_inseam_data = 0;
   ifstream fin;
   if (first)
   {
      srand(time(0));       //seeds the random values once every program run
      first = false;
   }
   fin.open("inseams.dat");
   while (fin >> inseam_data) num_inseam_data++;   //determines the amount of ints in the inseam.dat file
   fin.close();

   for (int i = 0; i < SIZE; i++)
   {
      p[i].available = true;
      random_num = rand() % (MAX_WAIST - MIN_WAIST + 1) + MIN_WAIST; //random number with range [20,40] inclusive
      p[i].waist = random_num;
      random_num = rand() % (MAX_NUM_COLORS); //random number with range [0,6] inclusive
      p[i].color = random_num;
      random_num = rand() % (num_inseam_data);   //random number with range [0,num_inseam_data - 1] inclusive
      fin.open("inseams.dat");
      for (int j = 0; j < num_inseam_data; j++)
      {
         if (j == random_num) fin >> p[i].inseam;
         else fin >> inseam_data;
      }
      fin.close();
   }
   return;
}

void Pants::fill_index()
{
   for (int i = 0; i < MAX_WAIST - MIN_WAIST + 1; i++) //goes through Pants_of_size ps[]
   {
      ps[i].waist = MIN_WAIST + i;
      for (int j = 0; j < SIZE; j++)  //goes through Pant p[]
      {
         if (ps[i].waist == p[j].waist)
         {
            for (int k = 0; k < MAX_NUM_COLORS; k++)
            {
               if (p[j].color == k) ps[i].colors[k]++;
            }
         }
      }
   }
    return;
}

void Pants::sort_catalog()
{
   int temp;
   for (int i = 0; i < SIZE - 1; i++)
   {
      for (int j = 0; j < SIZE - i - 1; j++)
      {
         if (p[j].waist > p[j+1].waist)
         {
            temp = p[j].waist;
            p[j].waist = p[j+1].waist;
            p[j+1].waist = temp;
         }
      }
   }
   return;
}

void Pants::print()
{
   bool first;
   bool no_pants_that_size;
   for (int i = 0; i < MAX_WAIST - MIN_WAIST + 1; i++)
   {
      first = true;
      no_pants_that_size = true;
      cout << "waist " << ps[i].waist;
      for (int j = 0; j < SIZE; j++)
      {
         if (p[j].waist == ps[i].waist)
         {
            no_pants_that_size = false;
            if (first)
            {
               cout << "   ";
               first = false;
            }
            else cout << "           ";
            cout << "inseam " << p[j].inseam << "  " << COLORS[p[j].color] << endl;
         }
      }
      if (no_pants_that_size)
      {
         cout << endl;   //just helps format
      }
   }
}

bool ask_for_next_customer()
{
   char another_customer;
   bool is_there_another;
   cout << "\nIs there another customer? (y/n)" << endl;
   cin >> another_customer;
   if (another_customer == 'y') is_there_another = true;
   else is_there_another = false;
   return is_there_another;
}

void Pants::prompt_user()
{
   const float BONUS_CHARGE_CONSTANT = 0.9;
   const int BONUS_CHARGE_AMOUNT = 40;
   bool customer;
    do {
      int user_waist = 0;
      int colors_of_size = 0;  //amount of unique color for a given size
      int user_color = 0;
      int user_inseam = 0;
      int bonus_charge;
      bool waist_available = false;
      bool inseam_available = false;
      bool color_available = false;
      bool any_in_stock = false;
      int count = 0;   //just used for formatting the print statements

      cout << "\nWelcome to Bart's Pants store.\n" << endl;
      cout << "What is your waist size?" << endl;
      cin >> user_waist;

      for (int k = 0; k < MAX_NUM_COLORS; k++)
      {
         if (ps[user_waist - MIN_WAIST].colors[k] > 0)
         {
            waist_available = true;
         }
      }
      if (user_waist < 20 || user_waist > 40)
      {
         cout << "Go shop somewhere else. Goodbye" << endl;
         customer = ask_for_next_customer();
      }
      else if (waist_available)
      {
         cout << "For size " << user_waist << " we have: ";
         for (int k = 0; k < MAX_NUM_COLORS; k++)
         {
             if (ps[user_waist - MIN_WAIST].colors[k] > 0)
             {
                colors_of_size++;
             }
         }
         for (int k = 0; k < MAX_NUM_COLORS; k++)
         {
            if (ps[user_waist - MIN_WAIST].colors[k] > 0)
            {
               count++;
               if (colors_of_size == 1) cout << COLORS[k] << " (enter " << k << ") ";
               else if (count == colors_of_size) cout << "and " << COLORS[k] << " (enter " << k << ").";
               else cout << COLORS[k] << " (enter " << k << "), ";
            }
         }
         cout << "\nEnter your choice (-1 for none): " << endl;
         cin >> user_color;

         if (ps[user_waist - MIN_WAIST].colors[user_color] > 0)
         {
            color_available = true;
         }

         for (int i = 0; i < MAX_WAIST - MIN_WAIST + 1; i++)
         {
            for (int k = 0; k < MAX_NUM_COLORS; k++)
            {
               if (ps[i].colors[k] > 0) any_in_stock = true;
            }
         }
         if (user_color >= 0 && user_color < MAX_NUM_COLORS && color_available && any_in_stock)
         {
            cout << "For size " << user_waist << " and in " << COLORS[user_color] << " we have: " << endl;
            for (int i = 0; i < SIZE; i++)
            {
               if (p[i].waist == user_waist && p[i].color == user_color && p[i].available)
               {
                  cout << "       Inseam: " << p[i].inseam << endl;
               }
            }
            cout << "Enter the inseam you want: " << endl;
            cin >> user_inseam;

            for (int i = 0; i < SIZE; i++)
            {
               if (p[i].waist == user_waist && p[i].color == user_color && p[i].available && p[i].inseam ==user_inseam)
               {
                  inseam_available = true;
               }
            }
            if (inseam_available)
            {
               bonus_charge = (user_inseam < BONUS_CHARGE_CONSTANT * user_waist - 2)? (BONUS_CHARGE_AMOUNT) : (0);
               cout << "The price of those pants are: $" << user_waist + user_inseam + bonus_charge << endl;
               ps[user_waist - MIN_WAIST].colors[user_color]--;
               cout << "Thank you for your purchase." << endl;
               for (int i = 0; i < SIZE; i++)
               {
                  if (p[i].waist == user_waist && p[i].color == user_color && p[i].inseam == user_inseam)
                  {
                     p[i].available = false;
                  }
               }
            }
         }

         if (user_color == -1)
         {
            cout << "Stop wasting my time and leave." << endl;
         }
         else if (!color_available || !inseam_available)
         {
            cout << "There are no available pants with that size, color, and inseam." << endl;
         }
         customer = ask_for_next_customer();
      }
      else
      {
         cout << "There are no pants of that size available." << endl;
         customer = ask_for_next_customer();
      }
      if (!customer) cout << "No more customers, stores closed.";
   } while (customer);
   return;
}
