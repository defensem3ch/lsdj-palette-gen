#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

int main( int argc, char *argv[] ){
  if ( argc == 3 ) {
    srand(time(NULL));
    FILE* fpalette;
    fpalette = fopen(argv[2], "wb+");
    fwrite(argv[1], sizeof(char), 4, fpalette);
    for (int i = 0; i < 40; i++) {
      fputc(rand(), fpalette);
    }
    fclose(fpalette);
  } else {
    printf("%s\n", "Usage : palettegen <Palette name> <output file.lsdpal>");
  }
  return 0;
}
