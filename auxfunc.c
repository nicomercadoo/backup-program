#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "auxfunc.h"

// Ordena los datos de un archivo de texto, utilizando Selection Sort.
void sort_file (char *fname){
  int n, i;
  char c;
  FILE *f;

  // Se abre el archivo en modo lectura
  f = fopen(fname, "r");
  if (f == NULL) { // El archivo no se pudo abrir
    printf("No se encontro o no se pudo abrir el archivo %s.\n", PATHS_FILE);
    exit(EXIT_FAILURE);
  }

  // Se cuentan la cantidad de lineas (ya que representan la cant. de paths)
  n = 0;
  while (!feof(f)){
    c = fgetc(f);
    if (c == '\n') n++;
    if (c == EOF) break;
  }

  char paths[n][PATH_MAX];
  
  // Se mueve la pocision del apuntador al comienzo del archivo
  fseek(f, 0, SEEK_SET);

  // Se carga el archivo con los datos del arreglo
  load_on_array(n, PATH_MAX, paths, &f);

  // Se ordena el arreglo
  selection_sort(n, PATH_MAX, paths);

  // Se abre el reabre el archivo en modo escritura
  freopen(fname, "w", f);
  if (f == NULL) { // El archivo no se pudo abrir
    printf("No se encontro o no se pudo abrir el archivo %s.\n", PATHS_FILE);
    exit(EXIT_FAILURE);
  }

  // Se vuelcan los datos del arreglo en el archivo
  load_on_file(n, PATH_MAX, paths, &f);

  // Se cierra el archivo
  fclose(f);
}

// Carga en un arrglo de strings los datos de un archivo de texto
void load_on_array(unsigned n, unsigned m, char a[n][m], FILE **file){
  char buffer[m];
  int i;

  i = 0;
  while (!feof(*file)){
    if (fgets(buffer, m, *file)){
      strcpy(a[i], buffer);
    }
    printf("a[%d]: %s\tbuffer: %s\n", i, a[i], buffer);
    i++;
  }
}

// Ordena un arreglo de strings usando el algoritmo Selection Sort
void selection_sort (int n, int m, char strings[n][m]){
  char temp[100];
  
  // Algoritmo Selection Sort
  for (int i = 0; i < (n - 1); i++){
    // Busqueda de la posicion del minimo string (minimo alfabeticamente)
    int j_min = i;
    for (int j = i + 1; j < n; j++)
      if (strcmp(strings[j], strings[j_min]) < 0)
        j_min = j;
    
    // if necesario, intercambia el minimo string con el string en el indice i
    if (j_min != i){
      strcpy(temp, strings[i]);
      strcpy(strings[i], strings[j_min]);
      strcpy(strings[j_min], temp);
    }
  }
}

// Carga en un archivo los datos de un arreglo de strings
void load_on_file(unsigned n, unsigned m, char a[n][m], FILE **file){
  int i;

  i = 0;
  while (i <= n){
    fputs(a[i], *file);
    i++;
  }
}
