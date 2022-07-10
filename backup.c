#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>

#include "types.h"
#include "help.h"
#include "add.h"

/* Variables, Estructuras y Tipos */

/* Acciones */
void leave();
void arrive();
void add();
void rm();
void config();
// void help();

/* Funciones */
TSubCommand which_subcommand(char *param);
int exist_config_file(char *path);

int main(int argc, char const *argv[]){
  char arg[20] = "";
  TSubCommand sub_command;

  if (argc >= 2){
    //Se decide que subcomando ejecutar en base al argumento ingresado
    strcpy(arg, argv[1]);
    sub_command = which_subcommand(arg);
    switch (sub_command){
    case LEAVE:   leave();            break;
    case ARRIVE:  arrive();           break;
    case ADD:     add(argc,argv);     break;
    case RM:      rm();               break;
    case CONFIG:  config();           break;
    case HELP:    help();             break;
    default: printf("%s no es un comando valido.\n", arg); break;
    }
  } else {
    //update();
    help();
  }
  //Se evalua si existe el archivo de configuracion.
  // if (access("./.backup.conf", F_OK) == 0){
  //   puts("Exists config file\n");
  // }
  // else puts("Not exists config file");
  // printf("test return: %i\n", access( "./.bakup-config/paths.txt", F_OK ));

  return 0;
}

/* Definicion de Funciones */

//Evalua cual es el subcomando ingresado
TSubCommand which_subcommand(char *param){
  if (strcmp(param, "leave") == 0)        return LEAVE;
  else if (strcmp(param, "arrive") == 0)  return ARRIVE;
  else if (strcmp(param, "add") == 0)     return ADD;
  else if (strcmp(param, "rm") == 0)      return RM;
  else if (strcmp(param, "config") == 0)  return CONFIG;
  else if (strcmp(param, "help") == 0 
    || strcmp(param, "--help") == 0
    || strcmp(param, "-h") == 0 )         return HELP;
  else                                    return NONE;
}  


void leave(){
  puts("es leave\n");
};
void arrive(){
puts("es arrivef\n");
};
void rm(){
  puts("es rm\n");
};
void config(){
  puts("es set\n");
};
