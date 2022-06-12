#include <stdio.h>
#include <stdlib.h>

#include "add.h"

//IMPLEMENTACION
void add(char *path){
  FILE *file;
  //TODO: Comprobar que el string 'path' sea una ruta verdadera y existente.
  file = fopen("paths.txt", "a");
  if(file == NULL) EXIT_FAILURE;
	fputs(path, file);fputs("\n",file);
  fflush(file);
  fclose(file);
}