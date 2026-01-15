#ifndef _ROLL_H
#define _ROLL_H

//seed the generator for future rolls
void roll_seed(unsigned int seed);
//get current seed value - defaults to 0
char* roll_current_seed();
char* roll_previous_seed();
//roll 1dx
int d(int sides);
//roll ydx
int roll(int die, int sides);
//roll ydx but pass in a pointer to be filled with the results of the rolls
//results must be <die> long
int rroll(int die, int sides, int* results);

#endif
