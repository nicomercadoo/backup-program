#include <stdio.h>
#include <stdlib.h>

#include "add.h"

//IMPLEMENTACION
void add(char *path){
  FILE *file;
 
  file = fopen("paths.txt", "a");
  if(file == NULL) EXIT_FAILURE;
	fputs(path, file);fputs("\n",file);
  fflush(file);
  fclose(file);
}