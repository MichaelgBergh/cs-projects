/*
 * Programmer:      Michael Bergh
 * MST Username:    mgb99m
 * Section:         109
 * Date:            4/20/2021
 * File:            Hawtdawgmeister.h
 * Purpose:         Header file for Hawtdawgmeister class
*/

#ifndef HW7_HAWTDAWGMEISTER_H
#define HW7_HAWTDAWGMEISTER_H

using namespace std;

class Hawtdawgmeister
{
private:
   string name;
   float meister_cash;
public:
   Hawtdawgmeister(const string nam, float cash) {name = nam; meister_cash = cash;}
   float operator += (const float cash) {return meister_cash += cash;}
   float operator -= (const float cash) {return meister_cash -= cash;}
};

#endif
