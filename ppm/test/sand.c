#include <stdio.h>
#include <stdlib.h>

int main() {
  srandom(arc4random());
  printf("Rng: %ld", random());
  return 0;
}
