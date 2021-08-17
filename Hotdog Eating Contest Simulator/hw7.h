/*
 * Programmer:      Michael Bergh
 * MST Username:    mgb99m
 * Section:         109
 * Date:            4/20/2021
 * File:            hw7.h
 * Purpose:         Header file for hw7
*/


#ifndef HW7_HW7_H
#define HW7_HW7_H

#include "Customer.h"


//Desc: Runs a simulation of one round. Updates Customer's values and prints them to the screen.
//Pre: None.
//Post: num_contestants is returned to main() and 1 round of the competition ends.
int start_round(const int round_number, Customer contestants[], int num_contestants,Hawtdawgmeister &meister);

//Desc: Initiates a chain of Customer's throwing Hawtdawgs at one another and updates their values accordingly.
//Pre: None
//Post: Messages are printed and the Customer's values are updated.
void start_food_fight(int index, Customer contestants[],int num_contestants, Hawtdawgmeister &meister);

//Desc: Initiates a chain of Customer's vomiting on each other.
//Pre: None
//Post: Messages are printed and the Customer's values are updated.
void start_vomit_chain(int index, Customer contestants[], int num_contestants,Hawtdawgmeister &meister);


#endif //HW7_HW7_H
