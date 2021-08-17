/*
 * Programmer:      Michael Bergh
 * MST Username:    mgb99m
 * Section:         109
 * Date:            4/20/2021
 * File:            random_generated_values.h
 * Purpose:         Header file for functions involving random outcomes
*/

#ifndef HW7_RANDOM_GENERATED_VALUES_H
#define HW7_RANDOM_GENERATED_VALUES_H

#include <cstdlib>
#include <ctime>

//Desc: Returns a random int between min and max inclusive.
//Pre: min and max must be positive ints.
//Post: A random int is returned.
int make_random_number(const int min, const int max);

//Desc: Returns whether a certain instance occurred given its chance to occur as a percentage.
//Pre: chance is a percentage value.
//Post: true or false is returned based on whether the random chance occurred.
bool random_chance(const int chance);

#endif //HW7_RANDOM_GENERATED_VALUES_H
