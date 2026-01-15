#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "roll.h"

#define RNG_SIZE 32
static int roll_has_seeded = 0;
static char last_seed_state[RNG_SIZE];
static char new_seed_state[RNG_SIZE];

char* roll_current_seed(){
  return new_seed_state;
}

char* roll_previous_seed(){
  return last_seed_state;
}

void roll_seed(unsigned int seed){
  if(roll_has_seeded == 1) return;
  char* prev_state = initstate(seed, new_seed_state, RNG_SIZE);
  memcpy(&last_seed_state, prev_state, RNG_SIZE);
  roll_has_seeded = 1;
}

static void init_seed() {
  roll_seed(arc4random());
}
 
int d(int sides) {
  //if the number of sides doesn't divide MAX_INT 
  //cleanly, then there is a bias if the random 
  //call lands in that remainder area. So, if it 
  //does, we just run it again.
  init_seed();

  int result = 0;
  int remainder_start = RAND_MAX - (RAND_MAX % sides);

  while((result = random()) >= remainder_start);
  return (int)result % sides;
}

int roll(int die, int sides){
  init_seed();

  int res = 0;
  int i;

  for(i = 0; i < die; i++){
    res += d(sides);
  }

  return res;
}

int rroll(int die, int sides, int* results){
  init_seed();

  int res = 0;
  int ires = 0;
  int i;
  
  for(i = 0; i < die; i++){
    ires = d(sides);
    res += ires;
    results[i] = ires;
  }

  return res; 
}
  
