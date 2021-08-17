/*
 * Programmer:      Michael Bergh
 * MST Username:    mgb99m
 * Section:         109
 * Date:            3/9/2021
 * File:            main.cpp
 * Purpose:         Header file for Assignment 5
*/

/*
 *  The original 2-D array is set up in the following format
 *
 *  0 1 0 0 0 0 0 0 0  (run 0 is minimum distance)
 *  0 1 0 0 0 0 0 0 0  (run 1 is minimum distance + run)
 *  0 1 0 0 0 0 0 0 0  (run 2 is minimum distance + run)
 *  ...
 *
 *  Where the index of the '1' is the current location of the adult.
 *  The amount of rows is (max - min + 1)
 *  The amount of zeros that follow the '1' is the maximum distance value.
 *  The location of the casino has an index of (min + run -1).
*/

#ifndef HW5_HW5_H
#define HW5_HW5_H

//Desc: Prompts the user to enter a minimum and maximum distance value.
//Pre: min and max must be greater than 2.
//Post: The values of min and max are equal to the user's inputted values.
void prompt_user(int &min, int &max);

//Desc: Fills a 2-D array with zeros and a '1' at index = 1 (starting position).
//Pre: **array must already be defined before calling the function
//Post: **array is filled as described in the comment block above.
void fill_array(int **array,const int min, const int max);

//Desc: Returns true if the random number is within the chance value, false otherwise.
//Pre: None.
//Post: Whether the adults moves forward or not in returned to main().
bool does_adult_moves_forward(const int rand, const int chance);

//Desc: Adjusts the position of the adult (the '1') in the array moves one index higher and a zero takes its old spot.
//Pre: None.
//Post: The array is updated.
void move_adult_forward(int **array, const int run);

//Desc: Adjusts the position of the adult (the '1') in the array moves one index lower and a zero takes its old spot.
//Pre: None.
//Post: The array is updated.
void move_adult_backward(int **array, const int run, const int max);

//Desc: Simulates a single case of whether the adult makes it to the casino and returns that as true or false.
//Pre: the run cannot be greater than the max value.
//Post: The random simulation's truth is returned to main().
bool simulate(int **array, const int run, const int max, const int min);

#endif
