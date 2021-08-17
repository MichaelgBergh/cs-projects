/*
 * Programmer:      Michael Bergh
 * MST Username:    mgb99m
 * Section:         109
 * Date:            3/30/2021
 * File:            hw6.h.cpp
 * Purpose:         Header file for Assignment 6
*/

#ifndef HW6_HW6_H
#define HW6_HW6_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Pants
{
private:
   static const int SIZE = 100;
   static const int MAX_NUM_COLORS = 7;
   static const int MAX_WAIST = 40;
   static const int MIN_WAIST = 20;
   const string COLORS[MAX_NUM_COLORS] = {"black", "blue", "red", "rainbow",
                                          "checkered", "electric green", "polka dot"};
   struct Pant
   {
      int waist;
      int inseam;
      int color;
      bool available;
   };
   struct Pants_of_size
   {
      int waist;
      short colors[MAX_NUM_COLORS] = {0};
   };
   Pant p[SIZE];
   Pants_of_size ps[MAX_WAIST - MIN_WAIST + 1];
public:
   //Desc: Uses random values to fill in an array of Pant's waist and color. Also reads in inseam values at random.
   //Pre: inseams.dat file must be in file.
   //Post: The Pant array values are filled.
   void fill_catalog();

   //Desc: Fills the index array values of waist and colors[] based on the values from the Pant array.
   //Pre: The Pant array must already be filled.
   //Post: The index array is filled.
   void fill_index();

   //Desc: Sorts the Pant array based on waist size.
   //Pre: The Pant array must already be filled.
   //Post: The Pant array is sorted.
   void sort_catalog();

   //Desc: Prints the Pant array to the screen in order.
   //Pre: The Pant array must already be filled.
   //Post: the Pant array is printed to the screen.
   void print();

   //Desc: Prompts the public, asking for which Pants they would like to buy and removes bought items from the array.
   //Pre: The Pant and the index array must already be filled.
   //Post: The public buys Pants and the arrays are updated.
   void prompt_user();
};

//Desc: Prompts the public if there is another customer in line and returns that truth value.
//Pre: None.
//Post: Whether or not there is another customer is returned to prompt_user().
bool ask_for_next_customer();

#endif
