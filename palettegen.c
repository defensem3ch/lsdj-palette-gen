#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

uint8_t r,g,b;
short rgb[20];

int main( int argc, char *argv[] ){
  if ( argc == 3 ) {
    srand(time(NULL));
    FILE* fpalette;
    for (int i = 0; i < 20; i++) {
      r = rand() % 32;
      g = rand() % 32;
      b = rand() % 32;
      rgb[i] = (r << 10 | g << 5 | b);
    }
    fpalette = fopen(argv[2], "wb+");
    fwrite(argv[1], sizeof(char), 4, fpalette);
    for (int i = 0; i < 20; i++) {
      fwrite(&rgb[i], sizeof(short), 1, fpalette);
    }
    fclose(fpalette);
  } else {
    printf("%s\n", "Usage : palettegen <Palette name> <output file.lsdpal>");
  }
  return 0;
}
