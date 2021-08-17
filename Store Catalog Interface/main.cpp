/*
 * Programmer:      Michael Bergh
 * MST Username:    mgb99m
 * Section:         109
 * Date:            3/30/2021
 * File:            main.cpp
 * Purpose:         Driver file for Assignment 6
*/

#include "hw6.h"

int main()
{
   Pants ppp;
   ppp.fill_catalog();
   ppp.sort_catalog();
   ppp.fill_index();
   ppp.print();
   ppp.prompt_user();
   return 0;
}


