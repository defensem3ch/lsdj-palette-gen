#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

int main( int argc, char* argv[] ){

  void randPalette(char* filename) {
    FILE* fpalette;
    fpalette = fopen(filename, "wb+");
    fwrite(filename, sizeof(char), 4, fpalette);
    for (int i = 0; i < 40; i++) {
      fputc(rand(), fpalette);
    }
    fclose(fpalette);
    return;
  }

  char filename[12];
  srand(time(NULL));
  if (argc == 1) {
    printf("Enter a 4-character palette name: ");
    fgets(filename, 5, stdin);
    strncpy(&filename[4], ".lsdpal\0", 8);
    randPalette(filename);
  } else if ( argc == 2 ) {
    strncpy(filename, argv[1], 4);
    strncpy(&filename[4], ".lsdpal\0", 8);
    randPalette(filename);
  } else if ( argc == 3 ) {
    randPalette(argv[2]);
  } else {
    printf("%s\n", "Usage : palettegen <Palette name> <output file.lsdpal>");
  }
  return 0;
}
