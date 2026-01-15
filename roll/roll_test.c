#include "roll.h"
#include <assert.h>
#include <stdio.h>

int main() {

  //Make sure we get a result
  int res = d(6);
  assert(res >= 1 && res <= 6); 

  //now lets get our seed and make sure
  //it doesn't change. It is set from the previous
  //test. This isn't ideal but whatever
  char* seed_start = roll_current_seed();
  res = d(20);
  assert(seed_start == roll_current_seed()); 
  
  printf("Tests complete!\n");

}
