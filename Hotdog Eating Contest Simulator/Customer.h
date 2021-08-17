/*
 * Programmer:      Michael Bergh
 * MST Username:    mgb99m
 * Section:         109
 * Date:            4/20/2021
 * File:            Customer.h
 * Purpose:         Header file for Customer class
*/

#ifndef HW7_CUSTOMER_H
#define HW7_CUSTOMER_H

#include <iostream>
#include <string>
#include <fstream>
#include "Hawtdawg.h"
#include "Hawtdawgmeister.h"
#include "random_generated_values.h"

using namespace std;

class Customer
{
private:
   string name;
   float customer_cash;
   short health;
   int weight;
   bool is_alive;
   bool is_contestant;

public:
   Customer();

   //Desc: Determines whether or not a Customer can eat a passed in Hawtdawg based on their health and cash.
   //Pre: None
   //Post: true or false is returned and the Customer's values are updated.
   bool eat(Hawtdawg hd, Hawtdawgmeister &meister);
   void decrease_health(const int amount) {health -= amount;}
   void decrease_cash(const int amount) {customer_cash -= amount;}
   void disqualify() {is_contestant = false;}
   bool is_still_contestant() {return is_contestant;}

   void introduce_contestant();
   string get_name() {return name;}
   float get_cash() {return customer_cash;}
   short get_health() {return health;}
   int get_weight() {return weight;}
   bool get_alive() {return is_alive;}
   void kill() {is_alive = false;}

   static const int num_phrases = 5;
   const string vomit_phrase[num_phrases] = {"GAAAA!", "BLAHHHH!", "EEEEEK!", "YULLLK!", "PLEHH!"};

   //Desc: Halves the health of the Customer who vomits and prints a message.
   //Pre: None
   //Post: The Customer's health value is updated and a message is printed.
   void vomits();

};

#endif //HW7_CUSTOMER_H
