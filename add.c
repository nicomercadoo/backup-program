#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#include "types.h"
#include "add.h"

void add(char *argpath){
  FILE *file;
  char buf[PATH_MAX];
  char *path;
  
  if (argpath == NULL){ //No se pasó una ruta
    printf("Faltan argumentos.\n");
    exit(EXIT_FAILURE);
  } else { //Se pasó una ruta.
    path = realpath(argpath, buf);
    if (path == NULL){ //La ruta no existe
      printf("Ruta invalida.\n");
      exit(EXIT_FAILURE);
    }
    file = fopen(PATHS_FILE, "a");
    if (file == NULL) { //El archivo no se pudo abrir
      printf("No se encontro o no se pudo abrir el archivo %s.\n", PATHS_FILE);
      exit(EXIT_FAILURE);
    }
    //Se escribe la ruta en el archivo
    fputs(path, file);fputs("\n",file);
    fflush(file);
    fclose(file);
  }
}