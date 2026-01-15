#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/param.h>

int rand_color(int max_rgb);

int main(int argc, char** argv) {
  
  srandom(arc4random());
  
  /*
    P6 <width> <height> <max_color> 
    Byte Raster (array of bytes width*height*3(rgb))
  */
  size_t max_row, max_col, max_rgb;
  size_t row, col, i, p;

  max_row = 256;
  max_col = 256;
  max_rgb = 256;
  
  size_t pix_cnt = max_row * max_col * 3;

  FILE* fpic;
  char fname[256];

  for(i = 0; i < 60; i++) {
    
    memset(fname, 0, 256);
    sprintf(fname, "imgs/frame-%04ld.ppm", i);
    printf("Creating frame %04ld\n", i);
    
    fpic = fopen(fname, "w");
    if (fpic == NULL) {
      printf("Could not open file for writing: %s", fname);
      return 1;
    }

    int num_bytes = fprintf(fpic, "P6 %ld %ld %ld\n", max_row-1, max_col-1, max_rgb-1);
    if (num_bytes < 0) {
      printf("Could not write header to file: %s", fname);
      return 1;
    }

    for(p = 0; p < pix_cnt; p++){
      fputc(rand_color(max_rgb), fpic);
    }
    
    fclose(fpic);

  }

  return 0;
}

int rand_color(int max_rgb){
  return (int)( (random() % max_rgb) + 1 );
}
