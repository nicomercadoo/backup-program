#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#include "types.h"
#include "add.h"

void add(int argcant, char **argpaths){
  FILE *file;
  char buf[PATH_MAX];
  char *path, *argpath;
  int i;

  file = fopen(PATHS_FILE, "a");
  if (file == NULL) { //El archivo no se pudo abrir
    printf("No se encontro o no se pudo abrir el archivo %s.\n", PATHS_FILE);
    exit(EXIT_FAILURE);
  }

  printf("Agregando rutas:\n");
  for ( i = 2; i < argcant; i++ )
  {
    argpath = argpaths[i];
    if (argpath == NULL){ //No se pasó almenos una ruta
      printf("Faltan argumentos.\n");
      exit(EXIT_FAILURE);
    } else { //Se pasó una ruta
      path = realpath(argpath, buf);
      if (path == NULL){ //La ruta no existe
        printf(RED "\tNo exitiste:\t%s\n" RESET, argpath);
        continue; //Siguiente ruta
      }
      //Se escribe la ruta en el archivo
      fputs(path, file);fputs("\n",file);
      fflush(file);
      printf(GRN "\tAgregado:\t%s\n" RESET, argpath);
    }
  }

  fclose(file);
  
}