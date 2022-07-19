#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "types.h"
#include "auxfunc.h"
#include "add.h"

void add(int argcant, char **argpaths){
  FILE *file;
  char tmp[PATH_MAX];
  char path[PATH_MAX], argpath[PATH_MAX];
  unsigned i;

  // Se agrega la ruta
  printf("Agregando rutas:\n");
  for ( i = 2; i < argcant; i++ )
  {
    strcpy(argpath, argpaths[i]);
    if (argpath == NULL){ // No se pasó almenos una ruta
      printf("Faltan argumentos.\n");
      exit(EXIT_FAILURE);
    } else { // Se pasó una ruta
      realpath(argpath, tmp);
      strcpy(path, tmp);

      // Se evalua si la ruta existe
      if (path == NULL){ // La ruta no existe
        printf(RED "\tNo exitiste:\t%s\n" RESET, argpath);
        continue; // Siguiente ruta
      }

      // Se evalua si la ruta ya existe en el archivo de paths
      if (binary_search_file(path, PATHS_FILE)){ // La ruta ya esta cargada en el archivo
      printf(YEL "\tAgregado:\t%s\n" RESET, argpath);
        continue; // Siguiente ruta
      }
      
      //Como la ruta existe y no esta en el archivo de paths
      // Se abre el archivo para agregar la ruta
      file = fopen(PATHS_FILE, "ab");
      if (file == NULL){ // El archivo no se pudo abrir
        // Se escribe la ruta en el archivo
        fwrite(&path, sizeof(path), 1, file);
        fflush(file);
        printf(GRN "\tNuevo:\t%s\n" RESET, argpath);

        fclose(file);
      } else { // El archivo no se pudo abrir
        printf(ERROR_FILE_MSG, PATHS_FILE);
        exit(EXIT_FAILURE);
      }
    }
  }
}