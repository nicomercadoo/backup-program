#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#include "add.h"

void add(char *argpath){
  FILE *file;
  char buf[PATH_MAX];
  char *path;
  
  if (argpath == NULL){
    printf("Faltan argumentos.\n");
    exit(EXIT_FAILURE);
  } else {
    path = realpath(argpath, buf);
    if (path == NULL){
      printf("Ruta invalida.\n");
      exit(EXIT_FAILURE);
    }

    file = fopen("paths.txt", "a");
    if (file == NULL) {
      printf("No se encontro o no se pudo abrir el archivo paths.txt.\n");
      exit(EXIT_FAILURE);
    }
    
    fputs(path, file);fputs("\n",file);
    fflush(file);
    fclose(file);
  }
}