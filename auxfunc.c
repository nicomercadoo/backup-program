#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "auxfunc.h"

// Se cuenta la cantidad de strings (ya que representan la cant. de paths)
unsigned int number_of_strings(char *file_name){
  FILE *f;
  unsigned n;
  char s[PATH_MAX];

  f = fopen(file_name, "rb");
  if (f != NULL){ // Se pudo abrir

    // Se calcula el tamaño del archivo y se lo divide por el tamaño de los elemetos
    // dento del mismo. Así se obtiene la cant de elementos.
    n = 0;
    fseek(f, 0, SEEK_END);
    n = ftell(f)/sizeof(s);
    fclose(f);

    return n;
  } else { // No se pudo abrir
    printf(ERROR_FILE_MSG, file_name);
    return 0;
  }
}

// Busca en un archivo binario de strings un string utilizando busqueda binaria
// Devuelve 1 si el elemento existe, 0 si no existe
int binary_search_file (char s[], char *file_name){
  FILE *file;
  int a,b;
  unsigned n, m, k, inf, sup;
  n = number_of_strings(file_name);
  m = PATH_MAX;
  char tmp[m], s_inf[m], s_sup[m], s_k[m];
  char strings[n][m];

  // Se cargan los datos del archivo en un arrglo
  // load_on_array(n, m, strings, file_name);

  // Se realiza la busqueda binaria sobre el arreglo anterior
  if (n <= 0) return 0;
  inf = 0;
  sup = n - 1;
  strcpy(tmp, s);
  // if (!exist_enter_char(s, m)) strncat(tmp, "\n", 2);

  file = fopen(file_name, "r");
  if (file != NULL) {
    fseek(file, inf, SEEK_SET);
    fread(&s_inf, m, 1, file);
    fseek(file,  m*sup, SEEK_SET);
    fread(&s_sup, m, 1, file); 

    a = strcmp(tmp, s_inf);
    b = strcmp(tmp, s_sup);
    
    if ((a < 0) || (b > 0)) return 0; // No está en el arreglo
    if ((a >= 0) && (b <= 0)){

      while (inf < sup){
        k = (inf + sup) / 2;

        fseek(file, m*k, SEEK_SET);
        fread(&s_k, m, 1, file);
        if (strcmp(tmp, s_k) > 0) inf = k + 1;
        else sup = k;
      }

      fseek(file, m*inf, SEEK_SET);
      fread(&s_inf, m, 1, file);
      if (strcmp(s_inf, tmp) == 0) return 1;
      else return 0;
    }
  } else printf(ERROR_FILE_MSG, file_name);

}
