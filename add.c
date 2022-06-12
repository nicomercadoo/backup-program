#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "add.h"
#define MAX 100
//IMPLEMENTACION
int main() {
  char p[MAX] = "";
  printf("Ingrese un Path: ");
  // scanf("%s", p);
  fgets(p, sizeof p, stdin);
  printf("El Path es: %s\n", p);
  puts("antes de funcion add\n");
  add(p);
  printf("\nSe guardo en el archivo de configuracion\n");
  return 0;
}
void add(char *path){
  puts("es add");
  FILE *file;
 
  file = fopen("path.txt", "a");
  puts("Abrio el archivo\n");
  if(file == NULL) EXIT_FAILURE;
  printf("%s\n", path);
  puts("Controlo el null\n");
	fputs(path, file);
  puts("Escribio el archivo\n");
  fflush(file);
  fclose(file);
  puts("Cerro el archivo\n");
}