#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#include "help.h"

/* Variables y Estructuras */
typedef enum{
  LEAVE,
  ARRIVE,
  ADD,
  RM,
  SET,
  HELP
} subc; //Subcomandos

// FILE *f

/* Acciones */
void leave();
void arrive();
void add();
void rm();
void set();
void help();

/* Funciones */
subc which_subcommand(char *param);


int main(int argc, char const *argv[])
{
  char arg[20] = "";
  // printf("argc: %d\n", argc);
  subc sub_command;
  // printf("%s\n", argv[1]);

  if (argc >= 2)
  {
    strcpy(arg, argv[1]);
    sub_command = which_subcommand(arg);
    switch (sub_command)
    {
    case LEAVE:   leave();  break;
    case ARRIVE:  arrive(); break;
    case ADD:     add();    break;
    case RM:      rm();     break;
    case SET:     set();    break;
    case HELP:    help();   break;
    default:                break;
    }
  }
  else
  {
    help();
  }
  
  return 0;
}

/* Definicion de Funciones */
// arg whichArg(char *argv[])
subc which_subcommand(char *param){
  if (strcmp(param, "leave") == 0)  return LEAVE ;
  if (strcmp(param, "arrive") == 0) return ARRIVE;
  if (strcmp(param, "add") == 0)    return ADD;
  if (strcmp(param, "rm") == 0)     return RM;
  if (strcmp(param, "set") == 0)    return SET;
  if (strcmp(param, "help") == 0)   return HELP;
}  

void leave(){
  puts("es leave\n");
};
void arrive(){
puts("es arrivef\n");
};
void add(){
  puts("es add\n");
};
void rm(){
  puts("es rm\n");
};
void set(){
  puts("es set\n");
};



