/*
 * Programmer:      Michael Bergh
 * MST Username:    mgb99m
 * Section:         109
 * Date:            4/20/2021
 * File:            Hawtdawg.h
 * Purpose:         Header file for Hawtdawg class
*/

#ifndef HW7_HAWTDAWG_H
#define HW7_HAWTDAWG_H

#include <iostream>
#include <ostream>

using namespace std;

class Hawtdawg
{
private:
   int num_animals,ounces_of_onion,num_pickles;
   bool has_relish,has_cheese,has_pathogen;
   float cost;
public:
   Hawtdawg(const int num_animals, const int ounces_of_onion, const int num_pickles,
            const bool has_relish, const bool has_cheese, const bool has_pathogen);
   Hawtdawg();
   float get_cost() {return cost;}
   bool has_virulent_pathogen() {return has_pathogen;}
   friend ostream & operator << (ostream & os, const Hawtdawg hd)
   {
      return os << "number of animals: " << hd.num_animals << ", ounces of onions: " << hd.ounces_of_onion
         << ", number of pickles: " << hd.num_pickles << ", " << ((hd.has_relish)?("with relish"):("without relish"))
         << ", " << ((hd.has_cheese)?("with cheese"):("without cheese"))
         << ((hd.has_pathogen)?("with a pathogen"):("without a pathogen"));
   }
};

#endif //HW7_HAWTDAWG_H
